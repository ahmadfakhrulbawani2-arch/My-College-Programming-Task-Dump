#include <stdio.h>

int main() {
    char a, b, c;
    scanf("%c%c%c", &a, &b, &c);
    int indo = 0, iraq = 0, saudi = 0;

    switch (a)
    {
    case 'I':
        indo += 3;
        break;
    case 'S':
        saudi += 3;
        break;
    case 'D':
        indo += 1;
        saudi += 1;
        break;
    default:
        break;
    }
    switch (b)
    {
    case 'I':
        indo += 3;
        break;
    case 'R':
        iraq += 3;
        break;
    case 'D':
        iraq += 1;
        indo += 1;
        break;
    default:
        break;
    }
    switch (c)
    {
    case 'R':
        iraq += 3;
        break;
    case 'S':
        saudi += 3;
        break;
    case 'D':
        iraq += 1;
        saudi += 1;
        break;
    default:
        break;
    }

    int pertama = (indo >= iraq) ? indo : iraq;
    pertama = (pertama > saudi) ? pertama : saudi;

    int kedua;
    if (pertama == indo) {
        printf("King Indo lolos pildun!!!");
        return 0;
    } else if (pertama == iraq) {
        kedua = (indo >= saudi) ? indo : saudi;
    } else if (pertama == saudi) {
        kedua = (indo >= iraq) ? indo : iraq;
    }

    if (kedua == indo) {
        printf("Masih ada harapan! Tetap semangat!");
    } else {
        printf("Kali ini kami menyatakan kalah, tapi selanjutnya kami akan menang!");
    }

    /*
    if((indo == iraq && indo == saudi) || (indo > saudi && indo > iraq) || ((indo == iraq && indo > saudi) || (indo == saudi && indo > iraq))) {
        printf("King Indo lolos pildun!!!");
    } else if((indo > iraq && saudi > indo) || (indo > saudi && iraq > indo)) {
        printf("Masih ada harapan! Tetap semangat!");
    } else if(indo < saudi && indo < iraq) {
        printf("Kali ini kami menyatakan kalah, tapi selanjutnya kami akan menang!");
    }
    */

    return 0;
}