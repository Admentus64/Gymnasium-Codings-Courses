#include<iostream>
#include<stack>
#include<cstdlib>
#include<string>
using namespace std; //läggas till alla #include och namespace som behövs

void mata_in_strang(string& strang, int& error) //funktionen var man mata in strangen
{
        system("cls");
        cout<<"Mata in 0 f\224r att avsluta programmet!"<<endl<<endl;
        cout<<"Ange en str\204ng: "; //skriver ut text, och börjar med vitt skärm
        getline(cin,strang); //mata in strangen
        if (strang.size()==0) //om storleken av strangen är större än 0
        {
            error=1; //error blir 1
            cout<<"\nMata in en string g\204rna, f\224rs\224k om!"; //skriver ut text
        }
}

bool strang_check(stack<char>& parentes, string strang) //funktionen var returnas texten om parenteser är stängda
{
    while(!parentes.empty())
        parentes.pop(); //stacken blir tomt

    for (int i=0;i<strang.size();i++) //går genom hela strangen
        {
            if (strang.at(i)=='(') //om det hittar en "("
                parentes.push('('); //läggas till "(" i stacken som char
            if (strang.at(i)==')') //om det hittar en ")"
            {
                if (parentes.empty()) //om stacken är tomt
                    return cout<<"\nFel! Det finns parenteser som inte \204r st\204ngda."; //skriver uit text
                if (!parentes.empty()) //om stacken är inte tomt
                    parentes.pop(); //den högsta "(" tars bort från stacken
            }
        }
    if (!parentes.empty()) //om stacken är tomt
        return cout<<"\nFel! Det finns parenteser som inte \204r st\204ngda."; //skriver uit text

    return cout<<"\nOk! Alla parenteser \204r st\204ngda."; //skriver uit text
}

int main() //huvudfunktioen
{
    stack<char> parentes;
    string strang;
    int error; //läggas till alla variabler

    while (strang!="0") //om strangen är inte likamed "0" körs loopen till
    {
        error=0; //error är 0
        mata_in_strang(strang,error); //ropa mata_in_strang funktionen
        if (strang=="0") //om strangen är likamed "0"
            return 0; //avsluta programmet
        if (error==0) //om error är 0
            strang_check(parentes,strang); //ropa strang_check funktionen
        cin.ignore(); //behövs klicka på enter
    }
}
