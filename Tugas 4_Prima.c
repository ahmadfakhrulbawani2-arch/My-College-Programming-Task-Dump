#include <stdio.h>
#include <math.h>

int main() {
    int cek = 0;
    for(int i = 1; i < 10000000; i++) {
        int rooti = sqrt(i);
        for(int j = 2; j <= rooti; j++) {
            if(i % j == 0) {
                cek = 0;
                break;
            } else {
                cek = 1;
            }
        }
        if(cek == 1 || i == 2 || i == 3) {
            printf("%d ", i);
        }
    }
    return 0;
}