#ifndef STUDENTH
#define STUDENTH
#include <string>
#include "Person.h"
using namespace std;

class Student : public Person
{
public:
    string studentID;
    string antagningsAr;
};

#endif
