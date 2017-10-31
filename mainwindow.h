#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAxObject>
#include <QDesktopWidget>

#include "form.h"
#include "typedefine.h"
#include "expmodel.h"
#include "teldelegate.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringList readCodeList(QString codeListPath);  //读取订单号
    Form *form;
    ExpModel *express;
    ExpressMap expMap;
    QProgressDialog *progress;  //进度条
signals:

private slots:
    void onActionOpenCode_triggered();
    void openForm(QTreeWidgetItem *item, int column);
};

#endif // MAINWINDOW_H
