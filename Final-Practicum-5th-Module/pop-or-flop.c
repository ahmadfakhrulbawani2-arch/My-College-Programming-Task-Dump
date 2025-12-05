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
#define NEGLL -1000000000000000000
#define POSLL 1000000000000000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define DECISI(a, b) ((a > b) ? (1) : (2))
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90

ll dp[605][605];
int primes[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1};

ll calcGcd(int a, int b) {
    if(b == 0) return a;
    return calcGcd(b, a % b);
}

ll infoSkor(int k, int l, int r, int me[]) {
    int lNeighbor = me[l-1];
    int rNeighbor = me[r+1];

    if(primes[me[k]]) {
        return 1LL * me[k] * 2 * calcGcd(lNeighbor, rNeighbor);
    } else {
        return 1LL * lNeighbor * me[k] * rNeighbor;
    }
}

ll dfs(int l, int r, int me[]) {
    if(l > r) return 0;

    if(dp[l][r] != NEGLL) return dp[l][r];

    ll best = NEGLL;

    for(int k = l; k <= r; k++) {
        ll left = dfs(l, k-1, me);
        ll right = dfs(k+1, r, me);
        ll curr = infoSkor(k, l, r, me);

        best = FNDMAX(best, left + right + curr);
    }

    dp[l][r] = best;

    return dp[l][r];
}

ll solve(int me[], int len) {

    for(int i = 0; i < 605; i++) {
        for(int j = 0; j < 605; j++) {
            dp[i][j] = NEGLL;
        }
    }

    return dfs(1, len - 2, me);

}

int main(void) {

    int n;
    scanf("%d", &n);
    int me[n+2]; me[0] = 1; me[n+1] = 1;
    for(int i = 1; i <= n; i++) scanf("%d", &me[i]);
    int len1 = n + 2;
    ll maxMe = solve(me, len1);

    int m;
    scanf("%d", &m);
    int him[m+2]; him[0] = 1; him[m+1] = 1;
    for(int i = 1; i <= m; i++) scanf("%d", &him[i]);
    int len2 = m + 2;
    ll maxHim = solve(him, len2);

    if(maxHim == maxMe) {
        printf("Draw: %lld = %lld", maxMe, maxHim);
    } else if(maxMe > maxHim) {
        printf("Pop: %lld > %lld", maxMe, maxHim);
    } else printf("Flop: %lld < %lld", maxMe, maxHim);

    return 0;
}
// leetcode baloon burst problem