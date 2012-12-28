#include "filters.h"

Filters::Filters()
{
}

Filters::~Filters()
{
    for(int i = 0; i<5; i++)
        delete []conversionMatrix[i];
    delete []conversionMatrix;
    for(int i = 0; i<5; i++)
        delete []brightnessPixelsInMatrix[i];
    delete []brightnessPixelsInMatrix;
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
    int sumOfColors;
    sumOfColors = 0;
    brightnessPixelsInMatrix = new QColor * [5];
    for(int i = 0; i<5 ; i++)
    {
        brightnessPixelsInMatrix [i] = new QColor[5];
    }

    for (int i = -2 ; i <= 2 ; i++)
        for(int j = -2 ; j <= 2 ; j++)
        {
            colorPixel.setRgb(0, 0, 0);
            brightnessPixelsInMatrix[i+2][j+2] = colorPixel;
        }
//==================================== P R Z E J S C I E   P O   C A L Y M   O B R A Z I E ========================================
//================== P L U S   Z A B E Z P I E C Z E N I E   O P E R A C J I   N A   K R A W E D Z I A C H ========================

    //================= LEWY GORNY ===================
    if(indexX < 2 && indexY < 2)
    {
        for (int i = indexX ; i <= 2 ; i++)
            for(int j = indexY ; j <= 2 ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+2][j+2] = colorPixel;
            }
    }
    //================= PRAWY DOLNY ===================
    else if((indexX > imageBefore.width() - 3) && (indexY > imageBefore.height() - 3))
    {
        for (int i = - 2; i <= (imageBefore.width() - 1 - indexX) ; i++)
            for(int j = - 2 ; j <= (imageBefore.height() - 1 - indexY) ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+2][j+2] = colorPixel;
            }
    }
    //================= LEWY DOLNY =====================
    else if((indexX < 2) && (indexY > imageBefore.height() - 3))
    {
        for (int i = indexX ; i <= 2 ; i++)
            for(int j = - 2 ; j <= (imageBefore.height() - 1 - indexY) ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+2][j+2] = colorPixel;
            }
    }
    //================= PRAWY GORNY ====================
    else if((indexX > imageBefore.width() - 3) && (indexY < 2))
    {
        for (int i = - 2; i <= (imageBefore.width() - 1 - indexX) ; i++)
            for(int j = indexY ; j <= 2 ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+2][j+2] = colorPixel;
            }
    }
    //================= LEWA KRAWEDZ ===================
    else if(indexX < 2)
    {
        for (int i = indexX ; i <= 2 ; i++)
            for(int j = -2 ; j <= 2 ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+2][j+2] = colorPixel;
            }
    }
    //================= GORNA KRAWEDZ ==================
    else if(indexY < 2)
    {
        for (int i = -2 ; i <= 2 ; i++)
            for(int j = indexY ; j <= 2 ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+2][j+2] = colorPixel;
            }
    }
    //================= DOLNA KRAWEDZ =====================
    else if(indexY > imageBefore.height() - 3)
    {
        for (int i = -2 ; i <= 2 ; i++)
            for(int j = - 2 ; j <= (imageBefore.height() - 1 - indexY) ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+2][j+2] = colorPixel;
            }
    }
    //================= PRAWA KRAWEDZ ====================
    else if(indexX > imageBefore.width() - 3)
    {
        for (int i = - 2; i <= (imageBefore.width() - 1 - indexX) ; i++)
            for(int j = -2 ; j <= 2 ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+2][j+2] = colorPixel;
            }
    }
    //================ SRODEK OBRAZU ======================
    else
    {
        for (int i = -2 ; i <= 2 ; i++)
            for(int j = -2 ; j <= 2 ; j++)
            {
                colorPixel.setRgb(imageBefore.pixel(indexX + i,indexY + j));
                brightnessPixelsInMatrix[i+2][j+2] = colorPixel;
            }
    }
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
            for (int i = 0 ; i < 5 ; i++)
                for(int j = 0 ; j < 5 ; j++)
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

void Filters::denoisingFilter()
{

}
