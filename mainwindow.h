#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void start_git_clone();
    void on_select_clicked();

    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
