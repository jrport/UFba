#include <math.h>
extern double media_aritimetica(int, int, int);
extern double media_geometrica(int, int, int);
extern double media_harmonica(int, int, int);

double media_aritimetica(int a, int b, int c) {
    double media;
    media = ((double)(a + b + c) )/3;
    return media;
}


double media_geometrica(int a, int b, int c) {
    double media;
    media = (cbrt(a * b * c));
    return media;
}


double media_harmonica(int a, int b, int c) {
    double media;
    media = (3.0 / ((1.0 / ((double)a)) + (1.0 / ((double)b)) + (1.0 / ((double)c))));
    return media;
}
