// the explanation is in the bottom
// Bismillahirrahmanirrahim
// dengan menyebut nama Allah Subhanahuwata'ala yang Mahapengasih lagi Mahapenyayang.

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

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#define POSINF 100000000
#define NEGINF -100000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90

int main(void) {
    ull a, b, c, x, y;
    scanf("%llu %llu %llu %llu %llu", &a, &b, &c, &x, &y);
    ull bungaLebah = a + c;
    if(bungaLebah >= x) {
        ll sisaMari = x - a;
        if (sisaMari < 0) sisaMari = 0; 
        sisaMari = c - sisaMari;
        if(sisaMari + b >= y) {
            printf("Okay, okay, okay, okay, okay, okay, gas bagiin ae Teto\n");
        } else {
            printf("WEH TAHAN DULU TETO, JAN DIBAGIIN DULU!\n");
        }
    } else {
        printf("WEH TAHAN DULU TETO, JAN DIBAGIIN DULU!\n");
    }
    return 0;
}