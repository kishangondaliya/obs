#ifndef BUILD_H
#define BUILD_H

#include <QMainWindow>

namespace Ui {
class Build;
}

class Build : public QMainWindow
{
    Q_OBJECT

public:
    explicit Build(QWidget *parent = 0);
    ~Build();

private:
    Ui::Build *ui;
};

#endif // BUILD_H
