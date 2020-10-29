# TODO
import cs50
import csv
import sys

#Check if they've put cmd line args
if len(sys.argv) != 2:
    print("Error")
    exit(1)

#Create the database
open("students.db", "w").close

#Open that file for SQLite
db = cs50.SQL("sqlite:///students.db")

#Create a table
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth TEXT)")

#Open the file with the data
with open(sys.argv[1], "r") as char:

    reader = csv.DictReader(char)

    #Write the data
    for row in reader:

        #Split the names to see if you need to fill the middle
        names = row["name"].split()

        if len(names) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", names[0], names[1], names[2], row["house"], row["birth"])

        if len(names) == 2:
            db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)", names[0], names[1], row["house"], row["birth"])

