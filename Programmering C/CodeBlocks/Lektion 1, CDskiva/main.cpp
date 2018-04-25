#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Lat.h"
#include "CDSkiva.h"
using namespace std;

void meny(string& val)
{
    val="aa";
    system("cls");

    while (val.size()!=1 || (val!="1" && val!="2" && val!="3" && val!="4" && val!="5"))
    {
        cout<<endl<<" V\204lj ditt val"<<endl<<" -------------"<<endl;
        cout<<" 1. Visa informationen"<<endl;
        cout<<" 2. Tilla en ny l\206t"<<endl;
        cout<<" 3. \216ndra skivans uppgifter"<<endl;
        cout<<" 4. Ta bort l\206ter fr\206n listan"<<endl;
        cout<<" 5. Avsluta programmet"<<endl;
        cout<<endl<<" Ange ditt val: ";

        getline(cin,val);
        cout<<"\a";

        if (val.size()==0 || (val!="1" && val!="2" && val!="3" && val!="4" && val!="5"))
        {
            cout<<endl<<endl<<endl<<" Fel inmatning!"<<endl; //Error text skrivs ut
            cout<<" Mata bara in siffrorna 1 <-> 5!"<<endl;
            cout<<" F\224rs\224k om g\204rna!"<<endl;
            cin.ignore();
        }
        system("cls");
    }
    cout;
}

int main(int argc, char *argv[])
{
    string val;
    Lat lat;
    CDSkiva cd;

    while (val!="5")
    {
        meny(val);
        cout<<endl;

        if (val=="1")
        {
            cd.latar.clear();

            ifstream infil("Lat.txt");
            while(infil.peek()!=EOF)
            {
                infil>>lat.latnamn;
                infil>>lat.lattid;
                cd.latar.push_back(lat);
            }
            infil.close();

            cd.visa();
        }

        if (val=="2")
            lat.inmat();

        if (val=="3")
            cd.inmat();

        if (val=="4")
        {
            ofstream utfil;
            utfil.open("Lat.txt");
            utfil.close();
            cout<<" Alla l\206ter p\206 listan har taggits bort nu.";
        }

        if (val=="5")
            cout<<" Programmet st\204nger sig av nu."<<endl<<endl;

        if (val!="5")
        {
            cin.ignore();
            cout<<"\a";
        }
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
