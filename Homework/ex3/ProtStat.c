//Avichai Aziz 316373497 & Asaf Ben Shabat 312391774.
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

ProtStats* ProtStatsCreate(char* protname,char* protSequence){ //Creating a Protstats data info by name & sequence
    ProtStats *prot = (ProtStats*)calloc(sizeof(ProtStats),1);
    if(prot == NULL)
        return NULL;
    ProtStatsInit(protname, protSequence, prot);
    return prot;
}
void ProtStatsInit(char* protname,char* protSequence,ProtStats* protID){ // initializing protstats date info to the sent address
    int hydro=0,charged=0,polar=0; // types of amino acid
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
    strcpy(prot1->name, prot2->name); //copy the prot2 name to the prot1 name
    prot1->length = prot2->length; //copy the prot2 length to the prot1 length
    //copy the prot2 aa_freq to the prot1 aa_freq
    prot1->aa_freq[Hydrophobic] = prot2->aa_freq[Hydrophobic];
    prot1->aa_freq[Polar] = prot2->aa_freq[Polar];
    prot1->aa_freq[Charged] = prot2->aa_freq[Charged];

}

void ProtStatsSwap(ProtStats* prot1, ProtStats* prot2) {
    ProtStats* temp = (ProtStats*)calloc(sizeof(ProtStats),1);
    //swap the prot's name
    strcpy(temp->name, prot1->name);
    strcpy(prot1->name, prot2->name);
    strcpy(prot2->name, temp->name);
    //swap the prot's length
    temp->length = prot1->length;
    prot1->length = prot2->length;
    prot2->length = temp->length;
    //swap the prot's aa_freq
    for(int aminoAc=0; aminoAc <= Polar; aminoAc++) {
        temp->aa_freq[aminoAc] = prot1->aa_freq[aminoAc];
        prot1->aa_freq[aminoAc] = prot2->aa_freq[aminoAc];
        prot2->aa_freq[aminoAc] = temp->aa_freq[aminoAc];
    }
    free(temp);
}

ProtStats* read_fasta_file(char* fastafilename,  unsigned int* number) { // reading prots from fasta file and initializing prots data info
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

aa_type find_type(char charAminoAcids){ // finding the type of the Amino by the letter received 
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