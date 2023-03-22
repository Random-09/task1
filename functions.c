#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


int check_format(const char date[]) {
    int is_correct = 0;
    if (strlen(date) == 19
        && (date[2] == 46 && date[5] == 46)     // check for . in DD.MM.YYYY
        && (date[13] == 58 && date[16] == 58)   // check for : in HH:MM:SSSS
        && date[10] == 32) {                    // check for space between time and date
        for (int i = 0; i < 19; i++) {          // check for nums in date & time
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


int check_date(Date_t date) { // CHECK FOR NEGATIVE NUMS (ARE THEY NECESSARY?)
    if (1 <= date.days && date.days <= 30 && 1 <= date.months && date.months <= 12 && 0 <= date.hours
        && date.hours <= 23 && 0 <= date.minutes && date.minutes <= 59 && 0 <= date.seconds && date.seconds <= 59)
        return 1;
    else
        return 0;
}


Date_t convert_to_date(const char date_string[]) {
    char days_str[3], months_str[3], years_str[5], hours_str[3], minutes_str[3], seconds_str[3];
    slice(date_string, days_str, 0, 1);
    slice(date_string, months_str, 3, 4);
    slice(date_string, years_str, 6, 9);
    slice(date_string, hours_str, 11, 12);
    slice(date_string, minutes_str, 14, 15);
    slice(date_string, seconds_str, 17, 18);
    int days, months, years, hours, minutes, seconds;
    days = strtol(days_str, NULL, 10);
    months = strtol(months_str, NULL, 10);
    years = strtol(years_str, NULL, 10);
    hours = strtol(hours_str, NULL, 10);
    minutes = strtol(minutes_str, NULL, 10);
    seconds = strtol(seconds_str, NULL, 10);
    Date_t date = {days, months, years, hours, minutes, seconds};
    return date;
}


long long date_to_seconds(Date_t date) {
    long long result = 0;
    result += date.years * SECONDS_IN_A_YEAR;
    result += date.months * SECONDS_IN_A_MONTH;
    result += date.days * SECONDS_IN_A_DAY;
    result += date.hours * SECONDS_IN_AN_HOUR;
    result += date.minutes * SECONDS_IN_A_MINUTE;
    result += date.seconds;
    return result;
}


void print_date_difference(Date_t date_1, Date_t date_2) {
    long long total_seconds = llabs(date_to_seconds(date_1) - date_to_seconds(date_2));
    int years = (int) (total_seconds / SECONDS_IN_A_YEAR);
    total_seconds -= years * SECONDS_IN_A_YEAR;
    int months = (int) (total_seconds / SECONDS_IN_A_MONTH);
    total_seconds -= months * SECONDS_IN_A_MONTH;
    int days = (int) (total_seconds / SECONDS_IN_A_DAY);
    total_seconds -= days * SECONDS_IN_A_DAY;
    int hours = (int) (total_seconds / SECONDS_IN_AN_HOUR);
    total_seconds -= hours * SECONDS_IN_AN_HOUR;
    int minutes = (int) (total_seconds / SECONDS_IN_A_MINUTE);
    total_seconds -= minutes * SECONDS_IN_A_MINUTE;
    int seconds = (int) (total_seconds);
    printf("%02d.%02d.%04d %02d:%02d:%02d", days, months, years, hours, minutes, seconds);
}