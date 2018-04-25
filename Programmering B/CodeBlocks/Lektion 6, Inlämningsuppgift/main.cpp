//I detta program skapas n�gra person-variabler, som sedan sparas
//i en textfil.
//Programmet l�ser d�refter in data fr�n filen i nya
//personvariabler, som lagras i en vektor.

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct person
{
    string namn;
    int alder;
    string pnummer;
};

//Konverterar en str�ng med siffertecken till ett heltal, t.ex.
//str�ngen "123" till talet 123
int stringtoint(string talstr)
{
    int talet;
    stringstream sstr(talstr);
    sstr>>talet;
    return talet;
}

void skriv_ut_person(person& p)
{
    cout<<"Namn: "<<p.namn<<endl;
    cout<<"\217lder: "<<p.alder<<endl;
    cout<<"Personnummer: "<<p.pnummer<<endl<<endl;
}

int main()
{
    person p1={"Anders",34,"1111-2222"};
    person p2={"Bengt",55,"3333-4444"};
    person p3={"Carl",23,"5555-6666"};
    //Skapar filen personer.txt och skriver persondata till filen
    ofstream utfil("personer.txt");
    utfil<<p1.namn<<endl;
    utfil<<p1.alder<<endl;
    utfil<<p1.pnummer<<endl;
    utfil<<p2.namn<<endl;
    utfil<<p2.alder<<endl;
    utfil<<p2.pnummer<<endl;
    utfil<<p3.namn<<endl;
    utfil<<p3.alder<<endl;
    utfil<<p3.pnummer<<endl;
    utfil.close();

    string namn, alder, pnummer;
    vector<person> personer;
    ifstream infil("personer.txt");

    //Loopen forts�tter s� l�nge n�sta tecken i filen inte �r
    //EOF (End Of File).
    //Vid inl�sning fr�n filen utnyttjar vi att varannan rad �r
    //namn, varannan �lder.
    while(infil.peek()!=EOF)
    {
        getline(infil,namn);
        getline(infil,alder);
        getline(infil,pnummer);
        person temp={namn,stringtoint(alder),pnummer};
        personer.push_back(temp);
    }
    infil.close();

    //Sriv ut alla personer i vektorn.
    for(int i=0;i<personer.size();i++)
        skriv_ut_person(personer.at(i));

    return 0;
}
