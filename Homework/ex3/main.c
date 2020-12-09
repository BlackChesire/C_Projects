//Avichai Aziz 316373497 & Asaf Ben Shabat 312391774.
#include "ProtStats.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr,"\nUsage : %s <fastafile>\n",argv[0]); // to make sure argv[1] is fasta file !
        return 1;
    }
    int n =0;
    ProtStats *a = read_fasta_file(argv[1],&n);
    printf("N\tName\tLength\tHydro\tCharged\tPolar\n"); // print file format
    for(int i=0; i < n; i++) {
        printf("%d\t%s\t%d\t%.1lf\t%.1lf\t%.1lf\n",i+1,a[i].name,a[i].length,a[i].aa_freq[0],a[i].aa_freq[1],a[i].aa_freq[2]);
    }
    free(a); // free memory of the Prostats
    // all allocated memory freed inside the functions, zero memory leaked
    return 0;
}
