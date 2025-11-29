## README PLEASEEE
To compile this program:
```bash
gcc src/*.c -I include -o program -lm
```

Recap: <br>
``1. Susun function dulu semuanya dalam main.c`` <br>
``2. Baru pisahkan function dari main.c`` <br>
``3. Buat file .h dan .c dengan nama yang sama dimana:`` <br>

di file .h: <br>
```c
#ifndef NAMA_FILE_H
#define NAMA_FILE_H

// place your function declaration

#endif
```

di file .c: <br>
```c
#include "namafile.h"

// place your function structure
```

4. Include semua header file yg dibuat dengan cara #include "namafile.h"
5. Coba compile & run.