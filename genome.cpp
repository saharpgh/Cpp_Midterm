#include "genome.h"
#include "utils.cpp"
#include <iostream>
#include <string>
#include <regex>

void Genome::setRNA(string rna)
{
    for (int i = 0; i < rna.size(); i++)
    {
        RNA.push_back(rna[i]);
    }
}
void Genome::setDNA(string dna)
{
    for (int i = 0; i < dna.size(); i++)
    {
        DNA.first.push_back(dna[i]);
        DNA.second.push_back(GivePair(dna[i]));
    }
  
}

void Genome::MakeDNABasedOnRNA()
{
    // make DNA base on RNA
    for (int i = 0; i < RNA.size(); i++)
    {
        cout << GivePair(RNA[i]);
    }
    cout << endl;
}

void Genome::SmallMutationRNA(char ch1, char ch2, int n)
{
    // replace the first n ch1 in RNA with ch2
    while (n > 0)
    {
        for (int i = 0; i < RNA.size(); i++)
        {
            if (RNA[i] == ch1)
            {
                RNA[i] = ch2;
                n -= 1;
            }
        }
    }
}

void Genome::SmallMutationDNA(char ch1, char ch2, int n)
{
    // replace the first n ch1 in DNA with ch2 (in both lines)
    while (n > 0)
    {
        for (int i = 0; i < DNA.first.size(); i++)
        {
            if (DNA.first[i] == ch1)
            {
                DNA.first[i] = ch2;
                n -= 1;
            }
            else if (DNA.second[i] == ch1)
            {
                DNA.second[i] = ch2;
                n -= 1;
            }
        }
    }
}

void Genome::BigMutationRNA(string str1, string str2)
{
    string RNAStr(RNA.begin(),RNA.end());

    RNAStr = regex_replace(RNAStr, regex(str1), str2);
    RNA.clear();
    for (char ch : RNAStr)
       RNA.push_back(ch);
}

void Genome::BigMutationDNA(string str1, string str2)
{
    string DNAFirstStr(DNA.first.begin(), DNA.first.end());
    string DNASecondStr(DNA.second.begin(), DNA.second.end());
   
    int firstIndex = DNAFirstStr.find(str1);
    int secondIndex = DNASecondStr.find(str1);

    cout <<"FIRST INDEX:" << firstIndex << endl;
    cout <<"SECOND INDEX:" << secondIndex << endl;

    // substring not found in both strings
    if (firstIndex == string::npos && secondIndex == string::npos) return;

    if (firstIndex < secondIndex) // firstly found on the first string
    {
       DNAFirstStr = regex_replace(DNAFirstStr, regex(str1), str2);
       DNA.first.clear();
       for (char ch : DNAFirstStr)
            DNA.first.push_back(ch);

       DNA.second.clear();
       for (char ch : DNAFirstStr)
            DNA.second.push_back(GivePair(ch));
    }
    else // firstly found on the second string
    {
       DNASecondStr = regex_replace(DNASecondStr, regex(str1), str2);
       DNA.second.clear();
       for (char ch : DNASecondStr)
            DNA.second.push_back(ch);

       DNA.first.clear();
       for (char ch : DNASecondStr)
            DNA.first.push_back(GivePair(ch));
    }

    // for (char ch : DNA.first)
    //    cout << ch;
    // cout <<endl;
    // for (char ch : DNA.second)
    //    cout << ch;
}