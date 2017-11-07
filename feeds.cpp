#include "feeds.h"
#include "ui_feeds.h"
#include "qdebug.h"
#include "qprocess.h"
#include "qiodevice.h"
#include "qfiledialog.h"
#include "mainwindow.h"

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

void Feeds::on_update_Feeds_Button_clicked()
{
    QProcess getSourceUp;
    QStringList argsUp;

    argsUp<<"update";

    if (ui->all_feeds_radio->isChecked())
        argsUp<<"-a";
    else {
        if (ui->packages_cb->isChecked()) argsUp<<"packages";
        if (ui->luci_cb->isChecked()) argsUp<<"luci";
        if (ui->management_cb->isChecked()) argsUp<<"management";
        if (ui->routing_cb->isChecked()) argsUp<<"routing";
        if (ui->targets_cb->isChecked()) argsUp<<"targets";
        if (ui->telephony_cb->isChecked()) argsUp<<"telephony";
    }

    getSourceUp.start("./scripts/feeds", argsUp, QIODevice::ReadWrite);

    while (getSourceUp.pid())
        MainWindow().delay(3000);

    if (getSourceUp.exitCode())
        qDebug() << "Error : " << getSourceUp.readAllStandardError();
    else
        qDebug() << "Successfully ";

}
