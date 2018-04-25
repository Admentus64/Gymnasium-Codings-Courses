#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double raknaMedel(vector<double> v)
{
    double summa=0;
    for(int i=0; i<v.size(); i++)
        summa+=v.at(i);
    return summa/v.size();
}

double raknaMedian(vector<double> v)
{
    sort(v.begin(),v.end());

    int jamnt;

    if (v.size()%2==0)
        jamnt=1;
    else
        jamnt=0;

    if (jamnt==1)
    {
        double summa=v.at((v.size()-1)/2)+v.at(v.size()/2);
        return summa/2;

        //double mediantal=0;
        //mediantal+=v.at((v.size()/2)+1);
        //mediantal+=v.at((v.size()/2)-1);
        //return mediantal/2;
    }
    if (jamnt==0)
    {
        return v.at(v.size()/2);
    }
}

int main()
{
    vector<double> v;
    int antal;
    double input;

    cout<<"Ange antal flyttal i vektorn: ";
    cin>>antal; cin.ignore();
    cout<<endl;
    for(int i=0; i<antal; i++)
    {
        cout<<"Ange tal "<<i+1<<": ";
        cin>>input; cin.ignore();
        v.push_back(input);
    }

    cout<<endl;
    cout<<"Talens medelv\204rde \204r: "<<raknaMedel(v)<<endl;
    cout<<"Talens medianv\204rde \204r: "<<raknaMedian(v)<<endl;

    vector<int> x1; vector<int> y1;
     for(int i=0; i<10; i++)
     {
         cout<<"X: "<<i*40+20<<endl;
     }

    return 0;
}

