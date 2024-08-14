#include <stdio.h>
#include <string.h>

int main() {
    char ch, array[100] = "01111110", read_array[100];
    int count = 0, i = 8, j, k;

    // Get data to be transmitted
    printf("Enter data to be transmitted (end with newline): ");

    while ((ch = getchar()) != '\n') {
        if (ch == '1')
            count++;
        else
            count = 0;

        array[i++] = ch;

        // Insert '0' after five consecutive '1's
        if (count == 5) {
            array[i++] = '0';
            count = 0;
        }
    }

    // Append the flag pattern for the end of the HDLC frame
    strcat(array, "01111110");

    // Print the transmitted bit stream after stuffing
    printf("\nTransmitted bit stream (After stuffing) at the transmitter side is: %s\n", array);

    // DESTUFFING
    j = strlen(array);
    count = 0;
    k = 0;

    // Skip the initial flag and process the data
    for (i = 8; i < j - 8; i++) {
        if (array[i] == '1')
            count++;
        else
            count = 0;

        read_array[k++] = array[i];

        // Skip the stuffed '0' if five consecutive '1's are detected
        if (count == 5 && array[i + 1] == '0') {
            i++;
            count = 0;
        }
    }

    // Null-terminate the destuffed array
    read_array[k] = '\0';

    // Print the destuffed data
    printf("Destuffed data at the receiver is: %s\n", read_array);

    return 0;
}
