#ifndef KURSTILLFALLEH
#define KURSTILLFALLEH
#include <string>
#include "kurs.h"
using namespace std;

class Kurstillfalle : public Kurs
{
public:
    string startTid;
    string slutTid;
    string kurs;
};


#endif // KURSTILLFALLEH
