#include <stdio.h>
#include <string.h>
#include "functions.h"


int main(int argc, char *argv[]) {
    if (argc == 3) {
        int date_1_size = (int) strlen(argv[1]);
        int date_2_size = (int) strlen(argv[2]);
        char date_1_string[date_1_size];
        char date_2_string[date_2_size];
        strcpy(date_1_string, argv[1]);
        strcpy(date_2_string, argv[2]);
        if (check_format(date_1_string) && check_format(date_2_string)) {
            Date_t date_1 = convert_to_date(date_1_string);
            Date_t date_2 = convert_to_date(date_2_string);
            if (check_date(date_1) && check_date(date_2)) {
                print_date_difference(date_1, date_2);
            } else
                printf("Incorrect date!");
        } else
            printf("Wrong format!");
    } else
        printf("Please enter 2 dates as arguments");
}
