import sqlite3
import datetime

ct = datetime.datetime.now()

connection = sqlite3.connect('database.db')

foreign_connection = sqlite3.connect('student.db')


with open('schema.sql') as f:
    connection.executescript(f.read())

cur = connection.cursor()
for_cur = foreign_connection.cursor()


# Insertion of test-data

title = 'This is a food title entry'
content = "Assorted random ingredients"

cur.execute("INSERT INTO posts (title, content) VALUES (?, ?)",
            (title, content)
            )

cur.execute('INSERT INTO recipes (name, email) VALUES (?, ?)',
                (title, content))


# Grab the amount of entities in the table
for_cur.execute("SELECT COUNT(*) FROM tbl_student;")
num = for_cur.fetchone()

for a in num:
    rows = a

# Store the name and email into a tuple to be indexed
for n in range(a):
    for_cur.execute("select name, email FROM tbl_student;")
    for_res = for_cur.fetchmany(a)
    tuple_list = for_res

#Grab the first element of each pair of tuples
title_list = [x[0] for x in tuple_list]
ingr_list = [y[1] for y in tuple_list]

# Insert the data into the table
for i in range(a):
    print(i)
    cur.execute("INSERT INTO posts (title,created, content) VALUES (?,?, ?)",
    (str(title_list[i]), ct, str(ingr_list[i])))

connection.commit()
connection.close()