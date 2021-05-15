#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>
#include <QDialog>
using namespace std;

namespace Ui {
class User;
}

class User : public QDialog
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();
private: string customerid;
public:
    Ui::User *ui;
public: void displayuser(string);
private slots:
    void on_pushButton_clicked();
    void on_Delete_clicked();
};

#endif // USER_H
