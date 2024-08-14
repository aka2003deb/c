#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char seq[36] = "qwertyuiopasdfghjklzxcvbnm1234567890";
    char data[100];
    char decoded[100];
    int i, j, len, present = 0;

    printf("\nEnter data: ");
    fgets(data, sizeof(data), stdin);
    len = strlen(data);
    
    // Removing newline character from fgets input
    if(data[len-1] == '\n') {
        data[len-1] = '\0';
        len--;
    }

    for(i = 0; i < len; i++) {
        present = 0;
        for(j = 0; j < 36 && !present; ++j) {
            if(seq[j] == tolower(data[i])) {
                if(isupper(data[i])) {
                    decoded[i] = 'A' + j;
                } else if(islower(data[i])) {
                    decoded[i] = 'a' + j;
                } else {
                    decoded[i] = '0' + (j - 26);
                }
                present = 1;
            }
        }
        if(!present) {
            decoded[i] = data[i];
        }
    }
    
    decoded[len] = '\0';
    printf("\nDecoded string is: %s\n", decoded);
    return 0;
}
