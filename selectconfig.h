#ifndef SELECTCONFIG_H
#define SELECTCONFIG_H

#include <QMainWindow>
#include "build.h"

namespace Ui {
class SelectConfig;
}

class SelectConfig : public QMainWindow
{
    Q_OBJECT

public:
    explicit SelectConfig(QWidget *parent = 0);
    ~SelectConfig();

private slots:

    void on_next_b_clicked();
    void doDefConfig();

private:
    Build *build;
    Ui::SelectConfig *ui;
};

#endif // SELECTCONFIG_H
