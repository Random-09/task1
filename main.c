#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date {
    int days, months, years, hours, minutes, seconds;
} Date_t;


int check_format(const char date[]) {
    int is_correct = 0;
    if ((date[0] == 34 && date[20] == 34) // check for " at the start & end of date
        && (date[3] == 46 && date[6] == 46) // check for . in DD.MM.YYYY
        && (date[14] == 58 && date[17] == 58) // check for : in HH:MM:SSSS
        && date[11] == 32) {
        for (int i = 0; i < 21; i++) { // check for nums in date & time
            if ((i != 0 && i != 3 && i != 6 && i != 11 && i != 14 && i != 17)
                && 48 <= date[i] && date[i] <= 57)
                is_correct = 1;
        }
    }
    return is_correct;
}


void slice(const char *string, char *result, int start, int end) {
    int j = 0;
    for (size_t i = start; i <= end; ++i) {
        result[j++] = string[i];
    }
}


Date_t convert_to_date(const char date_string[]) {
    char days_str[2];
    char months_str[2];
    char years_str[4];
    char hours_str[2];
    char minutes_str[2];
    char seconds_str[2];
    slice(date_string, days_str, 1, 2);
    slice(date_string, months_str, 4, 5);
    slice(date_string, years_str, 7, 10);
    slice(date_string, hours_str, 12, 13);
    slice(date_string, minutes_str, 15, 16);
    slice(date_string, seconds_str, 18, 19);
    Date_t date;
    date.days = strtol(days_str, NULL, 10);
    date.months = strtol(months_str, NULL, 10);
    date.years = strtol(years_str, NULL, 10);
    date.hours = strtol(hours_str, NULL, 10);
    date.minutes = strtol(minutes_str, NULL, 10);
    date.seconds = strtol(seconds_str, NULL, 10);
    return date;
}


int main(int argc, char *argv[]) {
    if (argc == 3) {
        int date_1_size = strtol(argv[1], NULL, 10);
        int date_2_size = strtol(argv[2], NULL, 10);
        if (date_1_size == 21 && date_2_size == 21) {
            char date_1_string[21];
            char date_2_string[21];
            strcpy(date_1_string, argv[1]);
            strcpy(date_2_string, argv[2]);
            if (check_format(date_1_string) && check_format(date_2_string)) {
                Date_t date_1 = convert_to_date(date_1_string);
                Date_t date_2 = convert_to_date(date_2_string);
            }
        } else
            printf("Please enter dates in a specified format (\"DD.MM.YYYY HH:MM:SS\")");
    } else
        printf("Please enter 2 dates as arguments");
}

// TODO
//calc_dates "DD.MM.YYYY HH:MM:SS" "DD.MM.YYYY HH:MM:SS"