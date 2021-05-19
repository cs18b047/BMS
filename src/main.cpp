#include "bank.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <bits/stdc++.h>
#include "sql.h"
using namespace std;

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("us.dreamcometrue.studio");
    db.setUserName("vissu");
    db.setPassword("xxxxxx");
    db.setDatabaseName("bank");
    db.open();
    QApplication a(argc, argv);
    Bank w;    
    w.show();
    a.exec();
    return 0;
}
