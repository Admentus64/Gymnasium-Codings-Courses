#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool palindrom(string ord);

int main()
{
    string ord;

    cout<<"-----------------------------\nUppgift: \204r det en palindrom?\n-----------------------------"<<endl;
    cout<<"Skriv ett ord: ";
    cin>>ord; cin.get();
    cout<<endl;

    if (palindrom(ord)==true)
        cout<<"Ordet du skrev \204r en palindrom."<<endl;
    else
        cout<<"Ordet du skrev \204r inte en palindrom."<<endl;

    return 0;
}

bool palindrom(string ord)
{
    for(int i=0; i<ord.size(); i++)
    {
        if (ord.at(i)!=ord.at(ord.size()-1-i))
            return false;
    }
    return true;
}
