#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "QMessageBox"
#include "QFileDialog"
#include "QImage"
#include "QFile"
#include "QGraphicsScene"
#include "QGraphicsPixmapItem"
#include "QGraphicsView"
#include "QImageWriter"
#include "denoisingFilter.h"
#include <QVector3D>
#include <QtCore/qmath.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void openPicture();
    void savePictureAs();
    void savePicture();
    void denoisingFilter();
    void showImageBefore();
    void showImageAfter();
    void writeFile(QString fileName);
    void readFile(QString fileName);

    void on_actionDenoising_triggered();

private:
    Ui::MainWindow *ui;
    QImage imageBefore, imageAfter;
    QString fileOpenedName;
    QGraphicsScene* scene;
};

#endif // MAINWINDOW_H
