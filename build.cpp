#include "build.h"
#include "ui_build.h"

Build::Build(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Build)
{
    ui->setupUi(this);
}

Build::~Build()
{
    delete ui;
}
