#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"
#include "qfiledialog.h"
#include "qiodevice.h"
#include "qdebug.h"
#include "QTime"
#include "fetchsource.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->hide();
    /* TODO: Add welcome screen/label */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void MainWindow::on_b_button_clicked()
{
    if (QDir(ui->lineEdit->text()).exists()) {
            QDir::setCurrent(ui->lineEdit->text());
            fetchSource = new FetchSource(this);
            fetchSource->show();
            this->hide();
    } else {
            ui->label_2->show();
    }
}

void MainWindow::on_toolButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    ui->lineEdit->setText(dir);
}


