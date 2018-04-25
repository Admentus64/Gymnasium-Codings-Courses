#include <iostream>
#include <fstream>
#include <sstream>
#include "CDSkiva.h"
using namespace std;

void CDSkiva::inmat()
{
    cout<<"  Mata in albumnamn: ";
    cin>>album;
    cout;
    cout<<" Mata in artistnamn: ";
    cin>>artist;

    ofstream utfil;
    utfil.open("CDSkiva.txt");
    utfil<<album;
    utfil<<endl<<artist;
    utfil.close();
}

void CDSkiva::visa()
{
    ifstream infil("CDSkiva.txt");
    infil>>album;
    infil>>artist;
    infil.close();

    cout<<"  Albumnamn: "<<album<<endl;
    cout<<" Artistnamn: "<<artist<<endl;
    cout<<" ----------- "<<endl;

    for (unsigned int i=0; i<latar.size(); i++)
        latar[i].visa();
}
