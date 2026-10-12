#include "llsi.h"
#include "citiri.h"
#include <iostream>
using namespace std;

Citiri citi_llsi;

void Llsi::int_llsi(nod*&prim,nod*&ultim,bool&creat)
{
    prim=ultim=NULL;
    creat=true;
}

void Llsi::creare_primul(nod *&prim,nod *&ultim)
{
    int x;
    cout<<"valoarea din primul nod x= "; citi_llsi.citire_valori(x,"valoarea din primul nod x= ");
    prim=new nod;
    prim->info=x;
    prim->urm=NULL;
    ultim=prim;
}

void Llsi::adaug_sfarsit(nod*prim,nod*&ultim,int x)
{
    p=new nod;
    p->info=x;
    p->urm=NULL;
    ultim->urm=p;
    ultim=p;
}

void Llsi::afisez(nod*prim,nod*ultim)
{
    p=prim;
    while(p!=NULL)
    {
        cout<<p->info<<' ';
        p=p->urm;
    }
    cout<<endl;
}

void Llsi::adaug_inceput(nod*&prim,nod*ultim,int x)
{
    p=new nod;
    p->info=x;
    p->urm=prim;
    prim=p;
}

void Llsi::inserare_dvk(nod*prim,nod*&ultim, int x, int k)
{
    inserat_dvk=false;
    p=prim;
    while(p->info!=k && p->urm!=NULL)
        p=p->urm;
    if(p->info==k && p->urm==NULL)
    {
        adaug_sfarsit(prim,ultim,x);
        inserat_dvk=true;
    }
    else if(p->info==k)
    {
        nod *q=new nod;
        q->info=x;
        q->urm=p->urm;
        p->urm=q;
        inserat_dvk=true;
    }
}

void Llsi::inserare_ivk(nod*&prim,nod*ultim,int x, int k)
{
    inserat_ivk=false;
    if(prim->info==k)
    {
        adaug_inceput(prim,ultim,x);
        inserat_ivk=true;
        return;
    }
    p=prim;
    while(p->urm!=NULL)
    {
        if(p->urm->info==k)
        {
            nod*q=new nod;
            q->info=x;
            q->urm=p->urm;
            p->urm=q;
            inserat_ivk=true;
            return;
        }
        p=p->urm;
    }
}

void Llsi::inserare_ppk(nod*&prim,nod*&ultim,int x, int k)
{
    inserat_ppk=false;
    if(k==1)
    {
        adaug_inceput(prim,ultim,x);
        inserat_ppk=true;
        return;
    }
    p=prim;
    for(int i=1;i<k-1&&p!=NULL;i++)
        p=p->urm;
    if(p==NULL)
        return;

    nod*q=new nod;
    q->info=x;
    q->urm=p->urm;
    p->urm=q;
    if(q->urm==NULL)
        ultim=q;
    inserat_ppk=true;
}

void Llsi::stergere_primul(nod*&prim,nod*ultim)
{
    nod*q=prim;
    prim=prim->urm;
    delete q;
}

void Llsi::stergere_ultimu(nod*prim,nod*&ultim)
{
    if(prim->urm==NULL){
        delete prim;
        prim=NULL;
        return;
    }
    p=prim;
    while(p->urm->urm!=NULL)
        p=p->urm;
    nod*q=p->urm;
    p->urm=NULL;
    ultim=p;
    delete q;
}

void Llsi::stergere_k(nod*&prim,nod*&ultim,int k)
{
    sters_k=false;
    if(prim!=NULL&&prim->info==k)
    {
        stergere_primul(prim,ultim);
        sters_k=true;
        return;
    }
    p=prim;
    while(p!=NULL&&p->urm!=NULL)
    {
        if(p->urm->info==k)
        {
            nod*q=p->urm;
            p->urm=p->urm->urm;
            delete q;
            sters_k=true;
            return;
        }
        p=p->urm;
    }
}

void Llsi::stergere_pk(nod*&prim,nod*&ultim,int k)
{
    sters_pk=false;
    if(k==1)
    {
        stergere_primul(prim,ultim);
        sters_pk=true;
        return;
    }
    p=prim;
    for(int i=1;i<k-1&&p!=NULL;i++)
        p=p->urm;
    if(p==NULL||p->urm==NULL)
        return;
    nod*q = p->urm;
    p->urm=q->urm;
    if(q==ultim)
        ultim=p;
    sters_pk=true;
    delete q;
}