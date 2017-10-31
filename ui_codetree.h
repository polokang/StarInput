/********************************************************************************
** Form generated from reading UI file 'codetree.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODETREE_H
#define UI_CODETREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodeTree
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *CodeTree)
    {
        if (CodeTree->objectName().isEmpty())
            CodeTree->setObjectName(QStringLiteral("CodeTree"));
        CodeTree->resize(265, 375);
        gridLayout = new QGridLayout(CodeTree);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeWidget = new QTreeWidget(CodeTree);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);


        retranslateUi(CodeTree);

        QMetaObject::connectSlotsByName(CodeTree);
    } // setupUi

    void retranslateUi(QWidget *CodeTree)
    {
        CodeTree->setWindowTitle(QApplication::translate("CodeTree", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CodeTree: public Ui_CodeTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODETREE_H
