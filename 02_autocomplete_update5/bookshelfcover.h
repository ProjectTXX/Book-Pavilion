#ifndef BOOKSHELFCOVER_H
#define BOOKSHELFCOVER_H

#include <QWidget>

namespace Ui {
class BookshelfCover;
}

class BookshelfCover : public QWidget
{
    Q_OBJECT

public:
    explicit BookshelfCover(QWidget *parent = nullptr);
    ~BookshelfCover();
    Ui::BookshelfCover *getui();

private:
    Ui::BookshelfCover *ui;
};

#endif // BOOKSHELFCOVER_H
