#include <stdio.h>
#include <math.h>

typedef struct{
    double real;
    double imaginary;
} hasilComplex;

void printAll(hasilComplex rootComplex1, hasilComplex rootComplex2) {
    if(rootComplex1.imaginary > 0) {
        printf("X1 = %.2lf + %.2lf i\n", rootComplex1.real, rootComplex1.imaginary);
    } 
    if(rootComplex2.imaginary > 0) {
        printf("X2 = %.2lf + %.2lf i\n", rootComplex2.real, rootComplex2.imaginary);
    }
    if(rootComplex1.imaginary < 0) {
        rootComplex1.imaginary *= -1;
        printf("X1 = %.2lf - %.2lf i\n", rootComplex1.real, rootComplex1.imaginary);
    } 
    if(rootComplex2.imaginary < 0) {
        rootComplex2.imaginary *= -1;
        printf("X2 = %.2lf - %.2lf i\n", rootComplex2.real, rootComplex2.imaginary);
    }
}

double akarKuadrat1(double a, double b, double c) {
    return ((-1 * b) + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
}

double akarKuadrat2(double a, double b, double c) {
    return ((-1 * b) - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
}
double akarKuadrat3(double a, double b) {
    return ((-1 * b) / (2 * a));
}
double akarKuadrat4(double diskrim, double a) {
    return (sqrt(diskrim) / (2 * a));
}
double akarKuadrat5(double diskrim, double a) {
    return -1 * (sqrt(diskrim) / (2 * a));
}

int main() {
    hasilComplex rootComplex1, rootComplex2;

    double a = 0, b = 0, c = 0;
    double im1, im2;
    double diskrim;
    printf("Masukkan koefisien persamaan kuadrat> ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if(pow(b, 2) - (4 * a * c) >= 0) {
        rootComplex1.real = akarKuadrat1(a, b, c);
        rootComplex2.real = akarKuadrat2(a, b, c);    
        printf("X1 = %.2lf\n", rootComplex1.real);
        printf("X2 = %.2lf\n", rootComplex2.real);
    } else {
        diskrim = -1 * (pow(b, 2) - (4 * a * c));
        rootComplex1.real = akarKuadrat3(a, b);
        rootComplex2.real = akarKuadrat3(a, b);
        rootComplex1.imaginary = akarKuadrat4(diskrim, a);
        rootComplex2.imaginary = akarKuadrat5(diskrim, a);

        printAll(rootComplex1, rootComplex2);
    }

    return 0;
}