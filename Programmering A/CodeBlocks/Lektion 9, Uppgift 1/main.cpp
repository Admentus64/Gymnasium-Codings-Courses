#include <iostream>
#include <vector>
using namespace std;

void bytPlats(int a, int b)
{
    int c=a;
    a=b;
    b=c;

}

int main()
{
    int a=1, b=2;
    cout<<"F\224re bytet: "<<a<<" "<<b<<endl;
    bytPlats(a,b);
    cout<<"Efter bytet: "<<a<<" "<<b<<endl;
    return 0;
}
