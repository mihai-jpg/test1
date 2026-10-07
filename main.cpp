#include "src/menu_llsi.h"
#include "src/menu_lldi.h"
#include "src/citiri.h"
#include "src/menu_coada.h"
#include <iostream>
using namespace std;

int main(){
    M_llsi m_llsi;
    M_lldi m_lldi;
    M_coada m_coada;
    Citiri c;

    int op;

    do
    {
        op=-1;
        cout<<"1. Lista Liniară Simplu Înlănțuită (LLSI)"<<endl;
        cout<<"2. Lista Liniară Dublu Înlănțuită (LLDI)"<<endl;
        //cout<<"3. Lista Circulară"<<endl;
        cout<<"3. Coadă (FIFO)"<<endl;
        //cout<<"4. Stivă (LIFO)"<<endl;
        cout<<"0. Exit"<<endl<<endl;
        c.citire_optiune(op,3);
        cout<<endl;

        if(op==1)
        {
            m_llsi.llsi_menu();
        }
        else if(op==2)
        {
            m_lldi.lldi_menu();
        }
        else if(op==3)
        {
            m_coada.coada_menu();
        }
    }
    while(op!=0);
    return 0;
}