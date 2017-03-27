#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_child.h"
#include "list_parent.h"

#include <iostream>

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define child(P) P->child
#define parent(P) P->parent

using namespace std;

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_relasi prev;
    address_child child;
    address_parent parent;
};

struct list_relasi{
    address_relasi first;
    address_relasi last;
};

void createList(list_relasi &L);
void insertFirst(list_relasi &L, address_relasi P);
void insertLast(list_relasi &L, address_relasi P);
void inserAfter(list_relasi &L, address_relasi Prec, address_relasi P);
void deleteFirst(list_relasi &L, address_relasi &P);
void deleteLast(list_relasi &L, address_relasi &P);
void deleteAfter(list_relasi &L, address_relasi Prec, address_relasi &P);
address_relasi alokasi(address_parent P, address_child C);
void dealokasi_relasi(address_relasi &P);
//address_relasi findElm(list_relasi L, address_parent P, address_child C);
void printInfo(list_relasi L);





#endif // LIST_RELASI_H_INCLUDED
