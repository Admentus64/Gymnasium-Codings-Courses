#include <iostream>

using namespace std;

int main()
{
    int antalNegativa=0, inmatning=1;
    //Introducera 2 variabler.

    cout<<"S\206 l\204nge ingen 0 \204r inmattad f\224rts\204tter programmet.\n"<<endl;
    //Skriv ut ett text p� sk�rmen.

    while(inmatning!=0)
    //S� l�nge ingen 0 �r inmattad d� k�r den vidare.
    {
        cout<<"Skriv ett tal: ";
        //Skriv ut ett text p� sk�rmen.
        cin>>inmatning;
        //Anv�ndare m�ste fylla in ett tal.
        cout<<endl;
        //Ett nytt r�d p� sk�rmen.

        if (inmatning<0)
            antalNegativa+=1;
        //Om talet �r mindre �n 0 d� stiger variablen antalNegativa med 1.
    }
    cout<<"Du skrev "<<antalNegativa<<" negativa tal."<<endl;
    //Skriv ut ett text p� sk�rmen som vissar hur mycker negativa tal anv�ndare har infyllat.

    return 0;
}
