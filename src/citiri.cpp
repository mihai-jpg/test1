#include "citiri.h"
#include <iostream>
#include <string>
using namespace std;

bool Citiri::este_cifra(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
            continue;
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}

void Citiri::citire_optiune(int&op,int n)
{
    string s;
    while(op<0||op>n)
    {
        cout<<"Alege optiune: "; getline(cin,s);
        if(este_cifra(s)&&!s.empty())
            op=stoi(s);
        else
        {
            cout<<"Optiune invalida!"<<endl;
            continue;
        }
        if(op<0||op>n)
            cout<<"Optiune invalida!"<<endl;
    }
}

void Citiri::citire_valori(int&n,string x)
{
    string s;
    getline(cin,s);
    while(!este_cifra(s)||s.empty())
    {
        cout<<endl<<"Valoare invalida!"<<endl<<endl;
        cout<<x; getline(cin,s);
    }
    n=stoi(s);
}