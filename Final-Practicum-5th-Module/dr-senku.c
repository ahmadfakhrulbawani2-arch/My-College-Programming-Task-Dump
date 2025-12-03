// the explanation is in the bottom
// Bismillahirrahmanirrahim
// dengan menyebut nama Allah Subhanahuwata'ala yang Mahapengasih lagi Mahapenyayang.

// Header doang banyak, tapi gak dipake awokawokawoawok
#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

//  Terusin tambahin define terus sampai meleduck wkkwkkkwkwkw
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int usi;
#define POSINF 100000000
#define NEGINF -100000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90

int generatePrime(int primeNum[], int n) {
    int idx = 0;
    for(int i = 2; i <= n; i++) {
        bool isPrime = true;
        for(int j = 2; j*j <= i; j++) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            primeNum[idx++] = i;
        }
    }
    return idx;
}

int isIn(int r, int primeNum[], int size) {
    if(r <= 1) return 0;

    for(int i = 0; i < size; i++) {
        if(r == primeNum[i]) return 1;
    }
    return 0;
}

void aturB(char roomSec[], char rCode, int len) {

    for(int i = 0; i < len; i += 2) {
        // aturA
        switch (rCode) {
        case 'A':
            roomSec[i] = 'C';
            break;
        case 'B':
            roomSec[i] = 'A';
            break;
        case 'C':
            roomSec[i] = 'B';
            break;
        default:
            break;
        }
    }

    for(int i = 1; i < len; i += 2) {
        roomSec[i] = rCode;
    }
}

void aturA(char roomSec[], char rCode, int len) {
    char toSet = 'X'; // default kalau rCode tidak valid
    switch (rCode)
    {
    case 'A': toSet = 'C'; break;
    case 'B': toSet = 'A'; break;
    case 'C': toSet = 'B'; break;
    }
    for(int i = 0; i < len; i ++) {
        roomSec[i] = toSet;
    }
}


int main(void) {
    int n, r;
    char kodeR;
    scanf("%d %d", &n, &r);
    scanf(" %c", &kodeR);

    int primeNum[1000]; // actual size should be 25, let's pick max instead and pick the actual size later

    int actualPrimeSize = generatePrime(primeNum, n);

    int cekPrime = isIn(r, primeNum, actualPrimeSize);

    char roomSec[n+1]; roomSec[n] = '\0';

    if(n & 1) {
        aturB(roomSec, kodeR, n);
    } else {
        aturA(roomSec, kodeR, n);
    }

    roomSec[r-1] = kodeR;


    if(cekPrime) {
        for(int i = 0; i < n; i++) {
            int roomNo = i+1;
            if(roomNo != r && isIn(roomNo, primeNum, actualPrimeSize)) {
                switch(roomSec[i]) { 
                    case 'A': roomSec[i] = 'B'; break;
                    case 'B': roomSec[i] = 'C'; break;
                    case 'C': roomSec[i] = 'A'; break;
                }
            }
        }
    }



    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(roomSec[i] == kodeR && i != r-1) cnt++;
    }

    printf("%d\n", cnt);
    // printf("%d", cekPrime);
    // printf("%s", roomSec);

    return 0;
}

// EXPLANATION

/*

in:
5 3
B

Out:
2

Jadi n = 5 (ganjil) sehingga

ruangan 2 & 4 adalah B (sama dengan r - aturan B)
Untuk ruangan 1, 5 adalah A dan 3 yaitu ruang r adalah B.

1 2 3 4 5 
A B B B A   

lalu karena r = 3 (prima) maka
ruang 2 adalah C dan ruang 5 adalah B


akhirnya
1 2 3 4 5 
A C B B B

jadi ada 2 ruang lain yang berkode sama dengan r.

Kita bisa buat array of char dari sini dimana index nya adalah nomor ruang, lalu terapkan maksimal 3 kali aturan. Dan maksimum teoretis 300 iterasi (aman).

Kita bisa simpan angka prima dalam array juga dengan cara generate atau kita langsung buat.


4 2 
A

aturA karena n genap

1 2 3 4
C A C C

aturPrime karena r prima

1 2 3 4 
C A B C

it must ouput 0!


*/