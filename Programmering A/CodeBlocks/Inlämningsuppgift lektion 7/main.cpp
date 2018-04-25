#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int slumptal, spelares_tal, ganger=0;
    //Inkludera variabler slumptal, spelares_tal och ganger (g�nger).

    srand(time(0));
    slumptal=rand()%101;
    //Datorn ska g�r ett slumptal mellan 0 och 100.

    cout<<"Dataspel: Gissa r\204tt talet\n--------------------------\n"<<endl;
    cout<<"Datorn har valt ett slumptal. Kan du gissa vilka den \204r?\n"<<endl;
    //Skrivs ut introductiontext p� sk�rmen.

    while (spelares_tal!=slumptal)
    //S� l�nge spelaras_tal �r inte lika med slumptal d� f�rst�tter programmet i en loop.
    {
        cout<<"Skriv ett tal: ";
        //Skrivs ut text p� sk�rmen.
        cin>>spelares_tal;
        //Anv�ndare ska fylla in ett tal. Det blir variablen spelares_tal.
        ganger+=1;
        //Variablen ganger addera med 1 varje g�ng man gissa.
        cout<<endl;
        //Skrivs ut ett nytt r�d p� sk�rmen.

        if (spelares_tal!=slumptal)
        {
            //Programmet ska kontrollera om inmattade talet �r r�tt eller fel. Om ja g�r den vidare.
            cout<<"Du gissade fel talet. F\224rs\224ka igen. ";
            //Skrivs ut text p� sk�rmen som visar att inmattade talet var fel.
            if (spelares_tal<slumptal)
            {
            //Programmet ska kontrollera om talet var f�r l�gt.
                cout<<"Talet som du gissade var f\224r l\206gt."<<endl;
                //Skrivs ut text p� sk�rmen som visar att inmattade talet var f�r l�gt.
            }
            if (spelares_tal>slumptal)
            {
            ////Programmet ska kontrollera om talet var f�r h�gt.
                cout<<"Talet som du gissade var f\224r h\224gt."<<endl;
                //Skrivs ut text p� sk�rmen som visar att inmattade talet var f�r h�gt.
            }
        }
    }

    cout<<"Grattis!\nDu har gissat r\204tt tal."<<endl;
    cout<<"Du har gissat "<<ganger<<" g\206nger f\224r att f\206r r\204tt talet."<<endl;
    //Skrivs ut text p� sk�rmen som vissar att r�tt tal �r gissat och hur m�nga g�nger det togs.

    return 0;
    //Programmet �r slut.
}
