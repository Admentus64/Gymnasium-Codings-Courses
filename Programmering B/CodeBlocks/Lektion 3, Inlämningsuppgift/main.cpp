#include <iostream>
#include <list>
#include <string>
#include<cstdlib>
using namespace std;

struct person //Läggs till en struct med 3 variabler
{
    string fornamn;
    string efternamn;
    string personnummer;
};

void huvudmeny(string& menyVal) //Meny var man väljer en option
{
    cout<<"      HUVUDMENY\n======================"<<endl;
    cout<<"1. L\204gg till ny person"<<endl;
    cout<<"2. Skriv ut personregister"<<endl;
    cout<<"0. Avsluta programmet"<<endl;
    cout<<"Ange ditt val: ";
    getline(cin,menyVal);
    if (menyVal!="0")
        cout<<endl; //texten börja på nytt råd
    if (menyVal!="0" && menyVal!="1" && menyVal!="2") //Krävs 0, 1 eller 2 som inmattning
        {
            if(menyVal.size()==1)
                cout<<"Du angde ett felaktigt val, ange om g\204rna";
            if(menyVal.size()>1)
                cout<<"Du f\206r bara mata in 1 siffra, ange om g\204rna";
            if(menyVal.size()==0)
                cout<<"Du har inte angat ett val, ange g\204rna";

            cin.ignore(); //Klicka på Enter, därefter städas skärmen
            system("cls");
        }
}

void ny_person(list<person>& p_list) //Funktionen var man lägger till nya personer
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
            p_list.push_back(p); //Lägg till personen om det finns inga andra personer i listan

            system("cls"); //Klicka på Enter, därefter returna till main()
            return;
    }

    for(list<person>::iterator it=p_list.begin();it!=p_list.end();it++)
    {
        if(p.efternamn<it->efternamn)
        {
            p_list.insert(it,p); //Lägg till personen på alfabetiskt ordning om iterator inte pekar på sista element

            system("cls"); //Klicka på Enter, därefter returna till main()
            return;
        }
    }

    p_list.push_back(p); //Lägg till personen på sista plats om allt annat inte stämmer
    system("cls"); //Klicka på Enter
}

void skriv_ut(list<person>& p_list) //Funktionen var programmet skrivs ut personregister
{
    cout<<"UTSKRIFT AV HELA REGISTRET\n=========================="<<endl; //Titeln

    for(list<person>::iterator it=p_list.begin();it!=p_list.end();it++) //Skrivs ut fornamn, efternamn och personummer från alla personer på ordning de står in
    {
        cout<<"Namn: "<<it->fornamn<<" "<<it->efternamn<<endl;
        cout<<"Personnr: "<<it->personnummer<<endl<<endl;
    }

    cin.ignore(); //Klicka på Enter, därefter städas skärmen
    system("cls");
}

int main()
{
    list<person> p_list; //lägg till variabler och list
    string menyVal;

    while(menyVal!="0") //programmet kör tills menyVal inte är 0
    {
        cout<<endl; //texten börja på nytt råd i loopen
        huvudmeny(menyVal); //första funktion körs var man mata in val, därefter följer funkionen man valde, sen börja om (om ingen 0 inmattad)
        if(menyVal=="1")
            ny_person(p_list);
        if(menyVal=="2")
            skriv_ut(p_list);
    }
    return 0; //Programmer avsluta om man matade in 0 på menyVal (i huvudmeny funktionen)
}
