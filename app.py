import os
import sqlite3
from flask import Flask, render_template, request, url_for, flash, redirect
from werkzeug.exceptions import abort
import datetime
from flask_pymongo import PyMongo
       
            
app = Flask(__name__)
app.config["MONGO_URI"] = "mongodb://localhost:27017/"
app.config['SECRET_KEY'] = 'secret'
mongo = PyMongo(app)

def get_db_connection():
    conn = sqlite3.connect('database.db')
    conn.row_factory = sqlite3.Row
    return conn

def get_post(post_id):
    conn = get_db_connection()
    post = conn.execute('SELECT * FROM posts WHERE id = ?',
                        (post_id,)).fetchone()
    conn.close()
    if post is None:
        abort(404)
    return post


@app.route('/')
def home():
    conn = get_db_connection()
    posts = conn.execute('SELECT * FROM posts').fetchall()
    conn.close()
    return render_template("/pages/home.html",homeIsActive=True,addNoteIsActive=False, posts=posts)

@app.route('/<int:post_id>')
def post(post_id):
    post = get_post(post_id)
    return render_template('/pages/post.html',homeIsActive=True,addNoteIsActive=False,post=post)

@app.route("/add-note", methods=['GET','POST'])
def addNote():
    if(request.method == "GET"):

        return render_template("pages/add-note.html",homeIsActive=False,addNoteIsActive=True)

    elif (request.method == "POST"):

        # get the fields data
        title = request.form['title']
        content = request.form['content']
        created = datetime.datetime.now()
        conn = get_db_connection()
        conn.execute('INSERT INTO posts (title, content) VALUES (?, ?)',
                        (title, content))
        conn.commit()
        conn.close()

        return redirect("/")


@app.route('/<int:id>/edit', methods=('GET', 'POST'))
def edit(id):
    post = get_post(id)

    if request.method == 'POST':
        title = request.form['title']
        content = request.form['content']

        if not title:
            flash('Title is required!')
        else:
            conn = get_db_connection()
            conn.execute('UPDATE posts SET title = ?, content = ?'
                         ' WHERE id = ?',
                         (title, content, id))
            conn.commit()
            conn.close()
            return redirect("/")

    return render_template('pages/edit-notes.html', post=post)

@app.route('/<int:id>/delete', methods=('POST',))
def delete(id):
    post = get_post(id)
    conn = get_db_connection()
    conn.execute('DELETE FROM posts WHERE id = ?', (id,))
    conn.commit()
    conn.close()
    flash('"{}" was successfully deleted!'.format(post['title']))
    return redirect("/")

if __name__ == "__main__":
    app.run(debug=True ,port=8080)