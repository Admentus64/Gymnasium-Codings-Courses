#include <iostream>
#include <vector>
using namespace std;

void skapa(vector<int>& v)
{
    int input;
    cout<<"Hur m\206nga slumptal vill du mata in? ";
    cin>>input; cin.ignore();
    cout<<endl;

    cout<<"Programmet valde "<<input<<" slumptal mellan 0-100. De valda tal \204r: "<<endl;
    srand(time(0));
    for(int i=0; i<input; i++)
    {
        v.push_back(rand()%101);
        if (input<21)
            cout<<v.back()<<" ";
    }
    if (input>20)
        cout<<"Du valde f\224r mycket slumptal. Programmet ska inte vissa de";
    cout<<endl;
    cout<<endl;
}

int medelvarde(vector<int>& v)
{
    int summa=0;
    for(int i=0; i<v.size(); i++)
        summa+=v.at(i);
    return summa/v.size();
}

int medianvarde(vector<int>& v)
{
    sort(v.begin(),v.end());

    int jamnt;

    if (v.size()%2==0)
        jamnt=1;
    else
        jamnt=0;

    if (jamnt==1)
    {
        int summa=v.at((v.size()-1)/2)+v.at(v.size()/2);
        return summa/2;
    }
    if (jamnt==0)
    {
        return v.at(v.size()/2);
    }
}

int main()
{
    vector<int> talvektor;
    skapa(talvektor);

    cout<<"Talens medelv\204rde \204r: "<<medelvarde(talvektor)<<endl;
    cout<<"Talens medianv\204rde \204r: "<<medianvarde(talvektor)<<endl;

    return 0;
}
