#include <stdio.h>

void magician(long long *A1, long long *A2, int *X, long long *result) {
    if (*X == 1) {
        *result = *A1;
        return;
    }
    if (*X == 2) {
        *result = *A2;
        return;
    }

    long long prev1 = *A1;
    long long prev2 = *A2;
    long long cur = 0;

    for (int i = 3; i <= *X; i++) {
        cur = prev1 + prev2;
        prev1 = prev2;
        prev2 = cur;
    }

    *result = cur;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long A1, A2;
        int X;
        long long ans;

        scanf("%lld %lld %d", &A1, &A2, &X);

        magician(&A1, &A2, &X, &ans);

        printf("%lld\n", ans);
    }

    return 0;
}
