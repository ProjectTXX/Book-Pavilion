#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"preview.h"
#include"bookwidget.h"
#include <QMainWindow>
#include"view.h"
#include<bookshelfcover.h>
#include<ui_bookshelfcover.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    View* view;
    Preview * preview;
};

#endif // MAINWINDOW_H
