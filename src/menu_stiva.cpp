#include "menu_stiva.h"
#include "llsi.h"
#include "citiri.h"
#include <iostream>
using namespace std;

Llsi llsi_stiva;
Citiri c_stiva;

int n4,x4;

void creare_stiva()
{
    llsi_stiva.int_llsi(llsi_stiva.prim_stiva,llsi_stiva.ultim_stiva,llsi_stiva.stiva_creat);
    cout<<"nr de valori n= ";c_stiva.citire_valori(n4,"nr de valori n=");
    llsi_stiva.creare_primul(llsi_stiva.prim_stiva,llsi_stiva.ultim_stiva);
    for(int i=2;i<=n4;i++)
    {
        cout<<"x= "; c_stiva.citire_valori(x4,"x= ");
        llsi_stiva.adaug_sfarsit(llsi_stiva.prim_stiva, llsi_stiva.ultim_stiva, x4);
    }
}
void M_stiva::stiva_menu()
{
    do
    {
        op=-1;
        cout<<"~~~STIVA~~~"<<endl;
        if(llsi_stiva.stiva_creat)
        {
            cout<<"1.Adaugare"<<endl;
            cout<<"2.Eliminare"<<endl;
            cout<<"3.Afisare"<<endl;
            cout<<"0.Exit"<<endl<<endl;
            c_stiva.citire_optiune(op,3);
            cout<<endl;

            if(op==1)
            {
                cout<<"x= "; c_stiva.citire_valori(x4,"x= ");
                cout<<endl;
                llsi_stiva.adaug_sfarsit(llsi_stiva.prim_stiva,llsi_stiva.ultim_stiva,x4);
                cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
            }
            else if(op==2)
            {
                llsi_stiva.stergere_ultimu(llsi_stiva.prim_stiva,llsi_stiva.ultim_stiva);
                cout<<"*stergere efectuata cu succes*"<<endl<<endl;
            }
            else if(op==3)
            {
                llsi_stiva.afisez(llsi_stiva.prim_stiva,llsi_stiva.ultim_stiva);
                cout<<endl;
            }
        }
        else
        {
            cout<<"1.Creare"<<endl;
            cout<<"0.Exit"<<endl<<endl;
            c_stiva.citire_optiune(op,1);
            cout<<endl;
            if(op==1)
            {
                creare_stiva();
                cout<<endl<<"*llsi creat cu succes*"<<endl<<endl;
            }
        }
    }
    while(op!=0);
}