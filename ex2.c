// Asaf Ben Shabat 312391774 & Avichai Aziz 316373497
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int hash_arr(const char* str){
    unsigned long h = 5381;
    for (int i =0; str[i] != '\0'; i++){
        int c = str[i];
        h = h*33+c;
    }
    return h;
}

int hash_ptr(const char* str){
    unsigned long h = 5381;
    while (*str != '\0'){
        int c = *str;
        h = h*33+c;
        str++;
    }
    return h;
}

bool is_legal_word(const char* words){
    int len = strlen(words);
    for (int i = 0; i<len;i++){
        if(!(words[i] >= 'a' && words[i] <= 'z' || words[i] >= 'A' && words[i] <= 'Z'))
        return false; // 0
    }
    return true; /// 1  
}

char word_tolower(char* str){
      while (*str != '\0')
   {   
    if(*str >='A' && *str<='Z'){
    *str = *str + 32;
    }
      str++; 
   }
}
    
int main(){
    char word_hash[500000] = {0};
    char cmd[10] = {};
    char str[10] = {};
    while (true){
        unsigned long i = 0;
        printf("$ ");
        scanf("%s",cmd);
        if (!strcmp(cmd,"EXIT"))
        {
            break;
        }

        scanf("%s",str);
        if (!strcmp(cmd,"ADD") && (is_legal_word(str) == 1)){
            word_tolower(str);
            i = hash_arr(str);
            word_hash[i%500000] = 1;        
        }

        else if (!strcmp(cmd,"CHECK") && (is_legal_word(str) == 1)){
            word_tolower(str);
            i = hash_ptr(str);
            (word_hash[i%500000] == 1)? printf("exists\n") : printf("does not exist\n");
        }

        else
        {
            printf("illegal command\n");
            fflush(stdin);
        }
        

    }
    return 0;
}

/* RUN EXAMPLE :
$ ADD hello
$ CHECK HELLO
exists
$ CHECK world
does not exist
$ ADD 123
illegal command
$ KUKU hello
illegal command
$ EXIT*/
