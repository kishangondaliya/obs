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

private slots:

    void on_packages_cb_stateChanged(int arg1);
    void on_luci_cb_stateChanged(int arg1);
    void on_routing_cb_stateChanged(int arg1);
    void on_telephony_cb_stateChanged(int arg1);
    void on_management_cb_stateChanged(int arg1);
    void on_targets_cb_stateChanged(int arg1);
    void on_all_feeds_radio_toggled(bool checked);
    void on_update_Feeds_Button_clicked();
    void on_install_Feeds_Button_clicked();

    void on_next_b_clicked();

private:
    Ui::Feeds *ui;
};

#endif // FEEDS_H
