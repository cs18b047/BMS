#ifndef FORGOT_H
#define FORGOT_H
#include <bits/stdc++.h>
#include <QDialog>
using namespace std;
namespace Ui {
class Forgot;
}

class Forgot : public QDialog
{
    Q_OBJECT

public:
    explicit Forgot(QWidget *parent = nullptr);
    ~Forgot();
public: void displayuser(string);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Forgot *ui;
    string customerid;
};

#endif // FORGOT_H
