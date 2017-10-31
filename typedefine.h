#ifndef TYPEDEFINE
#define TYPEDEFINE

#define EXPNOCOL  1  //快递单号所在列（列从1开始）

#define COLUMN_EXPNO          0
#define COLUMN_RECVNAME       1
#define COLUMN_RECVTEL        2
#define COLUMN_SENDTIME       3
#define COLUMN_RECVCITY       4
#define COLUMN_RECVPROVINCE   5
#define COLUMN_RECVADDR       6
#define COLUMN_RECVPOSTAL     7
#define COLUMN_WEIGHT         8
#define COLUMN_SENDNAME       9
#define COLUMN_SENDTEL        10
#define COLUMN_GOODS          11
#define COLUMN_COMMENT        12

#endif // TYPEDEFINE
#include <QDebug>
#include <QtWidgets>
#include "express.h"

typedef QMap<QString, Express*> ExpressMap; //自定义一个map类型，值为EmployeeMap对象


