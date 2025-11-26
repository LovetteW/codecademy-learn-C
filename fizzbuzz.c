#include <stdio.h>
int main() {
  int printNumber = 1;
  for(printNumber = 1; printNumber < 101; printNumber++){
    if (printNumber % 3 == 0 && printNumber % 5 == 0) {
      printf("FizzBuzz\n");
    } else if (printNumber % 3 == 0) {
      printf("Fizz\n");
    } else if (printNumber % 5 == 0){
      printf("Buzz\n");
    } else {
      printf("%i\n", printNumber);
    }
  }
}
