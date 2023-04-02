// #include "/Users/meysam/stdc++.h"
#include "genome.h"
#include "cell.h"
#include <string>
using namespace std;

int main()
{
    Genome gen, gen2;
    gen.setDNA("AAACCC");
    gen2.setDNA("TTCCGGA");

    Cell cell;
    cell.addChromosome(gen);
    cell.addChromosome(gen2);
    cell.BigMutationDNA("AA",0,"GG",1);
}