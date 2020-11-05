// Asaf Ben Shabat 312391774 & Avichai Aziz 316373497
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int hash_arr(const char* str){
    unsigned long h = 5381;
    
    return h;
}
int hash_ptr(const char* str){
    unsigned long h = 5381;
    //TODO
    return h;
}
bool is_legal_word(const char* words){
    for (int i = 0; i<strlen(words);i++){
        if(!(words[i] >= 'a' && words[i] <= 'z' || words[i] >= 'A' && words[i] <= 'Z'))
        return false; // 0
    }

    return true; // 1
    
}

char word_tolower(char* word){
    
}
int main(){
    // char words[] ="AVICHAI";
    // word_tolower(words);
    char cmd[10] = {};
    char str[10] = {};
    while (true){
        printf("$ ");
        scanf("%s",cmd);
        if (!strcmp(cmd,"EXIT"))
        {
            break;
        }
        scanf("%s",str);
        if (!strcmp(cmd,"ADD") && (is_legal_word(str) == 1)){
            printf("ADD BLOCK");
            break;
        }
        if (!strcmp(cmd,"CHECK") && (is_legal_word(str) == 1)){
            printf("CHECK BLOCK");
            break;
        }

        else
        {
            printf("illegal command\n");
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