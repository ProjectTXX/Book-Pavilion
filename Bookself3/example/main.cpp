#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qDebug() << "Available drivers:";
        QStringList drivers = QSqlDatabase::drivers();  //获取现在可用的数据库驱动
        foreach(QString driver, drivers)
            qDebug() << driver;

    w.show();

    return a.exec();
}
