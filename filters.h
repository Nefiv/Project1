#ifndef FILTERS_H
#define FILTERS_H

#include "QImage"
#include "QColor"
#include <stdexcept>
#include "QRgb"
#include "exception"
#include <math.h>
#include "QMessageBox"

class Filters
{
    private:
        const static double KNNNOISE = 0.32;
        const static double LERPC = 0.2;
        const static double KNN_WEIGHT_THRESHOLD = 0.02;
        const static double KNN_LERP_THRESHOLD = 0.79;
        int sizeMatrix;
        QImage imageBefore, imageAfter;
        int ** conversionMatrix;
        double ** weightDenoisingMatrix;
        QColor ** brightnessPixelsInMatrix;
        void setBrightnessPixelsInMatrix(int indexX, int indexY);
        void setWeightDenoisingMatrix(int indexX, int indexY);
        double lerpf(double a, double b, double c);
        double vecLen(QColor middlePixel, QColor xyPixel);
    public:
        Filters();
        Filters(QImage imageBefore);
        Filters(QImage imageBefore, int ** conversionMatrix);
        QImage getImageBefore();
        QImage getImageAfter();
        void setSizeMatrix(int sizeMatrix);
        void setImageBefore(QImage imageBefore);
        void setImageAfter(QImage imageAfter);
        void setMatrixCustomFilter(int ** conversionMatrix);
        void customFilter(int scale, int offset);
        void denoisingFilter(QImage imageBefore);
        ~Filters();
};

#endif // FILTERS_H
