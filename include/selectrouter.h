#ifndef SELECTROUTER_H
#define SELECTROUTER_H

#include <QMainWindow>
#include "selectconfig.h"

namespace Ui {
class SelectRouter;
}

class SelectRouter : public QMainWindow
{
    Q_OBJECT

public:
    explicit SelectRouter(QWidget *parent = 0);
    ~SelectRouter();

private slots:

    void on_pushButton_clicked();

private:
    SelectConfig *selectconfig;
    Ui::SelectRouter *ui;
};


#endif // SELECTROUTER_H
