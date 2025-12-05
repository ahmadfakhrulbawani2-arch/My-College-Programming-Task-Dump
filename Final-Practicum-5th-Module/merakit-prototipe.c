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
#define POSINT 100000000
#define NEGINT -100000000
#define NEGLL -1000000000000000000
#define POSLL 1000000000000000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define DECISI(a, b) ((a > b) ? (1) : (2))
#define REP2(i, m, n) for(ll i = m; i <= n; i++) // change i with var. name.
#define REP1(i, m, n) for(ll i = m; i < n; i++) // change i with var. name.
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90
#define ASCII0 48
#define ASCII9 57
#define AWAL int main(void) {
#define AKHIR return 0;}


#define MOD 1000000007

static inline int addmod(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

static inline int submod(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

AWAL

    int N, K, P;
    if (scanf("%d %d %d", &N, &K, &P) != 3) return 0;

    int *a = (int*)malloc(sizeof(int) * N);
    int *b = (int*)malloc(sizeof(int) * N);

    int i;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    int rows = K + 1;
    int cols = P + 1;
    int size = rows * cols;

    int *old = (int*)malloc(sizeof(int) * size);
    int *nw  = (int*)malloc(sizeof(int) * size);

    memset(old, 0, sizeof(int) * size);
    old[0] = 1; 

    int *pref = (int*)malloc(sizeof(int) * 1200);

    // DP per item
    for (i = 0; i < N; i++) {
        int ai = a[i];
        int bi = b[i];

        memset(nw, 0, sizeof(int) * size);

        if (bi == 0) {
            int p, k;

            for (p = 0; p <= P; p++) {
                pref[0] = old[p];

                for (k = 1; k <= K; k++) {
                    pref[k] = addmod(pref[k-1], old[k * (P+1) + p]);
                }

                for (k = 0; k <= K; k++) {
                    int L = k - ai - 1;
                    int v = pref[k];
                    if (L >= 0) v = submod(v, pref[L]);
                    nw[k * (P+1) + p] = v;
                }
            }

            int *tmp = old; old = nw; nw = tmp;
            continue;
        }

        int r;
        for (r = 0; r < bi; r++) {
            int s_max = (P - r) / bi;
            if (s_max < 0) continue;

            int d;
            for (d = -s_max; d <= K; d++) {

                int sL = 0;
                if (sL < -d) sL = -d;

                int sR = s_max;
                int ttmp = K - d;
                if (sR > ttmp) sR = ttmp;

                if (sL > sR) continue;

                int len = sR - sL + 1;

                int t;
                for (t = 0; t < len; t++) {
                    int s = sL + t;
                    int k = s + d;
                    int p = s * bi + r;
                    int pos = k * (P + 1) + p;
                    int v = old[pos];

                    pref[t] = v;
                    if (t > 0) pref[t] = addmod(pref[t], pref[t-1]);
                }

                for (t = 0; t < len; t++) {
                    int left = t - ai;
                    int val = pref[t];
                    if (left - 1 >= 0) val = submod(val, pref[left-1]);

                    int s = sL + t;
                    int k = s + d;
                    int p = s * bi + r;
                    nw[k * (P+1) + p] = val;
                }
            }
        }

        int *tmp = old; old = nw; nw = tmp;
    }

    printf("%d\n", old[K * (P+1) + P]);

    free(a);
    free(b);
    free(old);
    free(nw);
    free(pref);

AKHIR
