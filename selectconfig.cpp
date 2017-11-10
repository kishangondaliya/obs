#include "selectconfig.h"
#include "ui_selectconfig.h"
#include "qdebug.h"

SelectConfig::SelectConfig(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectConfig)
{
    ui->setupUi(this);
}

SelectConfig::~SelectConfig()
{
    delete ui;
}

void SelectConfig::on_next_b_clicked()
{
    ui->next_b->setDisabled(true);

    if (ui->default_config_radioButton->isChecked())
        qDebug() << "Going with default configuration";
    else
        qDebug() << "Custom configuration";

}
