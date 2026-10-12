#include "menu_llsi.h"
#include "llsi.h"
#include "citiri.h"
#include <iostream>
using namespace std;

Llsi llsi;
Citiri c_llsi;

int n,x,i,y,k;

void creare()
{
    llsi.int_llsi(llsi.prim,llsi.ultim,llsi.llsi_creat);
    cout<<"nr de valori n= ";c_llsi.citire_valori(n,"nr de valori n=");
    llsi.creare_primul(llsi.prim,llsi.ultim);
    for(i=2;i<=n;i++)
    {
        cout<<"x= "; c_llsi.citire_valori(x,"x= ");
        llsi.adaug_sfarsit(llsi.prim, llsi.ultim, x);
    }
}

void meniu_adaugare(int&op)
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
        c_llsi.citire_optiune(op,5);
        cout<<endl;

        if(op==1)
        {
            cout<<"x= "; c_llsi.citire_valori(x,"x= ");
            cout<<endl;
            llsi.adaug_inceput(llsi.prim,llsi.ultim,x);
            cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
        }
        else if(op==2)
        {
            cout<<"x= "; c_llsi.citire_valori(x,"x= ");
            cout<<endl;
            llsi.adaug_sfarsit(llsi.prim,llsi.ultim,x);
            cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
        }
        else if(op==3)
        {
            cout<<"x= "; c_llsi.citire_valori(x,"x= ");
            cout<<"y= "; c_llsi.citire_valori(y,"y= ");
            cout<<endl;
            llsi.inserare_dvk(llsi.prim,llsi.ultim,x,y);
            if(llsi.inserat_dvk)
                cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
            else
                cout<<"!!Valoarea "<<y<<" nu exista in llsi!!"<<endl<<endl;
        }
        else if(op==4)
        {
            cout<<"x= "; c_llsi.citire_valori(x,"x= ");
            cout<<"y= "; c_llsi.citire_valori(y,"y= ");
            cout<<endl;
            llsi.inserare_ivk(llsi.prim,llsi.ultim,x,y);
            if(llsi.inserat_ivk)
                cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
            else
                cout<<"!!Valoarea "<<y<<" nu exista in llsi!!"<<endl<<endl;
        }
        else if(op==5)
        {
            cout<<"x= "; c_llsi.citire_valori(x,"x= ");
            cout<<"k= "; c_llsi.citire_valori(k,"k= ");
            cout<<endl;
            llsi.inserare_ppk(llsi.prim,llsi.ultim,x,k); 
            if(llsi.inserat_ppk)
                cout<<"*adaugare efectuata cu succes*"<<endl<<endl;
            else
                cout<<"!!Pozitia "<<k<<" nu exista in llsi!!"<<endl<<endl;
        }
    }
    while(op!=0);
}

void meniu_eliminare(int&op)
{
    do
    {
        if(llsi.prim!=NULL)
        {
            op=-1;
            cout<<"~~~Eliminare~~~"<<endl;
            cout<<"1.Stergerea primului nod"<<endl;
            cout<<"2.Stergerea ultimului nod"<<endl;
            cout<<"3.Stergerea nodului cu valoarea y"<<endl;
            cout<<"4.Stergerea nodului de pe pozitia k"<<endl;
            cout<<"0.Exit"<<endl<<endl;
            c_llsi.citire_optiune(op,4);
            cout<<endl;

            if(op==1)
            {
                llsi.stergere_primul(llsi.prim,llsi.ultim);
                cout<<"*stergere efectuata cu succes*"<<endl<<endl;
            }
            else if(op==2)
            {
                llsi.stergere_ultimu(llsi.prim,llsi.ultim);
                cout<<"*stergere efectuata cu succes*"<<endl<<endl;
            }
            else if(op==3)
            {
                cout<<"y= "; c_llsi.citire_valori(y,"y= ");
                cout<<endl;
                llsi.stergere_k(llsi.prim,llsi.ultim,y);
                if(llsi.sters_k)
                    cout<<"*stergere efectuata cu succes*"<<endl<<endl;
                else
                    cout<<"!!Valoarea "<<y<<" nu exista in llsi!!"<<endl<<endl;
            }
            else if(op==4)
            {
                cout<<"k= "; c_llsi.citire_valori(k,"k= ");
                cout<<endl;
                llsi.stergere_pk(llsi.prim,llsi.ultim,k);
                if(llsi.sters_pk)
                    cout<<"*stergere efectuata cu succes*"<<endl<<endl;
                else
                    cout<<"!!Pozitia "<<k<<" nu exista in llsi!!"<<endl<<endl;
            }
        }
        else
        {
            cout<<"!!Lista este goala!!"<<endl<<endl;
            op=0;
        }
    }
    while(op!=0);
}

void M_llsi::llsi_menu()
{
    do
    {
        op=-1;
        cout<<"~~~LLSI~~~"<<endl;
        if(llsi.llsi_creat)
        {
            cout<<"1.Adaugare"<<endl;
            cout<<"2.Eliminare"<<endl;
            cout<<"3.Afisare"<<endl;
            cout<<"0.Exit"<<endl<<endl;
            c_llsi.citire_optiune(op,3);
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
                llsi.afisez(llsi.prim,llsi.ultim);
                cout<<endl;
            }
        }
        else
        {
            cout<<"1.Creare"<<endl;
            cout<<"0.Exit"<<endl<<endl;
            c_llsi.citire_optiune(op,1);
            cout<<endl;
            if(op==1)
            {
                creare();
                cout<<endl<<"*llsi creat cu succes*"<<endl<<endl;
            }
        }
    }
    while(op!=0);
}