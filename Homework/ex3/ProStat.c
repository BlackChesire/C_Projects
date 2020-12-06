#include "ProtStats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int num_prots(char* fasta_file_name){ // TODO
   int sumofprots;
   FILE* fp = fopen(fasta_file_name,"r");
   if (fp == NULL){
       printf("Failed to read the fasta file\n");
       return -1;
   }
   while (fscanf(fp) == 1)
   {
       sumofprots++;
   }
   return sumofprots;
    
} */

ProtStats* ProtStatsCreate(char* protname,int protlength){
  ProtStats *prot = (ProtStats*)calloc(sizeof(ProtStats),1);
  strcpy(prot->name,protname);
  prot->length = protlength;
  return prot;
}
void ProtStatsInit(char* protname,int protLength,ProtStats* protID){ //not sure !
    strcpy(protID->name,protname);
    protID->length = protLength;
}

