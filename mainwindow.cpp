#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("* { background-color: rgb(170,255,127) }");
    ui->label_2->setStyleSheet("* { background-color: rgb(85,170,255) }");
    ui->frame->setStyleSheet("* { background-color: rgb(251,255,179) }");
    ui->frame->hide();
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openPicture()));
    connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(savePictureAs()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(savePicture()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->actionDenoising, SIGNAL(triggered()), this, SLOT(denoisingFilter()));
    connect(ui->actionCustom_Filter, SIGNAL(triggered()), this, SLOT(customFilter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//===================================== O P E N  &  S A V E  F U N C T I O N S =================================

void MainWindow::openPicture()
{
    fileOpenedName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(),tr("Image (*jpg)"));
         if (!fileOpenedName.isEmpty())
         {
            readFile(fileOpenedName);
            ui->graphicsView->hide();
            ui->graphicsView_2->hide();
            showImageBefore();
            ui->label_8->setText(QString::number(imageBefore.width()));
            ui->label_9->setText(QString::number(imageBefore.height()));
         }
         fileOpenedName = "";
}

void MainWindow::savePictureAs()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save it??", "Do you really to save this image??", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        fileOpenedName = QFileDialog::getSaveFileName(this ,tr("Save as..") ,QDir::currentPath(),tr("Image (*jpg)"));
            if (fileOpenedName.isEmpty()) return;
            else writeFile(fileOpenedName);
    }
}

void MainWindow::savePicture()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save it??", "Do you really to save this image??", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        if(!fileOpenedName.isEmpty()) writeFile(fileOpenedName);
        else
        {
            fileOpenedName = QFileDialog::getSaveFileName(this ,tr("Save as..") ,QDir::currentPath(),tr("Image (*jpg)"));
            if (fileOpenedName.isEmpty()) return;
            else writeFile(fileOpenedName);
        }
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
    imageAfter.save(fileName,"JPG");
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
    imageBefore.load(fileName,"JPG");
    file.close();
}

//================================ S H O W  I M A G E  F U N C T I O N =============================

void MainWindow::showImageBefore()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(imageBefore));
    scene->addItem(item);
    ui->graphicsView->show();
}

void MainWindow::showImageAfter()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView_2->setScene(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(imageAfter));
    scene->addItem(item);
    ui->graphicsView_2->show();
}

//================================================ F I L T E R S  C L A S S ===========================================

void MainWindow::denoisingFilter()
{
    Filters * newFilter = new Filters();
    newFilter->setSizeMatrix(7);
    newFilter->denoisingFilter(imageBefore);
    for(int i = 0 ; i < 4 ; i++)
    {
        imageAfter = newFilter->getImageAfter();
        newFilter->denoisingFilter(imageAfter);
    }
    imageAfter = newFilter->getImageAfter();
    showImageAfter();
}

void MainWindow::customFilter()
{
    ui->frame->show();
}

void MainWindow::on_showImageCustomFilterButton_clicked()
{
    if(ui->spinBox_51->value() != 0)
    {
        int ** conversionMatrix;
        conversionMatrix = new int * [5];
        for(int i = 0; i<5 ; i++)
        {
            conversionMatrix [i] = new int[5];
        }
        conversionMatrix[0][0] = (int)ui->spinBox->value();
        conversionMatrix[0][1] = (int)ui->spinBox_2->value();
        conversionMatrix[0][2] = (int)ui->spinBox_3->value();
        conversionMatrix[0][3] = (int)ui->spinBox_4->value();
        conversionMatrix[0][4] = (int)ui->spinBox_5->value();

        conversionMatrix[1][0] = (int)ui->spinBox_6->value();
        conversionMatrix[1][1] = (int)ui->spinBox_7->value();
        conversionMatrix[1][2] = (int)ui->spinBox_8->value();
        conversionMatrix[1][3] = (int)ui->spinBox_9->value();
        conversionMatrix[1][4] = (int)ui->spinBox_10->value();

        conversionMatrix[2][0] = (int)ui->spinBox_11->value();
        conversionMatrix[2][1] = (int)ui->spinBox_12->value();
        conversionMatrix[2][2] = (int)ui->spinBox_13->value();
        conversionMatrix[2][3] = (int)ui->spinBox_14->value();
        conversionMatrix[2][4] = (int)ui->spinBox_15->value();

        conversionMatrix[3][0] = (int)ui->spinBox_16->value();
        conversionMatrix[3][1] = (int)ui->spinBox_17->value();
        conversionMatrix[3][2] = (int)ui->spinBox_18->value();
        conversionMatrix[3][3] = (int)ui->spinBox_19->value();
        conversionMatrix[3][4] = (int)ui->spinBox_20->value();

        conversionMatrix[4][0] = (int)ui->spinBox_21->value();
        conversionMatrix[4][1] = (int)ui->spinBox_22->value();
        conversionMatrix[4][2] = (int)ui->spinBox_23->value();
        conversionMatrix[4][3] = (int)ui->spinBox_24->value();
        conversionMatrix[4][4] = (int)ui->spinBox_25->value();

        Filters * newFilter = new Filters(imageBefore, conversionMatrix);
        newFilter->setSizeMatrix(5);
        newFilter->customFilter(ui->spinBox_51->value(), ui->spinBox_52->value());

        for(int i = 0; i<5; i++)
            delete []conversionMatrix[i];
        delete []conversionMatrix;

        imageAfter = newFilter->getImageAfter();
        showImageAfter();
    }
    else
    {
        QMessageBox::information(this, tr("Wrong scales value"),tr("Scale doesn't be \"0\" value! Try again."));
    }
}
