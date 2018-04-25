#include <iostream>

using namespace std;

double potens(double a, int n);

int main()
{
    double potensen_a;
    int potensen_n;

    cout<<"Potens\n======"<<endl;

    cout<<"\nSkriv A potensen. Man f\224r skriva decimaler: ";
    cin>>potensen_a;
    cin.get();

    cout<<"\nSkriv N potensen. Talet m\224ste vara ett heltal: ";
    cin>>potensen_n;
    cin.get();

    cout<<"\n\n\n";

    cout<<"Svaret \204r: "<<potens(potensen_a, potensen_n)<<endl;

    cout<<endl;
    return 0;
}

double potens(double a, int n)
{
    double p=a;
    for (int i=1; i<n; i++)
    {
        a=p*a;
    }
    return a;
}
