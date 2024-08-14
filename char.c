#include <stdio.h>
#include <string.h>

#define DLE 16
#define STX 2
#define ETX 3

int main() {
    char ch;
    char arr[100] = {DLE, STX};
    int i = 2, j;

    printf("\nEnter the data stream (CTRL+B->STX, CTRL+C->ETX, CTRL+P->DLE):\n");

    // Read data stream from user
    while ((ch = getchar()) != '\n') {
        if (ch == DLE) {
            arr[i++] = DLE;  // Stuff DLE
            arr[i++] = DLE;  // Stuff DLE again
        } else if (ch == STX) {
            arr[i++] = DLE;  // Stuff DLE before STX
            arr[i++] = STX;
        } else if (ch == ETX) {
            arr[i++] = DLE;  // Stuff DLE before ETX
            arr[i++] = ETX;
        } else {
            arr[i++] = ch;   // Normal character
        }
    }
    
    // Append end markers
    arr[i++] = DLE;
    arr[i++] = ETX;

    printf("\nThe stuffed stream is:\n");
    for (j = 0; j < i; j++) {
        if (arr[j] == DLE) {
            printf("DLE ");
        } else if (arr[j] == STX) {
            printf("STX ");
        } else if (arr[j] == ETX) {
            printf("ETX ");
        } else {
            printf("%c", arr[j]);
        }
    }

    printf("\nThe de-stuffed data is:\n");
    for (j = 2; j < i - 2; j++) {
        if (arr[j] == DLE) {
            j++;  // Skip the next character
            if (arr[j] == DLE) {
                printf("DLE ");
            } else if (arr[j] == STX) {
                printf("STX ");
            } else if (arr[j] == ETX) {
                printf("ETX ");
            }
        } else if (arr[j] == STX) {
            printf("STX ");
        } else if (arr[j] == ETX) {
            printf("ETX ");
        } else {
            printf("%c", arr[j]);
        }
    }

    return 0;
}
