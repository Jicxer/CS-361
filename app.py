import os
import datetime
from flask import Flask
from flask import request, Flask
from flask import request,Flask,render_template,redirect
from flask_pymongo import PyMongo
       
            
app = Flask(__name__)
app.config["MONGO_URI"] = "mongodb://localhost:27017/"
mongo = PyMongo(app)



@app.route('/')
def home():
    return render_template("/pages/home.html",homeIsActive=True,addNoteIsActive=False)


@app.route("/add-note", methods=['GET','POST'])
def addNote():
    if(request.method == "GET"):

        return render_template("pages/add-note.html",homeIsActive=False,addNoteIsActive=True)

    elif (request.method == "POST"):

        # get the fields data
        title = request.form['title']
        description = request.form['description']
        createdAt = datetime.datetime.now()



        return redirect("/")

@app.route('/edit-note', methods=['GET','POST'])
def editNote():

    if request.method == "GET":

        # get the id of the note to edit
        noteId = request.args.get('form')



        # direct to edit note page
        return render_template('pages/edit-note.html')

    elif request.method == "POST":

        #get the data of the note
        noteId = request.form['_id']
        title = request.form['title']
        description = request.form['description']



        return redirect("/")

@app.route('/delete-note', methods=['POST'])
def deleteNote():

    # get the id of the note to delete
    noteId = request.form['_id']

    # delete from the database

    # redirect to home page
    return redirect("/")

if __name__ == "__main__":
    app.run(debug=True ,port=8080)