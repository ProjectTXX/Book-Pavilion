#ifndef PREVIEW2_H
#define PREVIEW2_H

#include <QWidget>

namespace Ui {
class Preview2;
}

class Preview2 : public QWidget
{
    Q_OBJECT

public:
    explicit Preview2(QWidget *parent = nullptr);
    ~Preview2();
    Ui::Preview2* getui();
private:
    Ui::Preview2 *ui;
};

#endif // PREVIEW2_H
