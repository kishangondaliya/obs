#include "fetch_source.h"
#include "ui_fetch_source.h"
#include "qprocess.h"
#include "feeds.h"
#include "mainwindow.h"

Fetch_source::Fetch_source(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fetch_source)
{
    ui->setupUi(this);
    ui->wait_label->hide();
    ui->next_button->hide();
}

Fetch_source::~Fetch_source()
{
    delete ui;
}

void Fetch_source::on_start_button_clicked()
{
    QProcess getSource;
    QStringList args;

    ui->start_button->hide();
    ui->wait_label->show();

    args<<"clone"<<"https://github.com/openwrt/openwrt.git";
    getSource.start("git", args, QIODevice::ReadWrite);

    while (!getSource.waitForFinished(100)) {
        ui->wait_label->setText("Downloading source, please wait.");
        MainWindow().delay(100);
        ui->wait_label->setText("Downloading source, please wait..");
        MainWindow().delay(100);
        ui->wait_label->setText("Downloading source, please wait...");
        MainWindow().delay(100);
    }
    ui->wait_label->hide();
    ui->next_button->show();
}

void Fetch_source::on_next_button_clicked()
{
    feeds = new Feeds(this);
    feeds->show();
    this->hide();
}
