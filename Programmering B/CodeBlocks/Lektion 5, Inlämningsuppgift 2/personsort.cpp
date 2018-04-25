#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct person
{
    string fnamn;
    string enamn;
};

void skriv_ut(vector<person> pv)
{
    for(int i=0;i<pv.size();i++)
        cout<<pv.at(i).fnamn<<" "<<pv.at(i).enamn<<endl;
}

void bytPlats (string& a, string& b)
{
    string temp=a;
    a=b;
    b=temp;
}

void sortera(vector<person>& pv)
{
    for (int i=0;i<pv.size()-1;i++)
    {
        //Börjar med att sätta minsta till första
        int min=i;

        //Söker efter minsta tal, lägger detta i min
        for(int j=i+1;j<=pv.size()-1;j++)
            if (pv.at(j).enamn<pv.at(min).enamn)
                min=j;

        bytPlats(pv.at(i).enamn,pv.at(min).enamn);
        bytPlats(pv.at(i).fnamn,pv.at(min).fnamn);
    }
}

int main()
{
    vector<person> pv;
    person p1={"Hikaru","Sulu"};
    person p2={"Leonard","McCoy"};
    person p3={"Pavel","Chekov"};
    person p4={"Montgomery","Scott"};

    pv.push_back(p1);
    pv.push_back(p2);
    pv.push_back(p3);
    pv.push_back(p4);

    cout<<"Personerna i osorterad ordning: "<<endl;
    skriv_ut(pv);
    cout<<endl;

    sortera(pv);
    cout<<"Personerna i sorterad ordning: "<<endl;
    skriv_ut(pv);

    return 0;
}
