#include <stdio.h> //in order to use input & output

int main() {
    int number = 0;
    char str[10];
    printf("Enter a name:\n");
    scanf("%s", str);
    printf("Enter a number:\n");
    scanf("%d", &number); // &number means a pointer to number in the memory
    printf("hello, %s:\n", str);
    if (number % 2 == 0) {
        printf("Your number is even!\n");
    } else if (number > 10 && number % 2 !=0) {
        printf("Your number is ODD and greater than 10!\n");
    }
      else if (number % 2 != 0){
          printf("your number is Odd");
      }
      else {
        printf("Your number is ODD and less than or equal to - 10\n");
    }
    return 0;
    }

    
    