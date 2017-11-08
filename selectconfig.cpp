#include "selectconfig.h"
#include "ui_selectconfig.h"

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

void SelectConfig::on_default_config_radioButton_toggled(bool checked)
{
    /* Create default config */
}

void SelectConfig::on_custom_config_radioButton_toggled(bool checked)
{
    /* Create custom config */
}

void SelectConfig::on_next_b_clicked()
{
    /* Go to next window */
}
