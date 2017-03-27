#include "aplikasi.h"


void menu(list_child &LC, list_parent &LP, list_relasi &LR)
{
    int pil;
    do
    {
        cout<<endl;
        cout<<"  1)Masukan Data"<<endl<<endl;
        cout<<"  2)Tampil Data"<<endl<<endl;
        cout<<"  3)Keluar"<<endl<<endl;
        cout<<"  > PILIH : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            masukandata(LC,LP,LR);
        case 2:
            cout<<"dua";
        case 3:
            break;
        }
    }
    while(pil!=3);
}

void masukandata(list_child &LC, list_parent &LP, list_relasi &LR)
{
    int pil;
    do
    {
        cout<<endl;
        cout<<"  1)Masukan Data Pasien"<<endl<<endl;
        cout<<"  2)Masukan Data Dokter"<<endl<<endl;
        cout<<"  3)Kembali"<<endl<<endl;
        cout<<"  > PILIH: ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            insert_parent(LP);
            menu(LC,LP,LR);
        case 2:
            insert_child(LC);
            menu(LC,LP,LR);
        case 3:
            menu(LC,LP,LR);
        }
    }
    while (pil!=0);
}

void insert_child(list_child &LC)
{
    dokter D;
    address_child C;
    address_child prec;
    cout<<endl<<"  INPUT DATA DOKTER"<<endl<<endl;
    cout<<"  > Nama Dokter : ";
    cin>>D.nama;
    cout<<endl<<"  > ID : ";
    cin>>D.id;
    cout<<endl<<"  > Umur : ";
    cin>>D.usia;
    cout<<endl<<"  > Jenis Kelamin : ";
    cin>>D.jk;
    cout<<endl<<"  > Spesialis : ";
    cin>>D.spesialis;
    cout<<endl<<"  > No. HP : ";
    cin>>D.no_hp;
    cout<<endl<<"  > Alamat : ";
    cin>>D.alamat;
    cout<<endl;

    C = alokasi(D);
    prec = first(LC);
    if(first(LC) == NULL)
    {
        insertFirst(LC,C);
    }
    else
    {
        while(info(prec).nama < D.nama)
        {
            prec=next(prec);
        }
        if (next(prec)=first(LC))
        {
            insertLast(LC,C);
        }
        else
        {
            //insertAfter(LC,prec,C);
        }
    }
}

void insert_parent(list_parent &LP)
{
    pasien P;
    address_parent Q;
    address_parent prec;

    cout<<endl<<"  INPUT DATA PASIEN"<<endl<<endl;
    cout<<endl<<"  > Nama Pasien    : ";
    cin>>P.nama;
    cout<<endl<<"  > ID             : ";
    cin>>P.id;
    cout<<endl<<"  > Umur           : ";
    cin>>P.umur;
    cout<<endl<<"  > Jenis Kelamin  : ";
    cin>>P.jk;
    cout<<endl<<"  > Tanggal Lahir  : ";
    cin>>P.tgllahir;
    cout<<endl<<"  > Golongan Darah : ";
    cin>>P.darah;
    cout<<endl<<"  > Alamat         : ";
    cin>>P.alm;
    cout<<endl<<"  > Keluhan        : ";
    cin>>P.keluhan;
    cout<<endl;


    Q = alokasi(P);
    prec=first(LP);
    if(first(LP)==NULL)
    {
        insertFirst(LP,Q);
    }
    else
    {
        while(info(prec).nama < P.nama)
        {
            prec=next(prec);
        }
        if (next(prec)==NULL)
        {
            insertLast(LP,Q);
        }
        else
        {
            //insertAfter(LP,prec,Q);
        }
    }
}

void insertRelasi(list_relasi &LR,list_child LC,list_parent LP,adrress_child C,address_parent P)
{
    string x;
    int y;
    address_relasi R;
    cout<<"  1)Masukan No.KTP pasien    : ";
    cin>>x;
    cout<<"  2)Masukan ID Dokter        : ";
    cin>>y;
    C=findByID(LC,y);
    P=findByID(LP,x);
    if (C!=NULL && P !=NULL)
    {
        R=alokasi(P,C);
        insertFirst(LR,R);
    }

}
