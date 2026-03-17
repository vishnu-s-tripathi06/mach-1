import sqlite3
#creating database
conn=sqlite3.connect(':memory:')   #for temporary storage
#conn=sqlite3.connect('customer.db')
#Create a cursor , it executes all commands in sqlite3
c=conn.cursor()
#create a table
c.execute("""
         CREATE TABLE IF NOT EXISTS customers(
          id INTEGER PRIMARY KEY AUTOINCREMENT,
          first_name TEXT,
          last_name TEXT,
          email TEXT
          )
          """)
customers=[ ('john','jones','jonnybones300@gmail.com'),
           ('rampage','jackson','rampage@gmail.com'),
           ('conor','mcgregor','irissuma@gmail.com')]
c.executemany("""
INSERT INTO customers (first_name , last_name,email)
           
           VALUES (?,?,?)
           """,customers
          )
c.execute("SELECT * FROM customers WHERE last_name='jones' ")
#c.fetchmany(3)
items = c.fetchall()
for item in items: 
    print(str(item[0])+" "+item[1]+" "+item[2]+" "+item[3])




conn.commit()
print("Successfully made the changes...!")
#sqlite3 datatypes:  NULL, INTEGER , REAL, TEXT, BLOB
conn.close()