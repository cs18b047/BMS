#include "signup.h"
#include "ui_signup.h"
#include <stdio.h>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <bits/stdc++.h>
#include "sql.h"
using namespace std;
signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_5_clicked()
{
    //accessing input information from ui
    string phno = ui->Phonenumbutton->text().toStdString();
    string vid  = ui->voteridbutton->text().toStdString();
    string mail = ui->emailbutton->text().toStdString();
    string name = ui->namebutton->text().toStdString();
    string adhar= ui->aadhaarbutton->text().toStdString();
    QSqlQuery query;
    //accessing the lastest account number that is used
    query.exec("select * from latest;");
    string latest_id;
    while (query.next()) {
        latest_id = query.value(0).toString().toStdString();
    }

    query.exec(("DELETE FROM latest WHERE latest_num = '" + latest_id + "';").c_str());
    query.exec(("INSERT INTO latest VALUES ('" + to_string(stoi(latest_id)+1) + "');").c_str());

    string params;
    params = "('" + latest_id + "','" + name + "','" + phno + "','" + mail + "','" + adhar + "','" + vid +"')";
    query.exec(("INSERT INTO userdetails VALUES " + params + ";").c_str());
    query.exec(("INSERT INTO userpass VALUES ('" + latest_id + "','" + latest_id + "');").c_str());
    query.exec(("INSERT INTO userbalance VALUES ('" + latest_id + "','0');").c_str());
    QMessageBox msgBox;
    msgBox.setText(latest_id.c_str());
    msgBox.exec();
    close();
    return;
}
