#include <stdio.h>
int main(){
    char operator = 0;
    float num1 = 0, num2 = 0, result;
    printf("Please enter number 1");
    scanf("%f", &num1);
    printf("Please enter number 2");
    scanf("%f",&num2);
    printf("choose an operator:\n");
    scanf(" %c", &operator);
    switch(operator){
        case '+':
        result = num1 + num2;
        break;
        case '-':
        result = num1 - num2;
        break;
        case '*':
        result = num1 * num2;
        break;
        case '/':
        if (num1 == 0 || num2 == 0){
            printf("you cannot divide zero or by zero");
            return 1;
        }
        result = num1 / num2;
        break;
        default:
        printf("wrong operator");

    }
    printf("the is the result: %f", result);
    return 0;
}