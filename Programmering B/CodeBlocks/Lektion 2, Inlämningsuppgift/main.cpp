#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void introduktion(int& fraga)
{
    cout<<"\n Projekt Myra"<<endl<<endl;
    cout<<" Mata in en 1 om du vill ser hur myran g\206r, eller en 0 f\224r att skipa detta: ";
    cin>>fraga;
    if (fraga==0)
        cout<<"\n Du valde att skipa hur myran g\206r.";
    if (fraga==1)
        cout<<"\n Du valde att ser hur myran g\206r.";
    cin.ignore(); cin.ignore();
    system("cls");
}

void skapa_faltet(int faltet[8][8])
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            faltet[i][j]=0;

    faltet[rand()%8][rand()%8]=2;
}

void skriv_ut_faltet(int faltet[8][8],int& steg,int& nySteg,int& antalSteg)
{
    if (nySteg==0)
        return;

    if (nySteg==1)
    {
        cin.ignore();
        system("cls");
    }

    nySteg=0;

    cout<<"  Projekt Myra";
    cout<<endl<<" ---------------"<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<" ";
        for(int j=0;j<8;j++)
        {
            cout<<faltet[i][j]<<" ";
            }
        cout<<endl<<" ---------------"<<endl;
        }
    cout<<"\n Antal steg myran tog: "<<steg<<endl;
    cout<<" Antal platser myran beh\224ver att bes\224ka till: "<<antalSteg<<"/64"<<endl;
    cout<<" 0 = Obes\224kt plats - 1 = Bes\224kt plats - 2 = Myrans position"<<endl;
    if (antalSteg>0)
        cout<<"\n Tryck Enter att g\206r vidare. ";
}

void myra_ror(int faltet[8][8],int& steg,int& nySteg,int& antalSteg)
{
    int myraRorCheck=0;
    steg+=1;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(faltet[i][j]==2)
            {
                while(myraRorCheck==0)
                {
                    int riktning=rand()%4;
                    if (riktning==0 && i>0)
                    {
                        if (faltet[i-1][j]==0)
                        {
                            nySteg=1;
                            antalSteg+=1;
                        }
                        faltet[i-1][j]=3;
                        myraRorCheck=1;
                    }
                    if (riktning==1 && j<7)
                    {
                        if (faltet[i][j+1]==0)
                        {
                            nySteg=1;
                            antalSteg+=1;
                        }
                        faltet[i][j+1]=3;
                        myraRorCheck=1;
                    }
                    if (riktning==2 && i<7)
                    {
                        if (faltet[i+1][j]==0)
                        {
                            nySteg=1;
                            antalSteg+=1;
                        }
                        faltet[i+1][j]=3;
                        myraRorCheck=1;
                    }
                    if (riktning==3 && j>0)
                    {
                        if (faltet[i][j-1]==0)
                        {
                            nySteg=1;
                            antalSteg+=1;
                        }
                        faltet[i][j-1]=3;
                        myraRorCheck=1;
                    }
                }
                faltet[i][j]=1;
            }

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if (faltet[i][j]==3)
                faltet[i][j]=2;
}

void fardig(int faltet[8][8],int& fardigCheck)
{
    fardigCheck=0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            if (faltet[i][j]>0)
                fardigCheck+=1;
        }
}

int main()
{
    srand(time(0));
    int faltet[8][8], steg=0, nySteg=-1, fardigCheck=0,antalSteg=1,fraga=0;

    introduktion(fraga);
    skapa_faltet(faltet);
    while(fardigCheck<64)
    {
        fardig(faltet,fardigCheck);
        if (fraga==1)
            skriv_ut_faltet(faltet,steg,nySteg,antalSteg);
        myra_ror(faltet,steg,nySteg,antalSteg);
    }
    if (fraga==0)
        cout<<"\n Antal steg myran tog: "<<steg<<endl;
    cout<<"\n Myran har hoppad p\206 alla steg. Programet \204r slut.\n Trycka p\206 Enter f\224r att avsluta programmet."<<endl;
    return 0;
}
