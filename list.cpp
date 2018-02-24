#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //------------your code here-------------
    L.First = NULL;
    L.Last = NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = new elmlist;
    //-------------your code here-------------
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete(P)
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if(L.First == NULL)
    {
        L.First = P;
        L.Last = P;
    }
    else
    {
        P->next = L.First;
        P->prev = L.Last;
    }
    L.First->prev = P;
    L.Last->next = P;
    L.First = P;
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (L.First == NULL)
        insertFirst(L,P)
    else
    {
        P->next = L.First;
        P->prev = L.Last;
        L.Last->next = P;
        L.First->prev = P;
        L.Last = P;
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    address Q = L.First;
    //-------------your code here-------------
    do
    {
        if (Q->info.name == x.name)
            P = Q;
        Q = Q->next;
    }while(Q != L.First && Q != P)
    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    address Q = L.First;
    do
    {
        if (Q->info.name == x.name)
            P = Q;
        Q = Q->next;
    }while(Q != L.First && Q != P)
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (L.First != NULL)
    {
        P = L.First
        if (L.First == L.Last)
        {
            L.First = NULL;
            L.Last = NULL;
        }
        else
        {
            L.First = P->next;
            L.Last->next = P->next;
            L.First->prev = L.Last;
        }
        P->next = NULL;
        P->prev = NULL;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (L.First != NULL)
    {
        P = L.Last;
        if (L.First == L.Last)
            deleteFirst(L,P)
        else
        {
            L.Last = P->prev;
            L.First->prev = P->prev;
            L.Last->next = L.First;
        }
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if (Prec->next = Prec)
        insertLast(L,P)
    else
    {
        P->next = Prec->next;
        P->prev = Prec;
        Prec->next = P;
        P->next->prev = P;
    }
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    (if L.First != NULL)
    {
        if (Prec->next->next == L.First)
            deleteLast(L,P)
        else
        {
            P = Prec->next;
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = NULL;
            P->prev = NULL;
        }
    }
    //----------------------------------------
}

