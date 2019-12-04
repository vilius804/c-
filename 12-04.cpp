#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
  ifstream in;
  ofstream out("rez.txt");
  struct zaidejai{
     string vardas;
     float laikas;
     int amzius;
    };

    void skaito (zaidejai Struktura[], int kiek, const char failas[]);
    void raso (zaidejai Struktura[], int kiek, string txt);
    void kiekZaideju (int &kiek, const char failas[]);

int main()
{   int kiek1, kiek2;
    const char duom1[] = "duom1.txt";
    const char duom2[] = "duom2.txt";
    kiekZaideju (kiek1, duom1);
    kiekZaideju (kiek2, duom2);
    zaidejai Komanda[10000];
    skaito(Komanda, kiek1, duom1);
    raso(Komanda, kiek1, "\nPirma komanda:\n");
    skaito(Komanda, kiek2, duom2);
    raso(Komanda, kiek2, "\nAntra komanda:\n");
    zaidejai KomandaVisa[kiek1+kiek2];

    int i;
    in.open(duom1);
    for(i=0; i<kiek1; i++){
        in>>KomandaVisa[i].vardas>>KomandaVisa[i].laikas>>KomandaVisa[i].amzius;
    }
    in.close();
    in.open(duom2);
    for(i=kiek1; i<kiek1+kiek2; i++){
        in>>KomandaVisa[i].vardas>>KomandaVisa[i].laikas>>KomandaVisa[i].amzius;
    }
    in.close();

    for(int i=0; i<kiek1+kiek2; i++){
        cout<<setw(10)<<left<<KomandaVisa[i].vardas<<" "<<KomandaVisa[i].laikas<<" "<<KomandaVisa[i].amzius<<endl;
    }
    in.close();
    out.close();

    return 0;
  }

void skaito (zaidejai Struktura[], int kiek, const char failas[]){
    fstream in(failas);
    for(int  i = 0; i<kiek; i++){
        in>>Struktura[i].vardas>>Struktura[i].laikas>>Struktura[i].amzius;
    }
}
//------------------------------------------
//---------------------Raso-----------------
void raso (zaidejai Struktura[], int kiek, string txt)
{
    out<<txt;
    for(int i=0; i<kiek; i++){
        out<<setw(10)<<left<<Struktura[i].vardas<<" "<<Struktura[i].laikas<<" "<<Struktura[i].amzius<<endl;
    }
}

void kiekZaideju (int &kiek, const char failas[])
{
    fstream in(failas);
    kiek=0;
    zaidejai Struktura[1];
    int i=0;
    do{
        in>>Struktura[i].vardas>>Struktura[i].laikas>>Struktura[i].amzius;
        kiek++;
    }while(!in.eof());
    in.seekg(0);
    in.close();
}
