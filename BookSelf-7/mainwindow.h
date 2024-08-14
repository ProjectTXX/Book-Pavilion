#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"preview.h"
#include"bookwidget.h"
#include<bookintro.h>
#include <QMainWindow>
#include"view.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    View* view;
    Preview * preview;
    Bookintro *bookintro;
    //BookWidget* bookwidget;
};

#endif // MAINWINDOW_H
