//inkludera allt som beh�vs
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Huvudmenys funktion var man b�rjar
void huvudMeny()
{
    //Skriver ut n�gra introduktions meningar
    cout<<"======================================"<<endl;
    cout<<"     V\204lkommen till: Gissa ordet!"<<endl;
    cout<<"======================================"<<endl<<endl;
    cout<<"Klicka p\206 Enter f\224r att b\224rja"<<endl;

    //Beh�vs att klicka p� Enter, sk�rmet blir tomt igen
    cin.ignore();
    system("cls");
}

//Funktionen var man v�ljer svarigheten
void svarighet(int& chanser)
{
    //En loop s� l�nge chanser = 1< eller >6
    while(chanser<1 || chanser>6)
    {
        cout<<"Hur sv\206rt ska spelet vara?"<<endl<<endl;
        cout<<"1. Extremt: 5 chanser"<<endl;
        cout<<"2. Sv\206r: 10 chanser"<<endl;
        cout<<"3. Normalt: 15 chanser"<<endl;
        cout<<"4. L\204tt: 20 chanser"<<endl;
        cout<<"5. V\204lj sj\204lv dina chanser"<<endl;
        cout<<"6. O\204ndlig Chanser"<<endl<<endl;
        cout<<"Ange ditt val: ";

        //Mottager chanser, beh�vs att klicka p� Enter, b�rjar en ny textr�d.
        cin>>chanser;
        cin.ignore();
        cout<<endl;

        //Om chanser = >0 & 5<
        if (chanser>0 && chanser<5)
        {
            //Chanser = chanser * 5, sk�rmet blir tomt, returnera till main funktionen
            chanser=chanser*5;
            system("cls");
            return;
        }

        //Om chanser = 5
        if (chanser==5)
        {
            //Chanser = 0, sk�rmet blir tomt, returnera till main funktionen
            chanser=0;
            system("cls");
            return;
        }

        //Om chanser = 6
        if (chanser==6)
        {
            //Chanser = -1, sk�rmet blir tomt, returnera till main funktionen
            chanser=-1;
            system("cls");
            return;
        }

        //Skrivs ut en text att valet �r fel, h�nder bara om chanser = 0< & >6
        cout<<chanser<<" \204r inget val. Val igen"<<endl;

        //Beh�vs att klicka p� Enter, sk�rmet blir tomt, loopen b�rjar om
        cin.ignore();
        system("cls");
    }
}

//Funktionen var man v�ljer antal chanser om man valde Chanser = 0 i f�ra funktionen
void svarighetVal(int& chanser)
{
    //En loop s� l�nge chanser = 1< eller >50
    while(chanser<1 || chanser>50)
    {
        //Skriver ut n�gra meningar
        cout<<"Hur sv\206rt ska spelet vara?"<<endl<<endl;
        cout<<"1. Extremt: 5 chanser"<<endl;
        cout<<"2. Sv\206r: 10 chanser"<<endl;
        cout<<"3. Normalt: 15 chanser"<<endl;
        cout<<"4. L\204tt: 20 chanser"<<endl;
        cout<<"5. V\204lj sj\204lv dina chanser"<<endl;
        cout<<"6. O\204ndlig Chanser"<<endl<<endl;
        cout<<"Ange ditt val: 5"<<endl<<endl<<endl<<endl;
        cout<<"Hur m\206nga chanser vill du har?"<<endl;
        cout<<"Min. 1 chans - Max. 50 chanser"<<endl<<endl;
        cout<<"Mata in bara siffror eller spelet crashar!"<<endl<<endl;
        cout<<"Ange dit val: ";

        //Mottager chanser, beh�vs att klicka p� Enter, b�rjar en ny textr�d
        cin>>chanser;
        cin.ignore();
        cout<<endl;

        //Om chanser = >0 & 51< d� blir sk�rmet tomt returnera till main funktionen
        if (chanser>0 && chanser<51)
        {
            //sk�rmet blir tomt, returnera till main funktionen
            system("cls");
            return;
        }

        //Skrivs ut en text att valet �r fel, h�nder bara om chanser = 0< & >50
        cout<<"Du f\206r inte v\204lja att du ska har "<<chanser<<" chanser. Val igen"<<endl;

        //Beh�vs att klicka p� Enter, sk�rmet blir tomt, loopen b�rjar om
        cin.ignore();
        system("cls");
    }
}

//Funktionen var man v�ljer vem hitta p� ordet
void skapaOrd(int& ordVal)
{
    //En loop s� l�nge ordVal = inte 1 eller inte 2
    while(ordVal!=1 || ordVal!=2)
    {
        //Skrivs ut n�gra meningar
        cout<<"Ska datorn hittar p\206 ett ord eller g\224r du det sj\204lv?"<<endl<<endl;
        cout<<"1. Datorn hittar p\206 ordet"<<endl;
        cout<<"2. Du skappa ordet"<<endl<<endl;
        cout<<"Ange dit val: ";

        //Mottager ordVal, beh�vs att klicka p� Enter, b�rjar en ny textr�d
        cin>>ordVal;
        cin.ignore();
        cout<<endl;

        //Om ordVal = 1 eller 2
        if (ordVal==1 || ordVal==2)
        {
            //sk�rmet blir tomt, returnera till main funktionen
            system("cls");
            return;
        }

        //Skrivs ut en text att valet �r fel, h�nder bara om ordVal = inte 1 eller inte 2
        cout<<ordVal<<" \204r inget val. Val igen"<<endl;

        //Beh�vs att klicka p� Enter, sk�rmet blir tomt, loopen b�rjar om
        cin.ignore();
        system("cls");
    }
}

//Funktionen var datorn hitta p� ordet
void skapaOrdDatorn(vector<string>& o, vector<string>& oRatt)
{
    //Kreara variabel slump, datorn v�lja en slumptal
    int slump;
    srand(time(0));
    slump=rand()%5+1;

    //L�ggas till en ord i vektor o baserade p� slump
    if (slump==1)
    { o.push_back("t"); o.push_back("e"); o.push_back("n"); o.push_back("n"); o.push_back("i"); o.push_back("s"); }

    if (slump==2)
    { o.push_back("s"); o.push_back("l"); o.push_back("u"); o.push_back("m"); o.push_back("p"); o.push_back("t"); o.push_back("a"); o.push_back("l"); }

    if (slump==3)
    { o.push_back("a"); o.push_back("p"); o.push_back("p"); o.push_back("e"); o.push_back("l"); o.push_back("s"); o.push_back("i"); o.push_back("n"); }

    if (slump==4)
    { o.push_back("l"); o.push_back("e"); o.push_back("j"); o.push_back("o"); o.push_back("n"); }

    if (slump==5)
    { o.push_back("s"); o.push_back("k"); o.push_back("o"); o.push_back("l"); o.push_back("b"); o.push_back("\204"); o.push_back("n"); o.push_back("k"); }

    //L�ggas till en kopia av vektor o som vektor oRatt
    for (int i=0; i<o.size(); i++)
        oRatt.push_back(".");
}

//Funktionen var man skapa sj�lv ordet
void skapaOrdSjalv(vector<string>& o, vector<string>& oRatt, int& bokstavVal)
{
    //Kreara string b = bokstav, bokstavVal = 0
    string b;
    bokstavVal=0;

    //En loop s� l�nge ordVal = 1< eller >2
    while (bokstavVal<1 || bokstavVal>12)
    {
        //Skrivs ut n�gra meningar
        cout<<"Du f\206r max. anv\204nda 12 bokstaver, mata bara in siffror! "<<endl;
        cout<<"Mata in bara siffror eller spelet crashar!"<<endl<<endl;
        cout<<"Ange antal bokstaver f\224r ordet: ";

        //Motager bokstavVal
        cin>>bokstavVal;

        //Om bokstavVal < 0
        if (bokstavVal<1)
        {
            //Skivs ut n�gra meningar att valet �r fel
            cout<<endl;
            cout<<bokstavVal<<" \204r f\224r litet! Val igen"<<endl;
            cout<<"\Min. 1 bokstav och max. 12 bokstaver";

            //Beh�vs att klicka p� Enter, sk�rmet blir tomt, loopen b�rjar om
            cin.ignore();
            cin.ignore();
            system("cls");
        }

        //Om bokstavVal > 12
        if (bokstavVal>12)
        {
            //Skivs ut n�gra meningar att valet �r fel
            cout<<endl;
            cout<<bokstavVal<<" \204r f\224r stort! Val igen"<<endl;
            cout<<"\Min. 1 bokstav och max. 12 bokstaver";

            //Beh�vs att klicka p� Enter, sk�rmet blir tomt, loopen b�rjar om
            cin.ignore();
            cin.ignore();
            system("cls");
        }
    }
    //Beh�vs att klicka p� Enter, b�rjar en ny textr�d
    cin.ignore();
    cout<<endl;

    //Vektorna o och oRatt blir tomt
    o.clear();
    oRatt.clear();

    //En for loop som slutat n�r hele vektor o (ordet) �r f�rdigt
    for (int i=0; i<bokstavVal; i++)
    {
        //sk�rmet blir tomt
        system("cls");

        //Skrivs ut n�gra meningar
        cout<<"Du f\206r max. anv\204nda 12 bokstaver, mata bara in siffror! "<<endl;
        cout<<"Mata in bara siffror eller spelet crashar!"<<endl<<endl;
        cout<<"Ange antal bokstaver f\224r ordet: "<<bokstavVal<<endl<<endl;
        cout<<"Ordet s\206 framme: ";

        //En for loop i en for loop f�r att skriva ut ett ord
        for (int j=0; j<o.size(); j++)
        {
            //Om den f�rsta liten bokstaven skrivs ut d� skrivs den ut som en stor bokstav
            if (j==0)
            {
                if (o.at(j)=="a") cout<<"A"; if (o.at(j)=="b") cout<<"B"; if (o.at(j)=="c") cout<<"C"; if (o.at(j)=="d") cout<<"D"; if (o.at(j)=="e") cout<<"E";
                if (o.at(j)=="f") cout<<"F"; if (o.at(j)=="g") cout<<"G"; if (o.at(j)=="h") cout<<"H"; if (o.at(j)=="i") cout<<"I"; if (o.at(j)=="j") cout<<"J";
                if (o.at(j)=="k") cout<<"K"; if (o.at(j)=="l") cout<<"L"; if (o.at(j)=="m") cout<<"M"; if (o.at(j)=="n") cout<<"N"; if (o.at(j)=="o") cout<<"O";
                if (o.at(j)=="p") cout<<"P"; if (o.at(j)=="q") cout<<"Q"; if (o.at(j)=="r") cout<<"R"; if (o.at(j)=="s") cout<<"S"; if (o.at(j)=="t") cout<<"T";
                if (o.at(j)=="u") cout<<"U"; if (o.at(j)=="v") cout<<"V"; if (o.at(j)=="w") cout<<"W"; if (o.at(j)=="x") cout<<"X"; if (o.at(j)=="y") cout<<"Y";
                if (o.at(j)=="z") cout<<"Z"; if (o.at(j)=="\206") cout<<"\217"; if (o.at(j)=="\204") cout<<"\216"; if (o.at(j)=="\224") cout<<"\231";
            }
            //Om inte den f�rsta liten bokstaven skrivs ut d� skrivs den ut som vanlig
            if (j>0)
                cout<<o.at(j);
        }
        //B�rjar en ny textr�d
        cout<<endl<<endl;

        //Skrivs ut en mening
        cout<<"Ange bokstav "<<i+1<<" f\224r ordet: ";

        //Motager b
        getline(cin,b);

        //B�rjar en ny textr�d, l�ggas till b i vektor o
        cout<<endl;
        o.push_back(b);
    }

    //L�ggas till en kopia av vektor o som vektor oRatt
    for (int i=0; i<o.size(); i++) oRatt.push_back(".");

    //Sk�rmet blir tomt
    system("cls");
}

//Funktionen var ska kontrolleras om ordet som man mattade in �r r�tt
void skapaOrdSjalvKontroll(vector<string>& o, int& error, int& bokstavVal)
{
    //error = 0
    error=0;


    //En for loop som ska l�ssas hele vektor o (ordet)
    for (int i=0; i<o.size(); i++)
    {
        //Kontrolleras om o (ordet) anv�nder inte liten bokstaver - om ja: error = 1
        if (o.at(i)!="a" && o.at(i)!="b" && o.at(i)!="c" && o.at(i)!="d" && o.at(i)!="e" && o.at(i)!="f" && o.at(i)!="g" && o.at(i)!="h" && o.at(i)!="i" && o.at(i)!="j" && o.at(i)!="k" && o.at(i)!="l" && o.at(i)!="m" && o.at(i)!="n" && o.at(i)!="o" && o.at(i)!="p"  && o.at(i)!="q" && o.at(i)!="r" && o.at(i)!="s" && o.at(i)!="t" && o.at(i)!="u" && o.at(i)!="v" && o.at(i)!="w" && o.at(i)!="x" && o.at(i)!="y" && o.at(i)!="z" && o.at(i)!="\206" && o.at(i)!="\204" && o.at(i)!="\224")
            error=1;
    }

    //Om error = 1
    if (error==1)
    {
        //Skrivs ut n�gra meningar
        cout<<"Du skrev en eller flera icke-bokstaver eller du skrev ett \204r stort ord!"<<endl<<endl;
        cout<<"Det kan ocks\206 vara att du matade in stora bokstaver"<<endl;
        cout<<"Anv\204nd bara liten bokstaver!"<<endl<<endl;
        cout<<"VIKTIGT: Du f\206r bara mata in 1 bokstav varje g\206ng!"<<endl<<endl;
        cout<<"F\224rs\224k igen att hitta p\206 ett ord!"<<endl;

        //Beh�vs att klicka p� Enter, sk�rmet blir tomt
        cin.ignore();
        system("cls");
    }
}

//Funktionen var man mata in bokstaver f�r att gissa ordet
void mataIn(string& input, vector<string>& o, vector<string>& oRatt, vector<string>& bFel, int& chanser, int& cheat)
{
    //Input = string "aa"
    input="aa";

    //En loop s� l�nge input = inte en liten bokstav eller inte 0 eller man matade in >1 bokstaver
    while (input.size()!=1 || input!="0" && input!="a" && input!="b" && input!="c" && input!="d" && input!="e" && input!="f" && input!="g" && input!="h" && input!="i" && input!="j" && input!="k" && input!="l" && input!="m" && input!="n" && input!="o" && input!="p" && input!="q" && input!="r" && input!="s" && input!="t" && input!="u" && input!="v" && input!="w" && input!="x" && input!="y" && input!="z" && input!="\206" && input!="\204" && input!="\224")
    {
        //Skrivs ut en mening
        cout<<"Jag t\204nker p\206 ett ord: vet du vilket? "<<endl;

        //En for loop i en for loop f�r att skriva ut vilka bokstaver man hade gissat r�tt
        for (int i=0; i<oRatt.size(); i++)
        {
            //Om den f�rsta liten bokstaven skrivs ut d� skrivs den ut som en stor bokstav, punkten skrivs ut som vanlig
            if (i==0)
            {
                if (oRatt.at(i)=="a") cout<<"A"; if (oRatt.at(i)=="b") cout<<"B"; if (oRatt.at(i)=="c") cout<<"C"; if (oRatt.at(i)=="d") cout<<"D"; if (oRatt.at(i)=="e") cout<<"E";
                if (oRatt.at(i)=="f") cout<<"F"; if (oRatt.at(i)=="g") cout<<"G"; if (oRatt.at(i)=="h") cout<<"H"; if (oRatt.at(i)=="i") cout<<"I"; if (oRatt.at(i)=="j") cout<<"J";
                if (oRatt.at(i)=="k") cout<<"K"; if (oRatt.at(i)=="l") cout<<"L"; if (oRatt.at(i)=="m") cout<<"M"; if (oRatt.at(i)=="n") cout<<"N"; if (oRatt.at(i)=="o") cout<<"O";
                if (oRatt.at(i)=="p") cout<<"P"; if (oRatt.at(i)=="q") cout<<"Q"; if (oRatt.at(i)=="r") cout<<"R"; if (oRatt.at(i)=="s") cout<<"S"; if (oRatt.at(i)=="t") cout<<"T";
                if (oRatt.at(i)=="u") cout<<"U"; if (oRatt.at(i)=="v") cout<<"V"; if (oRatt.at(i)=="w") cout<<"W"; if (oRatt.at(i)=="x") cout<<"X"; if (oRatt.at(i)=="y") cout<<"Y";
                if (oRatt.at(i)=="z") cout<<"Z"; if (oRatt.at(i)=="\206") cout<<"\217"; if (oRatt.at(i)=="\204") cout<<"\216"; if (oRatt.at(i)=="\224") cout<<"\231"; if (oRatt.at(i)==".") cout<<".";
            }
            //Om inte den f�rsta liten bokstaven eller punkten skrivs ut d� skrivs den ut som vanlig
            if (i>0)
                cout<<oRatt.at(i);
        }
        //B�rjar en ny r�d
        cout<<endl<<endl;

        //Skrivs ut en meningar som vissar vilka bokstaver �r fel gissade, b�rjar en ny r�d
        cout<<"Felgissade Bokstaver: ";
        for (int i=0; i<bFel.size(); i++)
            cout<<bFel.at(i)<<" ";
        cout<<endl<<endl;

        //Om chanser = -1 d� skrivs ut att man har o�ndlig chanser, b�rjar en ny r�d
        if (chanser==-1)
            cout<<"Antal Chanser Kvar: O\204ndlig"<<endl<<endl<<endl<<endl;
        //Om chanser >0 & 11< d� skrivs antal chanser ut i teknet !, b�rjar en ny r�d
        if (chanser>0 && chanser<11)
        {
            cout<<"Antal Chanser Kvar: ";
            for (int i=0; i<chanser; i++)
            cout<<"!"; cout<<endl<<endl<<endl<<endl;
        }
        //Om chanser >10 d� skrivs antal chanser ut i siffror, b�rjar en ny r�d
        if (chanser>10)
            cout<<"Antal Chanser Kvar: "<<chanser<<endl<<endl<<endl<<endl;

        //Skrivs ut n�gra meningar
        cout<<"Mata in en 0 f\224r att avsluta spelet! "<<endl;
        cout<<"Mata in en 1 f\224r att fuskar! "<<endl<<endl;
        cout<<"Mata in ett bokstav / tal: ";
        //Motager input som en string, b�rjar en ny r�d
        getline(cin,input);
        cout<<endl;

        //Om input = 0 d� returna till main funktionen och avsluta spelet
        if (input=="0")
            return;

        //Om input = 1 d� aktiveras fuskarmodus
        if (input=="1")
        {
            //Programmet ska komma ih�g att du fuskade
            cheat=1;

            //B�rjar en ny r�d, skrivs ut n�gra meningar
            cout<<endl<<endl;
            cout<<"Fuskarmodus aktiverad"<<endl<<endl;
            cout<<"Det r\204tta ordet \204r: ";

            //En for loop som ska skriv ut vektor o
            for (int i=0; i<o.size(); i++)
            {
                //Om den f�rsta liten bokstaven skrivs ut d� skrivs den ut som en stor bokstav
                if (i==0)
                {
                    if (o.at(i)=="a") cout<<"A"; if (o.at(i)=="b") cout<<"B"; if (o.at(i)=="c") cout<<"C"; if (o.at(i)=="d") cout<<"D"; if (o.at(i)=="e") cout<<"E";
                    if (o.at(i)=="f") cout<<"F"; if (o.at(i)=="g") cout<<"G"; if (o.at(i)=="h") cout<<"H"; if (o.at(i)=="i") cout<<"I"; if (o.at(i)=="j") cout<<"J";
                    if (o.at(i)=="k") cout<<"K"; if (o.at(i)=="l") cout<<"L"; if (o.at(i)=="m") cout<<"M"; if (o.at(i)=="n") cout<<"N"; if (o.at(i)=="o") cout<<"O";
                    if (o.at(i)=="p") cout<<"P"; if (o.at(i)=="q") cout<<"Q"; if (o.at(i)=="r") cout<<"R"; if (o.at(i)=="s") cout<<"S"; if (o.at(i)=="t") cout<<"T";
                    if (o.at(i)=="u") cout<<"U"; if (o.at(i)=="v") cout<<"V"; if (o.at(i)=="w") cout<<"W"; if (o.at(i)=="x") cout<<"X"; if (o.at(i)=="y") cout<<"Y";
                    if (o.at(i)=="z") cout<<"Z"; if (o.at(i)=="\206") cout<<"\217"; if (o.at(i)=="\204") cout<<"\216"; if (o.at(i)=="\224") cout<<"\231";
                }
                //Om inte den f�rsta liten bokstaven skrivs ut d� skrivs den ut som vanlig
                if (i>0)
                    cout<<o.at(i);
            }
            //Beh�vs att klicka p� Enter
            cin.ignore();
        }

        //Om man inte matade in input med 1 bokstav
        if (input.size()==0)
        {
            cout<<"\aDu m\206ste mata in ett bokstav!";
            cin.ignore();
        }

        //Om man inte matade in input med >1 bokstav
        if (input.size()>1)
        {
            cout<<"\aDu f\206r bara skriva 1 bokstav!";
            cin.ignore();
        }

        //Om input = inte en liten bokstav eller inte 0 eller man matade in >1 bokstaver
        if (input.size()==1 && input!="0" && input!="1" && input!="a" && input!="b" && input!="c" && input!="d" && input!="e" && input!="f" && input!="g" && input!="h" && input!="i" && input!="j" && input!="k" && input!="l" && input!="m" && input!="n" && input!="o" && input!="p" && input!="q" && input!="r" && input!="s" && input!="t" && input!="u" && input!="v" && input!="w" && input!="x" && input!="y" && input!="z" && input!="\206" && input!="\204" && input!="\224")
        {
            //Skrivs ut en mening att man gjorde fel, beh�vs att klicka p� Enter
            cout<<"\aDu f\206r bara mata in sm\206a bokstaver och talen 0 och 1!";
            cin.ignore();
        }
        //Sk�rmet blir tomt
        system("cls");
    }
}

//Funktionen som ska kontrolleras om den inmatade f�r �rdet st�mmer
void kontroll(string& input, vector<string>& o, vector<string>& oRatt, vector<string>& bFel, vector<string>& iM, int& chanser)
{
    //Skrivs ut alle meningar som skrevs ut tidigare i f�re funktionen
    cout<<"Jag t\204nker p\206 ett ord: vet du vilket?"<<endl;

    for (int i=0; i<oRatt.size(); i++)
    {
        if (i==0)
        {
            if (oRatt.at(i)=="a") cout<<"A"; if (oRatt.at(i)=="b") cout<<"B"; if (oRatt.at(i)=="c") cout<<"C"; if (oRatt.at(i)=="d") cout<<"D"; if (oRatt.at(i)=="e") cout<<"E";
            if (oRatt.at(i)=="f") cout<<"F"; if (oRatt.at(i)=="g") cout<<"G"; if (oRatt.at(i)=="h") cout<<"H"; if (oRatt.at(i)=="i") cout<<"I"; if (oRatt.at(i)=="j") cout<<"J";
            if (oRatt.at(i)=="k") cout<<"K"; if (oRatt.at(i)=="l") cout<<"L"; if (oRatt.at(i)=="m") cout<<"M"; if (oRatt.at(i)=="n") cout<<"N"; if (oRatt.at(i)=="o") cout<<"O";
            if (oRatt.at(i)=="p") cout<<"P"; if (oRatt.at(i)=="q") cout<<"Q"; if (oRatt.at(i)=="r") cout<<"R"; if (oRatt.at(i)=="s") cout<<"S"; if (oRatt.at(i)=="t") cout<<"T";
            if (oRatt.at(i)=="u") cout<<"U"; if (oRatt.at(i)=="v") cout<<"V"; if (oRatt.at(i)=="w") cout<<"W"; if (oRatt.at(i)=="x") cout<<"X"; if (oRatt.at(i)=="y") cout<<"Y";
            if (oRatt.at(i)=="z") cout<<"Z"; if (oRatt.at(i)=="\206") cout<<"\217"; if (oRatt.at(i)=="\204") cout<<"\216"; if (oRatt.at(i)=="\224") cout<<"\231"; if (oRatt.at(i)==".") cout<<".";
        }
        if (i>0)
            cout<<oRatt.at(i);
    }
    cout<<endl<<endl;

    cout<<"Felgissade Bokstaver: ";
    for (int i=0; i<bFel.size(); i++)
        cout<<bFel.at(i)<<" ";
    cout<<endl<<endl;

    if (chanser==-1)
        cout<<"Antal Chanser Kvar: O\204ndlig"<<endl<<endl<<endl<<endl;
    if (chanser>0 && chanser<11)
    {
        cout<<"Antal Chanser Kvar: ";
        for (int i=0; i<chanser; i++)
        cout<<"!"; cout<<endl<<endl<<endl<<endl;
    }
    if (chanser>10)
        cout<<"Antal Chanser Kvar: "<<chanser<<endl<<endl<<endl<<endl;

    cout<<"Mata in en 0 f\224r att avsluta spelet! "<<endl;
    cout<<"Mata in en 1 f\224r att fuskar! "<<endl<<endl;
    cout<<"Mata in ett bokstav / tal: "<<input<<endl<<endl;

    //Ska kontrolleras om din bokstav har redan anv�ndad, som blir sparas p� vektor iM (inMattad)
    for (int i=0; i<iM.size(); i++)
    {
        if (iM.at(i)=="a" || iM.at(i)=="b" || iM.at(i)=="c" || iM.at(i)=="d" || iM.at(i)=="e" || iM.at(i)=="f" || iM.at(i)=="g" || iM.at(i)=="h" || iM.at(i)=="i" || iM.at(i)=="j" || iM.at(i)=="k" || iM.at(i)=="l" || iM.at(i)=="m" || iM.at(i)=="n" || iM.at(i)=="o" || iM.at(i)=="p" || iM.at(i)=="q" || iM.at(i)=="r" || iM.at(i)=="s" || iM.at(i)=="t" || iM.at(i)=="u" || iM.at(i)=="v" || iM.at(i)=="w" || iM.at(i)=="x" || iM.at(i)=="y" || iM.at(i)=="z" || iM.at(i)=="\206" || iM.at(i)=="204" || iM.at(i)=="\224")
        {
            //Om din bokstav har redan anv�ndad
            if (input==iM.at(i))
            {
                //Skrivs ut en mening
                cout<<"\aDu har redan anv\204ndad denna bokstav!";

                //Beh�vs att klicka p� Enter, sk�rmet blir tomt, returnera till main funktionen
                cin.ignore();
                system("cls");
                return;
            }
        }
    }
    //L�ggas till input till vektor iM
    iM.push_back(input);

    //Kreara variabel tur = 0
    int tur=0;

    //En for loop som ska l�sa hele vektor o (ordet) f�r kontrollera om inmatade bokstaven st�mmer
    for (int i=0; i<o.size(); i++)
    {
        if (o.at(i)==input)
        {
            //Tur + = 1, den bokstaven av vektor oRatt som programmet �r p� = input
            tur+=1;
            oRatt.at(i)=input;
        }
    }

    //Om tur = 0
    if (tur==0)
    {
        //Skrivs ut en mening, ta bort 1 chans (om du inte har o�ndlig chanser), l�ggas till input till vektor bFel (bokstavFel)
        cout<<"\aDu har otur";
        if (chanser!=-1) chanser-=1;
        bFel.push_back(input);
    }
    //Om tur = 1 eller tur = >1 d� skrivs ut en mening att du gisade r�tt
    if (tur==1)
        cout<<"\aDu har tur, din bokstav har varrit gissat bra: 1 g\206ng";
    if (tur>1)
        cout<<"\aDu har tur, din bokstav har varrit gissat bra: "<<tur<<" g\206nger";

    //Beh�vs att klicka p� Enter, sk�rmet blir tomt
    cin.ignore();
    system("cls");
}

//Funktionen som ska kontrolleras om du vinner
void winKontroll(int& slutSpel, vector<string>& o, vector<string>& oRatt, int& cheat)
{
    //En for loop som ska l�sa hele vektor o (ordet) f�r att j�mf�ra om den �r likamed vektor oRatt (ordRatt) - Om nej returnera den till main funktionen
    for (int i=0; i<o.size(); i++)
    {
        if (oRatt.at(i)!=o.at(i))
            return;
    }

    //Sk�rmet blir tomt
    system("cls");

    //Slutspel = 1
    slutSpel=1;

    //Skivs ut att du vann
    cout<<"\a================"<<endl;
    cout<<"   Grattis!!!"<<endl;
    cout<<"================"<<endl<<endl;
    cout<<"Du gissade alla bokstaver ratt!"<<endl<<endl;
    cout<<"Ordet som du gissade r\204tt: ";

    //Skrivs ut det r�tta ordet
    for (int i=0; i<o.size(); i++)
    {
        //Om den f�rsta liten bokstaven skrivs ut d� skrivs den ut som en stor bokstav
        if (i==0)
            {
            if (o.at(i)=="a") cout<<"A"; if (o.at(i)=="b") cout<<"B"; if (o.at(i)=="c") cout<<"C"; if (o.at(i)=="d") cout<<"D"; if (o.at(i)=="e") cout<<"E";
            if (o.at(i)=="f") cout<<"F"; if (o.at(i)=="g") cout<<"G"; if (o.at(i)=="h") cout<<"H"; if (o.at(i)=="i") cout<<"I"; if (o.at(i)=="j") cout<<"J";
            if (o.at(i)=="k") cout<<"K"; if (o.at(i)=="l") cout<<"L"; if (o.at(i)=="m") cout<<"M"; if (o.at(i)=="n") cout<<"N"; if (o.at(i)=="o") cout<<"O";
            if (o.at(i)=="p") cout<<"P"; if (o.at(i)=="q") cout<<"Q"; if (o.at(i)=="r") cout<<"R"; if (o.at(i)=="s") cout<<"S"; if (o.at(i)=="t") cout<<"T";
            if (o.at(i)=="u") cout<<"U"; if (o.at(i)=="v") cout<<"V"; if (o.at(i)=="w") cout<<"W"; if (o.at(i)=="x") cout<<"X"; if (o.at(i)=="y") cout<<"Y";
            if (o.at(i)=="z") cout<<"Z"; if (o.at(i)=="\206") cout<<"\217"; if (o.at(i)=="\204") cout<<"\216"; if (o.at(i)=="\224") cout<<"\231";
        }
        //Om inte den f�rsta liten bokstaven skrivs ut d� skrivs den ut som vanlig
        if (i>0)
            cout<<o.at(i);
        }

    //Om du inte fusakde skrivs ut att man vann riktig
    if (cheat==0)
    {
        cout<<endl<<endl;
        cout<<"Du \204r en riktig vinnare!!!";
    }

    //Om du fuskade skrivs ut att man vann inte riktig
    if (cheat==1)
    {
        cout<<endl<<endl;
        cout<<"Tyv\204rr att du bara fuskade, s\206 du \204r inte en riktig vinare!!!";
    }

    //Beh�vs att klicka p� Enter
    cin.ignore();
}

//Funktionen som ska l�ta man veta att de f�rl�rade
void forlorat(vector<string>& o)
{
    //Sk�rmet blir vit
    system("cls");

    //Skrivs ut n�gra meningar ut att man f�rl�rade
    cout<<"\a==============="<<endl;
    cout<<"   Tyv\204rr!!!"<<endl;
    cout<<"==============="<<endl<<endl;
    cout<<"Du har inga chanser kvar!"<<endl<<endl;
    cout<<"Det r\204tta ordet var: ";

    //Skrivs ut det r�tta ordet
    for (int i=0; i<o.size(); i++)
    {
        //Om den f�rsta liten bokstaven skrivs ut d� skrivs den ut som en stor bokstav
        if (i==0)
        {
            if (o.at(i)=="a") cout<<"A"; if (o.at(i)=="b") cout<<"B"; if (o.at(i)=="c") cout<<"C"; if (o.at(i)=="d") cout<<"D"; if (o.at(i)=="e") cout<<"E";
            if (o.at(i)=="f") cout<<"F"; if (o.at(i)=="g") cout<<"G"; if (o.at(i)=="h") cout<<"H"; if (o.at(i)=="i") cout<<"I"; if (o.at(i)=="j") cout<<"J";
            if (o.at(i)=="k") cout<<"K"; if (o.at(i)=="l") cout<<"L"; if (o.at(i)=="m") cout<<"M"; if (o.at(i)=="n") cout<<"N"; if (o.at(i)=="o") cout<<"O";
            if (o.at(i)=="p") cout<<"P"; if (o.at(i)=="q") cout<<"Q"; if (o.at(i)=="r") cout<<"R"; if (o.at(i)=="s") cout<<"S"; if (o.at(i)=="t") cout<<"T";
            if (o.at(i)=="u") cout<<"U"; if (o.at(i)=="v") cout<<"V"; if (o.at(i)=="w") cout<<"W"; if (o.at(i)=="x") cout<<"X"; if (o.at(i)=="y") cout<<"Y";
            if (o.at(i)=="z") cout<<"Z"; if (o.at(i)=="\206") cout<<"\217"; if (o.at(i)=="\204") cout<<"\216"; if (o.at(i)=="\224") cout<<"\231";
        }
        //Om inte den f�rsta liten bokstaven skrivs ut d� skrivs den ut som vanlig
        if (i>0)
            cout<<o.at(i);
    }

    //Beh�vs att klicka p� Enter
    cin.ignore();
}

//Funktionen som ska l�ta man veta att de slutade
void avsluta(vector<string>& o)
{
    //Sk�rmet blir vit
    system("cls");

    //Skrivs ut n�gra meningar ut att man slutade
    cout<<"\a========================="<<endl;
    cout<<"   Spelet slutar nu!!!"<<endl;
    cout<<"========================="<<endl<<endl;
    cout<<"Tyv\204rr att du sluta f\224re spelet var f\204rdigt"<<endl<<endl;
    cout<<"Ordet den g\206ng var: ";

    //Skrivs ut det r�tta ordet
    for (int i=0; i<o.size(); i++)
    {
        //Om den f�rsta liten bokstaven skrivs ut d� skrivs den ut som en stor bokstav
        if (i==0)
        {
            if (o.at(i)=="a") cout<<"A"; if (o.at(i)=="b") cout<<"B"; if (o.at(i)=="c") cout<<"C"; if (o.at(i)=="d") cout<<"D"; if (o.at(i)=="e") cout<<"E";
            if (o.at(i)=="f") cout<<"F"; if (o.at(i)=="g") cout<<"G"; if (o.at(i)=="h") cout<<"H"; if (o.at(i)=="i") cout<<"I"; if (o.at(i)=="j") cout<<"J";
            if (o.at(i)=="k") cout<<"K"; if (o.at(i)=="l") cout<<"L"; if (o.at(i)=="m") cout<<"M"; if (o.at(i)=="n") cout<<"N"; if (o.at(i)=="o") cout<<"O";
            if (o.at(i)=="p") cout<<"P"; if (o.at(i)=="q") cout<<"Q"; if (o.at(i)=="r") cout<<"R"; if (o.at(i)=="s") cout<<"S"; if (o.at(i)=="t") cout<<"T";
            if (o.at(i)=="u") cout<<"U"; if (o.at(i)=="v") cout<<"V"; if (o.at(i)=="w") cout<<"W"; if (o.at(i)=="x") cout<<"X"; if (o.at(i)=="y") cout<<"Y";
            if (o.at(i)=="z") cout<<"Z"; if (o.at(i)=="\206") cout<<"\217"; if (o.at(i)=="\204") cout<<"\216"; if (o.at(i)=="\224") cout<<"\231";
        }
        //Om inte den f�rsta liten bokstaven skrivs ut d� skrivs den ut som vanlig
        if (i>0)
            cout<<o.at(i);
        }

    //Beh�vs att klicka p� Enter
    cin.ignore();
}

//Main funktionen som startar alla andra funktionen
int main()
{
    //Kreara vanliga variabler
    int chanser, ordVal, slutSpel=0, error=0, bokstavVal, cheat=0;
    //Kreara string variabel input
    string input;
    //Kreara vektor variabler, o = ordet, oRatt = ordetRatt, bFel = bokstaverFel och iM = inMattad
    vector<string> o; vector<string> oRatt; vector<string> bFel; vector<string> iM;

    //Anr�par funktionerna huvudMeny, sen svarighet och svarighetVal om chanser = 0 (fr�n svarighet)
    huvudMeny();
    svarighet(chanser);
    if (chanser==0) svarighetVal(chanser);

    //Anr�par funktionerna skapaOrd, sen skapaOrdDatorn (om ordVal = 1) eller skapaOrdSjalv och skapaOrdSjalvKontroll (om ordVal = 2)
    skapaOrd(ordVal);
    if (ordVal==1) skapaOrdDatorn(o, oRatt);
    if (ordVal==2)
    {
        skapaOrdSjalv(o, oRatt, bokstavVal);
        skapaOrdSjalvKontroll(o, error, bokstavVal);
    }
    //S� l�nge error = 0 (fr�n SkapaOrdSjalvKontroll funktionen) d� anr�pas funktionerna skapaOrdSjalv och skapaOrdSjalvKontroll
    while (error>0)
    {
        skapaOrdSjalv(o, oRatt, bokstavVal);
        skapaOrdSjalvKontroll(o, error, bokstavVal);
    }

    //S� l�nge man inte matade in 0 (i mataIn funktionen), har chanser kvar och inte gissade hele ordet d� anr�pas f�ljande funktionerna
    while (slutSpel==0)
    {
        //Anr�par funktion mataIn f�r att gissa en ny bokstav, om input = 0 d� anr�pas funktioen avsluta och avsluta spelet
        mataIn(input, o, oRatt, bFel, chanser, cheat);
        if (input=="0")
        {
            avsluta(o);
            return 0;
        }
        //Anr�par funktionerna kontroll och winKontroll f�r att kontrollera om inmattade bokstaven �r r�tt eller om man gissade r�tt hele ordet
        kontroll(input, o, oRatt, bFel, iM, chanser);
        winKontroll(slutSpel, o, oRatt, cheat);
        //Anr�par funktion f�rlorat f�r om man har inga chanser kvar, sen avsluta spelet
        if (chanser==0)
        {
            forlorat(o);
            return 0;
        }
    }
    //Avsluta spelet om slutspel inte = 1 (d� har man vunnit)
    return 0;
}
