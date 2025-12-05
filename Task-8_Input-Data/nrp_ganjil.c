#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

#define ll long long

int main(void) {
    int cmd = 0;
    int capacity = 100;   
    int idx = 0;      
    
    printf("NAMA: AHMAD FAKHRUL BAWANI\nNRP: 5025251143\n");
    printf("Muhammad Alhady Rizq - 5025251124\n");
    printf("1: Untuk masukkan data\n2: Tampilkan data\n9: Keluar dan write data\n");

    penduduk *data = malloc(capacity * sizeof(penduduk));
    if(!data) {
        printf("Memory allocation failed\n");
        return 1;
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
                    return 1;
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
        return 1;
    }

    fwrite(&idx, sizeof(int), 1, fp);
    fwrite(data, sizeof(penduduk), idx, fp);

    fclose(fp);

    free(data);
    return 0;
}
