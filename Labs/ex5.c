#include <stdio.h>
#include <stdbool.h>
void remove_char(char s[],char ch){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == ch){
            for(int j = i; s[j] != '\0';j++){
                s[j] = s[j+1];
            }
            i--;
        }
    }
}
void no_dividers(int* s1, unsigned int n1,int* s2,unsigned int n2){
    for(int i = 0; i < n1; i++){
        bool flag = true;
        for (int j = 0; j <n2; j++)
        {
            if(*(s1+i) % *(s2+j) == 0){
                flag = false;
                break;
            }

        }
        if (flag == true)
        {
            printf("%d ",*(s1+i));
        }
        
    }

}
int main(){
    int s1[] = {1, 10, 5, 4, 21, 49, 24}, s2[] = {2, 3};
    unsigned int n1 = sizeof(s1) / sizeof(int);
    unsigned int n2 = sizeof(s2) / sizeof(int);
    no_dividers(s1,n1,s2,n2);

    return 0;
}