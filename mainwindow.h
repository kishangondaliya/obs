#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fetchsource.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void delay(int millisecondsToWait);
    ~MainWindow();

private slots:

    void on_b_button_clicked();

    void on_toolButton_clicked();

private:
    FetchSource *fetchSource;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
