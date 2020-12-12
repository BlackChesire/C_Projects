#define _GNU_SOURCE // clears all servers warnings
#ifndef PROTSTATS_H
#define PROTSTATS_H

 typedef struct
{
    char name[32];
    int length;
    double aa_freq[3]; //hydro polar charged
}ProtStats;
typedef enum {Hydrophobic, Charged, Polar} aa_type;

int num_prots(char* fasta_file_name);

ProtStats* ProtStatsCreate(char* protname,char* protSequence);

void ProtStatsInit(char* protname,char* protSequence,ProtStats* protID);

void ProtStatsCopy(ProtStats* protID1, ProtStats* protID2);

void ProtStatsSwap(ProtStats* protID1, ProtStats* protID2);

ProtStats* read_fasta_file(char* fastafilename,unsigned int* number);

aa_type find_type(char type);

#endif