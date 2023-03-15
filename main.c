#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date {
    int data;
} Date_t;


int check_format(const char date[]) {
    int is_correct = 0;
    if ((date[0] == 34 && date[20] == 34)
        && (date[3] == 46 && date[6] == 46)
        && (date[14] == 58 && date[17] == 58)
        && date[11] == 32) {
        for (int i = 0; i < 21; i++) {
            if ((i != 0 && i != 3 && i != 6 && i != 11 && i != 14 && i != 17)
                && 48 <= date[i] && date[i] <= 57)
                is_correct = 1;
        }
    }
    return is_correct;
}


int main(int argc, char *argv[]) {
    if (argc == 3) {
        int date_1_size = strtol(argv[1], NULL, 10);
        int date_2_size = strtol(argv[2], NULL, 10);
        if (date_1_size == 21 && date_2_size == 21) {
            char date_1[21];
            char date_2[21];
            strcpy(date_1, argv[1]);
            strcpy(date_2, argv[2]);
        } else
            printf("Please enter dates in a specified format (\"DD.MM.YYYY HH:MM:SS\")");
    } else
        printf("Please enter 2 dates as arguments");
}

// TODO
//calc_dates "DD.MM.YYYY HH:MM:SS" "DD.MM.YYYY HH:MM:SS"