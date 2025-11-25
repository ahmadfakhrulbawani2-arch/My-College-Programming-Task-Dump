#include <stdio.h>

int sumASCII(const char *str) {
    // Base case: if the string is empty, return 0
    if (*str == '\0') {
        return 0;
    }
    // Recursive case: add the ASCII value of the current character
    // to the sum of the rest of the string
    return *str + sumASCII(str + 1);
}

int main() {
    const char *string;
    int sum = sumASCII(string);
    printf("The sum of ASCII values is: %d\n", sum);
    return 0;
}
