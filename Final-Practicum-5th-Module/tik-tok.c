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
typedef unsigned int usi;
#define POSINF 100000000
#define NEGINF -100000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90

int solve() {
    int n;
    scanf("%d", &n); int isValid = 0;
    if(n == 0) {
        printf("Y\n");
        isValid = 1;
    }

    for(int i = 1; i <= 720 && isValid != 1; i++) {
        int sudutMnt = i * 6;
        sudutMnt %= 360;
        int sudutJam = (i / 12) * 6;
        sudutJam %= 360;
        int netSudut = abs(sudutMnt - sudutJam);
        if(netSudut > 180) netSudut = 360 - netSudut;
        if(netSudut == n) {
            printf("Y\n");
            isValid = 1;
            break;
        }
    }
    
    if(!isValid) printf("N\n");
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
} 