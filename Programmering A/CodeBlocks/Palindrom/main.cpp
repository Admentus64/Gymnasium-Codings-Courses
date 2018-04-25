#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[10], palindrom[10];
    cout<<"Skriv ett ord: ";
    cin>>str;
    strcpy(palindrom,str);

    strlen(palindrom)-1;
    for(int i=0; i<strlen(palindrom); i++)
        palindrom[i]=palindrom[strlen(palindrom)-1-i];

    if (strcmp(str,palindrom)==0)
        cout<<"Ordet: "<<str<<" \204r en palindrom.";
    else
        cout<<"Ordet: "<<str<<" \204r inte en palindrom.";
    return 0;
}
