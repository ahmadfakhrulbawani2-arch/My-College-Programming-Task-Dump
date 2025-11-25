#include <stdio.h>

int main() {
    int d1, h1, m1, d2, h2, m2;
    char type, bayar;
    scanf("%d %d:%d\n%d %d:%d\n%c\n%c", &d1, &h1, &m1, &d2, &h2, &m2, &type, &bayar);

    if(h2 - h1 < 0 && d2 - d1 < 0) {
        printf("Tidak mungkin");
        return 0;
    }

    long long hargaAwal = 0;

    int jamtotal = 0;
    int mtotal = 0;
    int htotal = 0;
    if(type == 'M') {
        if(d2 - d1 == 0) {
            if(m2 - m1 >= 0) {
                jamtotal = jamtotal + (h2 - h1);
            } else if(m2 - m1 < 0) {
                --h2;
                jamtotal = jamtotal + (h2 - h1);
            }

            if (jamtotal <= 3) {
                hargaAwal += 10000;
            } else if(jamtotal > 3) {
                hargaAwal += 10000;
                hargaAwal = hargaAwal + (jamtotal - 3) * 2000;
            }
        } else if(d2 - d1 > 0) {
            if(h2 - h1 < 0) {
                htotal = d2 - d1 - 1;
                jamtotal = h1 - h2;
            } else if(h2 - h1) {
                htotal = d2 - d1;
                jamtotal = h2 - h1;
            }

            hargaAwal += 10000;
            hargaAwal = hargaAwal + 150000 * htotal + jamtotal * 2000;
        }
    } else if(type == 'S') {
        if(d2 - d1 == 0) {
            if(m2 - m1 >= 0) {
                jamtotal = jamtotal + (h2 - h1);
            } else if(m2 - m1 < 0) {
                --h2;
                jamtotal = jamtotal + (h2 - h1);
            }

            hargaAwal += 3000;
        } else if(d2 - d1 > 0) {
            if(h2 - h1 < 0) {
                htotal = d2 - d1 - 1;
                jamtotal = h1 - h2;
            } else if(h2 - h1) {
                htotal = d2 - d1;
                jamtotal = h2 - h1;
            }

            hargaAwal += 3000;
            hargaAwal += htotal * 50000;
        }
    }

    if(m2 - m1 >= 0) {
        mtotal = m2 - m1;
    } else if(m2 - m1 < 0) {
        mtotal = (60 + m2) - m1;
    }

    printf("Anda telah berada di sini selama %d hari, %d jam, dan %d menit. Anda harus membayar sebesar ", htotal, jamtotal, mtotal);
    if(bayar == 'a') {
        printf("%lld rupiah", hargaAwal);
    } else if(bayar == 'b') {
        if(hargaAwal >= 50000) {
            hargaAwal -= 10000;
            printf("%lld rupiah", hargaAwal);
        } else {
            hargaAwal *= 0.8;
            printf("%lld rupiah", hargaAwal);
        }
    } else if(bayar == 'c') {
        if(hargaAwal >= 200000) {
            hargaAwal -= 20000;
            printf("%lld rupiah", hargaAwal);
        } else {
            hargaAwal *= 0.9;
            printf("%lld rupiah", hargaAwal);
        }
    }
    return 0;
}
