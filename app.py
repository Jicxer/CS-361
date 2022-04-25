from flask import Flask
from flask import request, Flask
from flask import request,Flask,render_template,redirect
from flask_pymongo import PyMongo

app = Flask(__name__)
app.config["MONGO_URI"] = "mongodb://localhost:27017/flaskCrashCourse"
mongo = PyMongo(app)

if __name__ == "__main__":
    app.run(debug=True)


@app.route('/')
def home():
    return "<p>The home page</p>"

