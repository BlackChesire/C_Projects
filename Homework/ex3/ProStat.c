//Avichai Aziz 316373497 & Asaf Ben Shabat 312391774
#include "ProtStats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_prots(char* fasta_file_name){ // checking the amount of prots in fasta files
    size_t maxl = 256; // in order to allocate memory for line
    char *line = malloc(maxl * sizeof(char));
    if(!line){
        printf("Error, memory not allocated!\n");
        return -2;
    }
    int num_of_prots = 0;
    FILE* file = fopen(fasta_file_name, "r");
    if(!(file)){
        fprintf(stderr,"Error, failed to open file %s, line:%d\n",__FILE__, __LINE__);
        exit(1);
    }
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '>') {
            num_of_prots++;
        }
    }
    fclose(file);
    free(line);
    return num_of_prots;
} 

ProtStats* ProtStatsCreate(char* protname,char* protSequence){ //Creating a Prostats data info by the name and the sequence
    int length = strlen(protSequence);
    int hydro = 0 , charged = 0 ,polar = 0;
    ProtStats *prot = (ProtStats*)calloc(sizeof(ProtStats),1);
    if(prot == NULL)
        return NULL;
    strcpy(prot->name,protname);
    prot->length = length;
    for (int i =0; protSequence[i] != '\0'; i++){ 
        switch (find_type(protSequence[i])) {
            case Hydrophobic:
                hydro++;
                break;
            case Charged:
                charged++;
                break;
            case Polar:
                polar++;
                break;
        }
    }
    prot->aa_freq[Hydrophobic] = (float)hydro / length *100;
    prot->aa_freq[Charged] = (float)charged / length *100;
    prot->aa_freq[Polar] = (float)polar/ length *100;
    return prot;
}
void ProtStatsInit(char* protname,char* protSequence,ProtStats* protID){
    int hydro=0,charged=0,polar=0;
    int length = strlen(protSequence);
    strcpy(protID->name,protname);
    protID->length = strlen(protSequence);
    for (int i =0; protSequence[i] != '\0'; i++){ 
        switch (find_type(protSequence[i])) {
            case Hydrophobic:
                hydro++;
                break;
            case Charged:
                charged++;
                break;
            case Polar:
                polar++;
                break;
        }
    }
      protID->aa_freq[Hydrophobic] = ((float)hydro / length) * 100;
      protID->aa_freq[Polar] = ((float)polar / length) * 100;
      protID->aa_freq[Charged] = ((float)charged / length) * 100;  
}

void ProtStatsCopy(ProtStats* prot1, ProtStats* prot2) {
    
    prot1->name = strdup(prot2->name); //copy the prot2 name to the prot1 name
    prot1->length = prot2->length; //copy the prot2 length to the prot1 length
    //copy the prot2 aa_freq to the prot1 aa_freq
    prot1->aa_freq[Hydrophobic] = prot2->aa_freq[Hydrophobic];
    prot1->aa_freq[Charged] = prot2->aa_freq[Charged];
    prot1->aa_freq[Polar] = prot2->aa_freq[Polar];
}

void ProtStatsSwap(ProtStats* prot1, ProtStats* prot2) {
    char* str =NULL;
    int num = 0;
    double val = 0;
    //swap the prot's name
    str = strdup(prot1->name);
    free(prot1->name);
    prot1->name = strdup(prot2->name);
    free(prot2->name);
    prot2->name = strdup(str);
    free(str);
    //swap the prot's length
    num = prot1->length;
    prot1->length = prot2->length;
    prot2->length = num;
    //swap the prot's aa_freq
    for(int aminoAc=0; aminoAc <= Polar; aminoAc++) { //loop1: aminoAc=Hydrophobic , loop2: aminoAc=Charged, loop3: aminoAc=Polar
        val = prot1->aa_freq[aminoAc];
        prot1->aa_freq[aminoAc] = prot2->aa_freq[aminoAc];
        prot2->aa_freq[aminoAc] = val;
    }
}

ProtStats* read_fasta_file(char* fastafilename,  unsigned int* number) {
    FILE* file = fopen(fastafilename, "r");
    char* buffer = NULL; 
    size_t bufsize = 0;
    *number = num_prots(fastafilename);
    ProtStats* prots = (ProtStats*) malloc(sizeof(ProtStats)*(*number));
    
    if(file == NULL) {
        fprintf(stderr, "Error, invilable to open the file %s, line: %d\n", __FILE__, __LINE__);
        return NULL;
    }
    for(int i=0; i < *number; i++) {
        if(getline(&buffer, &bufsize, file) != EOF) {
            char* name = strdup(buffer);
            name[strlen(name)-1]='\0';
            if(getline(&buffer, &bufsize, file) != EOF) {
                buffer[strlen(buffer)-1]='\0';
                ProtStatsInit(name+1, buffer, prots+i);
            }
            free(name);
        }
    }
    free(buffer);
    fclose(file);
    return prots;
}

aa_type find_type(char charAminoAcids){
    if(strchr("AILFVPG", charAminoAcids) != NULL) {
        return Hydrophobic;
    }    
    else if(strchr("QNHSTYCMW", charAminoAcids) != NULL) {
        return Polar;
    }
    else if(strchr("RKDE", charAminoAcids) != NULL) {
        return Charged;
    }
}