#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string a; vector<string> b;

    getline(cin,a);
    b.push_back(a);

    cout<<"Getline A: "<<a<<endl;
    cout<<"Vector B: "<<a<<endl;

    cin.ignore();

    return 0;
}
