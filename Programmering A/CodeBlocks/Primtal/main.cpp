#include <iostream>
#include <iomanip>

using namespace std;

bool primtal(int tal);

int main()
{
    int talet=0;

    cout<<"Primtal\n======="<<endl;

    cout<<"\nSkriv ett positivt heltal: ";
    cin>>setprecision(1)>>talet;
    cout<<"Du skrev talet: "<<talet<<". Alla inga-heltal blir avrundade till nedan."<<endl;

    while (talet<!0)
    {
        cout<<"\nSkriv ett positivt heltal g\204rna: ";
        cin>>setprecision(1)>>talet;
        cout<<"Du skrev talet: "<<talet<<". Alla inga-heltal blir avrundade till nedan."<<endl;
    }

    cin.get();
    cout<<"\n\n\n";

    if (primtal(talet)==true)
        cout<<"Talet "<<talet<<" \204r ett primtal."<<endl;
    else
        cout<<"Talet "<<talet<<" \204r inte ett primtal."<<endl;

    cout<<"Primtal som kommer f\224re inmatat talet: ";
    for (int i=2; i<talet; i++)
    {
        if (primtal(i)==true)
            cout<<i<<"  ";
    }

    cout<<endl;
    return 0;
}

bool primtal(int tal)
{
    for (int i=2; i<tal; i++)
    {
        if (tal%i==0)
            return false;
    }
    return true;
}
