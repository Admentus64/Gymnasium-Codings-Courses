#include <iostream>
using namespace std;

double klotvolym(double radie);

int main()
{
    double radien;

    cout<<"Ber\204kning av klotets volym"<<endl;
    cout<<"=========================="<<endl;

    cout<<"\nAnge klotets radien: ";
    cin>>radien;    cin.ignore();

    cout<<"Klotets volym \204r: "<<klotvolym(radien)<<endl;
    cin.get();

    return 0;
}

double klotvolym(double radie)
{
    double klotvolym=4*3.14*radie*radie*radie;
    return klotvolym;
}
