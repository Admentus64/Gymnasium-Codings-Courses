#ifndef DATORH
#define DATORH
#include <string>
using namespace std;

class Dator
{
private:
    string kraft;
    int minne;
    int disk;
    float pris;
public:
    void setKraft(string s);
    string getKraft();
    void setMinne(int i);
    int getMinne();
    void setDisk(int i);
    int getDisk();
    void setPris(float f);
    float getPris();
};

#endif
