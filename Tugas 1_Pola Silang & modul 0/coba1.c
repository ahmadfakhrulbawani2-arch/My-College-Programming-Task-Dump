#include <stdio.h>
#include <string.h>
int main() {
   char src[] = "Hello, World!";
   char dest[20];
   // Copy first 5 characters from src to dest
   strncpy(dest, src, 5);
   dest[5] = '\0'; // Manually add null terminator
   printf("Source: %s\n", src);
   printf("Destination: %s\n", dest);
   return 0;
}