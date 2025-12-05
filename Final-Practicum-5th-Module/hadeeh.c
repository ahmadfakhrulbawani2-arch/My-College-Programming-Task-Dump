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

typedef struct contact { 
    char name[100]; 
    char phoneNumber[100]; 
    struct contact *closeFriend; 
} contact; 

void addConnect(contact person[], int n, char str1[], char str2[]) {
    ll idxA = -1, idxB = -1;
    REP1(i, 0, n) {
        if(!strcmp(person[i].name, str1)) {
            idxA = i;
        } 
        if(!strcmp(person[i].name, str2)) {
            idxB = i;
        }
    }

    if(idxA == -1 || idxB == -1) return;

    person[idxA].closeFriend = &person[idxB];
    person[idxB].closeFriend = &person[idxA];
}

ll sumDigits(char str[]) {
    int len = strlen(str); ll retur = 0;
    REP1(i, 0, len) {
        retur += str[i] - ASCII0;
    }

    return retur;
}

int cmpContact(contact *a, contact *b) {
    ll hpA = sumDigits(a->phoneNumber);
    ll hpB = sumDigits(b->phoneNumber);

    if(hpB < hpA) return 1;
    else if(hpA < hpB) return 0;
    else {
        if(a->closeFriend != NULL && b->closeFriend != NULL) {
            ll hpTemanA = sumDigits(a->closeFriend->phoneNumber);
            ll hpTemanB = sumDigits(b->closeFriend->phoneNumber);
            if(hpTemanB < hpTemanA) return 1;
            else if(hpTemanA < hpTemanB) return 0;
            else return 0;
        } else return 0;
    }
}

void sortPerson(contact person[], int n) {
    REP1(i, 0, n-1) {
        REP1(j, 0, n-i-1) {
            if(cmpContact(&person[j], &person[j+1])) {
                contact temp = person[j];
                person[j] = person[j+1];
                person[j+1] = temp;
            }
        }
    }
}

void printContact(contact person[], int n) {
    REP1(i, 0, n) {
        if(i <= n-1) printf("\n");
        printf("Contact #%d\n\n", i+1);

        printf("Name : %s\n", person[i].name);
        printf("Phone Number : %s\n", person[i].phoneNumber);
        printf("-------------------------\n");
    }
}

AWAL
    
    ll n;
    scanf("%lld", &n);
    contact person[n];

    // closeFriend init
    REP1(i, 0, n) person[i].closeFriend = NULL;

    REP1(i, 0, n) {
        scanf("%s %s", person[i].name, person[i].phoneNumber);
    }

    ll m;
    scanf("%lld", &m);
    REP1(i, 0, m) {
        char str1[100], str2[100];
        scanf("%s %s", str1, str2);
        addConnect(person, n, str1, str2);
    }

    sortPerson(person, n);
    printContact(person, n);

AKHIR
