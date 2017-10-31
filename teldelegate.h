#ifndef TELDELEGATE_H
#define TELDELEGATE_H

#include <QItemDelegate>
#include <QComboBox>
#include "idb.h"

class TelDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit TelDelegate(QObject *parent = 0);
    IDB *db;
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option, const QModelIndex &index) const;
//private slots:
//    void commitAndCloseEditor();
};

#endif // TELDELEGATE_H
