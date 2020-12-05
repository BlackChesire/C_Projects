#include <stdio.h>
// Asaf ben shabat 31239174
char mytoupperr(char a){
    if(a >=97 && a<=122){
    a -= 32;
    return a;
    }
    else
    {
        return a;
    }
    
}

int main(){
    char string[26] ={0};
    char c =0;
    printf("please enter a char :");
    while((c = getchar()) != 10){
        c = mytoupperr(c);
        if(c>='A' && c<='Z')
        string[(c+13) % 26 ] += 1;
    }
    for(int i=0; i < 26; i++){
        printf("%c:%d\n",'A'+i,string[i]);
    }

}
