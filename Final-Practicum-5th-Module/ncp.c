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

void TOH(int n, int A, int B, int C, int *totCost) {
    int currCost = 0;

    if(n == 1) {
        printf("Crate 1, Zone %d -> Zone %d ", A, C);
        currCost += ((abs(C - A)) * n);
        printf("(Cost: %d)\n", currCost);
        *totCost += currCost;
        return;
    }

    TOH(n-1, A, C, B, totCost);
    printf("Crate %d, Zone %d -> Zone %d ", n, A, C);
    currCost += ((abs(C - A)) * n);
    printf("(Cost: %d)\n", currCost);
    *totCost += currCost;
    TOH(n-1, B, A, C, totCost);
}

int main(void) {
    int n, totalCost = 0;
    scanf("%d", &n);
    TOH(n, 1, 2, 3, &totalCost);
    printf("%d", totalCost);
    return 0;
}
// Use Tower of Hanoi