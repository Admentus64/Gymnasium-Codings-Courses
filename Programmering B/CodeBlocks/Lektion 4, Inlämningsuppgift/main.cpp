#include<iostream>
#include<stack>
#include<cstdlib>
#include<string>
using namespace std; //l�ggas till alla #include och namespace som beh�vs

void mata_in_strang(string& strang, int& error) //funktionen var man mata in strangen
{
        system("cls");
        cout<<"Mata in 0 f\224r att avsluta programmet!"<<endl<<endl;
        cout<<"Ange en str\204ng: "; //skriver ut text, och b�rjar med vitt sk�rm
        getline(cin,strang); //mata in strangen
        if (strang.size()==0) //om storleken av strangen �r st�rre �n 0
        {
            error=1; //error blir 1
            cout<<"\nMata in en string g\204rna, f\224rs\224k om!"; //skriver ut text
        }
}

bool strang_check(stack<char>& parentes, string strang) //funktionen var returnas texten om parenteser �r st�ngda
{
    while(!parentes.empty())
        parentes.pop(); //stacken blir tomt

    for (int i=0;i<strang.size();i++) //g�r genom hela strangen
        {
            if (strang.at(i)=='(') //om det hittar en "("
                parentes.push('('); //l�ggas till "(" i stacken som char
            if (strang.at(i)==')') //om det hittar en ")"
            {
                if (parentes.empty()) //om stacken �r tomt
                    return cout<<"\nFel! Det finns parenteser som inte \204r st\204ngda."; //skriver uit text
                if (!parentes.empty()) //om stacken �r inte tomt
                    parentes.pop(); //den h�gsta "(" tars bort fr�n stacken
            }
        }
    if (!parentes.empty()) //om stacken �r tomt
        return cout<<"\nFel! Det finns parenteser som inte \204r st\204ngda."; //skriver uit text

    return cout<<"\nOk! Alla parenteser \204r st\204ngda."; //skriver uit text
}

int main() //huvudfunktioen
{
    stack<char> parentes;
    string strang;
    int error; //l�ggas till alla variabler

    while (strang!="0") //om strangen �r inte likamed "0" k�rs loopen till
    {
        error=0; //error �r 0
        mata_in_strang(strang,error); //ropa mata_in_strang funktionen
        if (strang=="0") //om strangen �r likamed "0"
            return 0; //avsluta programmet
        if (error==0) //om error �r 0
            strang_check(parentes,strang); //ropa strang_check funktionen
        cin.ignore(); //beh�vs klicka p� enter
    }
}
