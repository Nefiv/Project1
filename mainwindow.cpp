#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
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

void MainWindow::on_pushButton_clicked()
{
    QMessageBox msbox;
    msbox.setText("KURWA MAC!!");
    msbox.exec();
}

void MainWindow::openPicture()
{
     QString fileName1 = QFileDialog::getOpenFileName(this,
                                         tr("Open File"), QDir::currentPath());
         if (!fileName1.isEmpty()) {
             QImage image(fileName1);
             if (image.isNull()) {
                 QMessageBox::information(this, tr("Image Viewer"),
                                          tr("Cannot load %1.").arg(fileName1));
                 return;
             }
             QGraphicsScene* scene = new QGraphicsScene();
             QGraphicsView* view = new QGraphicsView(scene);
             QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
             scene->addItem(item);
             view->show();
         }
}

void MainWindow::savePictureAs()
{
}

void MainWindow::savePicture()
{

}

void MainWindow::denoisingFilter()
{

}
