#include "admin.h"
#include "ui_admin.h"
#include <stdio.h>
#include <cstring>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <bits/stdc++.h>
#include "sql.h"
using namespace std;

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}
bool Admin::execAdmin()
{
    exec();
    return repeat;
}
//checks balance of all accounts
void Admin::on_balancebutton_clicked()
{
    int min_balance = stoi(ui->balancestand->text().toStdString());
    string ans = "";
    QSqlQuery query;
    query.exec("select * from userbalance;");
    int cur_balance;
    while(query.next())
    {
        cur_balance = stoi(query.value(1).toString().toStdString());
        if (cur_balance >= min_balance)
            ans += query.value(0).toString().toStdString() + "\n";
    }
    QMessageBox msgBox;
    msgBox.setText(ans.c_str());
    msgBox.exec();
}
//checks aadhaar number of all counts
void Admin::on_aadhaarbutton_clicked()
{
    string given_aadhaar= ui->aadhaarstand->text().toStdString();
    string ans = "";
    QSqlQuery query;
    query.exec("select * from userdetails;");
    string cur_aadhaar;
    while(query.next())
    {
        cur_aadhaar = query.value(4).toString().toStdString();
        if (given_aadhaar == cur_aadhaar)
            ans += query.value(0).toString().toStdString() + "\n";
    }
    QMessageBox msgBox;
    msgBox.setText(ans.c_str());
    msgBox.exec();
}
//checks name on all accounts
void Admin::on_namebutton_clicked()
{
    QString given_name = ui->namestand->text();
    string ans = "";
    QSqlQuery query;
    query.exec("select * from userdetails;");
    QString cur_name;
    while(query.next())
    {
        cur_name = query.value(1).toString();
        if (given_name == cur_name)
            ans += query.value(0).toString().toStdString() + "\n";
    }
    QMessageBox msgBox;
    msgBox.setText(ans.c_str());
    msgBox.exec();
}

void Admin::on_closebutton_clicked()
{
    repeat=false;
    close();
}
