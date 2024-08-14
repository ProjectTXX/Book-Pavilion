#ifndef PREVIEW_H
#define PREVIEW_H

#include <QWidget>

namespace Ui {
class Preview;
}

class Preview : public QWidget
{
    Q_OBJECT

public:
    explicit Preview(QWidget *parent = nullptr);
    ~Preview();
Ui::Preview* getui();
private:
    Ui::Preview *ui;
};

#endif // PREVIEW_H
