#include "user.h"
#include "ui_user.h"
#include <stdio.h>
#include <QMessageBox>
#include <bits/stdc++.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "sql.h"
using namespace std;
User::User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
}

User::~User()
{
    delete ui;
}

void User::displayuser(string id)
{
    this->customerid = id;
    QString phno,mail,vid,name,account_balance;
    QSqlQuery query;
    query.exec(("select * from userdetails where customerid = '" + this->customerid + "';").c_str());
    if(query.next())
    {
        phno = query.value(2).toString();
        mail = query.value(3).toString();
        vid = query.value(5).toString();
        name = query.value(1).toString();
    }
    query.exec(("select * from userbalance where customerid = '" + this->customerid + "';").c_str());
    if(query.next())
    {
        account_balance = query.value(1).toString();
    }

    //to diplay the user information
    ui->phonenumberbutton->setText(phno);
    ui->emailbutton->setText(mail);
    ui->voteridbutton->setText(vid);
    ui->namebutton->setText(name);
    ui->balancebutton->setText(account_balance);

    vector<pair<string,string>> recent;
    query.exec(("select * from transactions where customerid1 = '" + this->customerid + "';").c_str());
    while(query.next())
    {
        string other_id = query.value(1).toString().toStdString();
        string amount = query.value(2).toString().toStdString();
        recent.push_back(make_pair(other_id,amount));
    }

    if(recent.size() >=1)
    {
        ui->rc1->setText(QString::fromStdString(recent[recent.size()-1].first));
        ui->rc2->setText(QString::fromStdString(recent[recent.size()-1].second));
    }
    if(recent.size() >=2)
    {
        ui->rc3->setText(QString::fromStdString(recent[recent.size()-2].first));
        ui->rc4->setText(QString::fromStdString(recent[recent.size()-2].second));
    }
    if(recent.size() >=3)
    {
        ui->rc5->setText(QString::fromStdString(recent[recent.size()-3].first));
        ui->rc6->setText(QString::fromStdString(recent[recent.size()-3].second));
    }
}


void User::on_pushButton_clicked()
{
    QSqlQuery query;
    query.exec(("select * from userpass where customerid = '" + this->customerid + "';").c_str());
    QString pass;
    if(query.next())
    {
        pass = query.value(1).toString();
    }
    QString given_pass = ui->currentpasswordbutton->text();

    if(given_pass != pass)
    {
        QMessageBox msgBox;
        msgBox.setText("Wrong password");
        msgBox.exec();
        close();
        return;
    }

    //updating password
    if(ui->newpasswordbutton->text() != NULL)
    {
        string new_pass = ui->newpasswordbutton->text().toStdString();
        query.exec(("DELETE FROM userpass WHERE customerid = '" + this->customerid + "';").c_str());
        query.exec(("INSERT INTO userpass VALUES ('" + this->customerid + "','" + new_pass + "');").c_str());
    }

    //updating phone number
    string new_phno =ui->phonenumberbutton->text().toStdString();
    query.exec(("UPDATE userdetails SET phone = '" + new_phno + "' WHERE customerid = '" + this->customerid + "';").c_str());

    //updating email
    string new_mail =ui->emailbutton->text().toStdString();
    query.exec(("UPDATE userdetails SET mail = '" + new_mail + "' WHERE customerid = '" + this->customerid + "';").c_str());

    //updating voter id
    string new_vid =ui->voteridbutton->text().toStdString();
    query.exec(("UPDATE userdetails SET voter = '" + new_vid + "' WHERE customerid = '" + this->customerid + "';").c_str());

    //updating name on account
    string new_name =ui->namebutton->text().toStdString();
    query.exec(("UPDATE userdetails SET name = '" + new_name + "' WHERE customerid = '" + this->customerid + "';").c_str());

    //add money
    if(ui->addmoneybutton->text() != NULL)
    {
        string current_balance;
        query.exec(("select * from userbalance where customerid = '" + this->customerid + "';").c_str());
        if(query.next())
        {
            current_balance = query.value(1).toString().toStdString();
        }
        string addmoney = ui->addmoneybutton->text().toStdString();
        query.exec(("INSERT INTO transactions VALUES ('" + this->customerid + "','self','" + addmoney + "');").c_str());
        query.exec(("UPDATE userbalance SET balance = '" + to_string(stoi(current_balance) + stoi(addmoney)) + "' WHERE customerid = '" + this->customerid + "';").c_str());
    }

    //withdraw
    if(ui->withdrawbutton->text() != NULL)
    {
        string current_balance;
        query.exec(("select * from userbalance where customerid = '" + this->customerid + "';").c_str());
        if(query.next())
        {
            current_balance = query.value(1).toString().toStdString();
        }
        string wmoney = ui->withdrawbutton->text().toStdString();
        if(stoi(current_balance) < stoi(wmoney))
        {
            QMessageBox msgBox;
            msgBox.setText("Insufficient balance");
            msgBox.exec();
            close();
            return;
        }
        else
        {
            wmoney = "-" + wmoney;
            query.exec(("INSERT INTO transactions VALUES ('" + this->customerid + "','self','" + wmoney + "');").c_str());
            query.exec(("UPDATE userbalance SET balance = '" + to_string(stoi(current_balance) + stoi(wmoney)) + "' WHERE customerid = '" + this->customerid + "';").c_str());
        }
    }

    //processing other account transactions
    if(ui->otheraccountbutton->text() != NULL)
    {
        string current_balance;
        query.exec(("select * from userbalance where customerid = '" + this->customerid + "';").c_str());
        if(query.next())
        {
            current_balance = query.value(1).toString().toStdString();
        }
        string other_customerid =ui->otheraccountbutton->text().toStdString();
        string tmoney = ui->transferamountbutton->text().toStdString();
        query.exec(("select * from userbalance where customerid = '" + other_customerid + "';").c_str());
        if(!query.next())
        {
            QMessageBox msgBox;
            msgBox.setText("Invalid account number");
            msgBox.exec();
            close();
            return;
        }
        else if(stoi(current_balance) < stoi(tmoney))
        {
            QMessageBox msgBox;
            msgBox.setText("Insufficient balance");
            msgBox.exec();
            close();
            return;
        }
        else
        {
            string wmoney = "-" + tmoney;
            query.exec(("INSERT INTO transactions VALUES ('" + this->customerid + "','" + other_customerid + "','" + wmoney + "');").c_str());
            query.exec(("INSERT INTO transactions VALUES ('" + other_customerid + "','" + this->customerid + "','" + tmoney + "');").c_str());
            query.exec(("UPDATE userbalance SET balance = '" + to_string(stoi(current_balance) + stoi(wmoney)) + "' WHERE customerid = '" + this->customerid + "';").c_str());
            string other_current_balance;
            query.exec(("select * from userbalance where customerid = '" + other_customerid + "';").c_str());
            if(query.next())
            {
                other_current_balance = query.value(1).toString().toStdString();
            }
            query.exec(("UPDATE userbalance SET balance = '" + to_string(stoi(other_current_balance) + stoi(tmoney)) + "' WHERE customerid = '" + other_customerid + "';").c_str());
        }
    }
    displayuser(this->customerid);
}
//function to delete a account
void User::on_Delete_clicked()
{
    QSqlQuery query;
    query.exec(("select * from userpass where customerid = '" + this->customerid + "';").c_str());
    QString pass;
    if(query.next())
    {
        pass = query.value(1).toString();
    }
    QString given_pass = ui->currentpasswordbutton->text();
    if (given_pass != pass)
    {
        QMessageBox msgBox;
        msgBox.setText("Wrong password");
        msgBox.exec();
        return;
    }

    query.exec(("DELETE FROM userdetails WHERE customerid = '" + this->customerid + "';").c_str());
    query.exec(("DELETE FROM userpass WHERE customerid = '" + this->customerid + "';").c_str());
    query.exec(("DELETE FROM userbalance WHERE customerid = '" + this->customerid + "';").c_str());

    QMessageBox msgBox;
    msgBox.setText("a/c deleted successfully");
    msgBox.exec();
    return;
}
