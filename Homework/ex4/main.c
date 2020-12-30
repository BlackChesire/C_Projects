//Asaf Ben Shabat 312391774 & Avichai Aziz 316373497.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "LinkedList.h"
#include "Array.h"
#include "Set.h"

int is_legal_date(const char *str)
{ //checks if the pattern is day/month/year
    regex_t reg;
    int val = regcomp(&reg, "^[0-9]\\{1,2\\}/[0-9]\\{1,2\\}/[0-9]\\{1,4\\}$", REG_NEWLINE); // REG_NEWLINE is a flag to avoid \n
    val = regexec(&reg, str, 0, NULL, 0);
    regfree(&reg);
    return val == 0;
}
Element strCopy(Element element)
{
    if (!element) {
        return NULL;
    }
    char *source = element;
    char *newStr = strdup(source);
    return newStr;
}
bool strCompare(Element e1, Element e2)
{
    if ((e1 == NULL) || (e2 == NULL)) {
        return NULL;
    }
    else if ((strcmp(e1, e2) != 0)) {
        return false;
    }
    else if ((strcmp(e1, e2) == 0)) {
        return true;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <in-file> <out-unique> <out-order>\n", argv[0]);
        return (-1);
    }
    Array array_date = ArrayCreate(0, strCopy, free);
    Set set_date = SetCreate(strCopy, free, strCompare);
    FILE *file = fopen(argv[1], "r");
    FILE *file_set_out = fopen(argv[2], "w");
    FILE *file_array_out = fopen(argv[3], "w");
    char *buffer = NULL;
    size_t buffer_size = 0;
    char *line;
    int line_counter = 0;
    int j=0; //index
    while (getline(&buffer, &buffer_size, file) != EOF)
    {
        char *line = buffer;
        if (is_legal_date(line))
        {
	        Arrayput(array_date, line, j);
	        SetAdd(set_date, line);
	        j++;
        }
	line_counter++;
    }
    //argv[1] - path
    //argv[2] - set
    //argv[3] - array by apperance
    int i=0; //index
    for (i = 0; i < ArraySize(array_date); i++)
    {
        char* date = ArrayGet(array_date, i);  
	    fprintf(file_array_out, "%s", date);
    }
    // for (Element = setfirst; E != NULL;E = setnext) // iterate

    Element e;
    for (e = SetFirst(set_date); e != NULL; e = SetNext(set_date))
    {
        char *s_date = e;
        fprintf(file_set_out, "%s", s_date);
    }
    fclose(file);
    fclose(file_set_out);
    fclose(file_array_out);
    ArrayDestroy(array_date);
    SetDestroy(set_date);
    return 0;
}
