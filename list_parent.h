#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED

#include <iostream>
using namespace std;

#define nil NULL
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct pasien{
    int id;

    string nama,jk,darah,alm,keluhan;
    int umur,tgllahir;
};

typedef pasien infotype_parent;

typedef struct elmlist_parent *address_parent;

struct elmlist_parent{
    infotype_parent info;
    address_parent next;
    address_parent prev;
};

struct list_parent{
    address_parent first;
    address_parent last;
};

void createList(list_parent &L);
address_parent alokasi(infotype_parent x);
void insertFirst(list_parent &L, address_parent P);
void insertLast(list_parent &L, address_parent P);
void insertAfter(list_parent &L, address_parent Prec, address_parent P);
address_parent findByID(list_parent L, infotype_parent x);
void deleteFirst(list_parent &L, address_parent &P);
void deleteLast(list_parent &L, address_parent &P);
void deleteAfter(list_parent &L, address_parent Prec, address_parent &P);
void printinfo(list_parent L);

#endif // DOUBLELIST_H_INCLUDED

#endif // LIST_PARENT_H_INCLUDED
