#include <stdio.h>

int main() {
    int n1, n2, n3, n4, n5;
    char a1, a2, a3, a4, a5;
    scanf("%d %c\n%d %c\n%d %c\n%d %c\n%d %c", &n1, &a1, &n2, &a2, &n3, &a3, &n4, &a4, &n5,&a5);

    if(((n1 == n2) && (n2 == n3) && (n3 == n4)) || ((n2 == n3) && (n3 == n4) && (n4 == n5)) || ((n3 == n4) && (n4 == n5) && (n5 == n1)) || ((n4 == n5) && (n5 == n1) && (n1 == n2)) || ((n5 == n1) && (n1 == n2) && (n2 == n3))) {
        printf("Four of a Kind");
        return 0;
    }

    int sepasang = 0;
    int pasang1 = 0;
    int pasang2 = 0;
    if((n1 == n2) || (n1 == n3) || (n1 == n4) || (n1 == n5)) { 
        pasang1 = n1;
        sepasang = 1;
    }

    if((n2 == n3) || (n2 == n4) || (n2 == n5)) {
        pasang1 = n2;
        sepasang = 1;
    }

    if((n3 == n4) || (n3 == n5)) {
        pasang1 = n3;
        sepasang = 1;
    }

    if((n4 == n5)) {
        pasang1 = n4;
        sepasang = 1;
    }

    int tigaSama = 0;
    if(((n1 == n2) && (n2 == n3)) || ((n1 == n2) && (n2 == n4)) || ((n1 == n2) && (n2 == n5)) || ((n1 == n3) && (n3 == n4)) || ((n1 == n4) && (n4 == n5)) || ((n1 == n5) && (n5 == n2)) || ((n2 == n3) && (n3 == n4)) || ((n2 == n4) && (n4 == n5)) || ((n2 == n5) && (n5 == n1)) || ((n3 == n4) && (n4 == n5)) || ((n3 == n5) && (n5 == n2)) || ((n4 == n5) && (n5 == n3))) {
        tigaSama = 1;
    }

    if(sepasang == 1 && tigaSama == 1) {
        printf("Full House");
        return 0;
    }

    if((a1 == a2) && (a2 == a3) && (a3 == a4) && (a4 == a5)) {
        printf("Flush");
        return 0;
    }

    if(tigaSama == 1) {
        printf("Three of a Kind");
        return 0;
    }

    if(((n1 == n2) && (n1 != pasang1)) || ((n1 == n3) && (n1 != pasang1)) || ((n1 == n4) && (n1 != pasang1)) || ((n1 == n5) && (n1 != pasang1))) { 
        pasang2 = n1;
        sepasang = 2;
    }

    if(((n2 == n3) && (n2 != pasang1)) || ((n2 == n4) && (n2 != pasang1)) || ((n2 == n5) && (n2 != pasang1))) { 
        pasang2 = n2;
        sepasang = 2;
    }

    if(((n3 == n4) && (n3 != pasang1)) || ((n3 == n5) && (n3 != pasang1))) { 
        pasang2 = n3;
        sepasang = 2;
    }

    if(((n5 == n4) && (n5 != pasang1))) { 
        pasang2 = n1;
        sepasang = 2;
    }

    if(sepasang == 2 && pasang1 != pasang2 && (pasang1 != 0 && pasang2 != 0)) {
        printf("Two Pair");
        return 0;
    }

    if(sepasang == 1 && (pasang1 == 0 || pasang2 == 0)) {
        printf("One Pair");
        return 0;
    }


    printf("Tidak ada kombinasi khusus");
    return 0;
}