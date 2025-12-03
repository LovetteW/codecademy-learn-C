#include<stdio.h>
#include<string.h>
void copy(char* dst, char* src){
  // Code for copying a string goes here
  while(*src != '\0'){
    *dst = *src;
    src++; // Apparently the dereferenc operator isn't necessary, here?
    dst++; // I'm guessing 'cause * is what accesses it, but otherwise the arithmetic is just modifying which address it points to
  }
  *dst = '\0'; // Because our while loop stops AT the null character
}
int main(){
  char srcString[] = "We promptly judged antique ivory buckles for the next prize!";
  char dstString[strlen(srcString) + 1];
  copy(dstString, srcString);
  printf("%s", dstString);
}
