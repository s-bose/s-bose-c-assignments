#include <stdio.h>
#include "calendar.h"

int main() {
    int i, m, y;
    printf("Print calendar for a month or a year? (1 or 2): ");
    scanf("%d", &i);
    if (i == 1) {
        printf("\nEnter month and year (mm-yyyy): ");
        scanf("%d-%d", &m, &y);
        printCalendarMonth(m, y);
    }
    else if (i == 2) {
        printf("\nEnter year (yyyy): ");
        scanf("%d", &y);
        printCalendarYear(y);
    }
    else {
        printf("\nPlease enter a valid option\n");
    }
    return 0;
}