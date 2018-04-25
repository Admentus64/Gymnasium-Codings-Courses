#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(0));
    int summa=0, medelvarden, gang;
    const int SIZE=100;
    double talfalt[SIZE];

    for(int i=0;i<SIZE;i++)
        talfalt[i]=rand()%99;

    for(int i=0;i<SIZE;i++)
        summa+=talfalt[i];

    cout<<"Datorn skrev f\204ljanda tal: "<<endl;
    for(int i=0;i<SIZE;i++)
    {
        if(i%6==0)
            cout<<endl;
        cout<<setw(2)<<talfalt[i]<<" ";
    }

    medelvarden=summa/100;
    cout<<"\n\nMedelv\204rden \204r: "<<medelvarden<<endl;

    return 0;
}
