#include "teldelegate.h"
#include <QComboBox>
#include <QLineEdit>
#include <QDebug>

TelDelegate::TelDelegate(QObject *parent) : QItemDelegate(parent)
{
    qDebug()<<"TelDelegate";
    db = new IDB;
}

QWidget *TelDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    db->connect("startex.db");

    QString rvName = index.model()->data(index,Qt::UserRole).toString();
    QStringList list = db->getPhoneListBySender(rvName);
    if(list.size() < 1){
        QLineEdit *lineEdits = new QLineEdit(parent);
        lineEdits->setText("");
        return lineEdits;
    }else{
        QComboBox *editor = new QComboBox(parent);
        editor->addItems(list);
        editor->installEventFilter(const_cast<TelDelegate*>(this));
        return editor;
    }

}

//这个是初始化作用，初始化代理控件的数据
void TelDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(editor->inherits("QComboBox"))
    {
        QString str = index.model()->data(index).toString();
        QComboBox *box = static_cast<QComboBox*>(editor);
        int i=box->findText(str);
        box->setCurrentIndex(i);
    }else{
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
        lineEdit->setText(lineEdit->displayText());
    }

}

//将代理控件里面的数据更新到视图控件中
void TelDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(editor->inherits("QComboBox"))
    {
        QComboBox *box = static_cast<QComboBox*>(editor);
        QString str = box->currentText();
        model->setData(index,str);
    }else{
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
        model->setData(index, lineEdit->displayText());
    }
}

//代理中数据的改变放到model中
void TelDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    qDebug()<<"updateEditorGeometry";
    editor->setGeometry(option.rect);
}
