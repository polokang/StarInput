#ifndef EXPMODEL_H
#define EXPMODEL_H

#include <QAbstractTableModel>
#include "typedefine.h"

//快递单结构
typedef struct iexp
{
    QString expNo;          //快递单号
    QString recvName;       //收件人姓名
    QString recvTel;        //收件人电话
    QString sendTime;       //寄件日期
    QString recvProvince;   //收件人省份
    QString recvCity;       //收件人城市
    QString recvAddr;       //收件人地址
    QString recvPostal;     //收件人城市邮编
    QString weight;         //包裹重量
    QString sendName;       //寄件人姓名
    QString sendTel;        //寄件人电话
    QString goods;          //物品描述
    QString comment;        //备注
}T_IEXPRESS;


class ExpModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ExpModel(QObject *parent = 0);

    void setExpressMap(QMap<QString, Express*> &map);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    QStringList  header;
//    QMap<QString, T_IEXPRESS> expressMap;
    ExpressMap expressMap;

};

#endif // EXPMODEL_H
