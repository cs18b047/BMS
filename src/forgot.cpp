#include "forgot.h"
#include "ui_forgot.h"
#include <stdio.h>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <bits/stdc++.h>
#include "sql.h"
#include "md5.h"

using namespace std;

Forgot::Forgot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forgot)
{
    ui->setupUi(this);
}

Forgot::~Forgot()
{
    delete ui;
}
void Forgot:: displayuser(string id)
{
    this->customerid = id;
}

void Forgot::on_pushButton_clicked()
{
    //accessing input information from ui
    QString g_vid=ui->voteridbutton->text();
    QString g_mail=ui->emailbutton->text();
    QString g_aadhaar=ui->aadhaarbutton->text();
    QSqlQuery query;
    query.exec(("select * from userdetails where customerid = '" + this->customerid + "';").c_str());
    if(query.next())
    {
        QString cur_vid = query.value(5).toString();
        QString cur_mail = query.value(3).toString();
        QString cur_aadhaar = query.value(4).toString();
        string cur_phno = query.value(2).toString().toStdString();
        cur_phno = md5(cur_phno);
        if ((g_vid == cur_vid) && (g_mail == cur_mail) && (g_aadhaar == cur_aadhaar)){
            query.exec(("DELETE FROM userpass WHERE customerid = '" + this->customerid + "';").c_str());
            query.exec(("INSERT INTO userpass VALUES ('" + this->customerid + "','" + cur_phno + "');").c_str());
            QMessageBox msgBox;
            msgBox.setText("Password is reset to your phone number");
            msgBox.exec();
        }
        else {
            QMessageBox msgBox;
            msgBox.setText("Wrong Details");
            msgBox.exec();
            close();
            return;
        }

    }
    close();
    return;
}
