#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fetch_source.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

   // void start_git_clone();
    void on_b_button_clicked();

    void on_toolButton_clicked();

private:
    Fetch_source *fetch_source;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
