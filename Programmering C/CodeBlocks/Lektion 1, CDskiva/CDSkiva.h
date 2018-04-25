#ifndef CDSKIVAH
#define CDSKIVAH
#include <string>
#include <vector>
#include "Lat.h"
using namespace std;

class CDSkiva
{
public:
    string album;
    string artist;
    vector<Lat> latar;

    void inmat();
    void visa();
};

#endif
