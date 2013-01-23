#ifndef ENCODER_H
#define ENCODER_H

#include "QImage"
#include "math.h"
#include "time.h"

class Encoder
{
public:
    Encoder();
    QImage insertImage(QImage const &destination, QImage const &source);
    QImage extractImage(QImage encodedImage);
    QImage encodeImage(QImage encodedImage, int e, int n);
    QImage decodeImage(QImage encodedImage, int d, int n);
    void generate_passwords(int &e, int &d, int &n);
    int moduloPower(int exponent, int n, int base);
private:
};

#endif // ENCODER_H
