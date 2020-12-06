#include "ProtStats.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){ // argv[1] should be fasta file!
    char prot[200] = "prot1";
    char length[200] = "MEIVCNQNEFNYAIQLVSKAVASRPTHPILANLLLTADQGT";
    //ProtStats* a = ProtStatsCreate(prot,length);  WORKING both Create&Init!
    ProtStats *a = (ProtStats*)calloc(sizeof(ProtStats),1);
    ProtStatsInit(prot,length,a); 
    printf("%s,%d,%f,%f,%f",a->name,a->length,a->aa_freq[0],a->aa_freq[1],a->aa_freq[2]);
}