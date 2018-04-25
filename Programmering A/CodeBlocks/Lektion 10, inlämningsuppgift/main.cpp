#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct person
{
    string namn;
    string personnummer;
};

void Huvudmenu(int& val)
{
    cout<<"       HUVUDMENY"<<endl; cout<<"========================"<<endl;
    cout<<"1. L\204gg till ny person"<<endl; cout<<"2. Skriv ut personregistret"<<endl;
    cout<<"3. S\224k efter person"<<endl; cout<<"0. Avsluta programmet"<<endl;
    cout<<"Ange ditt val: ";
    cin>>val; cin.ignore(); cout<<endl;
}

void LaggTill(vector<person>& pvektor)
{
    system("cls");
    person p;
    cout<<"NYREGISTRERING AV PERSON"<<endl; cout<<"========================"<<endl;
    cout<<"Ange namn: "; getline(cin,p.namn);
    cout<<"Ange personnummer: "; getline(cin,p.personnummer);
    pvektor.push_back(p);
    cin.ignore(); system("cls");
}

void SkrivUt(const vector<person>& pvektor)
{
    system("cls");
    cout<<"UTSKRIVT AV HELE REGISTRET"<<endl; cout<<"========================"<<endl;
    for (int i=0; i<pvektor.size(); i++)
    {
        cout<<"Namn: "<<pvektor.at(i).namn<<endl;
        cout<<"Personnummer: "<<pvektor.at(i).personnummer<<endl;
        cout<<endl;
    }
}

void SokPerson(const vector<person>& pvektor)
{
    string LetaNummer;
    cout<<"S\231KNING I REGISTRET"<<endl; cout<<"========================"<<endl;
    cout<<"Ange Personnummer: ";
    getline(cin,LetaNummer);
    cout<<endl;
    for (int i=0; i<pvektor.size(); i++)
    {
        if (pvektor.at(i).personnummer==LetaNummer)
        {
            cout<<"Hittade f\224ljande person:"<<endl;
            cout<<"Namn: "<<pvektor.at(i).namn<<endl;
            cin.ignore(); system("cls");
            return;
        }
    }
    cout<<"Personen finns inte i registret"<<endl;
    cin.ignore(); system("cls");
}

void Error(int& val)
{
    cout<<val<<" \204r inget val. Val ett annat tal."<<endl; cout<<endl;
    cin.ignore(); system("cls");
}

void ErrorPerson()
{
    cout<<"Du har inte lagt till en person."<<endl; cout<<endl;
    cin.ignore(); system("cls");
}

int main()
{
    int val; vector<person> pvektor;
    while (val!=0)
    {
        Huvudmenu(val);
        if (val==1) LaggTill(pvektor);
        if (val==2)
        {
            if (pvektor.size()==0) ErrorPerson();
            else SkrivUt(pvektor);
        }
        if (val==3)
        {
            if (pvektor.size()==0) ErrorPerson();
            else SokPerson(pvektor);
        }
        if (val<0 || val>3) Error(val);
    }
    return 0;
}
