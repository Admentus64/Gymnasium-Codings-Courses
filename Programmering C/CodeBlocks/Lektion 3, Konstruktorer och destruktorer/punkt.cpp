#include <iostream>
#include "punkt.h"
using namespace std;

Punkt::Punkt(const Punkt& x)
{
    cout<<"Kopieringskonstruktor skrivs ut";
}
//Här står alla koden ifrån de vanliga konstruktorer.

//Punkt::Punkt()
//    { setX(0); setY(1); }
//Punkt::Punkt(float x0, float y0)
//    { setX(x0); setY(y0); }

//void Punkt::setX(float x0)
//    { x = x0; }
//float Punkt::getX()
//    { return x; }

//void Punkt::setY(float y0)
//    { y = y0; }
//float Punkt::getY()
//    { return y; }
