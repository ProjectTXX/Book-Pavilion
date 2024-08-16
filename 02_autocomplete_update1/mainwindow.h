#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"preview.h"
#include"preview2.h"
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
    Preview2* preview2;
};

#endif // MAINWINDOW_H
