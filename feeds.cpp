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
    ui->install_Feeds_Button->setDisabled(true);
    ui->next_b->setDisabled(true);
    ui->label->hide();
    ui->label_2->hide();
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

    ui->label->show();

    ui->update_Feeds_Button->setDisabled(true);

    while (getSourceUp.pid()) {
        ui->label->setText("Updating.");
        MainWindow().delay(1000);
        ui->label->setText("Updating..");
        MainWindow().delay(1000);
        ui->label->setText("Updating...");
        MainWindow().delay(1000);
    }

    /* TODO : Add handling on update failure */
    if (getSourceUp.exitCode())
        ui->label->setText("Error : " + getSourceUp.readAllStandardError());
    else {
        ui->label->setText("Updated!!");
        ui->install_Feeds_Button->setEnabled(true);
    }
}

void Feeds::on_install_Feeds_Button_clicked()
{
    QProcess getSourceUp;
    QStringList argsUp;

    argsUp<<"install";

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

    ui->label_2->show();

    ui->install_Feeds_Button->setDisabled(true);

    while (getSourceUp.pid()) {
        ui->label_2->setText("Installing.");
        MainWindow().delay(1000);
        ui->label_2->setText("Installing..");
        MainWindow().delay(1000);
        ui->label_2->setText("Installing...");
        MainWindow().delay(1000);
    }

    /* TODO : Add handling on install failure */
    if (getSourceUp.exitCode())
        ui->label_2->setText("Error : " + getSourceUp.readAllStandardError());
    else {
        ui->label_2->setText("Installed!!");
        ui->next_b->setEnabled(true);
    }
}

void Feeds::on_next_b_clicked()
{
    /* Go to next window */
}
