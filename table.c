#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int month_table[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
int all_day_counter = 0;


int main(void) {
    int input1_year=0, input1_month=0, input1_day=0;
    int input2_year=0, input2_month=0, input2_day=0;
    int ***table;
    table = (int ***)malloc(sizeof(int **)*10000);
    for (int i = 0; i < 10000; i++) {
        table[i] = (int **)malloc(sizeof(int *)*13);
        for (int j = 0; j < 13; j++) {
            table[i][j] = (int *)malloc(sizeof(int)*32);
            for (int k = 0; k < 32; k++) {
                table[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < 10000; i++) {
        if ((i%4 == 0 && i%100 != 0) || (i%400 == 0)) {
            month_table[2] = 29;
        } else {
            month_table[2] = 28;
        }
        for (int j = 1; j < 13; j++) {
            for (int k = 1; k <= month_table[j]; k++) {
                table[i][j][k] = all_day_counter++;
            }
        }
    }

    while(scanf("%d %d %d", &input1_year, &input1_month, &input1_day) != EOF && scanf("%d %d %d", &input2_year, &input2_month, &input2_day) != EOF) {
        int ans = table[input2_year][input2_month][input2_day] - table[input1_year][input1_month][input1_day];
        if (ans < 0) {
            ans = 0-ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}