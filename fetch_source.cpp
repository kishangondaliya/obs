#include "fetch_source.h"
#include "ui_fetch_source.h"

Fetch_source::Fetch_source(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fetch_source)
{
    ui->setupUi(this);
}

Fetch_source::~Fetch_source()
{
    delete ui;
}
