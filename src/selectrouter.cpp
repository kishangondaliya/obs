#include "include/selectrouter.h"
#include "ui_selectrouter.h"
#include "qdebug.h"
#include "include/selectconfig.h"

SelectRouter::SelectRouter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectRouter)
{
    ui->setupUi(this);
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
