#ifndef PROTSTATS_H
#define PROTSTATS_H
struct ProtStats
{
    char[32] name;
    int[200] length;
    double[3] aa_freq;
    enum aa_type {Hydrophobic,Charged,Polar};
};

int num_prots(Char* fasta_file_name);

ProtStats* ProtStatsCreate(Char* protname,int protlength);

void ProtStatsInit(Char* protname,int protLength,ProtStats* protID);

void ProtStatsCopy(ProtStats* protID1, ProtStats* protID2);

void ProtStatsSwap(ProtStats* protID1, ProtStats* protID2);

ProtStats* read_fasta_file(char* fastafilename,unsigned int* address);

aa_type find_type(char* type);

#endif
