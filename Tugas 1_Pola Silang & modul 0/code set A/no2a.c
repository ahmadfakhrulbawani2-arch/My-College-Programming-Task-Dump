#include <stdio.h>

int main() {
    int merah, biru;
    scanf("%d %d", &merah, &biru);

    int selisih = 0;
    if(merah == biru) {
        printf("%d 0", merah);
        return 0;
    }

    if(merah > biru) {
        selisih = merah - biru;
        printf("%d ", biru);
    } else {
        selisih = biru - merah;
        printf("%d ", merah);
    }

    int hariSama = selisih / 2;
    printf("%d", hariSama);
    return 0;
}