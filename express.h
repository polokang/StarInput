#ifndef EXPRESS_H
#define EXPRESS_H

#include <qstring.h>
#include <qmap.h>
#include <qstring.h>


class Express
{
public:
    Express(): expNo("") {}
    Express(QString expNo): expNo(expNo){ }

    QString expno() const { return expNo; }
    QString recvname() { return recvName; }
    QString recvtel() { return recvTel; }
    QString sendtime() { return sendTime; }
    QString rvprovince() { return rvProvince; }
    QString rvcity() { return rvCity; }
    QString rvaddr() { return rvAddr; }
    QString rvpostal() { return rvPostal; }
    QString getWeight() { return weight; }
    QString sendname() { return sendName; }
    QString sendtel() { return sendTel; }
    QString getGoods() { return goods; }
    QString getComment() { return comment; }

    void setExpNo( QString num ) { expNo = num; }
    void setRecvName(QString rvName) { recvName = rvName; }
    void setRecvTel(QString rvTel) { recvTel = rvTel; }
    void setSendTime(QString time) { sendTime = time; }
    void setRvProvince(QString prov) { rvProvince = prov; }
    void setRvCity(QString city) { rvCity = city; }
    void setRvAddr(QString addr) { rvAddr = addr; }
    void setRvPostal(QString postal) { rvPostal = postal; }
    void setWeight(QString wt) { this->weight = wt; }
    void setSendName(QString sName) { sendName = sName; }
    void setSendTel(QString sTel) { sendTel = sTel; }
    void setGoods(QString good) { this->goods = good; }
    void setComment(QString cmt) { this->comment = cmt; }

private:
    QString expNo;          //快递单号
    QString recvName;       //收件人姓名
    QString recvTel;        //收件人电话
    QString sendTime;       //寄件日期
    QString rvProvince;   //收件人省份
    QString rvCity;       //收件人城市
    QString rvAddr;       //收件人地址
    QString rvPostal;     //收件人城市邮编
    QString weight;         //包裹重量
    QString sendName;       //寄件人姓名
    QString sendTel;        //寄件人电话
    QString goods;          //物品描述
    QString comment;        //备注

};

#endif // EXPRESS_H
