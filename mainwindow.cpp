#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("* { background-color: rgb(170,255,127) }");
    ui->label_2->setStyleSheet("* { background-color: rgb(85,170,255) }");
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openPicture()));
    connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(savePictureAs()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(savePicture()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->actionDenoising, SIGNAL(triggered()), this, SLOT(denoisingFilter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openPicture()
{
    fileOpenedName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(),tr("Image (*jpg)"));
         if (!fileOpenedName.isEmpty()) {
             readFile(fileOpenedName);
            showImageBefore();
            showImageAfter();
         }
}

void MainWindow::savePictureAs()
{
        QString fileName2 = QFileDialog::getSaveFileName(this ,tr("Save as..") ,QDir::currentPath(),tr("Image (*jpg)"));
            if (fileName2.isEmpty())
                 return;
             else {
                writeFile(fileName2);
                fileOpenedName = fileName2;
        }
}

void MainWindow::savePicture()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save it??", "Do you really to save this image??", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        writeFile(fileOpenedName);
    }
}

void MainWindow::writeFile(QString fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }
    image.save(fileName,"JPG");
    file.close();
}

void MainWindow::readFile(QString fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }
    image.load(fileName,"JPG");
    file.close();
}

void MainWindow::showImageBefore()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->graphicsView->show();
}

void MainWindow::showImageAfter()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView_2->setScene(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->graphicsView_2->show();
}

void MainWindow::denoisingFilter()
{

}
