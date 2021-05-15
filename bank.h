#ifndef BANK_H
#define BANK_H
#include <bits/stdc++.h>
#include <QMainWindow>
#include "signup.h"
#include "admin.h"
#include "user.h"
#include "forgot.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Bank; }
QT_END_NAMESPACE

class Bank : public QMainWindow
{
    Q_OBJECT

public:
    Bank(QWidget *parent = nullptr);
    ~Bank();

private slots:
    void on_Loginbutton_clicked();

    void on_signupbutton_clicked();

    void on_forgotbutton_clicked();

    void on_Adminloginbutton_clicked();
bool OpenAdminInterface();
private:
    Ui::Bank *ui;
    signup* signupobj;
    Admin* adminobj;
    User* userobj;
    Forgot* forgotobj;
};
#endif // BANK_H
