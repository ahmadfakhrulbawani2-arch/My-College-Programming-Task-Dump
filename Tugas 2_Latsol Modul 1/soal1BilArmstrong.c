#include <stdio.h>

int main() {
    int n = 0;
    int bil;
    scanf("%d", &bil);

    int ratus = (int)bil / 100;
    int puluh = (bil % 100) / 10;
    int satuan = bil % 10;

    if(bil >= 100) {
        n = 3;
    } else if(bil >= 10 && bil < 100) {
        n = 2;
    } else {
        n = 1;
    }

    int arms;
    switch(n) {
        case 3:
            arms = ratus * ratus * ratus + puluh * puluh * puluh + satuan * satuan * satuan;
            break;
        case 2:
            arms = ratus * ratus + puluh * puluh + satuan * satuan;
            break;
        case 1:
            arms = ratus + puluh + satuan;
            break;
    }

    if(arms == bil) {
        printf("Merupakan Bilangan Armstrong");
    } else {
        printf("Bukan Merupakan Bilangan Armstrong");
    }

    return 0;
}