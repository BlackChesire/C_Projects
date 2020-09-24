#include <stdio.h>
int getnumber(){
    int num = 0;
    printf("enter number :\n");
    scanf("%d",&num);
    return num;
}
int addnumbers(int n1,int n2){
    return n1+n2;
}
int main(){
    int num1 = getnumber();
    int num2 = getnumber();
    printf("result:%d", addnumbers(num1,num2));
    return 0;
}