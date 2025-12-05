#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int main()
{
    int buffer;
    penduduk *penduduki = NULL; 

    FILE *file = fopen("WargaKebumen.dat","rb");
    if(file == NULL)
    {
        printf("Error: can't open file to read\n");
        return 1;
    }
    printf("File WargaKebumen.dat opened successfully to read\n");

    fread(&buffer, sizeof(int), 1, file);

    penduduk *tmp = realloc(penduduki, buffer * sizeof(penduduk));
    if (!tmp) {
        printf("Memory allocation failed\n");
        fclose(file);
        return 1;
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
