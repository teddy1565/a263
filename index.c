#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int month_table[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
int leap_year_check(int year) {
    if ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) {
        return 366;
    }
    return 365;
}

int answer(int input1_year, int input1_month, int input1_day, int input2_year, int input2_month, int input2_day) {
    int all_day_counter = 0;
    for (int start_year = input1_year + 1; start_year < input2_year; start_year++) {
        all_day_counter += leap_year_check(start_year);
    }
    if (leap_year_check(input1_year) == 366) {
        month_table[2] = 29;
    }
    for (int start_month = input1_month + 1; start_month <= 12; start_month++) {
        all_day_counter += month_table[start_month];
    }
    all_day_counter += month_table[input1_month] - input1_day;
    month_table[2] = 28;
    if (leap_year_check(input2_year) == 366) {
        month_table[2] = 29;
    }
    for (int end_month = input2_month - 1; end_month >= 1; end_month--) {
        all_day_counter += month_table[end_month];
    }
    all_day_counter += input2_day;
    month_table[2] = 28;
    if (input1_year == input2_year) {
        all_day_counter = 365 - all_day_counter;
        if (all_day_counter < 0) {
            all_day_counter = 0-all_day_counter;
        }
    }
    return all_day_counter;
}

int main(void) {
    int input1_year=0, input1_month=0, input1_day=0;
    int input2_year=0, input2_month=0, input2_day=0;
    int ans = 0;
    while(scanf("%d %d %d", &input1_year, &input1_month, &input1_day) != EOF && scanf("%d %d %d", &input2_year, &input2_month, &input2_day) != EOF) {
        if (input1_year > input2_year) {
            ans = answer(input2_year, input2_month, input2_day, input1_year, input1_month, input1_day);
        } else {
            ans = answer(input1_year, input1_month, input1_day, input2_year, input2_month, input2_day);
        }
        printf("%d\n", ans);
    }
    return 0;
}