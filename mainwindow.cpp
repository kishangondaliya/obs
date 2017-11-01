#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"
#include "qfiledialog.h"
#include "qprocess.h"
#include "qiodevice.h"
#include "qdebug.h"
#include "QTime"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("OpenWrt Build System");
    ui->lineEdit->setText(" ");
    ui->label_2->hide();
    ui->label_3->hide();
    ui->textBrowser->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void MainWindow::start_git_clone()
{
    QProcess getSource;
    QStringList args;
    ui->textBrowser->append("Started cloning OpenWRT project");
    args<<"clone"<<"https://github.com/openwrt/openwrt.git";

    getSource.start("git", args, QIODevice::ReadWrite);

    while (!getSource.waitForFinished(100)) {
    }
    ui->textBrowser->append("Getting OpenWRT source done");
}

void MainWindow::on_select_clicked()
{


    if (QDir(ui->lineEdit->text()).exists()) {
        ui->lineEdit->hide();
        ui->label->hide();
        ui->toolButton->hide();
        ui->select->hide();
        ui->label_2->hide();
        ui->textBrowser->show();
        ui->label_3->show();
        delay(500);
        QDir::setCurrent(ui->lineEdit->text());
        qDebug() << "click event done";
        start_git_clone();

    } else {
        ui->label_2->show();
    }
}

void MainWindow::on_toolButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    ui->lineEdit->setText(dir);
}


