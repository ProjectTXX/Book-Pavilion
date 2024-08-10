#ifndef BOOKINTRO_H
#define BOOKINTRO_H

#include <QWidget>

namespace Ui {
class Bookintro;
}

class Bookintro : public QWidget
{
    Q_OBJECT

public:
    explicit Bookintro(QWidget *parent = nullptr);
    ~Bookintro();
    Ui::Bookintro* geiUi();

private:
    Ui::Bookintro *ui;
};

#endif // BOOKINTRO_H
