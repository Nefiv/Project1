#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include "QFileDialog"
#include "QImage"
#include "QFile"
#include "QGraphicsScene"
#include "QGraphicsPixmapItem"
#include "QGraphicsView"
#include "QImageWriter"

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
    void on_pushButton_clicked();
    void openPicture();
    void savePictureAs();
    void savePicture();
    void denoisingFilter();
    void showImage();
    void writeFile(QString fileName);
    void readFile(QString fileName);

private:
    Ui::MainWindow *ui;
    QImage image;
    QString fileOpenedName;
};

#endif // MAINWINDOW_H
