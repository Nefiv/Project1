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
#include "QString"
#include "filters.h"
#include "encoder.h"

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
    void denoisingFilter();
    void customFilter();
    void on_showImageCustomFilterButton_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_triggered();

    void on_actionInsert_Image_triggered();

    void on_actionExtract_Image_triggered();

    void on_actionEncode_Image_triggered();

    void on_actionDecode_Image_triggered();

    void on_pushButton_clicked();

private:
    void showImageBefore();
    void showImageAfter();
    void writeImage(QString fileName, QImage &source);
    void readImage(QString fileName, QImage &image);
    QImage imageBefore, imageAfter;
    Ui::MainWindow *ui;
    QString fileOpenedName;
    QGraphicsScene* scene;
};

#endif // MAINWINDOW_H
