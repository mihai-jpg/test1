#include "menu_lldi.h"
#include "lldi.h"
#include "citiri.h"
#include <iostream>
using namespace std;

Lldi lldi;
Citiri c_lldi;

int n2,x2,y2,k2;

void creare_lldi()
{
    lldi.int_lldi(lldi.prim,lldi.ultim);
    cout<<"nr de valori n= ";c_lldi.citire_valori(n2,"nr de valori n=");
    lldi.creare_primul(lldi.prim,lldi.ultim);
    for(int i=2;i<=n2;i++)
    {
        cout<<"x= "; c_lldi.citire_valori(x2,"x= ");
        lldi.adaug_sfarsit(lldi.prim, lldi.ultim, x2);
    }
}

void meniu_adaugare(int op)
{
    do
    {
        op=-1;
        cout<<"~~~Adaugare~~~"<<endl;
        cout<<"1.Adaugare la inceput"<<endl;
        cout<<"2.Adaugare la final"<<endl;
        cout<<"3.Adaugare dupa valoarea y"<<endl;
        cout<<"4.Adaugare inainte de valoarea y"<<endl;
        cout<<"5.Adaugare pe pozitia k"<<endl;
        cout<<"0.Exit"<<endl<<endl;
        c_lldi.citire_optiune(op,5);
        cout<<endl;

        if(op==1)
        {
            cout<<"x= "; c_lldi.citire_valori(x2,"x= ");
            cout<<endl;
            lldi.adaug_inceput(lldi.prim,lldi.ultim,x2);
            cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
        }
        else if(op==2)
        {
            cout<<"x= "; c_lldi.citire_valori(x2,"x= ");
            cout<<endl;
            lldi.adaug_sfarsit(lldi.prim,lldi.ultim,x2);
            cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
        }
        else if(op==3)
        {
            cout<<"x= "; c_lldi.citire_valori(x2,"x= ");
            cout<<"y= "; c_lldi.citire_valori(y2,"y= ");
            cout<<endl;
            lldi.inserare_dvk(lldi.prim,lldi.ultim,x2,y2);
            if(lldi.inserat_dvk)
                cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
            else
                cout<<"!!Valoarea "<<y2<<" nu exista in llsi!!"<<endl<<endl;
        }
        else if(op==4)
        {
            cout<<"x= "; c_lldi.citire_valori(x2,"x= ");
            cout<<"y= "; c_lldi.citire_valori(y2,"y= ");
            cout<<endl;
            lldi.inserare_ivk(lldi.prim,lldi.ultim,x2,y2);
            if(lldi.inserat_ivk)
                cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
            else
                cout<<"!!Valoarea "<<y2<<" nu exista in llsi!!"<<endl<<endl;
        }
        else if(op==5)
        {
            cout<<"x= "; c_lldi.citire_valori(x2,"x= ");
            cout<<"k= "; c_lldi.citire_valori(k2,"k= ");
            cout<<endl;
            lldi.inserare_ppk(lldi.prim,lldi.ultim,x2,k2); 
            if(lldi.inserat_ppk)
                cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
            else
                cout<<"!!Pozitia "<<k2<<" nu exista in llsi!!"<<endl<<endl;
        }
    }
    while(op!=0);
}

void meniu_eliminare(int op)
{

}

void M_lldi::lldi_menu()
{
    do
    {
        op=-1;
        cout<<"~~~LLDI~~~"<<endl;
        if(lldi.lldi_creat)
        {
            cout<<"1.Adaugare"<<endl;
            cout<<"2.Eliminare"<<endl;
            cout<<"3.Afisare"<<endl;
            cout<<"0.Exit"<<endl<<endl;
            c_lldi.citire_optiune(op,3);
            cout<<endl;

            if(op==1)
            {
                meniu_adaugare(op);
                op=-1;
            }
            else if(op==2)
            {
                meniu_eliminare(op);
                op=-1;
            }
            else if(op==3)
            {
                lldi.afisez(lldi.prim,lldi.ultim);
                cout<<endl;
            }
        }
        else
        {
            cout<<"1.Creare"<<endl;
            cout<<"0.Exit"<<endl<<endl;
            c_lldi.citire_optiune(op,1);
            cout<<endl;
            if(op==1)
            {
                creare_lldi();
                cout<<endl<<"*lldi creat cu succes*"<<endl<<endl;
            }
        }
    }
    while(op!=0);
}