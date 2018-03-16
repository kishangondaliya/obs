#include "include/selectrouter.h"
#include "ui_selectrouter.h"
#include "qdebug.h"
#include "include/selectconfig.h"

SelectRouter::SelectRouter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectRouter)
{
    ui->setupUi(this);

    // TODO: Fetch list of target system from make menuconfig
    ui->comboBox_target_sys->addItem("Atheros AR7xxx/AR9xxx");
    ui->comboBox_target_sys->addItem("Broadcom BCM27xx");
    ui->comboBox_target_sys->addItem("Intel IXP4xx");
    ui->comboBox_target_sys->addItem("Marvell Kirkwood");

    // TODO: Fetch list of Subtarget from make menuconfig
    ui->comboBox_subtarget->addItem("Devices with small flash");
    ui->comboBox_subtarget->addItem("Generic devices with NAND flash");
    ui->comboBox_subtarget->addItem("Microtik devices with NAND/NOR flash");

    // TODO: Fetch list of target profile from make menuconfig
    ui->comboBox_target_profile->addItem("TPLink");
    ui->comboBox_target_profile->addItem("Wisnet");
    ui->comboBox_target_profile->addItem("Netgear");
    ui->comboBox_target_profile->addItem("LinkSys");
    ui->comboBox_target_profile->addItem("KTLI");
    ui->comboBox_target_profile->addItem("Meraki");
    ui->comboBox_target_profile->addItem("Cisco");
    ui->comboBox_target_profile->addItem("DLink");
}

SelectRouter::~SelectRouter()
{
    delete ui;
}

void SelectRouter::on_pushButton_clicked()
{
    this->close();
    selectconfig = new SelectConfig(this);
    selectconfig->show();
}

void SelectRouter::on_radioButton_novice_toggled(bool checked)
{
    if (checked == true) {
        ui->comboBox_subtarget->setDisabled(true);
        ui->comboBox_target_sys->setDisabled(true);
    } else {
        ui->comboBox_subtarget->setDisabled(false);
        ui->comboBox_target_sys->setDisabled(false);
    }
}
