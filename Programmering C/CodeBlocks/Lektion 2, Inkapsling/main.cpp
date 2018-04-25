#include <cstdlib>
#include <iostream>
#include <string>
#include "person.h"
#include "dator.h"
using namespace std;

int main(int argc, char *argv[])
{
    Person* P=new Person; Dator* D=new Dator;
    string s; int i; float f;

    cout << "Ange f\224rnamn: ";                            getline(cin,s);     P->setFornamn(s);
    cout << "Ange efternamn: ";                             getline(cin,s);     P->setEfternamn(s);
    cout << "Ange M eller K f\224r kvinna eller man: ";     getline(cin,s);     P->setKon(s);
    cout << "Ange f\224delse\206r: ";                       cin>>i;             P->setFodelsear(i);

    cout << endl; cin.ignore();

    cout << "Ange datorns processor: ";                     getline(cin,s);     D->setKraft(s);
    cout << "Ange datorns arbetsminne i Gb: ";              cin>>i;             D->setMinne(i);
    cout << "Ange datorns h\206rddisk i Gb: ";              cin>>i;             D->setDisk(i);
    cout << "Ange datorns pris i Kr: ";                     cin>>f;             D->setPris(f);

    cout << endl << P->getEfternamn()   << endl;
    cout << P->getFornamn()             << endl;
    cout << P->getKon()                 << endl;
    cout << P->getFodelsear()           << endl << endl;

    cout << D->getKraft()       << endl;
    cout << D->getMinne()               << endl;
    cout << D->getDisk()                << endl;
    cout << D->getPris()                << endl << endl;





    delete P; delete D;

    system("PAUSE");
}
