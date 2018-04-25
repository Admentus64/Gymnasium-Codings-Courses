#include <iostream>
using namespace std;

int kontroll(int aa, int bb, int cc);
int minsta(int a, int b, int c);
void storleksordning(int a, int b, int c);

int main()
{
    int tal1, tal2, tal3;
    int felen;

    cout<<"Storleksordning"<<endl;
    cout<<"==============="<<endl;

    cout<<"\nSkriv 3 heltal, separerade med blanksteg\nDu f\206r inte anv\204nda samma tal: ";
    cin>>tal1>>tal2>>tal3;
    cin.get();
    cout<<"\n";
    felen=kontroll(tal1,tal2,tal3);

    while(felen==1)
    {
        cout<<"\nDu skrev 3 heltal som var det samma.\nSkriv 3 andra heltal, separerade med blanksteg: ";
        cin>>tal1>>tal2>>tal3;
        cin.get();
        cout<<"\n";
        felen=kontroll(tal1,tal2,tal3);
    }

    cout<<"Det minsta talet \204r: "<<minsta(tal1,tal2,tal3)<<endl;

    cout<<"\nTalen i storleksordning: ";
    storleksordning(tal1,tal2,tal3);

    cout<<"\n";

    return 0;
}

int kontroll(int a, int b, int c)
{
    int fel;
    if (a==b or a==c or b==c)
        fel=1;
    else
        fel=0;
    return fel;
}

int minsta(int a, int b, int c)
{
    if (a<b && a<c)
        return a;

    if (b<a && b<c)
        return b;

    else
        return c;
}

void storleksordning(int a, int b, int c)
{
    if (a<b && a<c)
        if (b<c)
            cout<<a<<" "<<b<<" "<<c;
        else
            cout<<a<<" "<<c<<" "<<b;

    if (b<a && b<c)
        if (a<c)
            cout<<b<<" "<<a<<" "<<c;
        else
            cout<<b<<" "<<c<<" "<<a;

    if (c<a && c<b)
        if (a<b)
            cout<<c<<" "<<a<<" "<<b;
        else
            cout<<c<<" "<<b<<" "<<a;
}
