#include "feeds.h"
#include "ui_feeds.h"

Feeds::Feeds(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Feeds)
{
    ui->setupUi(this);
    ui->install_Feeds_Button->hide();
}

Feeds::~Feeds()
{
    delete ui;
}

void Feeds::on_packages_cb_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->custom_feeds_radio->setChecked(true);
}

void Feeds::on_luci_cb_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->custom_feeds_radio->setChecked(true);
}

void Feeds::on_routing_cb_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->custom_feeds_radio->setChecked(true);
}

void Feeds::on_telephony_cb_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->custom_feeds_radio->setChecked(true);
}

void Feeds::on_management_cb_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->custom_feeds_radio->setChecked(true);
}

void Feeds::on_targets_cb_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->custom_feeds_radio->setChecked(true);
}

void Feeds::on_all_feeds_radio_toggled(bool checked)
{
    if (checked == true) {
        ui->packages_cb->setChecked(true);
        ui->luci_cb->setChecked(true);
        ui->management_cb->setChecked(true);
        ui->routing_cb->setChecked(true);
        ui->targets_cb->setChecked(true);
        ui->telephony_cb->setChecked(true);
    }
}
