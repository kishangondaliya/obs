#include "feeds.h"
#include "ui_feeds.h"

Feeds::Feeds(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Feeds)
{
    ui->setupUi(this);
}

Feeds::~Feeds()
{
    delete ui;
}
