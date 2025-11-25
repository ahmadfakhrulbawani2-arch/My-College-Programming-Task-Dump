#include <stdio.h>

int main() {
    int x = 0, y = 0, z = 0;
    scanf("%d %d %d", &x, &y, &z);

    if(x <= 0 || y <= 0 || z <= 0) {
        printf("Tidak dapat menjadi segitiga.\n");
    } else if(x + y <= z || x + z <= y || y + z <= x) {
        printf("Tidak dapat menjadi segitiga.\n");
    } else if(x == y && y == z) {
        printf("Dapat menjadi segitiga, yaitu segitiga sama sisi.\n");
    } else if(x*x == y*y + z*z || y*y == x*x + z*z || z*z == x*x + y*y) {
        printf("Dapat menjadi segitiga, yaitu segitiga siku-siku.\n");
    } else if(x == y || x == z || y == z) {
        printf("Dapat menjadi segitiga, yaitu segitiga sama kaki.\n");
    } else {
        printf("Dapat menjadi segitiga, yaitu segitiga sembarang.\n");
    }

    return 0;
}
