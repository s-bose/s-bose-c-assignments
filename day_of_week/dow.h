#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifndef _DOW_H
#define _DOW_H



// ! assumes 01-01-01 to be Monday, and follows Gregorian (corrected Julian) calendar

// ? sakamoto's algorithm
int dowSakamotoNo(int day, int month, int year) {
    int t[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= (month < 3);
    return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

int dowSakamoto(int day, int month, int year) {
    char* weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    if (day > 31) return -1;   
    if (month > 12) return -1;
    
    printf("(Sakamoto's algorithm) The day of the week is %s\n" , weekdays[dowSakamotoNo(day, month, year)]);
    return 0;
}


// // ? Conway's algorithm
// /*
// * doomsdays
// * 1800-1899 = Friday
// * 1900-1999 = Wednesday
// * 2000-2099 = Tuesday
// * 2100-2199 = Sunday

// * to get anchor day for a given century c, compute (c mod 4)
// * 0 = Tuesday
// * 1 = Sunday
// * 2 = Friday
// * 3 = Wednesday

// * shifts by 5 every century
// */
// int dowConway(int d, int m, int y) {
//     if (d > 31) return -1;
//     if (m > 12) return -1;
//     char* weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//     // int anchordays[4] = {5, 3, 2, 0}; // (18 + i) * 100 to get the century
//     int anchorday = (5 * ((y / 100) % 4) + /*Tuesday*/ 2) % 7;

//     int yLow = y % 100;
//     int a = 0;
//     a += yLow / 12;
//     a += yLow % 12;
//     a += (yLow % 12)/4;
//     a %= 7;
//     a += anchorday;
//     a %= 7;
//     // printf("%s\n", weekdays[a]);  // ! dooms-weekday for the year y

//     int doomsdays[12] = {3, 28, 0, 4, 9, 6, 11, 8, 5, 10, 7, 12};
//     if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
//         for (int i = 0; i < 2; i++) {
//             doomsdays[i]++;
//         }
//     }


//     char* wDay;
//     // * find the closest doomsday in the same month
//     int dDay = doomsdays[m-1];
//     if (dDay < d) {
//         wDay = weekdays[(a + (d - dDay))%7];
//     }
//     else if (dDay > d) {
//         wDay = weekdays[a - (dDay - d)%7];
//     }
//     else {
//         wDay = weekdays[a];
//     }
//     // only gives the weekday of the doomsday, need to add up all the days leading to the given date from the closest doomsday
//     printf("(Conway's method) The day of the week is: %s\n" , wDay);
//     return 0;
// }

// ? difference between given date and 25-01-2020 (Saturday)
int calcNDays(int day, int month, int year) {
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int numDays = year*365 + day;
    year -= (month < 3);

     for (int i = 0; i < month-1; i++) {
         numDays += monthDays[i];
     }

     
     numDays += year/4 - year/100 + year/400;

     return numDays;
}

int dowDiff(int day, int month, int year) {

    int dd, mm, yyyy, dowInt;

    char* dow = (char*) malloc(sizeof(char));
    if (day > 31) return -1;
    if (month > 12) return -1;
    printf("Enter your Birthday: ");
    scanf("%d-%d-%d", &dd, &mm, &yyyy);

    printf("\nEnter the weekday on the birthday: ");
    scanf("%s", dow);


    char* weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    

    for (int i = 0; i < 7; i++) {
        if (!strcmp(weekdays[i], dow)) dowInt = i;
    }


    char* retDay = (char*) malloc(sizeof(char));
    int numDaysGiven = calcNDays(day, month, year);
    int numDaysCurr = calcNDays(dd, mm, yyyy);

    int diff = numDaysCurr - numDaysGiven;
    if (numDaysGiven < numDaysCurr) {
        retDay = weekdays[(dowInt - diff + 864197523) % 7];
    }
    else {
        diff = -diff;
        retDay = weekdays[(dowInt + diff) % 7];
    }
    // printf("%d\n", diff);
    printf("(Difference method) The day of the week is %s\n", retDay);
    return 0;
}



#endif