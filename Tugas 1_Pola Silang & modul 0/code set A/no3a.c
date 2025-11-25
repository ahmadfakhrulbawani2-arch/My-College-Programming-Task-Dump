#include <stdio.h>

int main() {
    int b;
    scanf("%d", &b);

    char c1;
    int n1;
    int x = 0, y = 0;
    scanf(" %c %d", &c1, &n1);
    switch (c1)
    {
    case 'N':
        y += n1;
        break;
    case 'E':
        x += n1;
        break;
    case 'W':
        x -= n1;
        break;
    case 'S':
        y -= n1;
        break;
    default:
        break;
    }
    scanf(" %c %d", &c1, &n1);
    switch (c1)
    {
    case 'N':
        y += n1;
        break;
    case 'E':
        x += n1;
        break;
    case 'W':
        x -= n1;
        break;
    case 'S':
        y -= n1;
        break;
    default:
        break;
    }
    scanf(" %c %d", &c1, &n1);
    switch (c1)
    {
    case 'N':
        y += n1;
        break;
    case 'E':
        x += n1;
        break;
    case 'W':
        x -= n1;
        break;
    case 'S':
        y -= n1;
        break;
    default:
        break;
    }
    scanf(" %c %d", &c1, &n1);
    switch (c1)
    {
    case 'N':
        y += n1;
        break;
    case 'E':
        x += n1;
        break;
    case 'W':
        x -= n1;
        break;
    case 'S':
        y -= n1;
        break;
    default:
        break;
    }

    x = (x >= 0) ? x : x * (-1);
    y = (y >= 0) ? y : y * (-1);

    if (x + y <= b) {
        printf("CONAN KECE BET");
    } else {
        printf("RAN KECEWA");
    }

    return 0;
}