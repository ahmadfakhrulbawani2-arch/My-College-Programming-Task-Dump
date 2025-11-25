#include <stdio.h>
#include <string.h>

int main() {

    char name[100];
    long long n = 0;
    long long jumlah = 0;
    scanf("%100s", name); scanf("%lld", &n);

    if(strcmp(name, "Oddie") == 0) {
        for(int i = 1; i <= n; i+= 2) {
            jumlah += i;
        }
        printf("%lld", jumlah);
    } else if(strcmp(name, "Ellie") == 0) {
        for(int i = 2; i <= n; i+= 2) {
            jumlah += i;
        }
        printf("%lld", jumlah);
    } else {
        printf("Who is that?");
    }
    return 0;
}