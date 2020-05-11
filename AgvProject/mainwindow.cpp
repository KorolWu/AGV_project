#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <c_systemlogmng.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GetSystemLogObj()->writeLog("log for test",1);
    testUtil();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testUtil()
{
    tText = new TcpUtil();
    tText->CreatTcpServer();
}
