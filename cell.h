#pragma once
#include "genome.h"
#include <vector>

using namespace std;

class Cell : public Genome
{
private:
    vector<Genome> Chromosomes;

public:
    void addChromosome(Genome genome);
    Genome getChromosome(int n);
    vector<Genome> getAllChromosomes();

    void CellDeath();

    void SmallMutationDNA(char ch1, char ch2, int n, int m);
    void BigMutationDNA(string str1, int n, string str2, int m);
    void ReverseMutationDNA(string str1, int n);

    void Palindorme(int n);
};