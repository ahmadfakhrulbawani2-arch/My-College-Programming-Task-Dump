#include <stdio.h>

int main() {
    int bil;
    scanf("%d", &bil);

    int ratus = (int)bil / 100;
    int puluh = (int)(bil % 100) / 10;
    int satuan = bil % 10;

    if(bil >= 100) {
        if(ratus > 0 && ratus <= 9) {
            switch(ratus) {
                case 1:
                    printf("Seratus ");
                    break;
                case 2:
                    printf("Dua ratus ");
                    break;
                case 3:
                    printf("Tiga ratus ");
                    break;
                case 4:
                    printf("Empat ratus ");
                    break;
                case 5:
                    printf("Lima ratus ");
                    break;
                case 6:
                    printf("Enam ratus ");
                    break;
                case 7:
                    printf("Tujuh ratus ");
                    break;
                case 8:
                    printf("Delapan ratus ");
                    break;
                case 9:
                    printf("Sembilan ratus ");
                    break;
            }
        }

        if(puluh > 1 && puluh <= 9) {
            switch(puluh) {
                case 2:
                    printf("dua puluh ");
                    break;
                case 3:
                    printf("tiga puluh ");
                    break;
                case 4:
                    printf("empat puluh ");
                    break;
                case 5:
                    printf("lima puluh ");
                    break;
                case 6:
                    printf("enam puluh ");
                    break;
                case 7:
                    printf("tujuh puluh ");
                    break;
                case 8:
                    printf("delapan puluh ");
                    break;
                case 9:
                    printf("sembilan puluh ");
                    break;
            }
        }

        if(satuan > 1 && satuan <= 9) {
            switch(satuan) {
                case 2:
                    printf("dua");
                    break;
                case 3:
                    printf("tiga");
                    break;
                case 4:
                    printf("empat");
                    break;
                case 5:
                    printf("lima");
                    break;
                case 6:
                    printf("enam");
                    break;
                case 7:
                    printf("tujuh");
                    break;
                case 8:
                    printf("delapan");
                    break;
                case 9:
                    printf("sembilan");
                    break;
            }
        }

        if(satuan > 1 && puluh == 1) {
            printf(" belas");
        } else if(satuan == 1 && puluh == 1) {
            printf("sebelas");
        } else if(puluh == 1 && satuan == 0) {
            printf("sepuluh");
        }
    } else if(bil < 100 && bil >= 20) {
        if(puluh > 1 && puluh <= 9) {
            switch(puluh) {
                case 2:
                    printf("Dua puluh ");
                    break;
                case 3:
                    printf("Tiga puluh ");
                    break;
                case 4:
                    printf("Empat puluh ");
                    break;
                case 5:
                    printf("Lima puluh ");
                    break;
                case 6:
                    printf("Enam puluh ");
                    break;
                case 7:
                    printf("Tujuh puluh ");
                    break;
                case 8:
                    printf("Delapan puluh ");
                    break;
                case 9:
                    printf("Sembilan puluh ");
                    break;
            }
        }

        if(satuan > 0 && satuan <= 9) {
            switch(satuan) {
                case 1:
                    printf("satu");
                    break;
                case 2:
                    printf("dua");
                    break;
                case 3:
                    printf("tiga");
                    break;
                case 4:
                    printf("empat");
                    break;
                case 5:
                    printf("lima");
                    break;
                case 6:
                    printf("enam");
                    break;
                case 7:
                    printf("tujuh");
                    break;
                case 8:
                    printf("delapan");
                    break;
                case 9:
                    printf("sembilan");
                    break;
            }
        }

        if(satuan > 1 && puluh == 1) {
            printf(" belas");
        } else if(satuan == 1 && puluh == 1) {
            printf("sebelas");
        } else if(puluh == 1) {
            printf(" belas");
        } else if(puluh == 1 && satuan == 0) {
            printf(" sepuluh");
        }
    } else if(bil >= 11 && bil < 20) {
        if(satuan > 1 && satuan <= 9) {
            switch(satuan) {
                case 2:
                    printf("Dua");
                    break;
                case 3:
                    printf("Tiga");
                    break;
                case 4:
                    printf("Empat");
                    break;
                case 5:
                    printf("Lima");
                    break;
                case 6:
                    printf("Enam");
                    break;
                case 7:
                    printf("Tujuh");
                    break;
                case 8:
                    printf("Delapan");
                    break;
                case 9:
                    printf("Sembilan");
                    break;
            }
        }

        if(satuan > 1 && puluh == 1) {
            printf(" belas");
        } else if(satuan == 1 && puluh == 1) {
            printf("Sebelas");
        } else if(puluh == 1) {
            printf(" belas");
        } else if(puluh == 1 && satuan == 0) {
            printf(" sepuluh");
        }
    } else if(bil == 10) {
        printf("Sepuluh");
    } else if(bil > 0 && bil <= 10) {
        switch(satuan) {
                case 1:
                    printf("Satu");
                    break;
                case 2:
                    printf("Dua");
                    break;
                case 3:
                    printf("Tiga");
                    break;
                case 4:
                    printf("Empat");
                    break;
                case 5:
                    printf("Lima");
                    break;
                case 6:
                    printf("Enam");
                    break;
                case 7:
                    printf("Tujuh");
                    break;
                case 8:
                    printf("Delapan");
                    break;
                case 9:
                    printf("Sembilan");
                    break;
            }
    }
    return 0;
}