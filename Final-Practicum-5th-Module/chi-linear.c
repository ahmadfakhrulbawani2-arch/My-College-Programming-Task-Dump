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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int impossibility(int a, int b, int x) {
    int y = gcd(a, b);
    if(x > FNDMAX(a, b)) return 1;
    if(x % y != 0) return 1;
    else return 0;
}

// isi penuh terus kurangi
int isiABro1(int *a, int b, int x, int *step) {
    *step += 1;
    while(*a > x) {
        *a -= b;
        *step += 1;
        if(*a == x) break;
        if(*a != x) *step += 1;
    }
    if(*a == x) return 1;
    else return 0;
}

// set nol terus tambah terus
int isiABro2(int a, int *b, int x, int *step) {
    *b = 0;
    while(*b < x) {
        *b += a;
        *step += 2;
    }
    if(*b == x) return 1;
    else return 0;
}

int isiBBro1(int a, int *b, int x, int *step) {
    *step += 1;
    while(*b > x) {
        *b -= a;
        *step += 1;
        if(*b == x) break;
        if(*b != x) *step += 1;
    }
    if(*b == x) return 1;
    else return 0;
}

int isiBBro2(int *a, int b, int x, int *step) {
    *a = 0;
    while(*a < x) {
        *a += b;
        *step += 2;
    }
    if(*a == x) return 1;
    else return 0;
}

void solve() {
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);

    if(impossibility(a, b, x)) {
        printf("IMPOSSIBLE\n");
        return;
    }

    if(a == x || b == x) {
        printf("1\n");
        return;
    }

    int isTrue1, isTrue2, step1 = 0, step2 = 0;
    if(a > b) {
        isTrue1 = isiABro1(&a, b, x, &step1);
        isTrue2 = isiBBro2(&a, b, x, &step2);
    } else {
        isTrue1 = isiBBro1(a, &b, x, &step1);
        isTrue2 = isiABro2(a, &b, x, &step2);
    }

    if(!isTrue1) step1 = POSINF;
    if(!isTrue2) step2 = POSINF;
    int min = FNDMIN(step1, step2);

    if(isTrue1 || isTrue2) {
        printf("%d\n", min);
        // printf("step1: %d, step2: %d\n", step1, step2);
    } else {
        printf("IMPOSSIBLE\n");
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
}

//
/*

2 10 4

ietrasi 1: (6 energi)
A B
0 10

A B
2 8

A B
0 8

A B 
2 6

A B
0 6

A B 
2 4


iterasi 2: (this is 4 energy, actual anwser)

A B
2 0

A B
0 2

A B
2 2

A B
0 4


*/