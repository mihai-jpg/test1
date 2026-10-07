#include "lldi.h"
#include "citiri.h"
#include <iostream>
using namespace std;

Citiri citi_lldi;

void Lldi::int_lldi(nod*&prim,nod*&ultim)
{
    prim=ultim=NULL;
    lldi_creat=true;
}

void Lldi::creare_primul(nod *&prim,nod *&ultim)
{
    int x;
    cout<<"valoarea din primul nod x= "; citi_lldi.citire_valori(x,"valoarea din primul nod x= ");
    prim=new nod;
    prim->info=x;
    prim->urm=NULL;
    prim->prec=NULL;
    ultim=prim;
}

void Lldi::afisez(nod*prim,nod*ultim)
{
    p=prim;
    while(p!=NULL)
    {
        cout<<p->info<<' ';
        p=p->urm;
    }
    cout<<endl;
}

void Lldi::adaug_sfarsit(nod*prim,nod*&ultim,int x)
{
    p=new nod;
    p->info=x;
    p->urm=NULL;
    p->prec=ultim;
    ultim->urm=p;
    ultim=p;
}

void Lldi::adaug_inceput(nod*&prim,nod*ultim,int x)
{
    p=new nod;
    p->info=x;
    p->urm=prim;
    p->prec=NULL;
    prim->prec=p;
    prim=p;
}

void Lldi::inserare_dvk(nod*prim,nod*&ultim, int x, int k)
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
        q->prec=p;
        p->urm->prec=q;
        p->urm=q;
        inserat_dvk=true;
    }
}

void Lldi::inserare_ivk(nod*&prim,nod*ultim,int x,int k)
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
        if(p->info==k)
        {
            nod *q=new nod;
            q->info=x;
            q->urm=p;
            q->prec=p->prec;
            p->prec->urm=q;
            p->prec=q;
            inserat_ivk=true;
            return;
        }
        p=p->urm;
    }
}

void Lldi::inserare_ppk(nod*&prim,nod*&ultim,int x, int k)
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

    nod *q=new nod;
    q->info=x;
    q->urm=p->urm;
    q->prec=p;
    p->urm->prec=q;
    p->urm=q;
    if(q->urm==NULL)
        ultim=q;
    inserat_ppk=true;
}

void Lldi::stergere_primul(nod*&prim,nod*ultim)
{
    nod *q=prim;
    prim=prim->urm;
    prim->prec=NULL;
    delete q;
}

void Lldi::stergere_ultimu(nod*&prim,nod*&ultim)
{
    if(prim->urm==NULL)
    {
        delete prim;
        prim=NULL;
        return;
    }
    nod *q=ultim;
    ultim=ultim->prec;
    ultim->urm=NULL;
    delete q;
}

void Lldi::stergere_k(nod*&prim,nod*&ultim,int k)
{
    sters_k=false;
    if(prim!=NULL&&prim->info==k)
    {
        stergere_primul(prim,ultim);
        sters_k=true;
        return;
    }
    p=prim;
    while(p!=NULL)
    {
        if(p->info==k)
        {
            if(p==ultim)
            {
                stergere_ultimu(prim,ultim);
                sters_k=true;
                return;
            }
            p->prec->urm=p->urm;
            p->urm->prec=p->prec;
            delete p;
            sters_k=true;
            return;
        }
        p=p->urm;
    }
}

void Lldi::stergere_pk(nod*&prim,nod*&ultim,int k)
{
    sters_pk=false;
    if(k==1)
    {
        stergere_primul(prim,ultim);
        sters_pk=true;
        return;
    }
    p=prim;
    for(int i=1;i<k&&p!=NULL;i++)
        p=p->urm;
    if(p==NULL)
        return;
    if(p==ultim)
    {
        stergere_ultimu(prim,ultim);
        sters_pk=true;
        return;
    }
    p->prec->urm=p->urm;
    p->urm->prec=p->prec;
    delete p;
    sters_pk=true;
}