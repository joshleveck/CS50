import cs50
import sys

#Check if they've put cmd line args
if len(sys.argv) != 2:
    print("Error")
    exit(1)

#Var for the house
house = sys.argv[1]

#Open the DB
db = cs50.SQL("sqlite:///students.db")

#Execute the search
names = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", house)

#Print the search
for i in range(len(names)):

    #Determine whether to print the middle name
    if not names[i]['middle']:
        print(f"{names[i]['first']} {names[i]['last']}, born {names[i]['birth']}")
    else:
        print(f"{names[i]['first']} {names[i]['middle']} {names[i]['last']}, born {names[i]['birth']}")