#include "person.h"

void Person::setFornamn(string s)
{
    fornamn=s;
}
string Person::getFornamn()
{
    return fornamn;
}

void Person::setEfternamn(string s)
{
    efternamn=s;
}
string Person::getEfternamn()
{
    return efternamn;
}

void Person::setKon(string s)
{
    if (s=="k" || s=="K")
        kon=true;
    else
        kon=false;
}
string Person::getKon()
{
    if (kon) return "K";
    else return "M";
}

void Person::setFodelsear(int i)
{
    fodelsear=i;

}
int Person::getFodelsear()
{
    return fodelsear;
}
