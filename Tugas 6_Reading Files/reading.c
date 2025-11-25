#include <stdio.h>
#include <stdlib.h>

typedef struct _penduduk {
    char nama[40];
    short tahun_lahir;
    short bulan_lahir;
    short tanggal_lahir;
    char desa[20];
    char kecamatan[20];
} penduduk;

void showRec(penduduk rec, short tahun, short bulan, short tanggal);

int main(void) {
    FILE *fp = fopen("WargaKebumen.dat", "rb");

    if(fp == NULL) {
        printf("Could not read attached file, Sorrryyyyyy\n");
        return 1;
    }

    fseek(fp, 4, SEEK_SET); // --> Ada 4 bit offset ternyata
    printf("\n%-40s %-20s %-20s %s", "Nama", "Tanggal Lahir", "Desa", "Kecamatan\n");
    printf("====================================================================================================\n");
    // printf("----------------------------------------------------------------------------------------------------\n");

    penduduk rec;
    while(fread(&rec, sizeof(penduduk), 1, fp) == 1) {
        short tahun, tanggal, bulan;
        tahun = rec.tahun_lahir % 100;
        bulan = rec.bulan_lahir % 13;
        tanggal = rec.tanggal_lahir % 40;

        // if(bulan == 2) tanggal = rec.tanggal_lahir % 38;
        // else if(bulan < 8) {
        //     if(bulan % 2 == 0) {
        //         tanggal = rec.tanggal_lahir % 40;
        //     } else tanggal = rec.tanggal_lahir % 41;
        // } else {
        //     if(bulan % 2 == 0) {
        //         tanggal = rec.tanggal_lahir % 40;
        //     } else tanggal = rec.tanggal_lahir % 41;
        // }

        // katakanlah kita ambil dari 31 Desember 2025, jadi kita ambil umur 6-17 dan lansia >= 60 sejak 31 Desember 2025

        int umur = 2025 - rec.tahun_lahir;

        if((umur >= 6 && umur <= 17) || (umur >= 60)) showRec(rec, tahun, bulan, tanggal);
        else continue;
    }

    fclose(fp);
    return 0;
}

void showRec(penduduk rec, short tahun, short bulan, short tanggal) {
    rec.nama[39] = '\0';
    rec.desa[19] = '\0';
    rec.kecamatan[19] = '\0';
    printf("%-40s ", rec.nama);
    printf("%02hd-%02hd-%02hd             ", tanggal, bulan, tahun);
    printf("%-20s %-20s\n", rec.desa, rec.kecamatan);
}