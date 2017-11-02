#ifndef FETCH_SOURCE_H
#define FETCH_SOURCE_H

#include <QMainWindow>
#include "feeds.h"

namespace Ui {
class Fetch_source;
}

class Fetch_source : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fetch_source(QWidget *parent = 0);
    ~Fetch_source();

private slots:
    void on_start_button_clicked();

    void on_next_button_clicked();

private:
    Ui::Fetch_source *ui;
    Feeds *feeds;
};

#endif // FETCH_SOURCE_H
