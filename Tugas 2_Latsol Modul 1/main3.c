#include <stdio.h>

int main() {
    char x, y;
    double n = 0, n1 = 0, n2 = 0, n3 = 0;
    int yes = 0;

    scanf("%lf %c %c", &n, &x, &y);

    switch(x) {
    case 'K':
        n1 = 1.8 * (n - 273) + 32; // fahrenheit
        n2 = n - 273; // celcius
        n3 = (n - 273) * 0.8; // reamur
        switch(y) {
        case 'F':
            printf("%.2lf %c", n1, y);
            break;
        case 'C':
            printf("%.2lf %c", n2, y);
            break;
        case 'R':
            printf("%.2lf %c", n3, y);
            break;
        case 'K':
            printf("%.2lf %c", n, y);
            break;
        default:
            printf("Jenis temperatur yang dimasukkan tidak ada");
            yes = 1;
            break;
        }
        break;
    case 'F':
        n1 = (n - 32) * (0.555555555555555555555555555555555555555555555555) + 273; // kelvin
        n2 = (n - 32) * (0.555555555555555555555555555555555555555555555555); // celcius
        n3 = (n - 32) * (0.444444444444444444444444444444444444444444444444); // reamur
        switch(y) {
        case 'K':
            printf("%.2lf %c", n1, y);
            break;
        case 'C':
            printf("%.2lf %c", n2, y);
            break;
        case 'R':
            printf("%.2lf %c", n3, y);
            break;
        case 'F':
            printf("%.2lf %c", n, y);
            break;
        default:
            printf("Jenis temperatur yang dimasukkan tidak ada");
            yes = 1;
            break;
        }
        break;
    case 'R':
        n1 = (1.25) * n; // celcius
        n2 = n * (1.25) + 273; // kelvin
        n3 = n * (2.25) + 32; // fahrenheit
        switch(y) {
        case 'C':
            printf("%.2lf %c", n1, y);
            break;
        case 'K':
            printf("%.2lf %c", n2, y);
            break;
        case 'F':
            printf("%.2lf %c", n3, y);
            break;
        case 'R':
            printf("%.2lf %c", n, y);
            break;
        default:
            printf("Jenis temperatur yang dimasukkan tidak ada");
            yes = 1;
            break;
        }
        break;
    case 'C':
        n1 = n * (1.8) + 32; // fahrenheit
        n2 = n + 273; // kelvin
        n3 = n * (0.8); // reamur
        switch(y) {
        case 'F':
            printf("%.2lf %c", n1, y);
            break;
        case 'K':
            printf("%.2lf %c", n2, y);
            break;
        case 'R':
            printf("%.2lf %c", n3, y);
            break;
        case 'C':
            printf("%.2lf %c", n, y);
            break;
        default:
            printf("Jenis temperatur yang dimasukkan tidak ada");
            yes = 1;
            break;
        }
        break;
    default:
        if(yes == 1) {
            break;
        } else {
            printf("Jenis temperatur yang dimasukkan tidak ada");
            break;
        }
    }
    return 0;
}
