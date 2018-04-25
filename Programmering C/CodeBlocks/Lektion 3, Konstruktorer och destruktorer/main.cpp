#include <cstdlib>
#include <iostream>
#include "punkt.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Punkt a: "; Punkt a(1,3);
    cout << "Punkt b: "; Punkt b(1);
    cout << "Punkt c: "; Punkt c();
    Punkt d;
    cout << "Punkt e: "; Punkt e = 5;
    cout << "Punkt f: "; Punkt* f = new Punkt;

    float x0, y0;

    cout << endl << "Ange X: ";     cin >> x0;       d.setX(x0);
    cout << "Ange Y: ";           cin >> y0;       d.setY(y0);
    cout << endl << "Punkt d: " <<"        (x = " << d.getX() << ") (y = " << d.getY() << ")" << endl << endl;

    Punkt p1 = d;
    cout << endl << "Punkt p1: " <<"       (x = " << p1.getX() << ") (y = " << p1.getY() << ")" << endl;

    delete f;

    //Här står alla koden ifrån de vanliga konstruktorer.

    //cout<<"Punkt a: ";
    //Punkt* a;
    //a = new Punkt;
    //cout<<"Punkt b: ";
    //Punkt b;
    //cout<<"Punkt c: ";
    //Punkt c(0,0);
    //cout<<"Punkt d: ";
    //Punkt * d = new Punkt(1,3);

    //delete a;
    //delete d;
}
