#ifndef ANSTALLDH
#define ANSTALLDH
#include <string>
#include "Person.h"
using namespace std;

class Anstalld : public Person
{
public:
    string stallningsID;
    bool tillsvidareAnstalld;
};

#endif
