from ipaddress import IPv4Address  # for your IP address
from pyairmore.request import AirmoreSession  # to create an AirmoreSession
from pyairmore.services.messaging import MessagingService  # to send message
import mysql.connector
import smtplib
done = 0

ip = IPv4Address("192.168.0.100")
session = AirmoreSession(ip)
was_accepted = session.request_authorization()
service = MessagingService(session)
while True:
    mydb = mysql.connector.connect( host="us.dreamcometrue.studio",user="vissu",password="xxxxxx",database="bank")
    mycursor = mydb.cursor()
    mycursor.execute("SELECT * FROM transactions;")
    myresult = mycursor.fetchall()
    if len(myresult) > done:
        c = myresult[done]
        mycursor.execute("SELECT phone FROM userdetails WHERE customerid ='"+c[0]+"';")
        myresult = mycursor.fetchall()
        if len(myresult)!=0:
            try:
                msg = "This is a auto generated message\n"+c[1]+"\n"+c[2]
                ip = IPv4Address("192.168.0.100")
                service.send_message(myresult[0][0], msg)
                done += 1
            except:
                done += 1
                pass
        else:
            done += 1
    mydb.close()
