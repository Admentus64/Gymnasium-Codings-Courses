#include<iostream> //Läggs till alla include som behöver att kuna köra programmet.
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<ctime>
#include <time.h>
using namespace std; //Läggs till namespace.

void laggVektor(vector<unsigned>& v,vector<unsigned>& v_kopia,unsigned& element) //Funktionen som lägger til vektorer med lite grund text.
{
    srand(time(0)); //Kod som behövs att kunna räkna ut en slumptal.

    cout<<"Mata in en 0 f\224r att avsluta programmet."<<endl; //Skrivs ut text på skärmen.
    cout<<"Mata in antalet element i vektorn: ";
    cin>>element; //Användare måste mata in ett värde för variablen element.

    if (element==0) //Om variablen element är likamed 0 då avbryttar denna funktionen till Huvud funktionen.
        return;

    system("cls"); //Skärmet blir tomt.
    cout<<"Mata in en 0 f\224r att avsluta programmet."<<endl; //Skrivs ut text på skärmen.
    cout<<"Mata in antalet element i vektorn: "<<element<<"."<<endl;

    if (v.size()>0) //Om vektorn v är större än 0 blir vektorn v tomt.
        v.clear();

    for(int i=0;i<element;i++) //Bestämmas antal element som läggas till i vektorn.
    {
        v.push_back(rand()%10001); //Bestämmes vilke värde en element kan får. Värde ett ett slumptal mellan 2 tal.
    }

    v_kopia=v; //Vektorn v_kopia blir det samma som vektorn v

    cout<<"Antal element i slumplistan: "<<v.size()<<"."<<endl<<endl; //Skrivs ut några text på skärmen.
    cout<<"N\206gra moment g\204rna tills ber\204kningarna \204r f\204rdiga."<<endl<<endl<<endl<<endl;
}

void bytPlats(unsigned& a, unsigned& b) //Funtionen att byta plats med een element i en vektorn.
{
    unsigned temp=a; //Element byts om med en annan.
    a=b;
    b=temp;
}

void bubblesort(vector<unsigned>& v) //Första sorterings funktion
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
        //Börjar med att sätta minsta till första
        int min=i;
        //Söker efter minsta tal, lägger detta i min
        for(int j=i+1;j<=v.size()-1;j++)
            if (v.at(j)<v.at(min))
                min=j;

        bytPlats(v.at(i),v.at(min));
    }
}

bool tidmatning(vector<unsigned> v,int gang_matning) //Funktionen som gör tidberäkning men skicka bara tillbaka en text till huvud funktionen.
{
    clock_t start,end; //Kod som behövs att kunna starta tidmatning.
    double matning; //Läggs till variablen

    start=clock(); //Första tidmätning börjar.

    if (gang_matning==1) //Om variablen gång_matning är likamed värde 1 (första gången funktionen körs).
        bubblesort(v); //Kör funktionen bubblesort (första sorterings funktionen)
    if (gang_matning==2) //Om variablen gång_matning är likamed värde 2 (andra gången funktionen körs).
        selectionsort(v); //Kör funktionen selectionsort (andra sorterings funktionen)

    end=clock(); //Första tidmätning slutat.
    matning=((double)(end-start))/CLOCKS_PER_SEC; //Beräknas ut tiden av första tidmätning.

    if (gang_matning==1) //Om variablen gång_matning är likamed värde 1 (första gången funktionen körs).
        return cout<<"          Buble sort: "<<setprecision(3)<<matning<<" sekunder."<<endl; //Skicka tillbaka beräkningen av Bubble sort till huvudfunktionen som kommer på skärmen. Svaret har 3 värdetal.
    if (gang_matning==2) //Om variablen gång_matning är likamed värde 2 (andra gången funktionen körs).
        return cout<<"          Selection sort: "<<setprecision(3)<<matning<<" sekunder."<<endl; //Skicka tillbaka beräkningen av Selection Sort till huvudfunktionen som kommer på skärmen. Svaret har 3 värdetal.
}

int main() //Huvud funktionen
{

    vector<unsigned> v,v_kopia; //Läggs till 2 vektorer.
    unsigned element; //Läggs till variablen element.

    while (element!=0) //Om variablen element är inte likamed 0 körs föjande kod därefter igen.
    {
        int gang_matning=1; //Läggs till variablen gång_matning på värde 1.

        laggVektor(v,v_kopia,element); //Kör funktionen laggVektor.
        if (element==0) //Om variablen element är likamed 0 avslutar programmet.
            return 0;

        tidmatning(v,gang_matning); //Kör funktionen tidmatning för första gången.
        v=v_kopia; //Vektorn v resetar.
        gang_matning+=1; //Variablen gång_matning adderas med 1.
        tidmatning(v,gang_matning); //Kör funktionen tidmatning för andra gången.

        cout<<"\n\n\nBer\204kningarna \204r nu f\204rdiga.";//Skrivs ut sista text på skärmen.

        cin.ignore(); cin.ignore(); //Behövs att klicka på enter för att köra program vidare.
        system("cls"); //Skärmet blir tomt.
    }
}
