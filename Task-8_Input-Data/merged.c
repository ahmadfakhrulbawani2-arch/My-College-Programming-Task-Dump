
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

#include "struct.h"

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

void cmd1();
void cmd2();

int main(void) {
    printf("\nKETIK 1 UNTUK MELAKUKAN:\n\n    1. INPUT DATA\n    2. MENAMPILKAN & MEMBUAT FILE DATA BINER\n\nKETIK 2 UNTUK MELAKUKAN\n\n    1. MENAMPILKAN DATA\n    2. MENGSORTIR DATA\n\nKETIK 9 UNTUK MENGHENTIKAN PROGRAM\n");
    int input; scanf("%d", &input);
    while(input != 9) {
        if(input == 1) {
            cmd1();
        } else if(input == 2) {
            cmd2();
        }
        printf("\nKETIK 1 UNTUK MELAKUKAN:\n\n    1. INPUT DATA\n    2. MENAMPILKAN & MEMBUAT FILE DATA BINER\n\nKETIK 2 UNTUK MELAKUKAN\n\n    1. MENAMPILKAN DATA\n    2. MENGSORTIR DATA\n\nKETIK 9 UNTUK MENGHENTIKAN PROGRAM\n");
        scanf("%d", &input);
    }
    return 0;
}

void cmd1() {
    int cmd = 0;
    int capacity = 100;   
    int idx = 0;      
    
    printf("NAMA: AHMAD FAKHRUL BAWANI\nNRP: 5025251143\n");
    printf("Muhammad Alhady Rizq - 5025251124\n");
    printf("1: Untuk masukkan data\n2: Tampilkan data\n9: Keluar dan write data\n");

    penduduk *data = malloc(capacity * sizeof(penduduk));
    if(!data) {
        printf("Memory allocation failed\n");
        return;
    }

    scanf("%d", &cmd);

    while(cmd != 9) {

        if(cmd == 1) {
            printf("Masukkan entry>\n");

            if(idx == capacity) {
                capacity *= 2;
                penduduk *tmp = realloc(data, capacity * sizeof(penduduk));
                if(!tmp) {
                    printf("Realloc gagal\n");
                    free(data);
                    return;
                }
                
                data = tmp;
            }

            scanf("%s %hd %hd %hd %s %s",
                data[idx].nama,
                &data[idx].tanggal_lahir,
                &data[idx].bulan_lahir,
                &data[idx].tahun_lahir,
                data[idx].desa,
                data[idx].kecamatan
            );

            idx++;

            printf("Data added\n");
            scanf("%d", &cmd);
        }

        else if(cmd == 2) {
            printf("\n%-40s %-20s %-20s %s", "Nama", "Tanggal Lahir", "Desa", "Kecamatan\n");
            printf("====================================================================================================\n");

            for(int i = 0; i < idx; i++) {
                printf("%-40s ", data[i].nama);
                printf("%02hd-%02hd-%02hd             ", data[i].tanggal_lahir, data[i].bulan_lahir, data[i].tahun_lahir);
                printf("%-20s %-20s\n", data[i].desa, data[i].kecamatan);
            }
            scanf("%d", &cmd);
        }

        else {
            printf("Unknown command\n");
            scanf("%d", &cmd);
        }
    }

    FILE *fp = fopen("CreateNew.dat", "wb");

    if(fp == NULL) {
        printf("Could not read attached file, Sorrryyyyyy\n");
        fclose(fp);
        return;
    }

    fwrite(&idx, sizeof(int), 1, fp);
    fwrite(data, sizeof(penduduk), idx, fp);

    fclose(fp);

    free(data);
    return;
}

void cmd2() {
    int buffer;
    penduduk *penduduki = NULL; 

    FILE *file = fopen("WargaKebumen.dat","rb");
    if(file == NULL)
    {
        printf("Error: can't open file to read\n");
        return;
    }
    printf("File WargaKebumen.dat opened successfully to read\n");

    fread(&buffer, sizeof(int), 1, file);

    penduduk *tmp = realloc(penduduki, buffer * sizeof(penduduk));
    if (!tmp) {
        printf("Memory allocation failed\n");
        fclose(file);
        return;
    }

    penduduki = tmp;

    fread(penduduki, sizeof(penduduk), buffer, file);

    printf("Muhammad Alhady Rizq - 5025251124\n"
        "Ahmad Fakhrul Bawani - 5025251143\n"
        "Pencet [1] buat menampilkan file yang telah disortir\n"
        "Pencet [2] untuk menampilkan data duplikat\n");

    int x;
    scanf("%d", &x);
    int loop;
    
    if (x == 1){
        for (int i = 0; i < buffer; i++) {
        for (int j = i + 1; j < buffer; j++) {
            if (strcmp(penduduki[i].nama, penduduki[j].nama) == 0) {
                if (penduduki[i].tanggal_lahir == penduduki[j].tanggal_lahir) {
                    if (penduduki[i].bulan_lahir == penduduki[j].bulan_lahir){
                        if (penduduki[i].tahun_lahir > penduduki[j].tahun_lahir){
                            penduduk temp = penduduki[i];
                            penduduki[i] = penduduki[j];
                            penduduki[j] = temp;
                            loop = 1;
                        }
                    }
                }
            }
            else if (strcmp(penduduki[i].nama, penduduki[j].nama) == 0) {
                if (penduduki[i].tanggal_lahir == penduduki[j].tanggal_lahir) {
                    if (penduduki[i].bulan_lahir > penduduki[j].bulan_lahir){
                        penduduk temp = penduduki[i];
                        penduduki[i] = penduduki[j];
                        penduduki[j] = temp;
                        loop = 1;
                    }
                }
            }
            else if (strcmp(penduduki[i].nama, penduduki[j].nama) == 0) {
                if (penduduki[i].tanggal_lahir > penduduki[j].tanggal_lahir) {
                    penduduk temp = penduduki[i];
                    penduduki[i] = penduduki[j];
                    penduduki[j] = temp;
                    loop = 1;
                }
            }
            else if (strcmp(penduduki[i].nama, penduduki[j].nama) > 0) {
                penduduk temp = penduduki[i];
                penduduki[i] = penduduki[j];
                penduduki[j] = temp;
                loop = 1;
            }
        }
        }

    printf("Muhammad Alhady Rizq - 5025251124\n"
        "Ahmad Fakhrul Bawani - 5025251143\n");
    
    for (int i = 0; i < buffer; i++){
        printf("%-38s ", penduduki[i].nama);

        if (penduduki[i].tanggal_lahir > 40){
            printf("%02hd", penduduki[i].tanggal_lahir - 40);
        }
        else printf("%02hd", penduduki[i].tanggal_lahir);

        printf("-%02hd-%02hd %-20s %-20s\n", 
            penduduki[i].bulan_lahir, 
            penduduki[i].tahun_lahir, 
            penduduki[i].desa, 
            penduduki[i].kecamatan);
    }
    }

    if (x == 2){
        for (int i = 0; i < buffer; i++) {
        for (int j = i + 1; j < buffer; j++) {
            if (strcmp(penduduki[i].nama, penduduki[j].nama) == 0) {
                if (penduduki[i].tanggal_lahir == penduduki[j].tanggal_lahir) {
                    if (penduduki[i].bulan_lahir == penduduki[j].bulan_lahir){
                        if (penduduki[i].tahun_lahir == penduduki[j].tahun_lahir){
                            printf("%-38s ", penduduki[i].nama);

                            if (penduduki[i].tanggal_lahir > 40){
                                printf("%02hd", penduduki[i].tanggal_lahir - 40);
                            }
                            else printf("%02hd", penduduki[i].tanggal_lahir);

                            printf("-%02hd-%02hd %-20s %-20s\n", 
                                penduduki[i].bulan_lahir, 
                                penduduki[i].tahun_lahir, 
                                penduduki[i].desa, 
                                penduduki[i].kecamatan);
                            
                            printf("%-38s ", penduduki[j].nama);

                            if (penduduki[j].tanggal_lahir > 40){
                                printf("%02hd", penduduki[j].tanggal_lahir - 40);
                            }
                            else printf("%02hd", penduduki[j].tanggal_lahir);

                            printf("-%02hd-%02hd %-20s %-20s\n", 
                                penduduki[j].bulan_lahir, 
                                penduduki[j].tahun_lahir, 
                                penduduki[j].desa, 
                                penduduki[j].kecamatan);
                        }
                    }
                }
            }
        }
    }
    }

    free(penduduki);
    fclose(file);
}