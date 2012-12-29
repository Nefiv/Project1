#include "filters.h"

Filters::Filters()
{
}

Filters::~Filters()
{
    for(int i = 0; i < sizeMatrix; i++)
        delete []conversionMatrix[i];
    delete []conversionMatrix;
    for(int i = 0; i < sizeMatrix; i++)
        delete []brightnessPixelsInMatrix[i];
    delete []brightnessPixelsInMatrix;
    for(int i = 0; i < sizeMatrix; i++)
        delete []weightDenoisingMatrix[i];
    delete []weightDenoisingMatrix;
}

Filters::Filters(QImage imageBefore)
{
    this->imageBefore = imageBefore;
    this->imageAfter = imageBefore;
}

Filters::Filters(QImage imageBefore, int ** conversionMatrix)
{
    this->imageBefore = imageBefore;
    this->imageAfter = imageBefore;
    this->conversionMatrix = conversionMatrix;
}

//================================== G E T  &  S E T  F U N C T I O N S ==============================

QImage Filters::getImageBefore()
{
    return this->imageBefore;
}

QImage Filters::getImageAfter()
{
    return this->imageAfter;
}

void Filters::setSizeMatrix(int sizeMatrix)
{
    this->sizeMatrix = sizeMatrix;
}

void Filters::setImageBefore(QImage imageBefore)
{
    this->imageBefore = imageBefore;
}

void Filters::setImageAfter(QImage imageAfter)
{
    this->imageAfter = imageAfter;
}

void Filters::setMatrixCustomFilter(int ** conversionMatrix)
{
    this->conversionMatrix = conversionMatrix;
}

void Filters::setBrightnessPixelsInMatrix(int indexX, int indexY)
{
    QColor colorPixel;
    brightnessPixelsInMatrix = new QColor * [sizeMatrix];
    for(int i = 0; i<sizeMatrix ; i++)
    {
        brightnessPixelsInMatrix [i] = new QColor[sizeMatrix];
    }
    int halfSizeMatrix = sizeMatrix/2;

    for (int i = -halfSizeMatrix ; i <= halfSizeMatrix ; i++)
        for(int j = -halfSizeMatrix ; j <= halfSizeMatrix ; j++)
        {
            colorPixel.setRgb(0, 0, 0);
            brightnessPixelsInMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = colorPixel;
        }
//==================================== P R Z E J S C I E   P O   C A L Y M   O B R A Z I E ========================================
//================== P L U S   Z A B E Z P I E C Z E N I E   O P E R A C J I   N A   K R A W E D Z I A C H ========================

    //================= LEWY GORNY ===================
    if(indexX < halfSizeMatrix && indexY < halfSizeMatrix)
    {
        for (int i = indexX ; i <= halfSizeMatrix ; i++)
            for(int j = indexY ; j <= halfSizeMatrix ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = colorPixel;
            }
    }
    //================= PRAWY DOLNY ===================
    else if((indexX > imageBefore.width() - halfSizeMatrix - 1) && (indexY > imageBefore.height() - halfSizeMatrix - 1))
    {
        for (int i = - halfSizeMatrix; i <= (imageBefore.width() - 1 - indexX) ; i++)
            for(int j = - halfSizeMatrix ; j <= (imageBefore.height() - 1 - indexY) ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = colorPixel;
            }
    }
    //================= LEWY DOLNY =====================
    else if((indexX < halfSizeMatrix) && (indexY > imageBefore.height() - halfSizeMatrix - 1))
    {
        for (int i = indexX ; i <= halfSizeMatrix ; i++)
            for(int j = - halfSizeMatrix ; j <= (imageBefore.height() - 1 - indexY) ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = colorPixel;
            }
    }
    //================= PRAWY GORNY ====================
    else if((indexX > imageBefore.width() - halfSizeMatrix - 1) && (indexY < halfSizeMatrix))
    {
        for (int i = - halfSizeMatrix; i <= (imageBefore.width() - 1 - indexX) ; i++)
            for(int j = indexY ; j <= halfSizeMatrix ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = colorPixel;
            }
    }
    //================= LEWA KRAWEDZ ===================
    else if(indexX < halfSizeMatrix)
    {
        for (int i = indexX ; i <= halfSizeMatrix ; i++)
            for(int j = -halfSizeMatrix ; j <= halfSizeMatrix ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = colorPixel;
            }
    }
    //================= GORNA KRAWEDZ ==================
    else if(indexY < halfSizeMatrix)
    {
        for (int i = -halfSizeMatrix ; i <= halfSizeMatrix ; i++)
            for(int j = indexY ; j <= halfSizeMatrix ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = colorPixel;
            }
    }
    //================= DOLNA KRAWEDZ =====================
    else if(indexY > imageBefore.height() - halfSizeMatrix - 1)
    {
        for (int i = -halfSizeMatrix ; i <= halfSizeMatrix ; i++)
            for(int j = - halfSizeMatrix ; j <= (imageBefore.height() - 1 - indexY) ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = colorPixel;
            }
    }
    //================= PRAWA KRAWEDZ ====================
    else if(indexX > imageBefore.width() - halfSizeMatrix - 1)
    {
        for (int i = - halfSizeMatrix; i <= (imageBefore.width() - 1 - indexX) ; i++)
            for(int j = -halfSizeMatrix ; j <= halfSizeMatrix ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = colorPixel;
            }
    }
    //================ SRODEK OBRAZU ======================
    else
    {
        for (int i = -halfSizeMatrix ; i <= halfSizeMatrix ; i++)
            for(int j = -halfSizeMatrix ; j <= halfSizeMatrix ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = colorPixel;
            }
    }
}

void Filters::setWeightDenoisingMatrix(int indexX, int indexY)
{
    QColor colorMiddlePixel, colorNeighborPixel;
    colorMiddlePixel.setRgb(imageBefore.pixel(indexX, indexY));

    weightDenoisingMatrix = new double * [sizeMatrix];
    for(int i = 0; i<sizeMatrix ; i++)
    {
        weightDenoisingMatrix [i] = new double[sizeMatrix];
    }
    int halfSizeMatrix = sizeMatrix/2;
    double distance = 0.0;

    for (int i = -halfSizeMatrix ; i <= halfSizeMatrix ; i++)
        for(int j = -halfSizeMatrix ; j <= halfSizeMatrix ; j++)
        {
            weightDenoisingMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = 0.0;
        }
//==================================== P R Z E J S C I E   P O   C A L Y M   O B R A Z I E ========================================
//================== P L U S   Z A B E Z P I E C Z E N I E   O P E R A C J I   N A   K R A W E D Z I A C H ========================

    //================= LEWY GORNY ===================
    if(indexX < halfSizeMatrix && indexY < halfSizeMatrix)
    {
        for (int i = indexX ; i <= halfSizeMatrix ; i++)
            for(int j = indexY ; j <= halfSizeMatrix ; j++)
            {
                colorNeighborPixel.setRgb(imageBefore.pixel(indexX + i, indexY + j));
                distance = vecLen(colorMiddlePixel, colorNeighborPixel);
                weightDenoisingMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = exp(- (distance * 1/(KNNNOISE * KNNNOISE) + (i * i + j * j) * 1/sizeMatrix* sizeMatrix));
            }
    }
    //================= PRAWY DOLNY ===================
    else if((indexX > imageBefore.width() - halfSizeMatrix - 1) && (indexY > imageBefore.height() - halfSizeMatrix - 1))
    {
        for (int i = - halfSizeMatrix; i <= (imageBefore.width() - 1 - indexX) ; i++)
            for(int j = - halfSizeMatrix ; j <= (imageBefore.height() - 1 - indexY) ; j++)
            {
                colorNeighborPixel.setRgb(imageBefore.pixel(indexX + i, indexY + j));
                distance = vecLen(colorMiddlePixel, colorNeighborPixel);
                weightDenoisingMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = exp(- (distance * 1/(KNNNOISE * KNNNOISE) + (i * i + j * j) * 1/sizeMatrix* sizeMatrix));
            }
    }
    //================= LEWY DOLNY =====================
    else if((indexX < halfSizeMatrix) && (indexY > imageBefore.height() - halfSizeMatrix - 1))
    {
        for (int i = indexX ; i <= halfSizeMatrix ; i++)
            for(int j = - halfSizeMatrix ; j <= (imageBefore.height() - 1 - indexY) ; j++)
            {
                colorNeighborPixel.setRgb(imageBefore.pixel(indexX + i, indexY + j));
                distance = vecLen(colorMiddlePixel, colorNeighborPixel);
                weightDenoisingMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = exp(- (distance * 1/(KNNNOISE * KNNNOISE) + (i * i + j * j) * 1/sizeMatrix* sizeMatrix));
            }
    }
    //================= PRAWY GORNY ====================
    else if((indexX > imageBefore.width() - halfSizeMatrix - 1) && (indexY < halfSizeMatrix))
    {
        for (int i = - halfSizeMatrix; i <= (imageBefore.width() - 1 - indexX) ; i++)
            for(int j = indexY ; j <= halfSizeMatrix ; j++)
            {
                colorNeighborPixel.setRgb(imageBefore.pixel(indexX + i, indexY + j));
                distance = vecLen(colorMiddlePixel, colorNeighborPixel);
                weightDenoisingMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = exp(- (distance * 1/(KNNNOISE * KNNNOISE) + (i * i + j * j) * 1/sizeMatrix* sizeMatrix));
            }
    }
    //================= LEWA KRAWEDZ ===================
    else if(indexX < halfSizeMatrix)
    {
        for (int i = indexX ; i <= halfSizeMatrix ; i++)
            for(int j = -halfSizeMatrix ; j <= halfSizeMatrix ; j++)
            {
                colorNeighborPixel.setRgb(imageBefore.pixel(indexX + i, indexY + j));
                distance = vecLen(colorMiddlePixel, colorNeighborPixel);
                weightDenoisingMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = exp(- (distance * 1/(KNNNOISE * KNNNOISE) + (i * i + j * j) * 1/sizeMatrix* sizeMatrix));
            }
    }
    //================= GORNA KRAWEDZ ==================
    else if(indexY < halfSizeMatrix)
    {
        for (int i = -halfSizeMatrix ; i <= halfSizeMatrix ; i++)
            for(int j = indexY ; j <= halfSizeMatrix ; j++)
            {
                colorNeighborPixel.setRgb(imageBefore.pixel(indexX + i, indexY + j));
                distance = vecLen(colorMiddlePixel, colorNeighborPixel);
                weightDenoisingMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = exp(- (distance * 1/(KNNNOISE * KNNNOISE) + (i * i + j * j) * 1/sizeMatrix* sizeMatrix));
            }
    }
    //================= DOLNA KRAWEDZ =====================
    else if(indexY > imageBefore.height() - halfSizeMatrix - 1)
    {
        for (int i = -halfSizeMatrix ; i <= halfSizeMatrix ; i++)
            for(int j = - halfSizeMatrix ; j <= (imageBefore.height() - 1 - indexY) ; j++)
            {
                colorNeighborPixel.setRgb(imageBefore.pixel(indexX + i, indexY + j));
                distance = vecLen(colorMiddlePixel, colorNeighborPixel);
                weightDenoisingMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = exp(- (distance * 1/(KNNNOISE * KNNNOISE) + (i * i + j * j) * 1/sizeMatrix* sizeMatrix));
            }
    }
    //================= PRAWA KRAWEDZ ====================
    else if(indexX > imageBefore.width() - halfSizeMatrix - 1)
    {
        for (int i = - halfSizeMatrix; i <= (imageBefore.width() - 1 - indexX) ; i++)
            for(int j = -halfSizeMatrix ; j <= halfSizeMatrix ; j++)
            {
                colorNeighborPixel.setRgb(imageBefore.pixel(indexX + i, indexY + j));
                distance = vecLen(colorMiddlePixel, colorNeighborPixel);
                weightDenoisingMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = exp(- (distance * 1/(KNNNOISE * KNNNOISE) + (i * i + j * j) * 1/sizeMatrix* sizeMatrix));
            }
    }
    //================ SRODEK OBRAZU ======================
    else
    {
        for (int i = -halfSizeMatrix ; i <= halfSizeMatrix ; i++)
            for(int j = -halfSizeMatrix ; j <= halfSizeMatrix ; j++)
            {
                colorNeighborPixel.setRgb(imageBefore.pixel(indexX + i, indexY + j));
                distance = vecLen(colorMiddlePixel, colorNeighborPixel);
                weightDenoisingMatrix[i+halfSizeMatrix][j+halfSizeMatrix] = exp(- (distance * 1/(KNNNOISE * KNNNOISE) + (i * i + j * j) * 1/sizeMatrix* sizeMatrix));
            }
    }
}

double Filters::lerpf(double a, double b, double c)
{
    return (a + (b/255 - a) * c);
}

double Filters::vecLen(QColor middlePixel, QColor xyPixel)
{
    return (double)(
               (xyPixel.red()/255 - middlePixel.red()/255) * (xyPixel.red()/255 - middlePixel.red()/255) +
               (xyPixel.green()/255 - middlePixel.green()/255) * (xyPixel.green()/255 - middlePixel.green()/255) +
               (xyPixel.blue()/255 - middlePixel.blue()/255) * (xyPixel.blue()/255 - middlePixel.blue()/255));
}

//================================ F I L T E R S  F U N C T I O N ===============================

void Filters::customFilter(int scale, int offset)
{
    int componentRedColor, componentGreenColor, componentBlueColor;
    QColor colorPixel;
    for(int x = 0; x < imageBefore.width(); x++)
    {
        for(int y = 0; y < imageBefore.height(); y++)
        {
            componentRedColor = 0;
            componentGreenColor = 0;
            componentBlueColor = 0;
            setBrightnessPixelsInMatrix(x, y);
            for (int i = 0 ; i < sizeMatrix ; i++)
                for(int j = 0 ; j < sizeMatrix ; j++)
                {
                    componentRedColor += conversionMatrix[i][j] * brightnessPixelsInMatrix[i][j].red();
                    componentGreenColor += conversionMatrix[i][j] * brightnessPixelsInMatrix[i][j].green();
                    componentBlueColor += conversionMatrix[i][j] * brightnessPixelsInMatrix[i][j].blue();
                }
            componentRedColor = componentRedColor/scale + offset;
            componentGreenColor = componentGreenColor/scale + offset;
            componentBlueColor = componentBlueColor/scale + offset;

            if (componentRedColor > 255) componentRedColor = 255;
            else if (componentRedColor < 0) componentRedColor = 0;
            if (componentGreenColor > 255) componentGreenColor = 255;
            else if (componentGreenColor < 0) componentGreenColor = 0;
            if (componentBlueColor > 255) componentBlueColor = 255;
            else if (componentBlueColor < 0) componentBlueColor = 0;

            colorPixel.setRed(componentRedColor);
            colorPixel.setGreen(componentGreenColor);
            colorPixel.setBlue(componentBlueColor);
            imageAfter.setPixel(x, y, colorPixel.rgb());
        }
    }
}

void Filters::denoisingFilter(QImage imageBefore)
{
    this->imageBefore = imageBefore;
    imageAfter = imageBefore;
    double componentRedColor, componentGreenColor, componentBlueColor;
    double sumWeights = 0.0;
    double fCount = 0.0;
    float lerpQ = 0.0;
    QColor colorPixel;
    for(int x = 0; x < imageBefore.width(); x++)
    {
        for(int y = 0; y < imageBefore.height(); y++)
        {
            sumWeights = 0.0;
            componentRedColor = 0.0;
            componentGreenColor = 0.0;
            componentBlueColor = 0.0;
            colorPixel.setRgb(imageBefore.pixel(x, y));
            setWeightDenoisingMatrix(x, y);
            setBrightnessPixelsInMatrix(x, y);
            for (int i = 0 ; i < sizeMatrix ; i++)
                for(int j = 0 ; j < sizeMatrix ; j++)
                {
                    componentRedColor += weightDenoisingMatrix[i][j] * brightnessPixelsInMatrix[i][j].red()/255;
                    componentGreenColor += weightDenoisingMatrix[i][j] * brightnessPixelsInMatrix[i][j].green()/255;
                    componentBlueColor += weightDenoisingMatrix[i][j] * brightnessPixelsInMatrix[i][j].blue()/255;
                    sumWeights += weightDenoisingMatrix[i][j];
                    fCount += (weightDenoisingMatrix[i][j] > KNN_WEIGHT_THRESHOLD) ? 1/sizeMatrix* sizeMatrix : 0.0;
                }
            sumWeights = 1.0 / sumWeights;
            componentRedColor *= sumWeights;
            componentGreenColor *= sumWeights;
            componentBlueColor *= sumWeights;

            lerpQ = (fCount > KNN_LERP_THRESHOLD) ? LERPC : 1.0 - LERPC;
            componentRedColor = lerpf(componentRedColor, colorPixel.red(), lerpQ);
            componentGreenColor = lerpf(componentGreenColor, colorPixel.green(), lerpQ);
            componentBlueColor = lerpf(componentBlueColor, colorPixel.blue(), lerpQ);

            if (componentRedColor > 1) componentRedColor = 1;
            else if (componentRedColor < 0) componentRedColor = 0;
            if (componentGreenColor > 1) componentGreenColor = 1;
            else if (componentGreenColor < 0) componentGreenColor = 0;
            if (componentBlueColor > 1) componentBlueColor = 1;
            else if (componentBlueColor < 0) componentBlueColor = 0;

            colorPixel.setRed((int)(componentRedColor* 255));
            colorPixel.setGreen((int)(componentGreenColor* 255));
            colorPixel.setBlue((int)(componentBlueColor* 255));
            imageAfter.setPixel(x, y, colorPixel.rgb());
        }
    }
}
