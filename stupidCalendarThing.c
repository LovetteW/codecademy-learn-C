#include <stdio.h>
#include <stdbool.h>
int main() {
  int mm;
  int dd;
  int yy;
  int days_left_to_add;
  printf("Input a \"mm dd yy\" year between 1800 and 10000 plus the numbers to add:\n");
  scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);


  int year;
  printf("Input a year between 1800 and 10000:\n");
  scanf("%d", &year);
  bool is_leap_year(int year){
    /*A leap year HAS to be divisible by 4 and
    NOT divisible by 100
    EXCEPT when divisible by 400.*/
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
      return true;
    } else {
      return false;
    };
  }


  int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  void add_days_to_date(int* mm, int* dd, int* yy, int* days_left_to_add){
    int days_left_in_month;
    while(*days_left_to_add != 0){
      days_left_in_month = days_in_month[*mm];
      if(*mm == 2 && is_leap_year(*yy)){
        days_left_in_month++;
      }
      if(*days_left_to_add > days_left_in_month){
        *days_left_to_add = *days_left_to_add - days_left_in_month - 1;
        if(*mm == 12){
          *mm = 1;
        } else {
          *mm += 1;
          *yy += 1;
        }
      }
      if(*days_left_to_add <= days_left_in_month){


      }
      *dd = *dd + *days_left_to_add;
      *days_left_to_add = 0;
    }
  }


  add_days_to_date(&mm, &dd, &yy, &days_left_to_add);
  printf("%d/%d/%d\n", mm, dd, yy);


  if(is_leap_year(year) == true) {
    printf("Leap Year\n");
  } else {
    printf("Not Leap Year\n");
  }
}

