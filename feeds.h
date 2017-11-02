#ifndef FEEDS_H
#define FEEDS_H

#include <QMainWindow>

namespace Ui {
class Feeds;
}

class Feeds : public QMainWindow
{
    Q_OBJECT

public:
    explicit Feeds(QWidget *parent = 0);
    ~Feeds();

private:
    Ui::Feeds *ui;
};

#endif // FEEDS_H
