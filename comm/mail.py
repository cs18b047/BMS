import mysql.connector
import smtplib
from email.mime.text import MIMEText
done = 0

while True:
    mydb = mysql.connector.connect( host="127.0.0.1",user="vissu",password="xxxxxx",database="bank")
    mycursor = mydb.cursor()
    mycursor.execute("SELECT * FROM transactions;")
    myresult = mycursor.fetchall()
    if len(myresult) > done:
        c = myresult[done]
        mycursor.execute("SELECT mail FROM userdetails WHERE customerid ='"+c[0]+"';")
        myresult = mycursor.fetchall()
        if len(myresult)!=0:
            try:
                msg = MIMEText("This is a auto generated email\n"+c[1]+"\n"+c[2])
                msg['From'] = 'bank@mymix.tech'
                msg['To'] = myresult[0][0]
                msg['Subject'] = 'Online Transaction alert'
                server = smtplib.SMTP('smtp.mymix.tech', port=587)
                server.login('bank@mymix.tech', 'eW%egbxOs6')
                server.sendmail('bank@mymix.tech', [myresult[0][0]], msg.as_string())
                server.quit()
                done += 1
            except:
                done += 1
                pass
        else:
            done += 1
    mydb.close()
