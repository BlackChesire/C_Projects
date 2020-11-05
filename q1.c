#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char to_lower(char* str){
      while ( *str != '\0' )
   {   
    if(*str >='A' && *str<='Z'){

    *str = *str + 32;
    }
      str++; 
   }
}
int main(){
    char str[] = "AVICHAIm";
    to_lower(str);
    printf("%s",str);
    }


    
    