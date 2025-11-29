To compile this program:
gcc src/*.c -I include -o program -lm

Recap:
1. Susun function dulu semuanya dalam main.c
2. Baru pisahkan function dari main.c
3. Buat file .h dan .c dengan nama yang sama dimana:

di file .h:
#ifndef NAMA_FILE_H
#define NAMA_FILE_H

// place your function declaration

#endif

di file .c:
#include "namafile.h"

// place your function structure

4. Include semua header file yg dibuat dengan cara #include "namafile.h"
5. Coba compile & run