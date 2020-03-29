#include <stdio.h>
#include "dow.h"

#ifndef _CALENDAR_H
#define _CALENDAR_H



int numDays(int month, int year) {
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) monthDays[1]++;
    return monthDays[month];
}

char* getMonthName(int month) {
    char* monthNames[12] = {"January", "February", "March", 
                       "April", "May", "June", 
                       "July", "August", "September", 
                       "October", "November", "December"
                      };

    return monthNames[month];
}

//print calendar for a given month 


void printCalendarMonth(int month, int year) {
    int days = numDays(month-1, year);

    int startWeekday = dowSakamotoNo(1, month, year);
    // printf("%d\n", startWeekday);
    printf("\n\n\t______%s______\n\n\n", getMonthName(month-1));
    int j;

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");     
    for (j = 0; j < startWeekday; j++) printf("     ");

    for (int k = 1; k <= days; k++) {
        printf("%5d", k); 

        if (++j > 6) {
            j = 0;
            printf("\n");
        }
    }

    printf("\n\n");
}


void printCalendarYear(int year) {
    for (int i = 1; i <= 12; i++) {
        printCalendarMonth(i, year);
    }
}

#endif