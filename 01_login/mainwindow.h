#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"form.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:

signals:

private:
    Ui::MainWindow *ui;
    Form *form;
};

#endif // MAINWINDOW_H
