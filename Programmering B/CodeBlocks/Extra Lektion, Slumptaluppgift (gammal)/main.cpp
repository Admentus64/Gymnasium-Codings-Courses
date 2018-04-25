#include <iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

void steg1(unsigned element)
{
    ofstream utfil;
    utfil.open("slumptal, 1 tärning.txt");

    for (int i=1;i<4;i++)
    {
        unsigned slumptal=0,tal1=0,tal2=0,tal3=0,tal4=0,tal5=0,tal6=0;
        cout<<"\nK\224rning: "<<i<<endl;

        for (int j=0;j<element;j++)
        {
            slumptal=(rand()%6+1);
            if (slumptal==1) tal1+=1;
            if (slumptal==2) tal2+=1;
            if (slumptal==3) tal3+=1;
            if (slumptal==4) tal4+=1;
            if (slumptal==5) tal5+=1;
            if (slumptal==6) tal6+=1;
        }
        cout<<"\nTal 1 f\224rekommer antal g\206nger: "<<tal1<<endl;
        cout<<"Tal 2 f\224rekommer antal g\206nger: "<<tal2<<endl;
        cout<<"Tal 3 f\224rekommer antal g\206nger: "<<tal3<<endl;
        cout<<"Tal 4 f\224rekommer antal g\206nger: "<<tal4<<endl;
        cout<<"Tal 5 f\224rekommer antal g\206nger: "<<tal5<<endl;
        cout<<"Tal 6 f\224rekommer antal g\206nger: "<<tal6<<endl;

        utfil<<"Tal 1 (körning "<<i<<") : "<<tal1<<endl;
        utfil<<"Tal 2 (körning "<<i<<") : "<<tal2<<endl;
        utfil<<"Tal 3 (körning "<<i<<") : "<<tal3<<endl;
        utfil<<"Tal 4 (körning "<<i<<") : "<<tal4<<endl;
        utfil<<"Tal 5 (körning "<<i<<") : "<<tal5<<endl;
        utfil<<"Tal 6 (körning "<<i<<") : "<<tal6<<endl;
        utfil<<""<<endl;
    }
    cout<<"\nAntal t\204rningkast varje k\224rning: "<<element<<endl<<endl<<endl;

    utfil.close();
}

void steg2(unsigned element)
{
    ofstream utfil;
    utfil.open("slumptal, 2 tärningar.txt");

    for (int i=1;i<4;i++)
    {
        unsigned slumptal1=0,slumptal2=0,tal2=0,tal3=0,tal4=0,tal5=0,tal6=0,tal7=0,tal8=0,tal9=0,tal10=0,tal11=0,tal12=0;
        cout<<"\nK\224rning: "<<i<<endl;

        for (int j=0;j<element;j++)
        {
            slumptal1=(rand()%6+1);
            slumptal2=(rand()%6+1);
            if (slumptal1+slumptal2==2) tal2+=1;
            if (slumptal1+slumptal2==3) tal3+=1;
            if (slumptal1+slumptal2==4) tal4+=1;
            if (slumptal1+slumptal2==5) tal5+=1;
            if (slumptal1+slumptal2==6) tal6+=1;
            if (slumptal1+slumptal2==7) tal7+=1;
            if (slumptal1+slumptal2==8) tal8+=1;
            if (slumptal1+slumptal2==9) tal9+=1;
            if (slumptal1+slumptal2==10) tal10+=1;
            if (slumptal1+slumptal2==11) tal11+=1;
            if (slumptal1+slumptal2==12) tal12+=1;
        }
        cout<<"\nTal 2 f\224rekommer antal g\206nger: "<<tal2<<endl;
        cout<<"Tal 3 f\224rekommer antal g\206nger: "<<tal3<<endl;
        cout<<"Tal 4 f\224rekommer antal g\206nger: "<<tal4<<endl;
        cout<<"Tal 5 f\224rekommer antal g\206nger: "<<tal5<<endl;
        cout<<"Tal 6 f\224rekommer antal g\206nger: "<<tal6<<endl;
        cout<<"Tal 7 f\224rekommer antal g\206nger: "<<tal7<<endl;
        cout<<"Tal 8 f\224rekommer antal g\206nger: "<<tal8<<endl;
        cout<<"Tal 9 f\224rekommer antal g\206nger: "<<tal9<<endl;
        cout<<"Tal 10 f\224rekommer antal g\206nger: "<<tal10<<endl;
        cout<<"Tal 11 f\224rekommer antal g\206nger: "<<tal11<<endl;
        cout<<"Tal 12 f\224rekommer antal g\206nger: "<<tal12<<endl;

        utfil<<"Tal 2 (körning "<<i<<") : "<<tal2<<endl;
        utfil<<"Tal 3 (körning "<<i<<") : "<<tal3<<endl;
        utfil<<"Tal 4 (körning "<<i<<") : "<<tal4<<endl;
        utfil<<"Tal 5 (körning "<<i<<") : "<<tal5<<endl;
        utfil<<"Tal 6 (körning "<<i<<") : "<<tal6<<endl;
        utfil<<"Tal 7 (körning "<<i<<") : "<<tal7<<endl;
        utfil<<"Tal 8 (körning "<<i<<") : "<<tal8<<endl;
        utfil<<"Tal 9 (körning "<<i<<") : "<<tal9<<endl;
        utfil<<"Tal 10 (körning "<<i<<") : "<<tal10<<endl;
        utfil<<"Tal 11 (körning "<<i<<") : "<<tal11<<endl;
        utfil<<"Tal 12 (körning "<<i<<") : "<<tal12<<endl;
        utfil<<""<<endl;
    }
    cout<<"\nAntal t\204rningkast varje k\224rning: "<<element<<endl<<endl<<endl;

    utfil.close();
}

int main()
{
    unsigned element;
    srand(time(0));

    cout<<"Mata in antal g\206nger programmet kastar t\204rningar: ";
    cin>>element;
    system("cls");

    cout<<"Steg 1: 1 T\204rning"<<endl;
    steg1(element);
    cin.ignore();cin.ignore();
    system("cls");
    cout<<"Steg 2: 2 T\204rningar"<<endl;
    steg2(element);

    return 0;
}
