// the explanation is in the bottom

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdint-gcc.h>

#define POSINF 100000000
#define NEGINF -100000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90

typedef long long ll;

typedef struct {
    char nama[105];
    int harga;
    int stok;
} Barang;

int cmpHarga(const void *a, const void *b) {
    const Barang *Ba = a;
    const Barang *Bb = b;
    return (Ba->harga > Bb->harga) - (Ba->harga < Bb->harga);
}

int cmpStok(const void *a, const void *b) {
    const Barang *BA = a;
    const Barang *BB = b;
    return (BA->stok < BB->stok) - (BA->stok > BA->stok);
}

void findMaxStock(Barang arrOfBarang[], int n) {
    Barang temp[n];
    memcpy(temp, arrOfBarang, n * sizeof(Barang));
    qsort(temp, n, sizeof(Barang), cmpStok);

    printf("%s %d %d\n", temp[0].nama, temp[0].harga, temp[0].stok);
    return;
}

void solve(Barang arrOfBarang[], int n) {
    char cmd[50];
    scanf("%s", cmd);

    if(!strcmp(cmd, "SWAP")) {
        int idx1, idx2;
        scanf("%d %d", &idx1, &idx2);
        Barang temp = arrOfBarang[idx1];
        arrOfBarang[idx1] = arrOfBarang[idx2];
        arrOfBarang[idx2] = temp;
        return;
    }

    if(!strcmp(cmd, "UPDATE")) {
        int idx, newHarga, newStok;
        scanf("%d %d %d", &idx, &newHarga, &newStok);
        arrOfBarang[idx].harga = newHarga;
        arrOfBarang[idx].stok = newStok;
        return;
    }

    if(!strcmp(cmd, "SORT")) {
        qsort(arrOfBarang, n, sizeof(Barang), cmpHarga);
        return;
    }

    if(!strcmp(cmd, "PRINT")) {
        for(int i = 0; i < n; i++) {
            printf("%s %d %d\n", arrOfBarang[i].nama, arrOfBarang[i].harga, arrOfBarang[i].stok);
        }
        return;
    }

    if(!strcmp(cmd, "MAXSTOCK")) {
        findMaxStock(arrOfBarang, n);
        return;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    Barang arrOfBarang[n];

    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", arrOfBarang[i].nama, &arrOfBarang[i].harga, &arrOfBarang[i].stok);
    }

    int m;
    scanf("%d", &m);
    while(m--) {
        solve(arrOfBarang, n);
    }
    return 0;
}