#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

namespace Ui {
class View;
}

class View : public QWidget
{
    Q_OBJECT
signals:
    void passpar(int );
public:
    explicit View(QWidget *parent = nullptr);
    ~View();
    Ui::View* getui();
    int setId(int);
    int getId();
protected:
    void closeEvent(QCloseEvent *event) override;
private:
    Ui::View *ui;
    int id;
};

#endif // VIEW_H
