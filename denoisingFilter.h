#ifndef DENOISINGFILTER_H
#define DENOISINGFILTER_H
#include "QImage"

class denoisingFilterr
{
public:
    static QImage knnFilter(QImage);
};

#endif // DENOISINGFILTER_H
