#ifndef IDB_H
#define IDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

class IDB : public QObject
{
    Q_OBJECT

public:
    explicit IDB(QObject *parent = 0);
    bool connect(const QString &dbName);
    bool creaTable(QString tabName);
//    bool addUser(User user);
    QStringList getPhoneListBySender(QString sender);
signals:

public slots:
};

#endif // IDB_H
