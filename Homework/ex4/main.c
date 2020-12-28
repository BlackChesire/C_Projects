#include <stdio.h>
#include <stdlib.h>
#include <regex.h> //?????????????????

int main(int argc, char *argv[]) {
    if(argc != 4) {
        fprintf(stderr, "Usage: %s <in-file> <out-unique> <out-order>\n",argv[0]);
    }
    //argv[1] - path
    //argv[2] - set
    //argv[3] - array by apperance
    Array array_date =  ArrayCreate(0,Element (*cpy)(Element), void (*fre)(Element)); //??????????
    Set set_date = SetCreate(Element (*cpy)(Element) //??????????????????
    char* buffer;
    size_t buffer_size;
    FILE* file = fopen(argv[1], "r");
    int line_counter = 0;
    while(getline(buffer, buffer_size, file) != EOF) {
        char* line = *buffer;
        
        for(int i=0; i<sizeof(line)-1; i++) {
            if(line[i] == "/")  {
                char* day = ; 
            }
        }
        if(line == "%[0-9]{1,2}s/%[0-9]{1,2}s/%[0-9]{1,4}s") {

        }

    }
    return 0;
}
