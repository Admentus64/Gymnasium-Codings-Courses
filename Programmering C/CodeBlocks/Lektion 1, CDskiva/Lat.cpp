#include <iostream>
#include <fstream>
#include <sstream>
#include "Lat.h"
using namespace std;

void Lat::inmat()
{
    cout<<" Mata in l\206tnamn: ";
    cin>>latnamn;
    cout;
    cout<<"  Mata in l\206ttid: ";
    cin>>lattid;

    ofstream utfil;
    utfil.open("Lat.txt", ios::app);
    utfil<<endl<<latnamn;
    utfil<<endl<<lattid;
    utfil.close();
}

void Lat::visa()
{
    cout<<endl<<"    L\206tnamn: "<<latnamn<<endl;
    cout<<"     L\206ttid: "<<lattid<<endl;
}
