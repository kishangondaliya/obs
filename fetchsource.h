#ifndef FETCH_SOURCE_H
#define FETCH_SOURCE_H

#include <QMainWindow>
#include "feeds.h"

namespace Ui {
class FetchSource;
}

class FetchSource : public QMainWindow
{
    Q_OBJECT

public:
    explicit FetchSource(QWidget *parent = 0);
    ~FetchSource();

private slots:
    void on_start_button_clicked();

    void on_next_button_clicked();

private:
    Ui::FetchSource *ui;
    Feeds *feeds;
};

#endif // FETCH_SOURCE_H
