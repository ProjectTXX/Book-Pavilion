#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QDebug>
#include<unistd.h>
#include<QTimer>

void mysqlConnect(QSqlDatabase db)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("bookself");
    db.setUserName("xyx");
    db.setPassword("xyx");
    if (!db.open()) {
        qDebug("Sql connect failed.");
        qDebug() << db.lastError().text();
    } else {
        qDebug("Sql connected.");
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db;
    mysqlConnect(db);
    db.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    book = new DialogBookself(this);
    book->show();
}
