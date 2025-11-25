// // [Tugas 5: Operasi Aritmatika pada Struct Bilangan Kompleks]

// #include <stdio.h>

// #define ll long long

// typedef struct {
//     double reZ;
//     double imZ;
// } zNum;

// void showComplex(zNum input) {
//     double a = input.reZ;
//     double b = input.imZ;

//     if(b >= 0) {
//         printf("%.5lf + %.5lf i", a, b);
//     } else {
//         b *= -1;
//         printf("%.5lf - %.5lf i", a, b);
//     }
// }

// void showRes(zNum hasil) {
//     printf("\nHasilnya: Z = "); showComplex(hasil); printf("\n");
// }

// int main(void) {
//     zNum input1, input2, hasil;
//     printf("\n=== Operasi Aritmatika Bilangan Kompleks ===\n");
//     printf("\nMasukkan bilangan a dan b sebagai bilangan kompleks Z = a + bi: \n");

//     printf("\nMasukkan bilangan pertama (nyatakan dalam decimal bukan pecahan atau karakter): \n");
//     printf("a = "); scanf("%lf", &input1.reZ);
//     printf("b = "); scanf("%lf", &input1.imZ);

//     printf("\nMasukkan bilangan kedua (nyatakan dalam decimal bukan pecahan atau karakter): \n");
//     printf("a = "); scanf("%lf", &input2.reZ);
//     printf("b = "); scanf("%lf", &input2.imZ);

//     printf("\nBilangan pertama yang anda masukkan: Z = "); showComplex(input1);
//     printf("\nBilangan kedua yang anda masukkan: Z = "); showComplex(input2); printf("\n");

//     printf("\n=== Operasi Artimatika [Ketelitian 10^-5] ===\n");;

//     printf("\nPenjumlahan: \n"); // f(a + bi, c + di) = (a + b) + (b + d)i
//     printf("("); showComplex(input1); printf(")"); printf(" + "); printf("("); showComplex(input2); printf(")"); printf("\n");
//     hasil.reZ = (input1.reZ) + (input2.reZ);
//     hasil.imZ = (input1.imZ) + (input2.imZ);

//     showRes(hasil);

//     printf("\nPengurangan: \n"); // f(a + bi, c + di) = (a - b) + (b - d)i
//     printf("("); showComplex(input1); printf(")"); printf(" - "); printf("("); showComplex(input2); printf(")"); printf("\n");
//     hasil.reZ = (input1.reZ) - (input2.reZ);
//     hasil.imZ = (input1.imZ) - (input2.imZ);

//     showRes(hasil);

//     printf("\nPerkalian: \n"); // f(a + bi, c + di) = (ac - bd) + (ad + bc)i; a = input1.reZ, b = input1.imZ, c = input2.reZ, d = input2.imZ
//     printf("("); showComplex(input1); printf(")"); printf(" X "); printf("("); showComplex(input2); printf(")"); printf("\n");
//     hasil.reZ = (input1.reZ * input2.reZ) - (input1.imZ * input2.imZ);
//     hasil.imZ = (input1.reZ * input2.imZ) + (input1.imZ * input2.reZ);

//     showRes(hasil);

//     printf("\nPembagian: \n"); // f(a + bi, c + di) = ((ac + bd)/(c^2 + d^2)) + ((bc - ad)/(c^2 + d^2))i; Gak bisa digabung soalnya 2 komponen yang berbeda. Tapi pembaginya sama.
//     printf("("); showComplex(input1); printf(")"); printf(" : "); printf("("); showComplex(input2); printf(")"); printf("\n");

//     double divisor = (input2.reZ * input2.reZ) + (input2.imZ * input2.imZ); // c^2 + d^2
//     hasil.reZ = ((input1.reZ * input2.reZ) + (input1.imZ * input2.imZ)) / divisor;
//     hasil.imZ = ((input1.imZ * input2.reZ) - (input1.reZ * input2.imZ)) / divisor;

//     showRes(hasil);

//     return 0;
// } Versi tanpa smooth print, lebih cepat

#include <stdio.h>
#include <windows.h>  // for sleep()

typedef struct {
    double reZ;
    double imZ;
} zNum;

void showComplex(zNum input) {
    double a = input.reZ;
    double b = input.imZ;

    if(b >= 0) {
        printf("%.5lf + %.5lf i", a, b);
    } else {
        b *= -1;
        printf("%.5lf - %.5lf i", a, b);
    }
}

void showRes(zNum hasil) {
    printf("\nHasilnya: Z = ");
    showComplex(hasil);
    printf("\n");
    Sleep(350);
}

void smoothPrint(char *text, int ms) {
    while (*text) {
        printf("%c", *text++);
        fflush(stdout);
        Sleep(ms);
    }
}

int main(void) {
    zNum input1, input2, hasil;

    smoothPrint("\n=== Operasi Aritmatika Bilangan Kompleks ===\n", 25);

    smoothPrint("\nMasukkan bilangan a dan b sebagai bilangan kompleks Z = a + bi:\n", 25);

    smoothPrint("\nMasukkan bilangan pertama (tanpa spasi, koma dengan .):\n", 15);
    printf("Z1 = "); scanf("%lf", &input1.reZ); scanf("%lf", &input1.imZ);
    getchar();
    smoothPrint("\nMasukkan bilangan kedua (tanpa spasi):\n", 15);
    printf("Z2 = "); scanf("%lf", &input2.reZ); scanf("%lf", &input2.imZ);

    smoothPrint("\n=== Operasi Aritmatika [Ketelitian 10^-5] ===\n", 25);

    // Penjumlahan
    smoothPrint("\nPenjumlahan:\n", 20);
    printf("("); showComplex(input1); printf(") + ("); showComplex(input2); printf(")\n");
    hasil.reZ = input1.reZ + input2.reZ;
    hasil.imZ = input1.imZ + input2.imZ;
    showRes(hasil);

    // Pengurangan
    smoothPrint("\nPengurangan:\n", 20);
    printf("("); showComplex(input1); printf(") - ("); showComplex(input2); printf(")\n");
    hasil.reZ = input1.reZ - input2.reZ;
    hasil.imZ = input1.imZ - input2.imZ;
    showRes(hasil);

    // Perkalian
    smoothPrint("\nPerkalian:\n", 20);
    printf("("); showComplex(input1); printf(") x ("); showComplex(input2); printf(")\n");
    hasil.reZ = (input1.reZ * input2.reZ) - (input1.imZ * input2.imZ);
    hasil.imZ = (input1.reZ * input2.imZ) + (input1.imZ * input2.reZ);
    showRes(hasil);

    // Pembagian
    smoothPrint("\nPembagian:\n", 20);
    printf("("); showComplex(input1); printf(") : ("); showComplex(input2); printf(")\n");

    double divisor = input2.reZ * input2.reZ + input2.imZ * input2.imZ;
    hasil.reZ = ((input1.reZ * input2.reZ) + (input1.imZ * input2.imZ)) / divisor;
    hasil.imZ = ((input1.imZ * input2.reZ) - (input1.reZ * input2.imZ)) / divisor;
    showRes(hasil);
    printf(" \n");

    return 0;
}
