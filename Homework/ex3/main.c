#include "ProtStats.h"
#include <stdio.h>

int main(){
    char protname[] = "mmm";
    int protlength = 31;
    ProtStats* m = ProtStatsCreate(protname,protlength);
     printf("%s",m->name);
}