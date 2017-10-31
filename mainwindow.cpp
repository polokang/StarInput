#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->splitter->setStretchFactor(0,9);
    ui->splitter->setStretchFactor(1,1);

    QDesktopWidget *desktop = QApplication::desktop();
    QRect screen = desktop->screenGeometry();
    int screenWidth = screen.width()-100;
    int screenHeight = screen.height()-100;

    this->resize(screenWidth,screenHeight);

    form = new Form();

    setWindowState(Qt::WindowMaximized);

    //设置进度条
    progress = new QProgressDialog(this);
    progress->setWindowTitle("文件加载");
    progress->setLabelText(tr("正在加载文件..."));
    progress->setCancelButtonText(tr("取消"));
    progress->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    progress->setWindowModality(Qt::WindowModal);
    progress->resize(600,400);


    express = new ExpModel(ui->inputTable);
    express->setHeaderData(COLUMN_EXPNO,Qt::Horizontal, QObject::tr("快递单号"));
    express->setHeaderData(COLUMN_RECVNAME,Qt::Horizontal, QObject::tr("收件人姓名"));
    express->setHeaderData(COLUMN_RECVTEL,Qt::Horizontal, QObject::tr("收件人电话"));
    express->setHeaderData(COLUMN_SENDTIME,Qt::Horizontal, QObject::tr("寄件日期"));
    express->setHeaderData(COLUMN_RECVCITY,Qt::Horizontal, QObject::tr("收件人城市"));
    express->setHeaderData(COLUMN_RECVPROVINCE,Qt::Horizontal, QObject::tr("收件人省份"));
    express->setHeaderData(COLUMN_RECVADDR,Qt::Horizontal, QObject::tr("收件人地址"));
    express->setHeaderData(COLUMN_RECVPOSTAL,Qt::Horizontal, QObject::tr("收件人邮编"));
    express->setHeaderData(COLUMN_WEIGHT,Qt::Horizontal, QObject::tr("重量"));
    express->setHeaderData(COLUMN_SENDNAME,Qt::Horizontal, QObject::tr("寄件人姓名"));
    express->setHeaderData(COLUMN_SENDTEL,Qt::Horizontal, QObject::tr("寄件人电话"));
    express->setHeaderData(COLUMN_GOODS,Qt::Horizontal, QObject::tr("物品描述"));
    express->setHeaderData(COLUMN_COMMENT,Qt::Horizontal, QObject::tr("备注"));

    ui->inputTable->setModel(express);

    TelDelegate *telDelegate = new TelDelegate;
    ui->inputTable->setItemDelegateForColumn(COLUMN_RECVTEL, telDelegate);


    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(onActionOpenCode_triggered()));


}


void MainWindow::onActionOpenCode_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), /*QString("./%1").arg(fileName)*/ "", tr("XML (*.xls *.xlsx)"));
    if(path.length() == 0)
    {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."),tr("Ok"));
    }
    else
    {
        QStringList expNoList = readCodeList(path);
        int listSize = expNoList.size();
        progress->setRange(0,listSize);

        QMap<QString, Express*>  data;

        for(int i=0;i<listSize;i++){
            QString expNo = expNoList.at(i);

//            T_IEXPRESS e;
//            e.expNo = expNo;
            Express *exp = new Express();
            exp->setExpNo(expNo);
            data[expNo] = exp;

            progress->setValue(i+1);
        }

        express->setExpressMap(data);

    }
}


void MainWindow::openForm(QTreeWidgetItem *item, int column)
{
    qDebug()<<item->text(0);

    form->show();
}

QStringList MainWindow::readCodeList(QString codeListPath)
{
    QStringList expNoList;
    QAxObject excel("Excel.Application"); //加载Excel驱动
    excel.setProperty("Visible", false); //不显示Excel界面，如果为true会看到启动的Excel界面
    QAxObject *pWorkBooks = excel.querySubObject("WorkBooks");
    pWorkBooks->dynamicCall("Open (const QString&)", codeListPath);//打开指定文
    QAxObject *pWorkBook = excel.querySubObject("ActiveWorkBook");
    QAxObject *pWorkSheets = pWorkBook->querySubObject("Sheets");
    int nSheetCount = pWorkSheets->property("Count").toInt();  //获取工作表的数目

    if(nSheetCount > 0)
    {
        QAxObject *pWorkSheet = pWorkBook->querySubObject("Sheets(int)", 1);//获取第一张表
        QAxObject *usedRange = pWorkSheet->querySubObject("UsedRange");
        QAxObject *rows = usedRange->querySubObject("Rows");
        int rowCount = rows->property("Count").toInt();

        progress->setRange(0,rowCount);

        QRegExp wordRX("[A-Za-z]");
        QRegExp numRX("[0-9]");

        for (int i = 1; i <= rowCount; i++)
        {
            QVariant seridVal = pWorkSheet->querySubObject("Cells(int,int)", i, EXPNOCOL)->dynamicCall("Value()");
            QString expNo = seridVal.toString();

            if(numRX.indexIn(expNo) > 0 && wordRX.indexIn(expNo) == 0){  //字母开头，且有数字
                expNoList<<expNo;
            } else if(numRX.indexIn(expNo) == 0 && expNo.length() > 8){
                expNoList<<expNo;
            }
            progress->setValue(i);
        }

        pWorkBooks->dynamicCall("Close()");

    }

    return expNoList;

}

MainWindow::~MainWindow()
{
    delete ui;
}
