#include "player.h"
#include <ctime>

int randomInt(int  max_int)
{
    /** YOU DON'T NEED TO MODIFY THIS */
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L)
{
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    * YOU DON'T NEED TO MODIFY THIS
    */

    address Q = first(L);
    do
    {
        cout<<"name    : "<<info(Q).name<<endl
            <<"ID      : "<<info(Q).ID<<endl
            <<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    }
    while(Q!=first(L));
    cout<<"==============================================="<<endl;
}


void playMusic(address P)
{
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    * YOU DON'T NEED TO MODIFY THIS
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L)
{
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //------------- YOUR CODE HERE -------------
    int r = randomInt(20);
    int i,j;
    address P = first(L);
    for(i=0; i < r; i++)
    {
        swap(info(P).name, info(next(P)).name);
        swap(info(P).ID, info(next(P)).ID);
        P = next(P);
    };
}

void playRepeat(List &L, int n)
{
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //------------- YOUR CODE HERE -------------
    for (int i = 0; i<n; i++)
    {
        address P = L.first;
        playMusic(P);
        while (P->next != L.first)
        {
            P = P->next;
            playMusic(P);
        }
    }
    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x)
{
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    //------------- YOUR CODE HERE -------------
    address Prec, P;
    P = findElmByID(L,x);
    if(P == L.first)
    {
        deleteFirst(L,P);
    }
    else if (P->next == NULL)
    {
        deleteLast(L,P);
    }
    else if (P->info.ID == x.ID)
    {
        Prec = L.first;
        while(Prec->next != P)
        {
            Prec = Prec->next;
        }
        deleteAfter(L, Prec, P);
    }
    //----------------------------------------
}
