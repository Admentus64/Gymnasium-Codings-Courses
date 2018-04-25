#include <iostream>
#include <list>
#include <string>
#include<cstdlib>
using namespace std;

struct person //L�ggs till en struct med 3 variabler
{
    string fornamn;
    string efternamn;
    string personnummer;
};

void huvudmeny(string& menyVal) //Meny var man v�ljer en option
{
    cout<<"      HUVUDMENY\n======================"<<endl;
    cout<<"1. L\204gg till ny person"<<endl;
    cout<<"2. Skriv ut personregister"<<endl;
    cout<<"0. Avsluta programmet"<<endl;
    cout<<"Ange ditt val: ";
    getline(cin,menyVal);
    if (menyVal!="0")
        cout<<endl; //texten b�rja p� nytt r�d
    if (menyVal!="0" && menyVal!="1" && menyVal!="2") //Kr�vs 0, 1 eller 2 som inmattning
        {
            if(menyVal.size()==1)
                cout<<"Du angde ett felaktigt val, ange om g\204rna";
            if(menyVal.size()>1)
                cout<<"Du f\206r bara mata in 1 siffra, ange om g\204rna";
            if(menyVal.size()==0)
                cout<<"Du har inte angat ett val, ange g\204rna";

            cin.ignore(); //Klicka p� Enter, d�refter st�das sk�rmen
            system("cls");
        }
}

void ny_person(list<person>& p_list) //Funktionen var man l�gger till nya personer
{
    cout<<"NYREGISTRERING AV PERSON\n========================"<<endl; //Titeln

    person p; //Inmattning av ny person med 3 variabler
    cout<<"Ange fornamn: ";
    getline(cin,p.fornamn);
    cout<<"Ange efternamn: ";
    getline(cin,p.efternamn);
    cout<<"Ange personnummer: ";
    getline(cin,p.personnummer);

    if(p_list.size()==0)
    {
            p_list.push_back(p); //L�gg till personen om det finns inga andra personer i listan

            system("cls"); //Klicka p� Enter, d�refter returna till main()
            return;
    }

    for(list<person>::iterator it=p_list.begin();it!=p_list.end();it++)
    {
        if(p.efternamn<it->efternamn)
        {
            p_list.insert(it,p); //L�gg till personen p� alfabetiskt ordning om iterator inte pekar p� sista element

            system("cls"); //Klicka p� Enter, d�refter returna till main()
            return;
        }
    }

    p_list.push_back(p); //L�gg till personen p� sista plats om allt annat inte st�mmer
    system("cls"); //Klicka p� Enter
}

void skriv_ut(list<person>& p_list) //Funktionen var programmet skrivs ut personregister
{
    cout<<"UTSKRIFT AV HELA REGISTRET\n=========================="<<endl; //Titeln

    for(list<person>::iterator it=p_list.begin();it!=p_list.end();it++) //Skrivs ut fornamn, efternamn och personummer fr�n alla personer p� ordning de st�r in
    {
        cout<<"Namn: "<<it->fornamn<<" "<<it->efternamn<<endl;
        cout<<"Personnr: "<<it->personnummer<<endl<<endl;
    }

    cin.ignore(); //Klicka p� Enter, d�refter st�das sk�rmen
    system("cls");
}

int main()
{
    list<person> p_list; //l�gg till variabler och list
    string menyVal;

    while(menyVal!="0") //programmet k�r tills menyVal inte �r 0
    {
        cout<<endl; //texten b�rja p� nytt r�d i loopen
        huvudmeny(menyVal); //f�rsta funktion k�rs var man mata in val, d�refter f�ljer funkionen man valde, sen b�rja om (om ingen 0 inmattad)
        if(menyVal=="1")
            ny_person(p_list);
        if(menyVal=="2")
            skriv_ut(p_list);
    }
    return 0; //Programmer avsluta om man matade in 0 p� menyVal (i huvudmeny funktionen)
}
