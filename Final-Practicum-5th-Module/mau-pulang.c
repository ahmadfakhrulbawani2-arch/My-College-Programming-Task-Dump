// Bismillahirrahmanirrahim

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

typedef struct {
    int r, c, dist;
} Pos;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int n;

int bfsAlgorithm(int map[n][n]) {
    int visited[n][n];
    memset(visited, 0, sizeof(visited));

    Pos queue[n*n];
    int front = 0, back = 0;

    // jika start bukan 1 → tidak ada jalan
    if (map[0][0] == 0) return POSINF;

    // push start
    queue[back++] = (Pos){0, 0, 0};
    visited[0][0] = 1;

    while (front < back) {
    Pos current = queue[front++];

        if (current.r == n-1 && current.c == n-1) return current.dist;

        for (int i = 0; i < 4; i++) {
            int nr = current.r + dr[i];
            int nc = current.c + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            if (map[nr][nc] == 0) continue;
            if (visited[nr][nc]) continue;

            visited[nr][nc] = 1;
            queue[back++] = (Pos){nr, nc, current.dist + 1};
        }
    }

    return POSINF;
}

int main(void) {
    scanf("%d", &n);

    int map[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int best = bfsAlgorithm(map);

    if (best == POSINF) printf("Dahlah gajadi balik\n");
    else printf("%d menit doang\n", best);

    return 0;
}
