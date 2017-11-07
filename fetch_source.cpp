#include "fetch_source.h"
#include "ui_fetch_source.h"
#include "qprocess.h"
#include "feeds.h"
#include "mainwindow.h"
#include "qfiledialog.h"

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

    /* TODO: Add calculating internet speed through speedtest or ping */

    ui->start_button->setDisabled(true);
    ui->wait_label->show();

    /*TODO: Give option to choose OpenWRT version(can add LEDE as well)*/
    /*TODO: Give option to clone to custom folder */

    args<<"clone"<<"https://github.com/openwrt/openwrt.git";
    getSource.start("git", args, QIODevice::ReadWrite);

    if (getSource.pid()) {
        do {
                ui->wait_label->setText("Downloading source, please wait.");
                MainWindow().delay(100);
                ui->wait_label->setText("Downloading source, please wait..");
                MainWindow().delay(100);
                ui->wait_label->setText("Downloading source, please wait...");
                MainWindow().delay(100);
            } while (getSource.pid());
    }
    else ui->wait_label->setText("Downloading Failed : Not able to start process");

    if (getSource.exitCode()) {
        ui->wait_label->setText("Downloading Failed : " + getSource.readAllStandardError());
        ui->wait_label->setWordWrap(true);
        /* TODO: What to do after error? Delete folder, no internet etc. */
    }
    else {
        ui->wait_label->setText("Downloading Successful");
        QDir::setCurrent(QDir::currentPath() + "/openwrt");
        ui->next_button->show();
    }
}

void Fetch_source::on_next_button_clicked()
{
    feeds = new Feeds(this);
    feeds->show();
    this->hide();
}
