#include <stdio.h>

int main() {
    int d1, h1, m1, d2, h2, m2;
    char tipe, bayar;
    scanf("%d %d:%d\n%d %d:%d\n%c\n%c", &d1, &h1, &m1, &d2, &h2, &m2, &tipe, &bayar);

    if(d2 < d1) {
        printf("Tidak mungkin");
        return 0;
    }
    if(d2 == d1 && (h2 < h1)) {
        printf("Tidak mungkin");
        return 0;
    }
    if(d2 == d1 && h2 == h1 && (m2 < m1)) {
        printf("Tidak mungkin");
        return 0;
    }

    int menit1 = 0, menit2 = 0, durasi = 0;
    menit1 = menit1 + (d1 * 1440) + (h1 * 60) + m1;
    menit2 = menit2 + (d2 * 1440) + (h2 * 60) + m2;
    durasi = menit2 - menit1;
    
    int hari = durasi / 1440;
    int jam = (durasi - hari * 1440) / 60;
    int menit = durasi - (hari * 1440) - (jam * 60);
    printf("Anda telah berada di sini selama %d hari, %d jam, dan %d menit. Anda harus membayar sebesar ", hari, jam, menit);

    int hargaTotal = 0;
    switch (tipe)
    {
    case 'M':
        if(hari >= 1) {
            if(menit > 0) {
                ++jam;
            }
            hargaTotal = 10000 + (jam * 2000) + (hari * 150000);
        } else {
            if(menit > 0) {
                ++jam;
            }
            if(jam >= 3) {
                hargaTotal = 10000 + (jam - 3) * 2000;
            } else {
                hargaTotal = 10000;
            }
        }
        break;
    case 'S':
        if(hari > 1) {
            hargaTotal = hargaTotal + 3000 + (hari * 50000);
        } else {
            hargaTotal = 3000;
        }
        break;
    default:
        break;
    }
    
    switch (bayar)
    {
    case 'a':
        printf("%d rupiah", hargaTotal);
        break;
    case 'b':
        if(hargaTotal >= 50000) {
            hargaTotal -= 10000;
            printf("%d rupiah", hargaTotal);
        } else {
            hargaTotal = hargaTotal * 0.8;
            printf("%d rupiah", hargaTotal);
        }
        break;
    case 'c':
        if(hargaTotal >= 200000) {
            hargaTotal -= 20000;
            printf("%d rupiah", hargaTotal);
        } else {
            hargaTotal = hargaTotal * 0.9;
            printf("%d rupiah", hargaTotal);
        }
        break;
    default:
        break;
    }
    
    return 0;
}