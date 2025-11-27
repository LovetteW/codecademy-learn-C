#include <stdio.h>
#include <string.h>

int main() {
  //create frequency counters for letters a, b, c, d
  int counter1[] = {0, 0, 0, 0};
  int counter2[] = {0, 0, 0, 0};
  //provide strings to compare
  char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad"; // 34 char + \0
  char s2[] = "bbbcc bdddccccad cdbbaaacaccdabdd"; //33 char + \0
  //create anagram flag [0 = true, 1 = false]
  int flag = 0;
  
  //confirm strlen() returns what I expect: yes it does
  printf("Strlen(s1): %i\n", (int)strlen(s1)); //prints 34
  printf("Strlen(s2): %i\n", (int)strlen(s2)); //prints 33

  //count frequency of each letter in s1
  //You call strlen(s1) and strlen(s2) in every loop condition, which recalculates the string length each time. Store the length in a variable before the loop to improve efficiency.
  for(int i = 0; i < strlen(s1); i++){
    switch(s1[i]){
      case 'a': counter1[0]++;
      break;
      case 'b': counter1[1]++;
      break;
      case 'c': counter1[2]++;
      break;
      case 'd': counter1[3]++;
      break;
      default: printf("Not registering character, \"%c\"\n", s1[i]);
      break;
    }
  }

  //count frequency of each letter in s2
  for(int i = 0; i < strlen(s2); i++){
    switch(s2[i]){
      case 'a': counter2[0]++;
      break;
      case 'b': counter2[1]++;
      break;
      case 'c': counter2[2]++;
      break;
      case 'd': counter2[3]++;
      break;
      default: printf("Not registering character, \"%c\"\n", s2[i]);
      break;
    }
  }

  //remembering sizeof() & dividing by data type
  printf("Size of counter1: %i\n", (int)sizeof(counter1));
  printf("Size of counter2: %i\n", (int)sizeof(counter2)/(int)sizeof(int));
  // ^^^^^^^^^ the (int) fixed the error: "warning: format ‘%i’ expects argument of type ‘int’, but argument 2 has type ‘long unsigned int’ [-Wformat=]"

  for(int i = 0; i < sizeof(counter1)/sizeof(int); i++){
    if(counter1[i] != counter2[i]){
      flag = 1;
      break;
    }
  }

  printf("Counter 1: %i, %i, %i, %i\n", counter1[0], counter1[1], counter1[2], counter1[3]);
  printf("Counter 2: %i, %i, %i, %i\n", counter2[0], counter2[1], counter2[2], counter2[3]);
  printf("Flag : %i\n", flag);

  if(flag != 0){
    printf("Not an anagram!");
  } else {
    printf("Holy FUCK it's an anagram!");
  }
}
