#include <iostream>

using namespace std;

int main()
{
    int antalNegativa=0, inmatning=1;
    //Introducera 2 variabler.

    cout<<"S\206 l\204nge ingen 0 \204r inmattad f\224rts\204tter programmet.\n"<<endl;
    //Skriv ut ett text på skärmen.

    while(inmatning!=0)
    //Så länge ingen 0 är inmattad då kör den vidare.
    {
        cout<<"Skriv ett tal: ";
        //Skriv ut ett text på skärmen.
        cin>>inmatning;
        //Användare måste fylla in ett tal.
        cout<<endl;
        //Ett nytt råd på skärmen.

        if (inmatning<0)
            antalNegativa+=1;
        //Om talet är mindre än 0 då stiger variablen antalNegativa med 1.
    }
    cout<<"Du skrev "<<antalNegativa<<" negativa tal."<<endl;
    //Skriv ut ett text på skärmen som vissar hur mycker negativa tal användare har infyllat.

    return 0;
}
