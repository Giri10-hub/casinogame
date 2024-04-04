import mysql.connector


db = mysql.connector.connect(
         host='localhost',
         port='3306',
         user='root',
         database='girish',
         auth_plugin='mysql_native_password',
         password='12345')
query = 'create table if not exists college(username varchar(20) primary key, password varchar(20))'
cur = db.cursor()
cur.execute(query)
print("created")
def insert(username, password):
    query = "insert into college(username,password) values('{}','{}')".format(username, password)
    cur = db.cursor()
    cur.execute(query)
    db.commit()
    print("login data added to database")
def displyall():
    query = "select * from college"
    cur = db.cursor()
    cur.execute(query)
    for row in cur:
        print("username:", row[0])
        print("password:", row[1])


def delete(username):
    query = "delete from college where username= '{}'".format(username)
    cur = db.cursor()
    cur.execute(query)
    db.commit()
    print("deleted")

while True:
    print("1. Insert 2.Display 3.Delete  ")
    choice = input("Enter your choice: ")
    if choice == "1":

        username = (input("Enter username : "))
        password = (input("Enter password : "))

        insert(username, password)
    elif choice == "2":
        displyall()
    elif choice == "3":
        username = (input("Enter username delete: "))
        delete(username)