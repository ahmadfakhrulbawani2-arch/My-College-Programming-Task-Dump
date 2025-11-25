#include <stdio.h>

int calcDet(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    int det;
    det = (a * e * i) + (b * f * g) + (c * d * h) - (c * e * g) - (a * f * h) - (b * d * i);
    return det;
}

int a, b, c, d, e, f, g, h, i;
int main() {
    scanf("%d %d %d\n%d %d %d\n%d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i);

    int det = calcDet(a, b, c, d, e, f, g, h, i);
    if(det == 0) {
        printf("Gabisa bang");
    } else {
        float A = (float) (e * i - f * h) / det;
        float B = (float) -1 * (b * i - c * h) / det;
        float C = (float) (b * f - c * e) / det;
        float D = (float) -1 * (d * i - f * g) / det;
        float E = (float) (a * i - c * g) / det;
        float F = (float) -1 * (a * f - c * d) / det;
        float G = (float) (d * h - e * g) / det;
        float H = (float) -1 * (a * h - b * g) / det;
        float I = (float) (a * e - b * d) / det;
        printf("%.2f %.2f %.2f\n%.2f %.2f %.2f\n%.2f %.2f %.2f", A, B, C, D, E, F, G, H, I);
    }
    return 0;
}