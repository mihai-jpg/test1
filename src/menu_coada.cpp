#include "menu_coada.h"
#include "lldi.h"
#include "citiri.h"
#include <iostream>
using namespace std;

Lldi lldi_coada;
Citiri c_coada;

int n3,x3;

void creare_coada()
{
    lldi_coada.int_lldi(lldi_coada.prim_coada,lldi_coada.ultim_coada,lldi_coada.coada_creat);
    cout<<"nr de valori n= ";c_coada.citire_valori(n3,"nr de valori n=");
    lldi_coada.creare_primul(lldi_coada.prim_coada,lldi_coada.ultim_coada);
    for(int i=2;i<=n3;i++)
    {
        cout<<"x= "; c_coada.citire_valori(x3,"x= ");
        lldi_coada.adaug_sfarsit(lldi_coada.prim_coada, lldi_coada.ultim_coada, x3);
    }
}

void M_coada::coada_menu()
{
    do
    {
        op=-1;
        cout<<"~~~COADA~~~"<<endl;
        if(lldi_coada.coada_creat)
        {
            cout<<"1.Adaugare"<<endl;
            cout<<"2.Eliminare"<<endl;
            cout<<"3.Afisare"<<endl;
            cout<<"0.Exit"<<endl<<endl;
            c_coada.citire_optiune(op,3);
            cout<<endl;

            if(op==1)
            {
                cout<<"x= "; c_coada.citire_valori(x3,"x= ");
                cout<<endl;
                lldi_coada.adaug_sfarsit(lldi_coada.prim_coada,lldi_coada.ultim_coada,x3);
                cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
            }
            else if(op==2)
            {
                lldi_coada.stergere_primul(lldi_coada.prim_coada,lldi_coada.ultim_coada);
                cout<<"*stergere efectuata cu succes*"<<endl<<endl;
            }
            else if(op==3)
            {
                lldi_coada.afisez(lldi_coada.prim_coada,lldi_coada.ultim_coada);
                cout<<endl;
            }
        }
        else
        {
            cout<<"1.Creare"<<endl;
            cout<<"0.Exit"<<endl<<endl;
            c_coada.citire_optiune(op,1);
            cout<<endl;
            if(op==1)
            {
                creare_coada();
                cout<<endl<<"*lldi creat cu succes*"<<endl<<endl;
            }
        }
    }
    while(op!=0);
}