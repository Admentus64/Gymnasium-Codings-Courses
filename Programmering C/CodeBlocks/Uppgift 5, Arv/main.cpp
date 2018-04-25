#include "Student.h"
#include "Anstalld.h"
#include "Kurs.h"
#include "DistansKurs.h"
#include "Kurstillfalle.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    //Person klasser

    Person p;
    p.forNamn = "Pelle";
    p.efterNamn = "Persson";
    p.persNr = "160390 - 3563";

    Student ps;
    ps.studentID = "67828";
    ps.antagningsAr = "2003";

    Anstalld pa;
    pa.stallningsID = "4678";
    pa.tillsvidareAnstalld = true;

    //Kurs klasser

    Kurs k;
    k.kursNamn = "Programmering C";
    k.kursPoang = 300;
    k.kursLedare = "Hans Huggson";

    DistansKurs kd;
    kd.ePlattform = "Itslearning.com";

    Kurstillfalle ku;
    ku.startTid = "Januari 2011";
    ku.slutTid = "Januari 2012";
    ku.kurs = "Programmering C";



    //Couts
    cout << "Klass Person" << endl << "------------" << endl;
    cout << "F\224rnamn: "<< p.forNamn << endl;
    cout << "Efternamn: " << p.efterNamn << endl;
    cout << "Person nummer: " << p.persNr << endl << endl;

    cout << "Klass Student" << endl << "------------" << endl;
    cout << "Student ID: " << ps.studentID << endl;
    cout << "Antagnings\206r: " << ps.antagningsAr << endl;
    cout << "Anst\204llnings ID: " << pa.stallningsID << endl;
    cout << "Tillsvidareanstalld: ";
    if (pa.tillsvidareAnstalld = true)
        cout << "Ja" << endl << endl;
    else
        cout << "Nej" << endl << endl;

    cout << "Klass Kurs" << endl << "------------" << endl;
    cout << "Kursnamn: " << k.kursNamn << endl;
    cout << "Kurspo\204ng: " << k.kursPoang << endl;
    cout << "Kursledare: " << k.kursLedare << endl << endl;

    cout << "Klass DistansKurs" << endl << "------------" << endl;
    cout << "E-plattform: " << kd.ePlattform << endl << endl;

    cout << "Klass Kurstillfalle" << endl << "------------" << endl;
    cout << "Starttid: " << ku.startTid << endl;
    cout << "Sluttid" << ku.slutTid << endl;
    cout << "Kurs: " << ku.kurs << endl << endl;

    return 0;
}
