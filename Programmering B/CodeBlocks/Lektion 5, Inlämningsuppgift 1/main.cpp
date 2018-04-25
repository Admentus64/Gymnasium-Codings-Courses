#include<iostream> //L�ggs till alla include som beh�ver att kuna k�ra programmet.
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<ctime>
#include <time.h>
using namespace std; //L�ggs till namespace.

void laggVektor(vector<unsigned>& v,vector<unsigned>& v_kopia,unsigned& element) //Funktionen som l�gger til vektorer med lite grund text.
{
    srand(time(0)); //Kod som beh�vs att kunna r�kna ut en slumptal.

    cout<<"Mata in en 0 f\224r att avsluta programmet."<<endl; //Skrivs ut text p� sk�rmen.
    cout<<"Mata in antalet element i vektorn: ";
    cin>>element; //Anv�ndare m�ste mata in ett v�rde f�r variablen element.

    if (element==0) //Om variablen element �r likamed 0 d� avbryttar denna funktionen till Huvud funktionen.
        return;

    system("cls"); //Sk�rmet blir tomt.
    cout<<"Mata in en 0 f\224r att avsluta programmet."<<endl; //Skrivs ut text p� sk�rmen.
    cout<<"Mata in antalet element i vektorn: "<<element<<"."<<endl;

    if (v.size()>0) //Om vektorn v �r st�rre �n 0 blir vektorn v tomt.
        v.clear();

    for(int i=0;i<element;i++) //Best�mmas antal element som l�ggas till i vektorn.
    {
        v.push_back(rand()%10001); //Best�mmes vilke v�rde en element kan f�r. V�rde ett ett slumptal mellan 2 tal.
    }

    v_kopia=v; //Vektorn v_kopia blir det samma som vektorn v

    cout<<"Antal element i slumplistan: "<<v.size()<<"."<<endl<<endl; //Skrivs ut n�gra text p� sk�rmen.
    cout<<"N\206gra moment g\204rna tills ber\204kningarna \204r f\204rdiga."<<endl<<endl<<endl<<endl;
}

void bytPlats(unsigned& a, unsigned& b) //Funtionen att byta plats med een element i en vektorn.
{
    unsigned temp=a; //Element byts om med en annan.
    a=b;
    b=temp;
}

void bubblesort(vector<unsigned>& v) //F�rsta sorterings funktion
{
    bool sorterad=false;
    while (!sorterad)
    {
        sorterad=true;
        for (int i=0;i<v.size()-1;i++)
        {
            if(v.at(i)>v.at(i+1))
            {
                sorterad=false;
                bytPlats(v.at(i),v.at(i+1));
            }
        }
    }
}

void selectionsort(vector<unsigned>& v) //Andra sorterings funktion
{
    for (int i=0;i<v.size()-1;i++)
    {
        //B�rjar med att s�tta minsta till f�rsta
        int min=i;
        //S�ker efter minsta tal, l�gger detta i min
        for(int j=i+1;j<=v.size()-1;j++)
            if (v.at(j)<v.at(min))
                min=j;

        bytPlats(v.at(i),v.at(min));
    }
}

bool tidmatning(vector<unsigned> v,int gang_matning) //Funktionen som g�r tidber�kning men skicka bara tillbaka en text till huvud funktionen.
{
    clock_t start,end; //Kod som beh�vs att kunna starta tidmatning.
    double matning; //L�ggs till variablen

    start=clock(); //F�rsta tidm�tning b�rjar.

    if (gang_matning==1) //Om variablen g�ng_matning �r likamed v�rde 1 (f�rsta g�ngen funktionen k�rs).
        bubblesort(v); //K�r funktionen bubblesort (f�rsta sorterings funktionen)
    if (gang_matning==2) //Om variablen g�ng_matning �r likamed v�rde 2 (andra g�ngen funktionen k�rs).
        selectionsort(v); //K�r funktionen selectionsort (andra sorterings funktionen)

    end=clock(); //F�rsta tidm�tning slutat.
    matning=((double)(end-start))/CLOCKS_PER_SEC; //Ber�knas ut tiden av f�rsta tidm�tning.

    if (gang_matning==1) //Om variablen g�ng_matning �r likamed v�rde 1 (f�rsta g�ngen funktionen k�rs).
        return cout<<"          Buble sort: "<<setprecision(3)<<matning<<" sekunder."<<endl; //Skicka tillbaka ber�kningen av Bubble sort till huvudfunktionen som kommer p� sk�rmen. Svaret har 3 v�rdetal.
    if (gang_matning==2) //Om variablen g�ng_matning �r likamed v�rde 2 (andra g�ngen funktionen k�rs).
        return cout<<"          Selection sort: "<<setprecision(3)<<matning<<" sekunder."<<endl; //Skicka tillbaka ber�kningen av Selection Sort till huvudfunktionen som kommer p� sk�rmen. Svaret har 3 v�rdetal.
}

int main() //Huvud funktionen
{

    vector<unsigned> v,v_kopia; //L�ggs till 2 vektorer.
    unsigned element; //L�ggs till variablen element.

    while (element!=0) //Om variablen element �r inte likamed 0 k�rs f�jande kod d�refter igen.
    {
        int gang_matning=1; //L�ggs till variablen g�ng_matning p� v�rde 1.

        laggVektor(v,v_kopia,element); //K�r funktionen laggVektor.
        if (element==0) //Om variablen element �r likamed 0 avslutar programmet.
            return 0;

        tidmatning(v,gang_matning); //K�r funktionen tidmatning f�r f�rsta g�ngen.
        v=v_kopia; //Vektorn v resetar.
        gang_matning+=1; //Variablen g�ng_matning adderas med 1.
        tidmatning(v,gang_matning); //K�r funktionen tidmatning f�r andra g�ngen.

        cout<<"\n\n\nBer\204kningarna \204r nu f\204rdiga.";//Skrivs ut sista text p� sk�rmen.

        cin.ignore(); cin.ignore(); //Beh�vs att klicka p� enter f�r att k�ra program vidare.
        system("cls"); //Sk�rmet blir tomt.
    }
}
