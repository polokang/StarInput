#include "idb.h"

IDB::IDB(QObject *parent) : QObject(parent)
{

}

bool IDB::connect(const QString &dbName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if (!db.open()) {
        qDebug() << "Database Error!";
        return false;
    }else{
        qDebug() << "Database Success!";
//        creaTable("user");
    }
    return true;
}


QStringList IDB::getPhoneListBySender(QString sender)
{
    QStringList list;
    QSqlQuery query(QString("SELECT rectel FROM user where receiver = '%1'").arg(sender));
    while (query.next()) {
        QString country = query.value(0).toString();
        qDebug()<<country;
        list<<country;
    }
    return list;
}


bool IDB::creaTable(QString tabName)
{
    QSqlQuery query;
    if (!query.exec("CREATE TABLE '"+tabName+"' ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "serid int,"
        "receiver VARCHAR,"
        "rectel VARCHAR,"
        "sendtime VARCHAR,"
        "product VARCHAR,"
        "sender VARCHAR,"
        "addr VARCHAR,"
        "exid VARCHAR)")) {
        qDebug() << "Create Table Failed!";
        return false;
    }else{
        qDebug() << "Database Success!";
    }
    return true;
}

/*
bool IDB::addUser(User user)
{
    QSqlQuery query;

    query.prepare("INSERT INTO user (serid, receiver, rectel, sendtime, product, sender, addr, exid) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

    query.bindValue(0, user.getSerid());
    query.bindValue(1, user.getReceiver());
    query.bindValue(2, user.getRectel());
    query.bindValue(3, user.getSendtime());
    query.bindValue(4, user.getProduct());
    query.bindValue(5, user.getSender());
    query.bindValue(6, user.getAddr());
    query.bindValue(7, user.getExid());

    if (!query.exec() ){
        qDebug() << "addUser Failed!";
        return false;
    }else{
//        qDebug() << "addUser Success!";
    }
    return true;

//    select * from user a where exists (select receiver from user where receiver=a.receiver group by receiver having count(*)>1)
}*/
