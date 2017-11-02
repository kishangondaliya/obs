#ifndef FETCH_SOURCE_H
#define FETCH_SOURCE_H

#include <QMainWindow>

namespace Ui {
class Fetch_source;
}

class Fetch_source : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fetch_source(QWidget *parent = 0);
    ~Fetch_source();

private:
    Ui::Fetch_source *ui;
};

#endif // FETCH_SOURCE_H
