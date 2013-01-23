#include "encoder.h"

Encoder::Encoder()
{
}

QImage Encoder::insertImage(QImage const &destination, QImage const &source)
{
    QImage result = destination;

    // najpierw wstawiamy szerokosc i wysokosc kodowanego obrazu:
    // w pikselu (0,0) szerokosc:
    QRgb pixel = result.pixel(0,0);
    int width_inserted = source.width();
    int r = width_inserted >> 6; // pierwsze 3 bity z 9 szyfrowanych
    int g = (width_inserted >> 3) & 0x7; // & 0000 0111
    int b = width_inserted & 0x7; // & 0000 0111, ostatnie 3 bity
    pixel = qRgb(
                (qRed(pixel) & 0xF8)|r,
                (qGreen(pixel) & 0xF8)|g,
                (qBlue(pixel) & 0xF8)|b
                );
    result.setPixel(0,0,pixel);
    //(1,0) wysokosc:
    pixel = result.pixel(1,0);
    int height_inserted = source.height();
    r = height_inserted >> 6; // pierwsze 3 bity z 9 szyfrowanych
    g = (height_inserted >> 3) & 0x7; // & 0000 0111
    b = height_inserted & 0x7; // & 0000 0111, ostatnie 3 bity
    pixel = qRgb(
                (qRed(pixel) & 0xF8)|r,
                (qGreen(pixel) & 0xF8)|g,
                (qBlue(pixel) & 0xF8)|b
                );
    result.setPixel(1,0,pixel);

    const uchar * pixelsBeingInserted = source.bits();

    int encoded_bytes_count = source.byteCount();

    int result_width = result.width();

    //iterate every encoded pixel from source:
    for(int i = 0; i < encoded_bytes_count; i++)
    {
        // avoid touching alpha channel:
        if ((i%4)==3) continue;

        int color_inserted = pixelsBeingInserted[i];
        //r,g,b - to co wstawiamy w sk³adowe docelowego piksela:
        r = color_inserted >> 5; // pierwsze 3 bity szyfrowanego koloru
        g = (color_inserted >> 2) & 0x7; // & 0000 0111
        b = color_inserted & 0x3; // & 0000 0011, ostatnie 2 bity

        int result_pixel_number = i-(i/4)+2; //+2 is from width and height

        int result_y = result_pixel_number/result_width;
        int result_x = result_pixel_number - result_y*result_width ;

        // wyzerowanie bitów na których zapisujemy znak wodny:
        QRgb pixel = result.pixel(result_x,result_y);
        pixel = qRgb(
                    qRed(pixel) & 0xF8,
                    qGreen(pixel) & 0xF8,
                    qBlue(pixel) & 0xFC
                );
        //wstawienie na miejsce wyzerowanych bitów wstawianego koloru (color inserted):
        pixel = qRgb(
                     qRed(pixel) | r,
                     qGreen(pixel) | g,
                     qBlue(pixel) | b
                    );

       //wstawienie danych:
        result.setPixel(result_x,result_y, pixel);
    }
    return result;
}

QImage Encoder::extractImage(QImage encodedImage)
{
    //pobranie wymiarów zakodowanego obrazu (max 9bx9b = 512x512):
    QRgb pixel = encodedImage.pixel(0,0);
    int pixel_r = qRed(pixel) & 0x7;
    int pixel_g = qGreen(pixel) & 0x7;
    int pixel_b = qBlue(pixel) & 0x7;
    int width = (pixel_r<<6)|(pixel_g<<3)|pixel_b;

    pixel = encodedImage.pixel(1,0);
    pixel_r = qRed(pixel) & 0x7;
    pixel_g = qGreen(pixel) & 0x7;
    pixel_b = qBlue(pixel) & 0x7;
    int height = (pixel_r<<6)|(pixel_g<<3)|pixel_b;

    QImage decoded = QImage(width,height, QImage::Format_RGB32);

    int decoded_pixel = 0;
    int color_number = 0;

    int max = 2+width*height*3;

    int encoded_height=encodedImage.height();
    int encoded_width=encodedImage.width();

    for(int y=0;y<encoded_height;y++)
    {
        for(int x=0;x<encoded_width;x++)
        {
            if(y==0 && x==0)x+=2; //first 2 pixels hold width and height information

            if (y*encoded_width+x > max)
                goto end_of_encoded_data;

            decoded_pixel = (y*encodedImage.width()+x-2)/3;

            // x,y of decoded pixel:
            int decoded_y = decoded_pixel/width;
            int decoded_x = decoded_pixel - decoded_y*width;

            //get one color from encoded pixel:
            pixel = encodedImage.pixel(x,y);
            pixel_r = qRed(pixel) & 0x7;
            pixel_g = qGreen(pixel) & 0x7;
            pixel_b = qBlue(pixel) & 0x3;
            int color = (pixel_r<<5)|(pixel_g<<2)|pixel_b;


            //set correct color in correct pixel:
            pixel = decoded.pixel(decoded_x,decoded_y);
            int red = qRed(pixel);
            int green = qGreen(pixel);
            int blue = qBlue(pixel);
            switch (color_number++%3)
            {
                case 0:
//                        pixel = qRgb(
//                                    color,
//                                    green,//qGreen(decoded.pixel(decoded_x,decoded_y)),
//                                    blue //qBlue(decoded.pixel(decoded_x,decoded_y))
//                                    );
                        pixel = qRgb(
                                    red,
                                    green,//qGreen(decoded.pixel(decoded_x,decoded_y)),
                                    color //qBlue(decoded.pixel(decoded_x,decoded_y))
                                    );
                    break;
                case 1:
                        pixel = qRgb(
                                    red, //qRed(decoded.pixel(decoded_x,decoded_y)),
                                    color,
                                    blue //qBlue(decoded.pixel(decoded_x,decoded_y))
                                    );
                    break;
                case 2:
//                        pixel = qRgb(
//                                    red, //qRed(decoded.pixel(decoded_x,decoded_y)),
//                                    green, //qGreen(decoded.pixel(decoded_x,decoded_y)),
//                                    color
//                                    );
                        pixel = qRgb(
                                    color, //qRed(decoded.pixel(decoded_x,decoded_y)),
                                    green, //qGreen(decoded.pixel(decoded_x,decoded_y)),
                                    blue
                                    );
                    break;
            }
            //insert prepared pixel:
             decoded.setPixel(decoded_x,decoded_y, pixel);
        }

    }
end_of_encoded_data:
    return decoded;
}

//-----------------------------============ RSA FUNCTIONS ===========-------------------------------------

void sito(int n, bool b[]){
    for (int i=2; i<n; i++) b[i]=1; // wype³nienie tablicy jedynkami
    int k=2; // zmienna k wskazuje na kolejne liczby pierwsze - indeksy uzupelnianej tablicy
    while (k<=sqrt(n)) {
          for (int i=k;i<n;i+=k) b[i]=0; // wszystkie wielokrotnosci danej liczby pierwszej zostaja usuniete wraz z nia sama
          b[k]++;                         // wiêc dodajemy j¹ na koñcu, by nie musiec w petli wykonywac dodatkowego porownania sprawdzajacego czy nie wyszlismy poza tablice po zwiekszeniu wskaŸnika i
          do k++; while (b[k]==0);
   }
}

int nwd(int a,int b){
    int nwd;
    if (a<=b){
        nwd=b; b=a; a=nwd;
    }

    while(a!=b){
      nwd=a-b;
      if (nwd>b){
        a=nwd;
      }
      else{
        a=b; b=nwd;
      }
    }
    return nwd;
}

bool czy_wzglednie_pierwsze(int a, int b)
{
    if (nwd(a,b)==1) return true;
    else return false;
}

int losuj_wzglednie_pierwsza(int a)
{
    int wynik;

    while (!czy_wzglednie_pierwsze(wynik=(rand()%a)+2,a));

    return wynik;
}

// draw prime from range [a,b]:
int draw_prime(const int a, int b){
    int chosen_number=0;
    //srand ( time(NULL) ); // jakimœ cudem srand powinno byc w main
    int r = rand() % (b-a+1);   // r in the range [0,b-a]

    //to take [a,b] not [a,b):
    b++;

    bool *primes = new bool[b];
    sito(b,primes);

    for (int i=0; i<(b-a+1);i++)
    {
        if (primes[a + (r%(b-a+1))] == 1 )
        {
            chosen_number = a + (r%(b-a+1));
            break;
        }
    r++;
    }


    //if (chosen_number == 0)
        //printf("ERROR! No primes in this range\n");
    return chosen_number;
}

int znajdz_odwrotna(int e,int mod)
{
    int odwrotna=1;

    do
    {
        ++odwrotna;

    }while((odwrotna*e)%mod != 1);

    return odwrotna;
}

//Klucz publiczny jest definiowany jako para liczb (n, e), natomiast kluczem prywatnym jest para (n, d)
void Encoder::generate_passwords(int &e, int &d, int &n)
{
    srand ( time(NULL) );

    int p,q;

    do
    {
        //Wybieramy losowo dwie du¿e liczby pierwsze p i q (najlepiej w taki sposób,
        //aby obie mia³y zbli¿on¹ d³ugoœæ w bitach, ale jednoczeœnie by³y od siebie odleg³e
        //wartoœciami – istniej¹ lepsze mechanizmy faktoryzacji, je¿eli liczba ma dzielnik o wartoœci bliskiej )
        p=draw_prime(2,129);
        q=draw_prime(2,129);
        while(p==q)q=draw_prime(5,15);

        //Obliczamy wartoœæ n = pq
        n = p*q;
    } while (n<64 || n>256);
    //wynik musi byæ modulo [64,256] aby zakodowana liczba z zakresu [0,63] mieœci³a siê na 1 bajcie!

    //Obliczamy wartoœæ funkcji Eulera dla n:
    int E_n = (p-1)*(q-1);

    //Wybieramy liczbê e (1 < e < ?(n)) wzglêdnie pierwsz¹ z ?(n)
    e = losuj_wzglednie_pierwsza(E_n);

    //Znajdujemy liczbê d odwrotn¹ do e mod ?(n):
    d = znajdz_odwrotna(e,E_n);
}

int Encoder::moduloPower(int exponent, int n, int base)
{
    int result=1;
    while (exponent>0)
    {
        result = (result * base) % n;
        exponent--;
    }

    return result;
}

QImage Encoder::encodeImage(QImage image, int e, int n)
{
    for(int y=0; y < image.height() ;y++)
    {
        for(int x=0; x < image.width() ;x++)
        {
            QRgb pixel = image.pixel(x,y);

            //reduce to 6 bits before encoding:
            int red     = qRed(pixel) >> 2;
            int green   = qGreen(pixel) >> 2;
            int blue    = qBlue(pixel) >> 2;

            //encode:
            red     = moduloPower(e,n,red);
            green   = moduloPower(e,n,green);
            blue    = moduloPower(e,n,blue);

            pixel = qRgb(
                        red,
                        green,
                        blue
                        );
            image.setPixel(x,y, pixel);
        }
    }
    return image;
}

QImage Encoder::decodeImage(QImage encodedImage, int d, int n)
{
    for(int y=0; y < encodedImage.height() ;y++)
    {
        for(int x=0; x < encodedImage.width() ;x++)
        {
            QRgb pixel = encodedImage.pixel(x,y);

            int red     = qRed(pixel);
            int green   = qGreen(pixel);
            int blue    = qBlue(pixel);

            //decode:
            red     = moduloPower(d,n,red)<<2;
            green   = moduloPower(d,n,green)<<2;
            blue    = moduloPower(d,n,blue)<<2;

            pixel = qRgb(
                        red,
                        green,
                        blue
                        );
            encodedImage.setPixel(x,y, pixel);
        }
    }
    return encodedImage;
}
