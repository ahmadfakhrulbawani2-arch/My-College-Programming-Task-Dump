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
#define ILOOPTON2(start, n) for(i = start; i <= n; i++) // must declare i as global var.
#define ILOOPTON1(start, n) for(i = start; i < n; i++) // must declare i as global var.
#define JLOOPTON2(start, n) for(j = start; j <= n; j++) // must declare j as global var.
#define JLOOPTON1(start, n) for(j = start; j < n; j++) // must declare j as global var.
#define KLOOPTON2(start, n) for(k = start; k <= n; k++) // must declare k as global var.
#define KLOOPTON1(start, n) for(k = start; k < n; k++) // must declare k as global var.
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90

#define CONSTRAINT 2000005

ll g[CONSTRAINT];
ll prefCount[10][CONSTRAINT];
ll i, j; // buat forloop

ll funcF(int x) {
    int net = 1;
    while(x > 0) {
        int digits = x % 10;
        if(digits) net *= digits;
        x /= 10;
    }
    return net;
}

ll funcG(int x) {
    if(x < 10) return x;
    return funcG(funcF(x));
}

void precomp() {

    ILOOPTON2(1, CONSTRAINT-5) {
        g[i] = funcG(i);
        // memcpy(prefCount[*][i], prefCount[*][i-1], sizeof prefCount[*][i]); 
        JLOOPTON2(1, 9) {
            prefCount[j][i] = prefCount[j][i-1];
        }
        prefCount[g[i]][i]++;
    }

}

ll takes(ll l, ll r, ll target) {
    return prefCount[target][r] - prefCount[target][l-1];
}

void solve() {

    ll l, r, target;
    scanf("%lld %lld %lld", &l, &r, &target);

    ll res = takes(l, r, target);

    printf("%lld", res);

}

int main(void) {
    precomp();

    int q; scanf("%d", &q);
    while(q--) {
        solve();
        printf("\n");
    }
    
    return 0;

} 

/* 

===  Visualisasi  ====

* Soal mau kita hitung berapa bilangan yang memenuhi g(x) = target

* Caranya kita precompute semua nilai g(x) dulu. Kenapa? Karena precompute sudah memakan hampir 0.5 sekon (~5 jt operasi) dan ada beberapa test case jadi harus precompute dulu.

* Cara precomputenya pakai prefix count. Jadi buat array prefCount buat nyimpen ada berapa banyak angka yang memenuhi target dari 1 - 9 (x < 10) jadi visualisasinya begini:

prefCount = [

[0][]
[1][]
[2][]
[3][]
[4][]
[5][]

]

Nah yang kosong tidak benar2 kosong, mereka hasil copy index sebelumnya

memcpy(prefCount[*][i], prefCount[*][i-1], sizeof prefCount[*][i]); 
Atau pakai loop biasa. 

yang awalnya null terus ditambah oleh prefCount[g[i]][i]++; Jika ada nilai x yang memenuhi. x disini adalah i btw.

jadi kalau misal kita nemu x = 5 memenuhi target = 3 nih terus kita maju x = 6, x = 7, .., x = 12 baru nemu lagi, jadinya gini

prefCount = [

...
[2][0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ...]
[3][0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, ...]
[4][0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ...]
...

]
Nb: nilai awal benar2 0 karena di C, global variable langsung menjadi 0 (seperti calloc);

Makanya saat query kita tinggal nilai di index batas kanan kurangin sama yang di index kiri.

Q: Kenapa harus di copy? Gak disesuaikan sama target aja?
A: Karena prefCount juga precompute (nilai target belum ada). Perhatikan bahwa dari contoh di atas nilai x yang memenuhi dari 1 s.d. 12 adalah 2 tetapi dari 5 s.d 12 hanya satu saja. Itulah fungsi copy, kita bisa tentukan semua range yang diminta.

*/