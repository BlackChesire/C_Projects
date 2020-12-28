#include <stdio.h>
#include <stdlib.h>
#include <regex.h> 
#include "Array.h"
#include "Set.h"
int main(int argc, char *argv[]) {
    if(argc != 4) {
        fprintf(stderr, "Usage: %s <in-file> <out-unique> <out-order>\n",argv[0]);
    }
    //argv[1] - path
    //argv[2] - set
    //argv[3] - array by apperance
    Array array_date =  ArrayCreate(0,Element (*cpy)(Element), void (*fre)(Element)); //??????????
    Set set_date = SetCreate(Element (*cpy)(Element); //??????????????????
    char* buffer = NULL;
    size_t buffer_size= 0;
    char* line;
    FILE* file = fopen(argv[1], "r");
    int line_counter = 0;
    while(getline(&buffer, &buffer_size, file) != EOF) {
        char* line = *buffer;
        }
        if(is_legal_date(line)) {

        }
    return 0;
    }
    


int is_legal_date(const char *str) { //checks if the pattern is day/month/year 
  regex_t reg;
  int val = regcomp(&reg, "^[0-9]\\{1,2\\}/[0-9]\\{1,2\\}/[0-9]\\{1,4\\}$",
                    REG_NEWLINE);
  val = regexec(&reg, str, 0, NULL, 0);
  regfree(&reg);
  return val == 0;
}