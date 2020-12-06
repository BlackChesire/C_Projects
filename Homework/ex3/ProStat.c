#include "ProtStats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
hydrophobic (A I L F V P G)
charged (R K D E)
polar (Q N H S T Y C M W)
*/
int num_prots(char* fasta_file_name){ // WORKING
size_t maxl = 256; // in order to allocate memory for line
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

ProtStats* ProtStatsCreate(char* protname,char* protlength){ //WORKING
int length = strlen(protlength);
int hydro = 0 , charged = 0 ,polar = 0;
  ProtStats *prot = (ProtStats*)calloc(sizeof(ProtStats),1);
  strcpy(prot->name,protname);
  prot->length = length;
  for (int i =0; protlength[i] != '\0'; i++){
      if (protlength[i] == 'A' || protlength[i] == 'I' || protlength[i] == 'L' || protlength[i] == 'F' || protlength[i] == 'V' || protlength[i] == 'P' || protlength[i] == 'G')
      {
         hydro++;
      }
      else if (protlength[i] == 'R' || protlength[i] == 'K' || protlength[i] =='D' || protlength[i] == 'E')
      {
          charged++;
      }
      else if (protlength[i] == 'Q' || protlength[i] == 'N' || protlength[i] == 'H' || protlength[i] == 'S' || protlength[i] == 'T' || protlength[i] == 'Y' || protlength[i] == 'C' || protlength[i] == 'M' || protlength[i] == 'W')
      {
          polar++;
      }
   
  }
      prot->aa_freq[0] = (float)hydro / length;
      prot->aa_freq[1] = (float)polar / length;
      prot->aa_freq[2] = (float)charged / length;
  return prot;
}
void ProtStatsInit(char* protname,char* protlength,ProtStats* protID){
    int hydro=0,charged=0,polar=0;
    int length = strlen(protlength);
    strcpy(protID->name,protname);
    protID->length = strlen(protlength);
    for (int i =0; protlength[i] != '\0'; i++){
      if (protlength[i] == 'A' || protlength[i] == 'I' || protlength[i] == 'L' || protlength[i] == 'F' || protlength[i] == 'V' || protlength[i] == 'P' || protlength[i] == 'G')
      {
         hydro++;
      }
      else if (protlength[i] == 'R' || protlength[i] == 'K' || protlength[i] =='D' || protlength[i] == 'E')
      {
          charged++;
      }
      else if (protlength[i] == 'Q' || protlength[i] == 'N' || protlength[i] == 'H' || protlength[i] == 'S' || protlength[i] == 'T' || protlength[i] == 'Y' || protlength[i] == 'C' || protlength[i] == 'M' || protlength[i] == 'W')
      {
          polar++;
      }
      protID->aa_freq[0] = (float)hydro / length;
      protID->aa_freq[1] = (float)polar / length;
      protID->aa_freq[2] = (float)charged / length;
   
}
}

