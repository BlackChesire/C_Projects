#include "ProtStats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num_prots(char* fasta_file_name){ // WORKING
    char *line = malloc(maxl * sizeof(char));
if(!line){
    printf("Memory not allocated!!\n");
    return -2;
    }
    int num_of_prots = 0;
    FILE* file = fopen(fasta_file_name, "r");
    if(!(file)){
        fprintf(stderr,"failed to open file %s\n",fasta_file_name);
        exit(-1);
    }
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '>')
        {
            num_of_prots++;
        }
        
    }
    fclose(file);
    return num_of_prots;
} 

ProtStats* ProtStatsCreate(char* protname,int protlength){ //WORKING
  ProtStats *prot = (ProtStats*)calloc(sizeof(ProtStats),1);
  strcpy(prot->name,protname);
  prot->length = protlength;
  return prot;
}
void ProtStatsInit(char* protname,int protLength,ProtStats* protID){ //not sure ! 
    strcpy(protID->name,protname);
    protID->length = protLength;
}

