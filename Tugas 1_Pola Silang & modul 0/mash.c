#include <stdio.h>
#include <string.h>

int main() {
    char str[101];
    int shift; 
    scanf("%d", &shift);
    scanf("%s", str);

    int strlength = strlen(str);
    char strg[strlength + 1]; 
    strg[strlength] = '\0'; 

    int k = 0;

    for(int i = 0; i < shift; ++i) {
        for(int j = i; j < strlength; j += shift) {
            strg[j] = str[k];
            ++k;
        }
    }

    for (int l = 0; l < strlength; ++l) {
        if (strg[l] == '_') {
            strg[l] = ' ';
        }
    }

    printf("%s", strg);
    return 0;
}
