#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openPicture()));
    connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(savePictureAs()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(savePicture()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(quit()));
    connect(ui->actionDenoising, SIGNAL(triggered()), this, SLOT(denoisingFilter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox msbox;
    msbox.setText("KURWA MAC!!");
    msbox.exec();
}

void MainWindow::openPicture()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.*)"));
}

void MainWindow::savePictureAs()
{

}

void MainWindow::savePicture()
{

}

void MainWindow::quit()
{

}

void MainWindow::denoisingFilter()
{

}
