#ifndef SIGNUP_H
#define SIGNUP_H
#include <bits/stdc++.h>
#include <QDialog>
using namespace std;

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButton_5_clicked();
private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
