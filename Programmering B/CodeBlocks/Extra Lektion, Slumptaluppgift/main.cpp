#include <iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;

void vidare(int& sluta)
{
    sluta=2;
    while (sluta!=0 && sluta!=1)
    {
        system("cls");
        cout<<"Mata in en 0 om du vill avsluta programmet!"<<endl;
        cout<<"Mata in en 1 om du vill k\224ra programmet vidare!"<<endl;
        cout<<"Mata in g\204rna: ";
        cin>>sluta;
    }
}
void kast(unsigned& element)
{
    cout<<"=============================================\n=== V\204lkommen till simuleringsprogrammet! ===\n============================================="<<endl<<endl;
    cout<<"Denna programmet ska kastar t\204rningar med tal 1 till och med 6"<<endl;
    cout<<"Sen r\204knas ut hur m\206nga g\206nger ett visst tal f\224rekommer"<<endl<<endl<<endl<<endl;

    cout<<"Mata in antal g\206nger programmet kastar t\204rningar varje k\224rning: ";
    cin>>element;
    system("cls");
}

void steg(unsigned element,unsigned gang)
{
    vector<double> tal; vector<int> slumptal;
    unsigned temp_slumptal=0;

    for (int i=1;i<4;i++)
    {
        tal.clear();
        for (int j=0;j<(6*gang)-(1*gang)+1;j++)     tal.push_back(0);

        cout<<"\nK\224rning: "<<i<<endl<<endl;

        for (int j=0;j<element;j++)
        {
            for (int k=0;k<gang;k++)    slumptal.push_back(rand()%6+1);

            for (int k=0;k<slumptal.size();k++)     temp_slumptal+=slumptal.at(k);
            tal.at(temp_slumptal-(gang*1))+=1;
            slumptal.clear();
            temp_slumptal=0;
        }

        for (int j=0;j<tal.size();j++)      cout<<"Tal "<<j+gang<<" f\224rekommer antal g\206nger: "<<setprecision(1000)<<tal.at(j)<<" / "<<setprecision(3)<<tal.at(j)/element*100<<"%"<<endl;

    }
    cout<<"\nAntal t\204rningkast varje k\224rning: "<<element<<endl<<endl<<endl;

    //utfil.close();
}

int main()
{
    unsigned element,gang=1;
    int sluta;
    srand(time(0));

    kast(element);

    while (sluta!=0)
    {
        if (gang==1)    cout<<"Steg 1: 1 T\204rning"<<endl;
        if (gang>1)     cout<<"Steg "<<gang<<": "<<gang<<" T\204rningar"<<endl;
        steg(element,gang);
        cin.ignore();cin.ignore();
        vidare(sluta);
        system("cls");
        gang+=1;
    }

    return 0;
}
