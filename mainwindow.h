#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include "QFileDialog"
#include "QImage"
#include "QLabel"
#include "QScrollArea"
#include "QGraphicsScene"
#include "QGraphicsPixmapItem"
#include "QGraphicsView"

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
