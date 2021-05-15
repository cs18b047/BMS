#include "bank.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bank w;    
    w.show();
    return a.exec();
}
