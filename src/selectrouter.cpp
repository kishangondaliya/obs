#include "include/selectrouter.h"
#include "ui_selectrouter.h"
#include "qdebug.h"
#include "include/selectconfig.h"

SelectRouter::SelectRouter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectRouter)
{
    ui->setupUi(this);
    ui->comboBox->addItem("TPLink");
    ui->comboBox->addItem("Wisnet");
    ui->comboBox->addItem("Netgear");
    ui->comboBox->addItem("LinkSys");
    ui->comboBox->addItem("KTLI");
    ui->comboBox->addItem("Meraki");
    ui->comboBox->addItem("Cisco");
    ui->comboBox->addItem("DLink");
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
