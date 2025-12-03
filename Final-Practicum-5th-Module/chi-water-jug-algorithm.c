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
    else return gcd(b, a % b);
}

int pour(int start, int end, int target) {
    int from = start;
    int to = 0;

    int step = 1;

    while(from != target && to != target) {
        int tmp = FNDMIN(from, (end - to));

        to += tmp;
        from -= tmp;
        step++;

        if(from == target || to == target) break;

        if(!from) {
            from = start;
            step++;
        }

        if(to == end) {
            to = 0;
            step++;
        }
    }
    return step;
}

void showMins(int a, int b, int x) {

    if(x > FNDMAX(a, b) || x % gcd(a, b) != 0) {
        printf("IMPOSSIBLE\n");
        return;
    }

    int res1 = pour(b, a, x), res2 = pour(a, b, x);
    int actualMin = FNDMIN(res1, res2);
    printf("%d\n", actualMin);
}

void main2() {
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    showMins(a, b, x);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        main2();
    }
    return 0;
}