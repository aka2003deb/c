#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char seq[36] = "qwertyuiopasdfghjklzxcvvnm1234567890";
    char data[50];
    char encoded[50];
    int i, len;

    printf("\nEnter data: ");
    fgets(data, sizeof(data), stdin);
    len = strlen(data);
    
    // Removing newline character from fgets input
    if(data[len-1] == '\n') {
        data[len-1] = '\0';
        len--;
    }

    for(i = 0; i < len; i++) {
        if(isupper(data[i])) {
            encoded[i] = seq[data[i] - 'A'];
        } else if(islower(data[i])) {
            encoded[i] = toupper(seq[data[i] - 'a']);
        } else if(isdigit(data[i])) {
            encoded[i] = seq[data[i] - '0' + 26];
        } else {
            encoded[i] = data[i];
        }
    }
    
    encoded[len] = '\0';
    printf("\nEncoded string is: %s", encoded);
    return 0;
}
