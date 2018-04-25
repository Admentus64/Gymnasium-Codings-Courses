#ifndef PERSONH
#define PERSONH
#include <string>
using namespace std;

class Person
{
private:
    string fornamn;
    string efternamn;
    bool kon;
    int fodelsear;
public:
    void setFornamn(string s);
    string getFornamn();
    void setEfternamn(string s);
    string getEfternamn();
    void setKon(string s);
    string getKon();
    void setFodelsear(int i);
    int getFodelsear();
};

#endif
