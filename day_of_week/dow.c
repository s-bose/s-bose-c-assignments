#include <stdio.h>
#include "dow.h"
#include "calendar.h"


int main() {
    int d, m, y;
    // while (1) {
    printf("give a date (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &d, &m, &y);
    if (dowSakamoto(d, m, y) == -1) printf("Please enter a valid date\n");
    if (dowDiff(d, m, y) == -1) printf("Please enter a valid date\n");
    // if (dowConway(d, m, y) == -1) printf("Please enter a valid date\n");

    printCalendarMonth(m, y);

    // }


    return 0;
}