#ifndef LLDI_H
#define LLDI_H

class Lldi{
    public:
        struct nod
        {
            int info;
            nod *urm;
            nod *prec;
        }*p,*prim,*ultim;

        bool lldi_creat=false;
        bool inserat_dvk=false;
        bool inserat_ivk=false;
        bool inserat_ppk=false;
        bool sters_k=false;
        bool sters_pk=false;
        
        void int_lldi(nod*&prim,nod*&ultim);
        void creare_primul(nod *&prim,nod *&ultim);
        void afisez(nod*prim,nod*ultim);

        void adaug_sfarsit(nod*prim,nod*&ultim,int x);
        void adaug_inceput(nod*&prim,nod*ultim,int x);
        void inserare_dvk(nod*prim,nod*&ultim, int x, int k);
        void inserare_ivk(nod*&prim,nod*ultim,int x,int k);
        void inserare_ppk(nod*&prim,nod*&ultim,int x, int k);

        void stergere_primul(nod*&prim,nod*ultim);
        void stergere_ultimu(nod*&prim,nod*&ultim);
        void stergere_k(nod*&prim,nod*&ultim,int k);
        void stergere_pk(nod*&prim,nod*&ultim,int k);
};

#endif
