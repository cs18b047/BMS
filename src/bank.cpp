#include "bank.h"
#include "ui_bank.h"
#include <iostream>
#include <cstring>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <bits/stdc++.h>
#include "sql.h"
#include "md5.h"

using namespace std;
Bank::Bank(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bank)
{
    ui->setupUi(this);
}

Bank::~Bank()
{
    delete ui;
}

void Bank::on_Loginbutton_clicked()
{
    string name=ui->usernamebutton->text().toStdString();
    string pass=ui->passwordbutton->text().toStdString();
    QSqlQuery query;
    query.exec(("select * from userpass where customerid = '" + name + "';").c_str());
    int cnt = 0;
    string act_pass;
    while(query.next())
    {
        act_pass = query.value(1).toString().toStdString();
        cnt += 1;
    }
    if (cnt == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid Username");
        msgBox.exec();
        return;
    }
    pass = md5(pass);
    if(act_pass != pass)
    {
        QMessageBox msgBox;
        msgBox.setText("Wrong password");
        msgBox.exec();
        return;
    }
    //code for user interface

    userobj=new User(this);
    hide();
    userobj->displayuser(name);
    userobj->exec();
    show();
    return;
}

void Bank::on_signupbutton_clicked()
{
    //code for signup interface
    signupobj=new signup(this);
    hide();
    signupobj->show();
    signupobj->exec();
    show();
    return;
}

void Bank::on_forgotbutton_clicked()
{
    string name = ui->usernamebutton->text().toStdString();
    QSqlQuery query;
    query.exec(("select * from userdetails where customerid = '" + name + "';").c_str());
    if(!query.next())
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid Username");
        msgBox.exec();
        return;
    }

    forgotobj=new Forgot(this);
    hide();
    forgotobj->displayuser(name);
    forgotobj->exec();
    show();
    return;
}

void Bank::on_Adminloginbutton_clicked()
{
    string given_pass=ui->adminpass->text().toStdString();
    string act_pass;
    QSqlQuery query;
    query.exec("select * from admin;");
    while (query.next()) {
        act_pass = query.value(0).toString().toStdString();
    }
    given_pass = md5(given_pass);
    if(given_pass != act_pass)
    {
        QMessageBox msgBox;
        msgBox.setText("Wrong Password");
        msgBox.exec();
        return;
    }
    hide();
    bool t=true;
    while(t)
    {
        t=OpenAdminInterface();
    }
    show();
    return;
}
bool Bank::OpenAdminInterface()
{
    Admin* adminob=new Admin();
    adminob->repeat=true;
    bool t=adminob->execAdmin();
    return t;
}
