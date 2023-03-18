#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Date {
    int days, months, years, hours, minutes, seconds;
} Date_t;


int check_format(const char date[]) {
    int is_correct = 0;
    if ((date[2] == 46 && date[5] == 46) // check for . in DD.MM.YYYY
        && (date[13] == 58 && date[16] == 58) // check for : in HH:MM:SSSS
        && date[10] == 32) { // check for space between time and date
        for (int i = 0; i < 19; i++) { // check for nums in date & time
            if ((i != 2 && i != 5 && i != 10 && i != 13 && i != 16)
                && 48 <= date[i] && date[i] <= 57)
                is_correct = 1;
        }
    }
    return is_correct;
}


void slice(const char *string, char *result, int start, int end) {
    int j = 0;
    for (size_t i = start; i <= end; i++) {
        result[j++] = string[i];
    }
}


Date_t convert_to_date(const char date_string[]) { // CHECK FOR >24H, >60 MINUTES ETC.
    char days_str[3];
    char months_str[3];
    char years_str[5];
    char hours_str[3];
    char minutes_str[3];
    char seconds_str[3];
    slice(date_string, days_str, 0, 1);
    slice(date_string, months_str, 3, 4);
    slice(date_string, years_str, 6, 9);
    slice(date_string, hours_str, 11, 12);
    slice(date_string, minutes_str, 14, 15);
    slice(date_string, seconds_str, 17, 18);
    Date_t date;
    date.days = strtol(days_str, NULL, 10);
    date.months = strtol(months_str, NULL, 10);
    date.years = strtol(years_str, NULL, 10);
    date.hours = strtol(hours_str, NULL, 10);
    date.minutes = strtol(minutes_str, NULL, 10);
    date.seconds = strtol(seconds_str, NULL, 10);
    return date;
}


void print_date_difference(Date_t date_1, Date_t date_2) {

}


int main(int argc, char *argv[]) {
    if (argc == 3) {
        int date_1_size = (int) strlen(argv[1]);
        int date_2_size = (int) strlen(argv[2]);
        if (date_1_size == 19 && date_2_size == 19) {
            char date_1_string[21];
            char date_2_string[21];
            strcpy(date_1_string, argv[1]);
            strcpy(date_2_string, argv[2]);
            if (check_format(date_1_string) && check_format(date_2_string)) {
                Date_t date_1 = convert_to_date(date_1_string);
                Date_t date_2 = convert_to_date(date_2_string);
                print_date_difference(date_1, date_2);
            } else
                printf("Wrong format!");
        } else
            printf("Please enter dates in a specified format (\"DD.MM.YYYY HH:MM:SS\")");
    } else
        printf("Please enter 2 dates as arguments");
}

// TODO
//calc_dates "DD.MM.YYYY HH:MM:SS" "DD.MM.YYYY HH:MM:SS"