#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int slumptal, spelares_tal, ganger=0;
    //Inkludera variabler slumptal, spelares_tal och ganger (gånger).

    srand(time(0));
    slumptal=rand()%101;
    //Datorn ska gör ett slumptal mellan 0 och 100.

    cout<<"Dataspel: Gissa r\204tt talet\n--------------------------\n"<<endl;
    cout<<"Datorn har valt ett slumptal. Kan du gissa vilka den \204r?\n"<<endl;
    //Skrivs ut introductiontext på skärmen.

    while (spelares_tal!=slumptal)
    //Så länge spelaras_tal är inte lika med slumptal då förstätter programmet i en loop.
    {
        cout<<"Skriv ett tal: ";
        //Skrivs ut text på skärmen.
        cin>>spelares_tal;
        //Användare ska fylla in ett tal. Det blir variablen spelares_tal.
        ganger+=1;
        //Variablen ganger addera med 1 varje gång man gissa.
        cout<<endl;
        //Skrivs ut ett nytt råd på skärmen.

        if (spelares_tal!=slumptal)
        {
            //Programmet ska kontrollera om inmattade talet är rätt eller fel. Om ja går den vidare.
            cout<<"Du gissade fel talet. F\224rs\224ka igen. ";
            //Skrivs ut text på skärmen som visar att inmattade talet var fel.
            if (spelares_tal<slumptal)
            {
            //Programmet ska kontrollera om talet var för lågt.
                cout<<"Talet som du gissade var f\224r l\206gt."<<endl;
                //Skrivs ut text på skärmen som visar att inmattade talet var för lågt.
            }
            if (spelares_tal>slumptal)
            {
            ////Programmet ska kontrollera om talet var för högt.
                cout<<"Talet som du gissade var f\224r h\224gt."<<endl;
                //Skrivs ut text på skärmen som visar att inmattade talet var för högt.
            }
        }
    }

    cout<<"Grattis!\nDu har gissat r\204tt tal."<<endl;
    cout<<"Du har gissat "<<ganger<<" g\206nger f\224r att f\206r r\204tt talet."<<endl;
    //Skrivs ut text på skärmen som vissar att rätt tal är gissat och hur många gånger det togs.

    return 0;
    //Programmet är slut.
}
