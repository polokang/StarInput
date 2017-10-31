#include "expmodel.h"

ExpModel::ExpModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

void ExpModel::setExpressMap(QMap<QString, Express *> &map)
{
    beginResetModel();
    expressMap = map;
    endResetModel();
}

QVariant ExpModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if(role==Qt::DisplayRole && orientation==Qt::Horizontal){
        return header[section];
    }
    return QAbstractTableModel::headerData(section,orientation,role);
}

bool ExpModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        header<<value.toString();
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int ExpModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return expressMap.count();
    // FIXME: Implement me!
}

int ExpModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return header.size();
    // FIXME: Implement me!
}

QVariant ExpModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignCenter | Qt::AlignVCenter);
    } else if (role == Qt::DisplayRole) {
        switch(index.column())
        {
        case COLUMN_EXPNO:
            return (expressMap.begin() + index.row()).key();
            break;
        case COLUMN_RECVNAME:
            return (expressMap.begin() + index.row()).value()->recvname();
            break;
        case COLUMN_RECVTEL:
            return (expressMap.begin() + index.row()).value()->recvtel();
            break;
        case COLUMN_SENDTIME:
            return (expressMap.begin() + index.row()).value()->sendtime();
            break;
        case COLUMN_RECVPROVINCE:
            return (expressMap.begin() + index.row()).value()->rvprovince();
            break;
        case COLUMN_RECVCITY:
            return (expressMap.begin() + index.row()).value()->rvcity();
            break;
        default:
            return QVariant();
        }
    } else if(role == Qt::UserRole){
        switch(index.column())
        {
        case COLUMN_EXPNO:
            return (expressMap.begin() + index.row()).key();
            break;
        case COLUMN_RECVNAME:
            return (expressMap.begin() + index.row()-1).value()->recvname();
            break;
        case COLUMN_RECVTEL:
            return (expressMap.begin() + index.row()).value()->recvname();
            break;
        case COLUMN_SENDTIME:
            return (expressMap.begin() + index.row()).value()->sendtime();
            break;
        case COLUMN_RECVPROVINCE:
            return (expressMap.begin() + index.row()-1).value()->rvprovince();
            break;
        case COLUMN_RECVCITY:
            return (expressMap.begin() + index.row()-1).value()->rvcity();
            break;
        default:
            return QVariant();
        }

    }

    return QVariant();
}

bool ExpModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        QString expNo = this->data(this->index(index.row(),0),Qt::DisplayRole).toString();
        switch(index.column())
        {
        case COLUMN_RECVNAME:
            expressMap.value(expNo)->setRecvName(value.toString());
            break;
        case COLUMN_RECVTEL:
            expressMap.value(expNo)->setRecvTel(value.toString());
            expressMap.value(expNo)->setSendTime(value.toString());
            break;
        case COLUMN_SENDTIME:
            expressMap.value(expNo)->setSendTime(value.toString());
            break;
        case COLUMN_RECVPROVINCE:
            expressMap.value(expNo)->setRvProvince(value.toString());
            break;
        case COLUMN_RECVCITY:
            expressMap.value(expNo)->setRvCity(value.toString());
            break;
        default:
            break;
        }

        emit dataChanged(index, index, QVector<int>() << role);

        return true;
    }
    return false;
}


Qt::ItemFlags ExpModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    // FIXME: Implement me!
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if (index.column() != COLUMN_EXPNO) {
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

bool ExpModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
}

bool ExpModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
}

bool ExpModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}

bool ExpModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
}
