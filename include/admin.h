#ifndef ADMIN_H
#define ADMIN_H
#include <bits/stdc++.h>
#include <QDialog>
using namespace std;

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
bool execAdmin();
private slots:
    void on_balancebutton_clicked();

    void on_aadhaarbutton_clicked();

    void on_namebutton_clicked();

    void on_closebutton_clicked();

private:
    Ui::Admin *ui;
public:    bool repeat;
};

#endif // ADMIN_H
