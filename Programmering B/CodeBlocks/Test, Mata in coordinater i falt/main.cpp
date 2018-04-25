#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    int x=0,y=0;
    string y_bok;
    string falt[9][9];

    for(int i=1;i<9;i++)
        for(int j=1;j<9;j++)
            falt[i][j]="[X]";

    cout<<"Tal >> Bokstav. Mata in coordinaterna: ";
    cin>>x>>y_bok;

    if (y_bok=="a")     y=1;
    if (y_bok=="b")     y=2;
    if (y_bok=="c")     y=3;
    if (y_bok=="d")     y=4;
    if (y_bok=="e")     y=5;
    if (y_bok=="f")     y=6;
    if (y_bok=="g")     y=7;
    if (y_bok=="h")     y=8;

    cout<<endl;

    falt[x][y]="[O]";

    for (int i=1;i<9;i++)
    {
        for (int j=1;j<9;j++)
            cout<<falt[i][j]<<" ";
        cout<<endl<<endl;
    }

    return 0;
}
