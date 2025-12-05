#include <stdio.h>
#include <math.h>

long long maxCranes(long long T, long long K) {
    if (T < K) return 0;

    long double disc = 1.0L + 8.0L * (long double)T / (long double)K;
    long double root = floorl((-1.0L + sqrtl(disc)) / 2.0L);
    long long x = (root < 0) ? 0 : (long long)root;

    while (x > 0) {
        long double lhs = (long double)x * (long double)(x + 1);
        long double rhs = 2.0L * (long double)T / (long double)K; 
        if (lhs <= rhs) break;
        --x;
    }

    for (;;) {
        long long nx = x + 1;
        long double lhs = (long double)nx * (long double)(nx + 1);
        long double rhs = 2.0L * (long double)T / (long double)K;
        if (lhs <= rhs)
            x = nx;
        else
            break;
    }

    return x;
}

long long solveCase(long long N, long long K[], int M) {
    long long lo = 0, hi = 1;

    for (;;) {
        long long total = 0;
        for (int i = 0; i < M; ++i) {
            total += maxCranes(hi, K[i]);
            if (total >= N) break;
        }
        if (total >= N) break;
        hi *= 2;
        if (hi < 0) { 
            hi = 9e18;
            break;
        }
    }

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        long long total = 0;
        for (int i = 0; i < M; ++i) {
            total += maxCranes(mid, K[i]);
            if (total >= N) break;
        }
        if (total >= N) hi = mid;
        else lo = mid + 1;
    }

    return lo;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long N;
        scanf("%lld", &N);

        int M;
        scanf("%d", &M);

        long long K[200005];
        for (int i = 0; i < M; i++)
            scanf("%lld", &K[i]);

        long long ans = solveCase(N, K, M);
        printf("%lld\n", ans);
    }

    return 0;
}
