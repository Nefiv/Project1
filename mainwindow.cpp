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
    connect(ui->actionDenoising, SIGNAL(triggered()), this, SLOT(denoising()));
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
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save it??", "Do you really to save this image??", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        QString fileOpenedName = QFileDialog::getSaveFileName(this ,tr("Save as..") ,QDir::currentPath(),tr("Image (*jpg)"));
            if (fileOpenedName.isEmpty())
                 return;
             else {
                writeFile(fileOpenedName);
        }
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

void MainWindow::denoisingFilter()
{
     int imageW =  imageBefore.width();
     int imageH = imageBefore.height();

     imageAfter = imageBefore;
/*
     int KNN_WINDOW_RADIUS = 3;
     int INV_KNN_WINDOW_AREA ( 1.0f / (float)
                           ((2*KNN_WINDOW_RADIUS+1)*(2*KNN_WINDOW_RADIUS+1)) );
    int KNN_WEIGHT_THRESHOLD  =  0.02f;
    int KNN_LERP_THRESHOLD    =  0.79f;

     float Noise = 10;
     float lerpC = 0.2;

     for (int x = 0; x<imageW; x++ )
         for (int y = 0; y<imageH; y++ )
         {
             //const int ix = blockDim.x * blockIdx.x + threadIdx.x;
             //const int iy = blockDim.y * blockIdx.y + threadIdx.y;
             //Add half of a texel to always address exact texel centers
             //const float x = (float)ix + 0.5f;
             //const float y = (float)iy + 0.5f;

                 //Normalized counter for the weight threshold
                 float fCount = 0;
                 //Total sum of pixel weights
                 float sumWeights = 0;
                 //Result accumulator
                 QVector3D clr(0, 0, 0);
                 //Center of the KNN window
                 QRgb qrgb = imageBefore.pixel(x,y);
                 QVector3D clr00(
                             qRed(qrgb),
                             qGreen(qrgb),
                             qBlue(qrgb)
                             );


                 //Cycle through KNN window, surrounding (x, y) texel
                 for (float i = -KNN_WINDOW_RADIUS; i <= KNN_WINDOW_RADIUS; i++)
                     for (float j = -KNN_WINDOW_RADIUS; j <= KNN_WINDOW_RADIUS; j++)
                     {
                         qrgb = imageBefore.pixel(x+j,y+i);
                         QVector3D clrIJ(
                                      qRed(qrgb),
                                      qGreen(qrgb),
                                      qBlue(qrgb)
                                      );


                         float distanceIJ = clr00.length() - clrIJ.length();

                         //Derive final weight from color distance
                         float   weightIJ = qExp(- (distanceIJ * Noise + (i * i + j * j) * INV_KNN_WINDOW_AREA));

                         //Accumulate (x + j, y + i) texel color with computed weight
                         clr.setX(clr.x() + clrIJ.x() * weightIJ);
                         clr.setY(clr.y() + clrIJ.y() * (qreal)weightIJ);
                         clr.setZ(clr.z() + clrIJ.z() * (qreal)weightIJ);

                         //Sum of weights for color normalization to [0..1] range
                         sumWeights     += weightIJ;

                         //Update weight counter, if KNN weight for current window texel
                         //exceeds the weight threshold
                         fCount         += (weightIJ > KNN_WEIGHT_THRESHOLD) ? INV_KNN_WINDOW_AREA : 0;
                     }

                 //Normalize result color by sum of weights
                 sumWeights = 1.0f / sumWeights;
                 clr.setX(clr.x() * sumWeights);
                 clr.setY(clr.x() * sumWeights);
                 clr.setZ(clr.x() * sumWeights);

                 //Choose LERP quotent basing on how many texels
                 //within the KNN window exceeded the weight threshold
                 float lerpQ = (fCount > KNN_LERP_THRESHOLD) ? lerpC : 1.0f - lerpC;

                 //Write final result to global memory
                 clr.setX(clr.x() + (clr00.x() - clr.x()) * lerpQ);
                 clr.setY(clr.y() + (clr00.y() - clr.y()) * lerpQ);
                 clr.setZ(clr.z() + (clr00.z() - clr.z()) * lerpQ);
                 //dst[imageW * iy + ix] = make_color(clr.x, clr.y, clr.z, 0);
                 imageAfter.setPixel(
                                     x,
                                     y,
                                     qRgb(
                                         clr.x(),
                                         clr.y(),
                                         clr.z()
                                            )
                                     );
    }*/

     showImageAfter();

    //Tak bym chcia³ to wywo³ywaæ:
    //imageAfter = denoisingFilter.knnFilter(imageBefore);
}
