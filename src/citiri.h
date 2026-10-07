#ifndef CITIRI_H
#define CITIRI_H
#include <string>

class Citiri{
    public:
        bool este_cifra(std::string s);
        void citire_optiune(int&op,int n);
        void citire_valori(int&n,std::string x);
};

#endif