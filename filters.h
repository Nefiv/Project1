#ifndef FILTERS_H
#define FILTERS_H

#include "QImage"
#include "QColor"
#include <stdexcept>
#include "QRgb"

class Filters
{
    private:
        QImage imageBefore, imageAfter;
        int ** conversionMatrix;
        QColor ** brightnessPixelsInMatrix;
        void setBrightnessPixelsInMatrix(int indexX, int indexY);
    public:
        Filters();
        Filters(QImage imageBefore);
        Filters(QImage imageBefore, int ** conversionMatrix);
        QImage getImageBefore();
        QImage getImageAfter();
        void setImageBefore(QImage imageBefore);
        void setImageAfter(QImage imageAfter);
        void setMatrixCustomFilter(int ** conversionMatrix);
        void customFilter(int scale, int offset);
        void denoisingFilter();
        ~Filters();
};

#endif // FILTERS_H
