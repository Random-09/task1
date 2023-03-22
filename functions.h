#ifndef TASK1_FUNCTIONS_H
#define TASK1_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SECONDS_IN_A_YEAR ((long long)365 * 12 * 30 * 24 * 60 * 60)
#define SECONDS_IN_A_MONTH ((long )30 * 24 * 60 * 60)
#define SECONDS_IN_A_DAY (24 * 60 * 60)
#define SECONDS_IN_AN_HOUR (60 * 60)
#define SECONDS_IN_A_MINUTE 60

typedef struct Date {
    int days, months, years, hours, minutes, seconds;
} Date_t;

int check_format(const char date[]);
void slice(const char *string, char *result, int start, int end);
int check_date(Date_t date);
Date_t convert_to_date(const char date_string[]);
long long date_to_seconds(Date_t date);
void print_date_difference(Date_t date_1, Date_t date_2);

#endif //TASK1_FUNCTIONS_H
