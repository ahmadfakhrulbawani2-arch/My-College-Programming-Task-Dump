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
#define POSINF 100000000
#define NEGINF -100000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90

void solve() {
    ll x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

    ll res;
    if(x1 == x2 || y1 == y2) {
        res = 1;
        printf("%lld\n", res);
        return;
    }

    ll diffX = (x2 - x1);
    ll diffY = (y2 - y1);

    res = diffX * diffY;
    res++;
    printf("%lld\n", res);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
}

// EXPLANATION

/*

Aku awalnya mikir kemungkinan semua jalurnya memiliki nilai yang berbeda semua. 

Tapi aku menyadari bahwa jika kita ke bawah itu sama saja nilainya dengan ke kanan + 1. Artinya apa?

ke bawah 3 kali itu sama dengan ke kanan + 3 begitu juga sebaliknya. Nah coba kombinasi kanan 3 kali terus ke bawah 3 kali (RRRDDD) bandingkan dengan ke bawah dulu (DDDRRR). 

NAH ke kanan dulu itu adalah nilai minimum karena lihat baris 1 (1 2 4 ...) terus baris 2 (3 5 8 ...) terlihat jelas kalau ke kanan pada baris lebih bawah akan menambah nilai lebih besar pun juga dengan kolom.

logikanya kalau ke bawah 3 kali sama aja kayak ke kanan 3 kali ditambah 3 (lebih besar) terus kita udah di baris bawah (baris 3) nih dan nilai ke kanan akan lebih besar juga dari pada ke kanan di baris 1 ya kan. 

Terus coba kalau ke kanan dulu jelas lebih kecil ya bro dari pada ke bawah dulu. Tapi tunggu bagaimana dengan ke bawah? 

Lihat selisih baris 1 dengan baris 3 (1 2 4 ...) sama (6 9 13) selisihnya 5 + 7 + 9

Terus kolom 1 sama kolom 2 (1 3 6 ...) sama (4 8 13)
Selisihnya 3 + 5 + 7. Loh jauh lebih kecil lagi

Makanya ke kanan dulu -> Minimum
Ke bawah dulu -> maksimum

Terus banyak perbedaan ?

3 4 5 6 7 

adalah angka berbeda 3 s.d 7. Ada berapa banyak? MAX - MIN + 1 (7 - 3 + 1) angka atau 5 angka berbeda. 

Jadi asal tau nilai min dan max kita akan tahu jawabannya

Nah kalo kita lihat ke soal

1   2   4   7   11  16  22  29
3   5   8   12  17  23  30
6   9   13  18  24  31
10  14  19  25  32
15  20  26  33
21  27  34        107 - 117
28  35
36

Misal targetnya 25 (3, 3) dari (0, 0) diffX = 3 dan diffY = 3

RUMUS MAX - MIN adalah diffX * diffY. Polanya lihat scara diagonal dan hitung dari ke kanan dulu terus ke bawah dulu. Nanti selsisihnya adalah diffX * diffY. Soal ini butuh intuisi dan observasi dari pengalaman.

(diffY^2 + diffX^2 + (diffY - diffX)) / 2 == diffX * diffY ? Idk
*/