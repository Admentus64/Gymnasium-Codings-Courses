#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct person { string fnamn; string enamn; };

void sortera(vector<person>& pv)
{
    //skickaperson& a,b,c;
    //vector<skickaperson>& spv;
    //spv.push_back(a); spv.push_back(b); spv.push_back(c);

    string af,bf,cf,ae,be,ce;
    af=pv.at(0).fnamn; bf=pv.at(1).fnamn; cf=pv.at(2).fnamn;
    ae=pv.at(0).enamn; be=pv.at(1).enamn; ce=pv.at(2).enamn;

    if (ae<be && ae<ce)
    {
        pv.at(0).fnamn=af; pv.at(0).enamn=ae;
        if (be<ce)
        {
            pv.at(1).fnamn=bf; pv.at(2).fnamn=cf;
            pv.at(1).enamn=be; pv.at(2).enamn=ce;
        }
        if (ce<be)
        {
            pv.at(1).fnamn=cf; pv.at(2).fnamn=bf;
            pv.at(1).enamn=ce; pv.at(2).enamn=be;
        }
    }
    if (be<ae && be<ae)
    {
        pv.at(0).fnamn=bf; pv.at(0).enamn=be;
        if (ae<ce)
        {
            pv.at(1).fnamn=af; pv.at(2).fnamn=cf;
            pv.at(1).enamn=ae; pv.at(2).enamn=ce;
        }
        if (ce<ae)
        {
            pv.at(1).fnamn=cf; pv.at(2).fnamn=af;
            pv.at(1).enamn=ce; pv.at(2).enamn=ae;
        }
    }
    if (ce<ae && ce<be)
    {
        pv.at(0).fnamn=cf; pv.at(0).enamn=ce;
        if (ae<be)
        {
            pv.at(1).fnamn=af; pv.at(2).fnamn=bf;
            pv.at(1).enamn=ae; pv.at(2).enamn=be;
        }
        if (be<ae)
        {
            pv.at(1).fnamn=bf; pv.at(2).fnamn=af;
            pv.at(1).enamn=be; pv.at(2).enamn=ae;
        }
    }
}

int main()
{
    person p1, p2, p3;
    vector<person> pv;
    p1.fnamn="Luke"; p1.enamn="Skywalker"; pv.push_back(p1);
    p2.fnamn="Han"; p2.enamn="Solo"; pv.push_back(p2);
    p3.fnamn="Lando"; p3.enamn="Calrissian"; pv.push_back(p3);
    sortera(pv); //Sätta alla personer på ordning av efternamn
    for(int i=0;i<pv.size();i++) //Skriver ut alla personer
        cout<<pv.at(i).fnamn<<" "<<pv.at(i).enamn<<endl; //Skriver ut alla personer
    return 0;
}
