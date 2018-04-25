#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std; //L�ggs till allt som beh�vs att kunna k�ra programmet



void HUVUDMENY() //Huvudmeny funktionen
{
    //I denna funktionen vissas text p� sk�rmen och avspelar sig ett ljud. Man ska klicka p� Enter att k�ra vidare

    cout<<endl<<" ======================="<<endl<<" === V\204lkommen till ===="<<endl<<" ====== RobSchack ======"<<endl<<" ======================="<<endl<<endl<<endl;
    cout<<"\a";
    cout<<" Klicka p\206 Enter f\224r att starta spelet!";
    cin.ignore();
}



void MENY(string& val) //Meny funktionen
{
    //I denna funktionen ska man matta in v�rdet "val", det kommer att l�ggas en kontroll p� detta om man matade in r�tt
    //Varje g�ng n�r denna funktionen sk�rs resettar "val", spelas det ett ljud och blir sk�rmen tom
    //Genom denna funktion kan man anr�pa de andra funktioner
    //N�r denna funktion �r f�rdig blir sk�rmen tom igen

    val="aa";
    cout<<"\a";
    system("cls");
    while (val.size()!=1 || (val!="1" && val!="2" && val!="3" && val!="4" && val!="5" && val!="0"))
    {
        cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;
        cout<<" 1. Starta RobSchack"<<endl;
        cout<<" 2. L\204sa genom reglarna"<<endl;
        cout<<" 3. \216ndra namn p\206 spelare"<<endl;
        cout<<" 4. Visa po\204nglistan"<<endl;
        cout<<" 5. Radera po\204nglistan"<<endl;
        cout<<" 0. Avsluta spelet"<<endl;
        cout<<endl<<" Ange ditt val: ";
        getline(cin,val); //Anv�ndare kan mata in en v�rde
        cout<<"\a"; //Avspelar ett ljud

        if (val.size()==0 || (val!="1" && val!="2" && val!="3" && val!="4" && val!="5" && val!="0"))
        {
            cout<<"\n Fel inmatning!"<<endl; //Error text skrivs ut
            cout<<" Mata bara in siffrorna 0 <-> 5!"<<endl;
            cout<<" F\224rs\224k om g\204rna!"<<endl;
            cin.ignore();
        }
        system("cls");
    }
}





void BYGGA_SCHACKFALT(string schackfalt[8][8]) //Bygga_schackfalt funktionen
{
    //I denna funktionen indelas schackfaltet med alla pj�serna som beh�vs p� startposition, resten �r d� tomt

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            schackfalt[i][j]=" "; //L�ggs till ett tomt ruta

    schackfalt[7][4]="K"; //Kung           //Spelare 1 anv�nder stora bokstaver, vi b�rjar ligga till den f�rst
    schackfalt[7][3]="Q"; //Drottning
    schackfalt[7][0]="R"; schackfalt[7][7]="R"; //Torn
    schackfalt[7][1]="N"; schackfalt[7][6]="N"; //H�st
    schackfalt[7][2]="B"; schackfalt[7][5]="B"; //L�pare
    for (int j=0;j<8;j++)
        schackfalt[6][j]="P"; //Bonden

    schackfalt[0][4]="k"; //Kung           //Spelare 2 anv�nder mindra bokstaver, vi b�rjar ligga till den sist
    schackfalt[0][3]="q"; //Drottning
    schackfalt[0][0]="r"; schackfalt[0][7]="r"; //Torn
    schackfalt[0][1]="n"; schackfalt[0][6]="n"; //H�st
    schackfalt[0][2]="b"; schackfalt[0][5]="b"; //L�pare
    for (int j=0;j<8;j++)
        schackfalt[1][j]="p"; //Bonden
}





void SKRIV_UT_FALT(string schackfalt[8][8], int tur, string spelare1, string spelare2) //Skriv_ut_falt funktionen
{
    //I denna funktionen skrivs schackf�ltet ut som en cout (den av f�ra funktionen)
    //Ocks� skrivs ut vems tur det �r, coutet skrivs ut genom en lista som g�r 8*8 (64 f�lt)
    //Denna funktionen best�r n�stan bara av coututskrivning, ocks� ber�knas det p� f�r varje rad den tillas vilken rad det blir (varje rad f�r en siffrabeteckning)
    //Ocks� f�r varje linje en bokstavbeteckning, men det �r l�ttare f�r att det bara beh�vs att tillla en cout efter sista raden
    //Det sista den g�r �r att skriva ut (genom en ber�kning) vems tur det �r

    int row=9;
    cout<<endl<<" ";
    for (int i=0;i<8;i++)
    {
        row-=1;
        cout<<row<<" - ";
        for (int j=0;j<8;j++)
            cout<<"["<<schackfalt[i][j]<<"] ";
        cout<<endl<<endl<<" ";
    }
    cout<<"     -   -   -   -   -   -   -   -"<<endl<<"      A   B   C   D   E   F   G   H";
    cout<<endl<<endl;
    if (tur==1)    cout<<" "<<spelare1<<" \204r p\206 tur nu   -   ";
    else    cout<<" "<<spelare2<<" \204r p\206 tur nu   -   ";
}



void KUNG_CHECK(string schackfalt[8][8], int tur, int& vinna_spelet) //Kung_check funktionen
{
    //I denna funktionen kontrolleras det om n�gons kung fortfarande finns med p� schackf�ltet
    //Om det �r inte s� kommer det att returna ett v�rde varmed vi vet som vann
    //Om denna kontroll sk�rs n�r spelare 1 �r p� tur kommer spelare 2 att vinna, och tv�rtom

    int check=0;
    for (int i=0; i<8; i++)
        for (int j=0; j<8; j++)
        {
            if (tur==1)
            {
                if (schackfalt[j][i]=="K")
                    check=1;
            }
            if (tur==2)
            {
                if (schackfalt[j][i]=="k")
                    check=1;
            }
        }
    if (check==0)
    {
        if (tur==1)
            vinna_spelet=2;
        if (tur==2)
            vinna_spelet=1;
    }
}



void MATA_KOORDINATER(string schackfalt[8][8], int& error, int& x, int& y, string& x_str, string& y_str, int tur, int& vinna_spelet) //Mata_koordinater funktionen
{
    //I denna funktionen ska den som �r p� tur mata in koordinaterna som best�mmer vilken pj�s ska r�ras
    //Det finns en kontroll i fallet koordinater st�mmer inte (inte din pj�s, utanf�r bordet, tomt ruta), d� m�ste det g�ras om

    cout<<"0 0 = uppge\n\n Mata in koordinaterna: ";

    KUNG_CHECK(schackfalt, tur, vinna_spelet);
    if (vinna_spelet>0)
        return;

    //H�r mattas in koordinater

    cin>>x_str>>y_str;

    //H�r finns den kontrollen

    if (x_str=="a")   x=0;   else if (x_str=="b")   x=1;   else if (x_str=="c")   x=2;   else if (x_str=="d")   x=3;
    else if (x_str=="e")   x=4;   else if (x_str=="f")   x=5;   else if (x_str=="g")   x=6;   else if (x_str=="h")   x=7;
    else error=1;

    if (y_str=="1")   y=7;   else if (y_str=="2")   y=6;   else if (y_str=="3")   y=5;   else if (y_str=="4")   y=4;
    else if (y_str=="5")   y=3;   else if (y_str=="6")   y=2;   else if (y_str=="7")   y=1;   else if (y_str=="8")   y=0;
    else error=1;

    //Om inmatning �r p� b�da v�rder 0 ska programmet till avslutingsfunktionen

    if (x_str=="0" && y_str=="0")
        return;

    //Kontroll om man �ger pj�sen

    if (error==0)
    {
        if (   (tur==1) && (schackfalt[y][x]=="k" || schackfalt[y][x]=="q" || schackfalt[y][x]=="n" || schackfalt[y][x]=="r" || schackfalt[y][x]=="b" || schackfalt[y][x]=="p")   )
            error=2;
        if (   (tur==2) && (schackfalt[y][x]=="K" || schackfalt[y][x]=="Q" || schackfalt[y][x]=="N" || schackfalt[y][x]=="R" || schackfalt[y][x]=="B" || schackfalt[y][x]=="P")   )
            error=2;

        if (schackfalt[y][x]==" ")
            error=3;
    }

    //Varje kontroll betecknas med ett v�rde i "error", om error p� slutet �r 0 d� finns det ingen fel, om det blir ingen 0 d� m�ste funktionen g�ras om
    //Denna regeln med "error" g�ller �verallt

    if (error!=0)
    {
        if (error==1)
            cout<<"\n Fel inmatning!";
        if (error==2)
            cout<<"\n Pj\204sen \204r inte din!";
        if (error==3)
            cout<<"\n Rutan \204r tomt!";
        cout<<" F\224rs\224k om!";
        cin.ignore(); cin.ignore();
        system("cls");
    }

    cout<<"\a";
}



void BYGGA_SCHACKFALT_PJASER(string schackfalt[8][8], int schackfalt_pjaser[8][8], int tur) //Bygga_schackfalt_pjaser funktionen
{
    //Detta �r osynligt hemlig schackf�lt som kopieras alla v�rde fr�n det vanliga schackf�lt, den endaste skillnaden �r att:
    //Alla pj�ser av spelare 1 betecknas med 2 och av spelare 2 med 1
    //Den specielle regla (EN PASSENT) betecknas med en dubbel siffra

    for (int i=0; i<8; i++)
        for (int j=0; j<8; j++)
        {
            if (schackfalt_pjaser[i][j]!=11 && schackfalt_pjaser[i][j]!=22)
                schackfalt_pjaser[i][j]=0;

            if (tur==2 && schackfalt_pjaser[i][j]==11)
                schackfalt_pjaser[i][j]=0;
            if (tur==1 && schackfalt_pjaser[i][j]==22)
                schackfalt_pjaser[i][j]=0;

            if (schackfalt[i][j]=="K")
                schackfalt_pjaser[i][j]=2;
            if (schackfalt[i][j]=="Q")
                schackfalt_pjaser[i][j]=2;
            if (schackfalt[i][j]=="R")
                schackfalt_pjaser[i][j]=2;
            if (schackfalt[i][j]=="N")
                schackfalt_pjaser[i][j]=2;
            if (schackfalt[i][j]=="B")
                schackfalt_pjaser[i][j]=2;
            if (schackfalt[i][j]=="P")
                schackfalt_pjaser[i][j]=2;

            if (schackfalt[i][j]=="k")
                schackfalt_pjaser[i][j]=1;
            if (schackfalt[i][j]=="q")
                schackfalt_pjaser[i][j]=1;
            if (schackfalt[i][j]=="r")
                schackfalt_pjaser[i][j]=1;
            if (schackfalt[i][j]=="n")
                schackfalt_pjaser[i][j]=1;
            if (schackfalt[i][j]=="b")
                schackfalt_pjaser[i][j]=1;
            if (schackfalt[i][j]=="p")
                schackfalt_pjaser[i][j]=1;
        }
}



void ROCKAD_CHECK(string schackfalt[8][8], int tur, int& rockad_tur1, int& rockad_vanster_tur1, int& rockad_hoger_tur1, int& rockad_tur2, int& rockad_vanster_tur2, int& rockad_hoger_tur2) //Rockad_check funktionen
{
    //I denna funktionen kontrolleras om man f�r fortfarande anv�nda Rockaden (att byta kungen med en torn)
    //Den skickas olika v�rder tillbaka till andra funktioner s� programmet vet den spelare f�r g�ra det
    //Standard �r de v�rde 0 (betydder f�r g�ra), men om kungen och torn har r�rat sig fr�n startpostion blir den v�rde 1

    if (tur==1)
    {
        if (schackfalt[7][4]!="K")
            rockad_tur1=1;
        if (schackfalt[7][0]!="R")
            rockad_vanster_tur1=1;
        if (schackfalt[7][7]!="R")
            rockad_hoger_tur1=1;
    }
    if (tur==2)
    {
        if (schackfalt[0][4]!="k")
            rockad_tur2=1;
        if (schackfalt[0][0]!="r")
            rockad_vanster_tur2=1;
        if (schackfalt[0][7]!="r")
            rockad_hoger_tur2=1;
    }
}



void RORELSE_KONTROLL(string schackfalt[8][8], int schackfalt_pjaser[8][8], int tur, int& error, int x, int y) //Rorelse_kontroll funktionen
{
    //I denna funktionen kontrolleras om alla pj�ser utfom f�r h�sten (N/n, den f�r hoppa �ver allt) kan minst r�ra sig p� 1 h�l
    //Det kontrolleras genom den hemlig schackbordet (den kopia som r�cknar i 1 och 2) f�r att det kr�vs mindre if-satser
    //Varje riktning som inte g�r adderas move_check med ett v�rde, alla h�l tillsammans �r 8, om move_check blir d� 8 kan pj�sen inte r�ra sig
    //Varje g�ng denna funktionen sk�rs resettas move_check

    int move_check=0;

    //En konstig grej nu, schackfalt_pjaser �r baserande p� 3 olika tal, varav spelare 1 �r 2, spelare 2 �r 1 och resten �r 0
    //F�r att kunna k�ra denna kontroll bytter vi tur bara, men den sparas inte, s� efter funktionen blir tur den gamla v�rde

    if (tur==1)
        tur=2;
    else
        tur=1;

    //Och h�r k�rs de olika pj�ser p� kontroll

    if (schackfalt[y][x]=="P" || schackfalt[y][x]=="p")
    {
        if (tur==1)
        {
            if (schackfalt_pjaser[y+1][x]==tur)
                move_check+=8;
        }
        if (tur==2)
        {
            if (schackfalt_pjaser[y-1][x]==tur)
                move_check+=8;
        }
    }

    if (schackfalt[y][x]=="R" || schackfalt[y][x]=="r")
    {
        if (y!=7)
        {
            if (schackfalt_pjaser[y+1][x]==tur)
                move_check+=2;
        }
        else
            move_check+=2;
        if (y!=0)
        {
            if (schackfalt_pjaser[y-1][x]==tur)
                move_check+=2;
        }
        else
            move_check+=2;
        if (x!=7)
        {
            if (schackfalt_pjaser[y][x+1]==tur)
                move_check+=2;
        }
        else
            move_check+=2;
        if (x!=0)
        {
            if (schackfalt_pjaser[y][x-1]==tur)
                move_check+=2;
        }
        else
            move_check+=2;
    }

    if (schackfalt[y][x]=="B" || schackfalt[y][x]=="b")
    {
        if (y!=7 && x!=7)
        {
            if (schackfalt_pjaser[y+1][x+1]==tur)
                move_check+=2;
        }
        else
            move_check+=2;
        if (y!=7 && x!=0)
        {
            if (schackfalt_pjaser[y+1][x-1]==tur)
                move_check+=2;
        }
        else
            move_check+=2;
        if (y!=0 && x!=7)
        {
            if (schackfalt_pjaser[y-1][x+1]==tur)
                move_check+=2;
        }
        else
            move_check+=2;
        if (y!=0 && x!=0)
        {
            if (schackfalt_pjaser[y-1][x-1]==tur)
                move_check+=2;
        }
        else
            move_check+=2;
    }

    //F�r att kungen och drottningen har samma r�relses�tt kontrolleras de b�da i 1 kontroll

    if (schackfalt[y][x]=="Q" || schackfalt[y][x]=="q" || schackfalt[y][x]=="K" || schackfalt[y][x]=="k")
    {
        if (y!=7)
        {
            if (schackfalt_pjaser[y+1][x]==tur)
                move_check+=1;
        }
        else
            move_check+=1;
        if (y!=0)
        {
            if (schackfalt_pjaser[y-1][x]==tur)
                move_check+=1;
        }
        else
            move_check+=1;
        if (x!=7)
        {
            if (schackfalt_pjaser[y][x+1]==tur)
                move_check+=1;
        }
        else
            move_check+=1;
        if (x!=0)
        {
            if (schackfalt_pjaser[y][x-1]==tur)
                move_check+=1;
        }
        else
            move_check+=1;
        if (y!=7 && x!=7)
        {
            if (schackfalt_pjaser[y+1][x+1]==tur)
                move_check+=1;
        }
        else
            move_check+=1;
        if (y!=7 && x!=0)
        {
            if (schackfalt_pjaser[y+1][x-1]==tur)
                move_check+=1;
        }
        else
            move_check+=1;
        if (y!=0 && x!=7)
        {
            if (schackfalt_pjaser[y-1][x+1]==tur)
                move_check+=1;
        }
        else
            move_check+=1;
        if (y!=0 && x!=0)
        {
            if (schackfalt_pjaser[y-1][x-1]==tur)
                move_check+=1;
        }
        else
            move_check+=1;
    }

    //Och om move_check �r 8 f�r spelare error medelande, funktionen Rora_objekt k�rs vidaren, men ska k�ras om

    if (move_check==8)
    {
        error=2;
        //Error blir 2 s� att i funktioen Rora_objekt den inte beh�vs k�ra de f�ljande funktioner men direkt kan k�ra om
        cout<<"0 0 = uppge";
        cout<<endl<<endl<<" Det finns ingen m\224jlighet att flytta denna pj\204sen! V\204lj en annan!";
        cin.ignore(); cin.ignore();
        return;
    }
    //Annars blir error 0 och kan funktionen Rora_objekt k�ra vidare
    else
        error=0;
}



void MATA_STEG(string schackfalt[8][8], int schackfalt_pjaser[8][8], int tur, int& steg, int& steg_extra, string& riktning, int x, int y, string x_str, string y_str, int& error, int rockad_tur1, int rockad_vanster_tur1, int rockad_hoger_tur1, int rockad_tur2, int rockad_vanster_tur2, int rockad_hoger_tur2)
//Mata_steg funktionen
{
    //I denna funktionen ska mattas in hur du ska r�ra den pj�sen om selekterades
    //Den sk�r i olika steg, f�rst allts� ett v�rde reset
    //Och sk�rminfomation
    //Kom ih�g att errror resetas till 0 f�r att i den f�ra funktionen kom p� 0 (om den var 1 k�rde denna funktionen inte)

    string steg_str="a", steg_extra_str="a";
    steg=10, steg_extra=10;
    error=1;

    cout<<"0 = G\224ra om   -   ";
    cout<<"Du selekterade: "<<schackfalt[y][x]<<", "<<x_str<<y_str<<endl;

    //Bonden alts� (P/p) som blev selekterads, bonde kontrolleras genom att bara antalet steg ska mattas in, som ber�r av din position
    //Det skrivs ocks� ut instruktionerna ber�rande vad bonden f�r g�ra

    if (schackfalt[y][x]=="P" || schackfalt[y][x]=="p")
    {
        if (   (y==6 && tur==1) || (y==1 && tur==2)   )
            cout<<" Kr\204vs 0 <-> 2";
        else
            cout<<" Kr\204vs 0 <-> 1";

        if (   x!=0 && (   ((schackfalt_pjaser[y-1][x-1]==1 || schackfalt_pjaser[y-1][x-1]==11) && tur==1) || ((schackfalt_pjaser[y+1][x-1]==2 || schackfalt_pjaser[y+1][x-1]==22) && tur==2)  )   )
            cout<<", l";
        if (   x!=7 && (   ((schackfalt_pjaser[y-1][x+1]==1 || schackfalt_pjaser[y-1][x+1]==11) && tur==1) || ((schackfalt_pjaser[y+1][x+1]==2 || schackfalt_pjaser[y+1][x+1]==22) && tur==2)  )   )
            cout<<", r";
        cout<<endl<<" Mata in steg: ";



        cin>>steg_str;

        //Nu sk�rs alla kontroll, om steg �r 0, eller om antalet steg man mattade in st�mmer, eller om position g�ller, eller om vi kan attackara n�gon

        if (steg_str=="0")
            steg=0;
        if (steg==0)
            return;

        if (steg_str=="1")
            steg=1;
        if (steg_str=="2")
            if (   (y==6 && tur==1) || (y==1 && tur==2)   )
                steg=2;

        //Attackering betecknas med "steg" 3 och 4 ist�llet av r och l, b�ttre att beh�lla kvar det som en int v�rde

        if (steg_str=="l" && x!=0 && (   ((schackfalt_pjaser[y-1][x-1]==1 || schackfalt_pjaser[y-1][x-1]==11) && (tur==1))   ||   ((schackfalt_pjaser[y+1][x-1]==2 || schackfalt_pjaser[y+1][x-1]==22) && (tur==2))   )   )
            steg=4;
        if (steg_str=="r" && x!=7 && (   ((schackfalt_pjaser[y-1][x+1]==1 || schackfalt_pjaser[y-1][x+1]==11) && (tur==1))   ||   ((schackfalt_pjaser[y+1][x+1]==2 || schackfalt_pjaser[y+1][x+1]==22) && (tur==2))   )   )
            steg=3;

        if (steg>=1 && steg<=4)
            error=0;

        //Om spelare 1 �r p� tur �vers�tter vi antalet steg (s� l�nge det �r 1 eller 2) till ett minus tal, s� att vi reser up p� f�ltet ist�llet av nere

        if (error==0 && tur==1 && (steg==1 || steg==2)   )
            steg=steg*-1;

        //Och igen som med error, s� l�nge error blir 0 �r det ingen problem, i de flesta kontrolls anv�nds den v�rden "error", annars f�r man k�ra om funktionen

        if (error>0)
            cout<<endl<<" Fel antal steg!";
    }


    //Nu �r R/r (torn) selekterads, men den g�ng anv�nds det 2 v�rder: "steg" och "riktning", och riktning g�r som namnet s�ger
    //Ocks� beh�vs det mer kontroll f�r om riktningen g�ller och om steg g�ller (f�r nu blir till max. 7 ist�llet)

    if (schackfalt[y][x]=="R" || schackfalt[y][x]=="r") //Selekterad R/r
    {
        cout<<" Riktning kr\204vs: u, d, l, r    -   Steg kr\204vs 1 <-> 7"<<endl;
        cout<<" Mata in riktning + antal steg: "; //Skrivs ut instruktioner
        cin>>riktning>>steg_str;

        if (steg_str=="0" || riktning=="0")
            steg=0;
        if (steg==0)
            return;


        if (   (riktning!="u" && riktning!="d" && riktning!="r" && riktning!="l") || (steg_str!="1" && steg_str!="2" && steg_str!="3" && steg_str!="4" && steg_str!="5" && steg_str!="6" && steg_str!="7")  )
            cout<<endl;

        if (riktning!="u" && riktning!="d" && riktning!="r" && riktning!="l")
            cout<<" Fel riktning!  ";

        if (steg_str=="1") steg=1; else if (steg_str=="2") steg=2; else if (steg_str=="3") steg=3; else if (steg_str=="4") steg=4;
        else if (steg_str=="5") steg=5; else if (steg_str=="6") steg=6; else if (steg_str=="7") steg=7;
        else
            cout<<" Fel antal steg!";

        if (   (riktning=="u" || riktning=="d" || riktning=="r" || riktning=="l") && (steg>=1 && steg<=6)   )
            error=0;
    }

    //N/n (h�sten) ska anv�nda ett speciell r�relse s�tt, h�r matas in 2 antal steg, en f�r horisontell och en f�r verktikal, igen mer check

    if (schackfalt[y][x]=="N" || schackfalt[y][x]=="n")
    {
        cout<<" Kr\204vs: -2 <-> 2"<<endl;
        cout<<" Mata in antal horisontal steg + vertikal steg: ";
        cin>>steg_str>>steg_extra_str;

        if (steg_str=="0" || steg_extra_str=="0")
            steg=0;
        if (steg==0)
            return;

        if          (   (steg_str=="-2" && tur==1) || (steg_str=="2" && tur==2)   )         steg=2;
        else if     (   (steg_str=="-1" && tur==1) || (steg_str=="1" && tur==2)   )         steg=1;
        else if     (steg_str=="0")                                                         steg=0;
        else if     (   (steg_str=="1" && tur==1) || (steg_str=="-1" && tur==2)   )         steg=-1;
        else if     (   (steg_str=="2" && tur==1) || (steg_str=="-2" && tur==2)   )         steg=-2;
        //else                                                                                error=2;

        if          (steg_extra_str=="2")                                                   steg_extra=2;
        else if     (steg_extra_str=="1")                                                   steg_extra=1;
        else if     (steg_extra_str=="0")                                                   steg_extra=0;
        else if     (steg_extra_str=="-1")                                                  steg_extra=-1;
        else if     (steg_extra_str=="-2")                                                  steg_extra=-2;
        //else                                                                                error=2;

        if (   (steg*steg_extra==2) || (steg*steg_extra==-2)   )
            error=0;
        else
            cout<<endl<<" Fel antal steg!";
    }

    //Om du k�nner till hur torn fungeras �r B/b inget annat i kod, bara att det kontrolleras diagonalt ist�llet av andra riktningar

    if (schackfalt[y][x]=="B" || schackfalt[y][x]=="b")
    {
        cout<<" Riktning kr\204vs: ul, ur, dl, dr    -   Steg kr\204vs 1 <-> 7"<<endl;
        cout<<" Mata in riktning + antal steg: ";
        cin>>riktning>>steg_str;

        if (steg_str=="0" || riktning=="0")
            steg=0;
        if (steg==0)
            return;



        if (   (riktning!="ur" && riktning!="ul" && riktning!="dr" && riktning!="dr") || (steg_str!="1" && steg_str!="2" && steg_str!="3" && steg_str!="4" && steg_str!="5" && steg_str!="6" && steg_str!="7")  )
            cout<<endl;

        if (riktning!="ur" && riktning!="ul" && riktning!="dr" && riktning!="dl")
            cout<<" Fel riktning!  ";

        if (steg_str=="1") steg=1; else if (steg_str=="2") steg=2; else if (steg_str=="3") steg=3; else if (steg_str=="4") steg=4;
        else if (steg_str=="5") steg=5; else if (steg_str=="6") steg=6; else if (steg_str=="7") steg=7;
        else
            cout<<" Fel antal steg!";

        if (   (riktning=="ur" || riktning=="ul" || riktning=="dr" || riktning=="dl") && (steg>=1 && steg<=7)   )
            error=0;
    }

    //Drottningen (Q/q) �r en kombination av b�da torn och l�pare tillsammans, s� den har igen samman kod, men bara p� alla 8 h�ll

    if (schackfalt[y][x]=="Q" || schackfalt[y][x]=="q") //Selekterad R/r
    {
        cout<<" Riktning kr\204vs: u, d, l, r, ul, ur, dl, dr    -   Steg kr\204vs 1 <-> 7"<<endl;
        cout<<" Mata in riktning + antal steg: "; //Skrivs ut instruktioner
        cin>>riktning>>steg_str;

        if (steg_str=="0" || riktning=="0")
            steg=0;
        if (steg==0)
            return;


        if (   (riktning!="u" && riktning!="d" && riktning!="r" && riktning!="l" && riktning!="ur" && riktning!="ul" && riktning!="dr" && riktning!="dl") || (steg_str!="1" && steg_str!="2" && steg_str!="3" && steg_str!="4" && steg_str!="5" && steg_str!="6" && steg_str!="7")  )
            cout<<endl;

        if (riktning!="u" && riktning!="d" && riktning!="r" && riktning!="l" && riktning!="ur" && riktning!="ul" && riktning!="dr" && riktning!="dl")
            cout<<" Fel riktning!  ";

        if (steg_str=="1") steg=1; else if (steg_str=="2") steg=2; else if (steg_str=="3") steg=3; else if (steg_str=="4") steg=4;
        else if (steg_str=="5") steg=5; else if (steg_str=="6") steg=6; else if (steg_str=="7") steg=7;
        else
            cout<<" Fel antal steg!";

        if (   (riktning=="u" || riktning=="d" || riktning=="r" || riktning=="l" || riktning=="ur" || riktning=="ul" || riktning=="dr" || riktning=="dl") && (steg>=1 && steg<=6)   )
            error=0;
    }

    //Kungen (K/k) fungerar d� p� samma h�ll som drottningen, men bara att den f�r flytta 1 steg, s� man bara mata in v�rde "riktning", d� flyttas kungen automatiskt 1 steg denna h�let
    //Ocks� kontrolleras bara riktningen d� och inte antalet steg

    if (schackfalt[y][x]=="K" || schackfalt[y][x]=="k")
    {
        cout<<" Riktning kr\204vs: 0, u, d, l, r, ul, ur, dl, dr";
        if (tur==1)
        {
            if (rockad_tur1==0 && rockad_vanster_tur1==0)
                cout<<", lx";
            if (rockad_tur1==0 && rockad_hoger_tur1==0)
                cout<<", rx";
        }
        if (tur==2)
        {
            if (rockad_tur2==0 && rockad_vanster_tur2==0)
                cout<<", lx";
            if (rockad_tur2==0 && rockad_hoger_tur2==0)
                cout<<", rx";;
        }
        cout<<endl;
        cout<<" Mata in riktning: "; //Skrivs ut instruktioner
        cin>>riktning;

        if (riktning=="0")
            steg=0;
        if (steg==0)
            return;

        //En extra grej som anv�nder v�rder fr�n Rockad_check (h�mtades innan, men anv�nds h�r)
        //Som allt g�ller f�r kungen g�ra rockad, men bara med de torn som hade inte redan r�rt sig, och om kungen hade inte r�rt sig
        //Om man f�r g�ra det finns det m�jlighet till att kunna mata in x1 eller/och x2
        //Vidare sk�rs den vanliga kontroll om riktningen g�ller

        if (   (tur==1 && rockad_tur1==1)   ||   (tur==2 && rockad_tur2==1)   )
        {
            if (riktning!="u" && riktning!="d" && riktning!="r" && riktning!="l" && riktning!="ur" && riktning!="ul" && riktning!="dr" && riktning!="dl")
            {
                cout<<endl;
                cout<<" Fel riktning!";
            }
        }
        if (   (tur==1 && rockad_tur1==0 && rockad_hoger_tur1==0 && rockad_vanster_tur1==1)   ||   (tur==2 && rockad_tur2==0 && rockad_hoger_tur2==0 && rockad_vanster_tur2==1)   )
        {
            if (riktning!="u" && riktning!="d" && riktning!="r" && riktning!="l" && riktning!="ur" && riktning!="ul" && riktning!="dr" && riktning!="dl" && riktning!="rx")
            {
                cout<<endl;
                cout<<" Fel riktning!";
            }
        }
        if (   (tur==1 && rockad_tur1==0 && rockad_hoger_tur1==1 && rockad_vanster_tur1==0)   ||   (tur==2 && rockad_tur2==0 && rockad_hoger_tur2==1 && rockad_vanster_tur2==0)   )
        {
            if (riktning!="u" && riktning!="d" && riktning!="r" && riktning!="l" && riktning!="ur" && riktning!="ul" && riktning!="dr" && riktning!="dl" && riktning!="lx")
            {
                cout<<endl;
                cout<<" Fel riktning!";
            }
        }
        if (   (tur==1 && rockad_tur1==0 && rockad_hoger_tur1==0 && rockad_vanster_tur1==0)   ||   (tur==2 && rockad_tur2==0 && rockad_hoger_tur2==0 && rockad_vanster_tur2==0)   )
        {
            if (riktning!="u" && riktning!="d" && riktning!="r" && riktning!="l" && riktning!="ur" && riktning!="ul" && riktning!="dr" && riktning!="dl" && riktning!="rx" && riktning!="lx")
            {
                cout<<endl;
                cout<<" Fel riktning!";
            }
        }

        if (riktning=="u" || riktning=="d" || riktning=="r" || riktning=="l" || riktning=="ur" || riktning=="ul" || riktning=="dr" || riktning=="dl" )
            error=0;
        if (   (   (tur==1 && rockad_tur1==0 && rockad_vanster_tur1==0)   ||   (tur==2 && rockad_tur2==0 && rockad_vanster_tur2==0)   )   &&   riktning=="lx")
            error=0;
        if (   (   (tur==1 && rockad_tur1==0 && rockad_hoger_tur1==0)   ||   (tur==2 && rockad_tur2==0 && rockad_hoger_tur2==0)   )   &&   riktning=="rx")
            error=0;
    }

    //Om �r f�rtfarande p� "error" = 0, d� f�r man k�ra vidaren i Ror_objekt funktionen
    //Annars ska man g�ra om denna funktionen n�r Ror_objekt funktion kommer (och skrivs det nu ut felmedelande)

    if (error>0)
    {
        cout<<"\a";
        cout<<"   -   F\224rs\224k om!";
        cin.ignore(); cin.ignore();
    }
}



void OMVANDLA_BONDE(string schackfalt[8][8], int tur, string& omvandling, string spelare1, string spelare2, int x, int y, string x_str, string y_str) //Omvandla_bonde funktionen
{
    //Denna funktionen sk�rs n�r en bonde n�s sista f�ltet (uppe f�r P och nere f�r p)
    //D� f�r man mata in i vilken pj�s den ska omvandlas, alla f�r v�ljas utom bonden (sj�lvklart) och kungen (ocks� sj�lvklart)
    //Igen... kontroll... kontroll... Om inga fel inmattas k�rs den vidare till den gamla funktionen, annars k�rs detta om
    //En grej �r att n�r denna funktion anr�pas blir sk�rmen tomt, skrivs det ut snabbt nya text (sv�rt att ser f�r�ndring p� sk�rmen, bara att pj�sen n�des sista f�ltet)

    while (omvandling.size()!=1 || (omvandling!="q" && omvandling!="r" && omvandling!="n" && omvandling!="b"))
    {
        system("cls");
        SKRIV_UT_FALT(schackfalt, tur, spelare1, spelare2);
        cout<<"0 = G\224ra om   -   ";
        cout<<"Du selekterade: "<<schackfalt[y][x]<<", "<<x_str<<y_str<<endl;
        cout<<" K\204vs 0 <-> 1"<<endl<<" Mata in steg: 1"<<endl;

        cout<<endl<<" Bonden n\206de sista f\204ltet, inmatning kr\204vs: ";
        if (tur==1)
            cout<<" Q, R, N, B"<<endl;
        if (tur==2)
            cout<<" q, r, n, b"<<endl;
        cout<<" Mata in den nya omvandling: ";
        cin>>omvandling;

        if (omvandling.size()!=1 || (omvandling!="q" && omvandling!="r" && omvandling!="n" && omvandling!="b"))
        {
            cout<<"\n Fel inmatning!   -   F\224rs\224k om!";
            cin.ignore(); cin.ignore();
        }
    }

    if (tur==1)
    {
        if (omvandling=="q")
            omvandling="Q";
        if (omvandling=="r")
            omvandling="R";
        if (omvandling=="n")
            omvandling="N";
        if (omvandling=="b")
            omvandling="B";
    }
}



void EN_PASSANT(int schackfalt_pjaser[8][8], int tur, int x, int y) //En_passant funktionen
{
    //Denna funktionen �r den som tillas den dubbla tal p� schackfalt_pjaser (den kopia av schackf�ltet)
    //Det h�nder bara om en bonde (P/p) flytta 2 steg, det �r inf�r En Passent reglan s� att i n�sta tur kan blir s�gen
    //L�ser reglar av spelet f�r mer info om En Passant

    if (tur==1)
        schackfalt_pjaser[y-1][x]=22;
    if (tur==2)
        schackfalt_pjaser[y+1][x]=11;
}


void ROR_OBJEKT(string schackfalt[8][8], int schackfalt_pjaser[8][8], int steg, int steg_extra, int x, int y, string riktning, string x_str, string y_str, int& tur, int error, string spelare1, string spelare2, int& antal_satt_tur1, int& antal_satt_tur2, int rockad_tur1, int rockad_vanster_tur1, int rockad_hoger_tur1, int rockad_tur2, int rockad_vanster_tur2, int rockad_hoger_tur2)
//Ror_objekt funktionen
{
    //Som namnet s�gger, denna funktionen �r f�r att flytta pj�ser till nya koordinater... Om... Error �r 0, s�... Det ska finnas inga error som:
    //Du r�r utanf�r bordet, du r�r p� ett st�lle som redan finns en pj�s av dig, du r�r dig till ett st�lle som �r f�rsp�rrad (g�ller �ven f�r rockaden)
    //Liksom i Mata_koordinater funktionen sk�rs allt deta i steg ber�rande vilken pj�s du har

    //F�rst ska sk�rmen blir tomt och anr�pas funktionen Skriv_ut_falt (s� ser vi f�ltet p� sk�rmen) och Rorelse_kontroll funktionen
    //Sen anr�pas funktioner Rockad_check och Mata_steg var systemet ska veta hur pj�sen ska r�ra sig
    //Men om programmet fick ett felaktig v�rde ska det g�ras om hele grejen h�r

    while (error!=0)
    {
        system("cls");
        SKRIV_UT_FALT(schackfalt, tur, spelare1, spelare2);

        if (schackfalt[y][x]!="N" || schackfalt[y][x]!="n")
            RORELSE_KONTROLL(schackfalt, schackfalt_pjaser, tur, error, x, y);

        //Om Rorelse_kontroll funktionen misslyckades k�rs f�ljande inte vidare f�r error �r 2

        if (error!=2)
        {
            ROCKAD_CHECK(schackfalt, tur, rockad_tur1, rockad_vanster_tur1, rockad_hoger_tur1, rockad_tur2, rockad_vanster_tur2, rockad_hoger_tur2);
            MATA_STEG(schackfalt, schackfalt_pjaser, tur, steg, steg_extra, riktning, x, y, x_str, y_str, error, rockad_tur1, rockad_vanster_tur1, rockad_hoger_tur1, rockad_tur2, rockad_vanster_tur2, rockad_hoger_tur2);
        }

        //Och om error �r inte 0 k�rs while-loopen om tills den f�r error �r 0

        if (steg==0)
        {
            cout<<"\a";
            system("cls");
            return;
        }

    }

    //Bonden �r selekterad (P/p)
    //F�rst ska kontrolleras vilken v�rde vi fick fr�n funktionen Mata_steg
    //Det f�rsta som kontrolleras �r om att vi inte g�r utifr�n bordet, sen om platsen pj�sen ska vara �r tomt och att v�ggen �r fritt. Annars blir error > 0
    //Och som vanlig avbrytts aktionen om error �r inte 0, varje error v�rde skriver ut sitt eget medelande

    if (schackfalt[y][x]=="P" || schackfalt[y][x]=="p")
    {
        if (   (steg==1 || steg==2) &&  ((y+steg<0 && tur==1) || (y+steg>7 && tur==2))   )
            error=1;

        //H�r sk�rs allts� den "�r rutan och v�ggen fritt" kontrollen, grejen �r bara: om steg �r 1 (b�da postivit och negativt) k�rs bara kontrollen om platsten �r fritt.
        //Om steg �r 2 (+ och -) kontrolleras ocks� om v�ggen �r fritt genom att checka 1 steg vidare �r fritt att g� och om 2 steg vidare �r tomt

        if (error==0)
        {
            if (steg==1 || steg==-1)
                if (schackfalt[y+steg][x]!=" ")
                    error=2;

            if (steg==2 || steg==-2)
            {
                if (schackfalt[y+steg][x]!=" ")
                    error=2;
                if (schackfalt[y+(steg/2)][x]!=" ")
                    error=3;
            }
        }

        //Det hittades inga fel s� l�nge (om error �r inte 0 d� slutat funktionen h�r och skipar programmet till slutet
        //Nu ska pj�sen allts� flyttas till den nya st�lle (den finns ocks� kvar p� den gamla st�lle, s� den �r p� 2 platser, den gamla raderas senare
        //Viktig �r att det ocks� kontrolleras alltid vems tur det �r s� programmet vet vilken sort bonden den ska tillla

        if (error==0)
        {
            if (   tur==1 && (steg!=3 && steg!=4)   )
                schackfalt[y+steg][x]="P";
            if (   tur==2 && (steg!=3 && steg!=4)   )
                schackfalt[y+steg][x]="p";

            //H�r ska funktionen En_passent aktiveras om bonden r�r sig 2 steg p� schackf�ltet

            if (steg==2 || steg==-2)
                EN_PASSANT(schackfalt_pjaser, tur, x , y);

            //Nu om steg �r 3 (attackera r/h�ger) eller steg �r 4 (attackera l/v�nster) ska f�rst kontrolleras om vi f�r sla genom EN PASSANT regeln
            //Om ja d� s�tts fiendens rutan p� tomt
            //D�refter ska pj�sen
            //Kontrollen om pj�sen f�r sla �r gjords i funktionen Mata_steg, den bara utf�rs h�r

            if (steg==3)
            {
                if (   (tur==1 && schackfalt_pjaser[y-1][x+1]==11)   ||   (tur==2 && schackfalt_pjaser[y+1][x+1]==22)   )
                    schackfalt[y][x+1]=" ";
                if (tur==1)
                    schackfalt[y-1][x+1]="P";
                if (tur==2)
                    schackfalt[y+1][x+1]="p";
            }
            if (steg==4)
            {
                if (   (tur==1 && schackfalt_pjaser[y-1][x-1]==11)   ||   (tur==2 && schackfalt_pjaser[y+1][x-1]==22)   )
                    schackfalt[y][x-1]=" ";
                if (tur==1)
                    schackfalt[y-1][x-1]="P";
                if (tur==2)
                    schackfalt[y+1][x-1]="p";
            }

            //Nu om pj�sen �r n�sta p� sista f�ltet (1 steg innan) den kan n� och ska flytar sig d� aktiveras funktionen Omvandla_bonden s� att spelare f�r omvandla sitt bonde i en annan pj�s
            //Men ingen annan bonde eller kung
            //Ocks� som vanligt sk�rs kontrollen vems tur det �r, ocks� resettas stringen man ska matta in inf�r omvandlingen

            if (   (y==1 && tur==1)   ||   (y==6 && tur==2)   )
            {
                string omvandling="a";
                schackfalt[y][x]=" ";
                OMVANDLA_BONDE(schackfalt, tur, omvandling, spelare1, spelare2, x, y, x_str, y_str);

                //Om pj�sen slog h�ger eller v�nster, m�ste ocks� medr�knas, d�rf�r de 3 kontroll p� steg, men programmet vet allt det aldrig h�nder med 2 steg
                //S� vi f�r den nya pj�sen p� r�tt rutan


                if (steg==1 && tur==1)
                    schackfalt[y-1][x]=omvandling;
                if (steg==3  && tur==1)
                    schackfalt[y-1][x+1]=omvandling;
                if (steg==4  && tur==1)
                    schackfalt[y-1][x-1]=omvandling;
                if (steg==1 && tur==2)
                    schackfalt[y+1][x]=omvandling;
                if (steg==3  && tur==2)
                    schackfalt[y+1][x+1]=omvandling;
                if (steg==4  && tur==2)
                    schackfalt[y+1][x-1]=omvandling;
            }
        }
    }

    //H�r �r torn selekterads (R/r)
    //Alla pj�ser har samma struktur i kontroll och r�rselse, men f�r att n�gra pj�ser har andra r�relsereglar ska kontrollen fungerar litte ann�rlunda
    //F�rst d� error checken

    if (schackfalt[y][x]=="R" || schackfalt[y][x]=="r")
    {
        if (   (riktning=="u" && y-steg<0) || (riktning=="d" && y+steg>7) || (riktning=="r" && x+steg>7) || (riktning=="l" && x-steg<0)   )
            error=1;

        if (error==0)
        {
            //F�r att torn kan alltid f�r 7 som stegv�rde (naturligtviss kontrolleras f�rst om den inte g�r utifr�n bordet) ska det f�rst kontrolleras om varje steg
            //�r inte p� �r plats var redan 1 finns, om ja f�r man som v�rde att v�ggen �r sp�rande
            //Om sista rutan �r fyld f�r vi att error ska visa att rutan �r inte tomt d� f�r vi att vi avbrytter funktionen, men det finns 1 check kvar

            for (int i=1; i<=steg; i++)
            {
                if (   (riktning=="u" && schackfalt[y-i][x]!=" ") || (riktning=="d" && schackfalt[y+i][x]!=" ") || (riktning=="r" && schackfalt[y][x+i]!=" ") || (riktning=="l" && schackfalt[y][x-i]!=" ")   )
                {
                    if (i!=steg)
                        error=3;
                    if (i==steg && error!=3)
                        error=2;

                    //I denna checken ska kontrolleras om sista f�ltet �r fyld (bara sista) om det blev ett pj�s fr�n motst�ndaren, om ja, d� blir error pl�tslig 0

                    if (   error!=3 &&   (   (riktning=="u" && schackfalt_pjaser[y-steg][x]==tur) || (riktning=="d" && schackfalt_pjaser[y+steg][x]==tur) || (riktning=="r" && schackfalt_pjaser[y][x+steg]==tur) || (riktning=="l" && schackfalt_pjaser[y][x-steg]==tur)   )   )
                        error=0;
                }
            }
        }

        //D� error �r 0 flyttas torn, kom ih�g att torn f�r flytta p� 4 riktningar, s� alla de 4 riktningar med spelaren �r p� tur kontrolleras hela tiden

        if (error==0)
        {
            if (riktning=="u" && tur==1)    schackfalt[y-steg][x]="R";       if (riktning=="u" && tur==2)      schackfalt[y-steg][x]="r";
            if (riktning=="d" && tur==1)    schackfalt[y+steg][x]="R";       if (riktning=="d" && tur==2)      schackfalt[y+steg][x]="r";
            if (riktning=="r" && tur==1)    schackfalt[y][x+steg]="R";       if (riktning=="r" && tur==2)      schackfalt[y][x+steg]="r";
            if (riktning=="l" && tur==1)    schackfalt[y][x-steg]="R";       if (riktning=="l" && tur==2)      schackfalt[y][x-steg]="r";
        }
    }

    //H�r kommer h�sten (N/n)
    //H�sten �r den enklaste kontrollen, d�r kontrolleras bara om den inte g�r utifr�n bordet

    if (schackfalt[y][x]=="N" || schackfalt[y][x]=="n")
    {
        if ((y+steg>7) || (y+steg<0) || (x+steg_extra>7) || (x+steg_extra<0))
            error=1;

        //H�r finns ett kontroll som kontrollerar om h�sten kommer p� ett tomt rutan eller fiendens rutan, annars

        if (error==0 && (schackfalt[y+steg][x+steg_extra]!=" " && schackfalt_pjaser[y+steg][x+steg_extra]!=tur)   )
            error=2;

        if (error==0)
        {
            if (tur==1)
                schackfalt[y+steg][x+steg_extra]="N";
            else
                schackfalt[y+steg][x+steg_extra]="n";
        }
    }

    //L�pare (B/b) funger exakt samma som Torn, men bara �r det kontrollers av de 4 diagonala riktningar ist�llet av de andra 4 riktningar

    if (schackfalt[y][x]=="B" || schackfalt[y][x]=="b")
    {
        if (   (riktning=="ur" && (y-steg<0 || x+steg>7)   ) || (riktning=="ul" && (y-steg<0 || x+steg<0)   ) || (riktning=="dr" && (y+steg>7 || x+steg>7)   ) || (riktning=="dl" && (y+steg>7 || x-steg<0)   )   )       //Om nya koordinatera kommer att bli utifr�n bordet blir ERROR = 1
            error=1;

        if (error==0)
        {
            for (int i=1; i<=steg; i++)
            {
                if (   (riktning=="ur" && schackfalt[y-i][x+i]!=" ") || (riktning=="ul" && schackfalt[y-i][x-i]!=" ") || (riktning=="dr" && schackfalt[y+i][x+i]!=" ") || (riktning=="dl" && schackfalt[y+i][x-i]!=" ")   )
                {
                    if (i!=steg)
                        error=3;
                    else
                        error=2;

                    if (   (riktning=="ur" && schackfalt_pjaser[y-steg][x+steg]==tur) || (riktning=="ul" && schackfalt_pjaser[y-steg][x-steg]==tur) || (riktning=="dr" && schackfalt_pjaser[y+steg][x+steg]==tur) || (riktning=="dl" && schackfalt_pjaser[y+steg][x-steg]==tur)   )
                        error=0;
                }
            }
        }

        if (error==0)
        {
            if (riktning=="ur" && tur==1)    schackfalt[y-steg][x+steg]="B";       if (riktning=="ur" && tur==2)      schackfalt[y-steg][x+steg]="b";
            if (riktning=="ul" && tur==1)    schackfalt[y-steg][x-steg]="B";       if (riktning=="ul" && tur==2)      schackfalt[y-steg][x-steg]="b";
            if (riktning=="dr" && tur==1)    schackfalt[y+steg][x+steg]="B";       if (riktning=="dr" && tur==2)      schackfalt[y+steg][x+steg]="b";
            if (riktning=="dl" && tur==1)    schackfalt[y+steg][x-steg]="B";       if (riktning=="dl" && tur==2)      schackfalt[y+steg][x-steg]="b";
        }
    }

    //�ven hos Drottningen (Q/q) skillnar det inte, det �r bara en kombination av de riktningar av Torn och L�pare

    if (schackfalt[y][x]=="Q" || schackfalt[y][x]=="q")
    {
        if (   (riktning=="u" && y-steg<0) || (riktning=="d" && y+steg>7) || (riktning=="r" && x+steg>7) || (riktning=="l" && x-steg<0) || (riktning=="ur" && (y-steg<0 || x+steg>7)   ) || (riktning=="ul" && (y-steg<0 || x+steg<0)   ) || (riktning=="dr" && (y+steg>7 || x+steg>7)   ) || (riktning=="dl" && (y+steg>7 || x-steg<0)   )   )       //Om nya koordinatera kommer att bli utifr�n bordet blir ERROR = 1
            error=1;

        if (error==0)
        {
            for (int i=1; i<=steg; i++)
            {
                if (   (riktning=="u" && schackfalt[y-i][x]!=" ") || (riktning=="d" && schackfalt[y+i][x]!=" ") || (riktning=="r" && schackfalt[y][x+i]!=" ") || (riktning=="l" && schackfalt[y][x-i]!=" ") || (riktning=="ur" && schackfalt[y-i][x+i]!=" ") || (riktning=="ul" && schackfalt[y-i][x-i]!=" ") || (riktning=="dr" && schackfalt[y+i][x+i]!=" ") || (riktning=="dl" && schackfalt[y+i][x-i]!=" ")   )
                {
                    if (i!=steg)
                        error=3;
                    else
                        error=2;

                    if (   (riktning=="u" && schackfalt_pjaser[y-steg][x]==tur) || (riktning=="d" && schackfalt_pjaser[y+steg][x]==tur) || (riktning=="r" && schackfalt_pjaser[y][x+steg]==tur) || (riktning=="l" && schackfalt_pjaser[y][x-steg]==tur) || (riktning=="ur" && schackfalt_pjaser[y-steg][x+steg]==tur) || (riktning=="ul" && schackfalt_pjaser[y-steg][x-steg]==tur) || (riktning=="dr" && schackfalt_pjaser[y+steg][x+steg]==tur) || (riktning=="dl" && schackfalt_pjaser[y+steg][x-steg]==tur)   )
                        error=0;
                }
            }
        }

        if (error==0)
        {
            if (riktning=="ur" && tur==1)    schackfalt[y-steg][x+steg]="Q";         if (riktning=="ul" && tur==1)    schackfalt[y-steg][x-steg]="Q";
            if (riktning=="dr" && tur==1)    schackfalt[y+steg][x+steg]="Q";         if (riktning=="dl" && tur==1)    schackfalt[y+steg][x-steg]="Q";
            if (riktning=="u" && tur==1)    schackfalt[y-steg][x]="Q";               if (riktning=="d" && tur==1)    schackfalt[y+steg][x]="Q";
            if (riktning=="r" && tur==1)    schackfalt[y][x+steg]="Q";               if (riktning=="l" && tur==1)    schackfalt[y][x-steg]="Q";

            if (riktning=="ur" && tur==2)      schackfalt[y-steg][x+steg]="q";       if (riktning=="ul" && tur==2)      schackfalt[y-steg][x-steg]="q";
            if (riktning=="dr" && tur==2)      schackfalt[y+steg][x+steg]="q";       if (riktning=="dl" && tur==2)      schackfalt[y+steg][x-steg]="q";
            if (riktning=="u" && tur==2)      schackfalt[y-steg][x]="q";             if (riktning=="d" && tur==2)      schackfalt[y+steg][x]="q";
            if (riktning=="r" && tur==2)      schackfalt[y][x+steg]="q";             if (riktning=="l" && tur==2)      schackfalt[y][x-steg]="q";
        }
    }

    //Kungen (K/k) fungerar det samma som drottningen
    //Men det finns bara 2 skillnader, den kan bara r�ra sig 1 steg, s� det bara kontrolleras om rutan �r fritt och inte v�ggen
    //Det andra �r att det kontrolleras om rockaden kan utf�ras (att v�ggen �r fritt mellan rockaden) och att den kan utf�ra rockaden med 1 torn
    //Ocks� om rockaden g�r inte skrivs det ut error = 4, ett nytt v�rde

    if (schackfalt[y][x]=="K" || schackfalt[y][x]=="k")
    {
        if (   (riktning=="u" && y-1<0) || (riktning=="d" && y+1>7) || (riktning=="r" && x+1>7) || (riktning=="l" && x-1<0) || (riktning=="ur" && (y-1<0 || x+1>7)   ) || (riktning=="ul" && (y-1<0 || x+1<0)   ) || (riktning=="dr" && (y+1>7 || x+1>7)   ) || (riktning=="dl" && (y+1>7 || x-1<0)   )   )
            error=1;

        if (error==0)
        {
            if (   (riktning=="u" && schackfalt[y-1][x]!=" ") || (riktning=="d" && schackfalt[y+1][x]!=" ") || (riktning=="r" && schackfalt[y][x+1]!=" ") || (riktning=="l" && schackfalt[y][x-1]!=" ") || (riktning=="ur" && schackfalt[y-1][x+1]!=" ") || (riktning=="ul" && schackfalt[y-1][x-1]!=" ") || (riktning=="dr" && schackfalt[y+1][x+1]!=" ") || (riktning=="dl" && schackfalt[y+1][x-1]!=" ")   )
                    error=2;

            //I fallet du gl�mde, f�rst kontrolleras om rutan �r fritt, sen kontrolleras om rutan �r fr�n motst�ndaren, om det sista st�mmer blir error alltid 0

            if (   (riktning=="u" && schackfalt_pjaser[y-1][x]==tur) || (riktning=="d" && schackfalt_pjaser[y+1][x]==tur) || (riktning=="r" && schackfalt_pjaser[y][x+1]==tur) || (riktning=="l" && schackfalt_pjaser[y][x-1]==tur) || (riktning=="ur" && schackfalt_pjaser[y-1][x+1]==tur) || (riktning=="ul" && schackfalt_pjaser[y-1][x-1]==tur) || (riktning=="dr" && schackfalt_pjaser[y+1][x+1]==tur) || (riktning=="dl" && schackfalt_pjaser[y+1][x-1]==tur)   )
                    error=0;
        }

        if (error==0)
        {
            if (riktning=="ur" && tur==1)    schackfalt[y-1][x+1]="K";         if (riktning=="ul" && tur==1)    schackfalt[y-1][x-1]="K";
            if (riktning=="dr" && tur==1)    schackfalt[y+1][x+1]="K";         if (riktning=="dl" && tur==1)    schackfalt[y+1][x-1]="K";
            if (riktning=="u" && tur==1)    schackfalt[y-1][x]="K";            if (riktning=="d" && tur==1)    schackfalt[y+1][x]="K";
            if (riktning=="r" && tur==1)    schackfalt[y][x+1]="K";            if (riktning=="l" && tur==1)    schackfalt[y][x-1]="K";

            if (riktning=="ur" && tur==2)      schackfalt[y-1][x+1]="k";       if (riktning=="ul" && tur==2)      schackfalt[y-1][x-1]="k";
            if (riktning=="dr" && tur==2)      schackfalt[y+1][x+1]="k";       if (riktning=="dl" && tur==2)      schackfalt[y+1][x-1]="k";
            if (riktning=="u" && tur==2)      schackfalt[y-1][x]="k";          if (riktning=="d" && tur==2)      schackfalt[y+1][x]="k";
            if (riktning=="r" && tur==2)      schackfalt[y][x+1]="k";          if (riktning=="l" && tur==2)      schackfalt[y][x-1]="k";

            if (riktning=="rx" || riktning=="lx")
            {
                if (tur==1 && riktning=="rx" && schackfalt[7][5]==" " && schackfalt[7][6]==" ")
                {
                    schackfalt[7][6]="K";
                    schackfalt[7][5]="R";
                    schackfalt[7][7]=" ";
                }
                else if (tur==1 && riktning=="lx" && schackfalt[7][1]==" " && schackfalt[7][2]==" " && schackfalt[7][3]==" ")
                {
                    schackfalt[7][2]="K";
                    schackfalt[7][3]="R";
                    schackfalt[7][0]=" ";
                }
                else if (tur==2 && riktning=="rx" && schackfalt[0][5]==" " && schackfalt[0][6]==" ")
                {
                    schackfalt[0][6]="k";
                    schackfalt[0][5]="r";
                    schackfalt[0][7]=" ";
                }
                else if (tur==2 && riktning=="lx" && schackfalt[0][1]==" " && schackfalt[0][2]==" " && schackfalt[0][3]==" ")
                {
                    schackfalt[0][2]="k";
                    schackfalt[0][3]="r";
                    schackfalt[0][0]=" ";
                }
                else
                    error=4;
            }
        }
    }

    //Nu skrivs ut de olika error (om error �r inte 0 sj�lvklart), l�s bredvid f�r de olika betydelse

    if (error>0)
    {
        cout<<"\a"<<endl;
        cout<<" Du kan inte flytta pj\204sen! ";                                    //Allm�nt varning att flyttning g�r inte med ljudsignal
        if (error==1)                                                               //ERROR 1 = Bonden f�rs�kte g�r utifr�n bordet
            cout<<"Den kan inte g\204r utifr\206n bordet!";
        if (error==2)                                                               //ERROR 2 = Platsen var pj�sen ska flyttar till �r inte tomt
            cout<<"Det finns en annan pj\204s d\204r!";
        if (error==3)                                                               //ERROR 3 = V�ggen som pj�sen tar �r inte tomt
            cout<<"V\204ggen \204r sp\204rrade!";
        if (error==4)
            cout<<"Rockaden \204r inte tillg\204nglig!";                            //ERROR 4 = Rockaden �r inte tillg�nglig
        cout<<"   -   F\224rs\224k om!";                                            //Och ett allm�nt varning f�r att g�ra om
        cin.ignore(); cin.ignore();
        //Och hela funktionen startar om om error �r inte 0
        ROR_OBJEKT(schackfalt, schackfalt_pjaser, steg, steg_extra, x, y, riktning, x_str, y_str, tur, error, spelare1, spelare2, antal_satt_tur1, antal_satt_tur2, rockad_tur1, rockad_vanster_tur1, rockad_hoger_tur1, rockad_tur2, rockad_vanster_tur2, rockad_hoger_tur2);      //G�r om funktionen om ERROR > 0

    }

    //S� om programmet kunde klara hele funktionen utan error slutligen blev 0 kan den avsluta funktionen med sista saters och b�rja med de n�sta
    //F�rst bytta spelare sin tur till den andra spelare, s� den f�r k�ra
    //Sen h�jas antalet s�tt den spelare gjorde med 1 som man kan ser tillbaka i po�nglistan
    //Och till sist h�r man ett ljud och blir sk�rmet tomt

    if (error==0)
    {
        schackfalt[y][x]=" ";
        if (tur==1)
        {
            antal_satt_tur1+=1;
            tur=2;
        }
        else
        {
            antal_satt_tur2+=1;
            tur=1;
        }

        cout<<"\a";
        system("cls");
    }
}




void LASA_REGLARNA() //Lasa_reglarna funktionen
{
    //Denna funktionen skriver bara ut text som hj�lper man att f�rst� schackreglar och RobSchack systemet
    //Det beh�vs bara att klicka p� enter att kunna k�ra vidare

    cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;

    cout<<" BETECKNING AV PJ\216SER\n ------------------------------"<<endl;
    cout<<" K / k\t\tKung\t\t1 styck\t\tO\204ndlig antal po\204ng"<<endl;
    cout<<" Q / q\t\tDrottning\t1 styck\t\t9 po\204ng"<<endl;
    cout<<" R / r\t\tTorn\t\t2 stycken\t5 po\204ng"<<endl;
    cout<<" N / n\t\tH\204st\t\t2 stycken\t3 po\204ng"<<endl;
    cout<<" B / b\t\tL\224pare\t\t2 stycken\t3 po\204ng"<<endl;
    cout<<" P / p\t\tBonde\t\t8 stycken\t1 po\204ng"<<endl<<endl;
    cout<<" Om man sl\206r en pj\204s blir det inte sparats i po\204nglistan, det bara visa vilka\n pj\204ser har ett h\224gre prioritet att sl\206"<<endl<<endl<<endl<<endl<<endl;

    cout<<" HUR ATT SPELA\n ------------------------------"<<endl;
    cout<<" 1. Mata in koordinater av en pj\204s, f\224rst siffra koordinaten, sen bokstav\n    koordinaten"<<endl<<endl;
    cout<<" 2. Om du vill avsluta spelet mata in 0 i b\206da koordinater"<<endl<<endl;
    cout<<" 3. Om en pj\204s \204r selekterad, l\204s genom instruktionerna och mata in som st\206r\n    beskrivet d\204r f\224r att kunna r\224ra den"<<endl<<endl;
    cout<<" 4. Mata in minst en 0 (inom antal steg, riktning eller n\206got annat) f\224r att\n    annulera selekteringen av pj\204sen"<<endl<<endl;
    cout<<" 5. F\224r inmattning av mer \204n 1 variabel (tex. 2 koordinater) kr\204vs det mellan\n    varje variabel ett mellanslag"<<endl<<endl;
    cout<<" 6. N\204r din kung d\224r \206r spelet \224ver och vinner motst\206ndaren"<<endl<<endl;
    cout<<" 7. Om din pj\204s kan inte r\224ra sig att du m\206ste v\204lja en annan"<<endl<<endl;
    cout<<" 8. N\204r man ska r\224ra h\204sen f\206r man bara mata in 2 olika tal\n    (negativt och postivt ber\204cknas som samma tal)"<<endl<<endl;
    cout<<" 9. Du kan inte hoppa f\224rbi pj\204ser (utom h\204sten), \204ven om de attackerar, v\204lj\n    d\206 motst\206ndarens koordinater"<<endl<<endl;
    cout<<" 10. N\206gra inmatningar bara syns n\204r det kan utf\224ras, om en inmatning inte syns\n     kan pj\204sen inte utf\224ra detta"<<endl<<endl<<endl<<endl<<endl;

    cout<<" F\231RTECKNINGAR AV F\231RKORTNINGAR\n ------------------------------"<<endl;
    cout<<" Det f\224jande kan blir inmattad, men inte allt g\204ller f\224r en pj\204s"<<endl;
    cout<<" Kolla alltid p\206 instruktionerna n\204r du v\204ljer en pj\204s!"<<endl<<endl;
    cout<<" u = uppe            ur = uppe + h\224ger"<<endl;
    cout<<" d = nere            ul = uppe + v\204nster"<<endl;
    cout<<" r = h\224ger           dr = nere + h\224ger"<<endl;
    cout<<" l = v\204nster         dl = nere + v\204nster"<<endl<<endl;
    cout<<" Om bonden selekterad g\204ller l = v\204nsterattackering och r = h\224gerattackering"<<endl<<endl;
    cout<<" Siffrorna kan blir inmattade (men inte hos alla pj\204ser)"<<endl<<" Tecknet <-> betyder till och med"<<endl<<" Tex. 0 <-> 2 betyder 0 till och med 2 f\206r blir inmattad"<<endl<<endl;
    cout<<" Minst en 0 = Annulera inmatning av pj\204sen"<<endl;
    cout<<" 0 0 = Ger upp matchen, mots\206ndaren kommer at vinna d\206"<<endl<<endl;

    cout<<" Om det kr\204vs att mata in y/n, mata d\206 in bokstaven y eller n"<<endl;
    cout<<" y = ja              n = nej"<<endl<<endl<<endl<<endl<<endl;

    cout<<" SPECIELLA REGLAR\n ------------------------------"<<endl;
    cout<<" < Rockad >"<<endl;
    cout<<" Mata in kungen och sen mata in x1 eller x2 om det syns p\206 sk\204rmet f\224r att\n bytta plats"<<endl<<endl;
    cout<<" 1. Kungen m\206ste aldrig ha r\224rt sig"<<endl<<endl;
    cout<<" 2. Tornet som Kungen ska bytta med f\206r ocks\206 inte r\224ra sig"<<endl<<endl;
    cout<<" 3. Alla rutor mellan Tornen och Kungen ska vara tomt"<<endl<<endl;
    cout<<" 4. Det f\206 bara vara 1 rockad f\224r varje spelare i spelet"<<endl<<endl;
    cout<<" 5. N\204r de bytter plats kommer b\206da Kungen och Tornet st\206r 1 steg framf\224r den\n    nya platsen"<<endl<<endl<<endl;

    cout<<" < Omvandling av b\224nder >"<<endl;
    cout<<" N\204r en bonde ska n\206s sista rutan fr\206gas efter vilken pj\204s spelaren vill bytta\n den f\224r, kolla p\206 instruktionerna hur man ska inmata detta"<<endl<<endl;
    cout<<" 1. Man kan bara mata in f\224r en ny Torn, L\224pare, H\204st eller Drottning"<<endl<<endl;
    cout<<" 2. F\224r spelare 1 g\224ller att bonden ska n\206s rad 1, f\224r spelare 2 blir det rad 8"<<endl<<endl<<endl;

    cout<<" < En Passant >"<<endl;
    cout<<" N\204r en bonde ska flyttas 2 steg i ett tur d\206 kan en bonde av den andra spelare\n sl\206 den i n\204sta tur som om den hade bara hoppat 1 steg"<<endl<<endl;
    cout<<" 1. Den bonde som ska sl\206 kommer d\206 att sl\206 som vanlig, men bonden som hoppade\n    2 steg f\224rsvinner"<<endl<<endl;
    cout<<" 2. Om man kan anv\204nda denna regeln kommer man att ser r (h\224gerattackering)\n    eller n (v\204nsterattackering), d\206 kan man attackera genom denna regeln"<<endl<<endl<<endl;

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<" Klicka p\206 Enter f\224r att returnera till huvudmeny";

    cin.ignore();
}





void ANDRA_SPELARE(string spelare1, string spelare2) //Andra_spelare funktionen
{
    //I denna funktionen ska man mata in de namn av de 2 spelare, som sparas i filen "spelare.txt", som blir anv�nds i spelet och po�nglistan
    //Sen bara enter och man �r tillbaka i huvudfunktionen

    cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;

    cout<<" \216ndra namn p\206 spelare 1: ";
    getline(cin,spelare1);
    cout<<"\a";
    cout<<" \216ndra namn p\206 spelare 2: ";
    getline(cin,spelare2);
    cout<<"\a";

    ofstream utfil;
    utfil.open("spelare.txt");
    utfil<<spelare1<<endl;
    utfil<<spelare2<<endl;
    utfil.close();

    cout<<endl<<" De nya namn \204r sparats!";
    cout<<endl<<endl<<" Klicka p\206 Enter f\224r att returnera till huvudmeny";
    cin.ignore();
}



void RADERA_POANGLISTAN() //Radera_po�nglistan funktionen
{
    //I denna funktionen fr�ga systemet om anv�nderen vill radera po�nglistan, s� att filen "scorelistan.txt" blir tomt, det kr�vs en inmatning av y (ja) eller n (nej)
    //Sen bara enter och huvudfunktionen �r tillbaka

    string radera_score;

    while (radera_score.size()!=1 || (radera_score!="y" && radera_score!="n"))
    {
        system("cls");
        cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;    //Skrivs ut text p� sk�rmet

        cout<<" \216r du s\204kert att radera po\204nglistan? Mata in y/n: ";
        cin>>radera_score;
        cout<<"\a";

        if (radera_score.size()==0 || (radera_score!="y" && radera_score!="n"))
        {
            cout<<endl<<" Fel inmatning!"<<endl;
            cout<<" Bara mata in y eller n!"<<endl;
            cout<<" F\224rs\224k om g\204rna!"<<endl;
            cin.ignore(); cin.ignore();
        }
    }

    if (radera_score=="y")
    {
        ofstream utfil;
        utfil.open("scorelistan.txt");
        utfil.close();
        cout<<endl<<" Po\204nglistan \204r raderad nu!"<<endl<<endl;
    }
    if (radera_score=="n")
        cout<<endl<<" Po\204nglistan blev sparad!"<<endl<<endl;

    cout<<" Klicka p\206 Enter f\224r att returnera till huvudmeny";
    cin.ignore(); cin.ignore();
}



void VISA_POANGLISTAN() //Visa_scorelistan funktionen
{
    //I denna funktionen laddas in data fr�n filen "scorelistan.txt" och skrivs de ut p� sk�rmen, s� att man ser po�nglistan
    //Och igen.. Enter = tillbaka p� huvudfunktionen

    cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;   //Skrivs ut text p� sk�rmet

    string score_str;
    int score_cout=1, score_tal=1;

    ifstream infil;
    infil.open("scorelistan.txt");
    while(infil>>score_str) //Forts�tter s� l�nge det finns data kvar
    {
        if (score_cout==1)
        {
            cout<<" Sparade po\204ngnummer "<<score_tal<<endl<<endl;
            cout<<" Spelare:        "<<score_str<<endl;
            score_cout=2;
        }
        else
        {
            cout<<" Antal s\204tter:   "<<score_str<<endl<<endl<<endl<<endl;
            score_cout=1;
            score_tal+=1;
        }
    }
    infil.close();

    cout<<" Klicka p\206 Enter f\224r att returnera till huvudmeny";
    cin.ignore();
}



void SPELET_FARDIGT(int tur, string spelare1, string spelare2, int antal_satt_tur1, int antal_satt_tur2, int vinna_spelet) //Spelet_fardigt funktionen
{
    //Denna funktionen sk�rs n�r kungen av n�gon finns inte l�ngre p� schackf�ltet, eller om man matade in 0 0 p� koordinater (som betydder avbrytta)
    //F�rst kontrolleras om verkligen n�gon kung d�g (+ att data resetas och avspelas ett ljud)

    string spara_score;
    cout<<"\a";                                                                     //Sk�rmet blir tomt med ljudsignal

    if (vinna_spelet==0)
    {
        //Tyv�rr, ingen kung d�g, s� ingen po�ng blir sparats i po�nglistan, men n�gon vann allts�, gratz till den

        system("cls");
        cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;

        if (tur==1)
            cout<<" Grattis!"<<endl<<endl<<" Du har vunnit "<<spelare2<<" f\224r att "<<spelare1<<" gav upp"<<endl<<endl;
        if (tur==2)
            cout<<" Grattis!"<<endl<<endl<<" Du har vunnit "<<spelare1<<" f\224r att "<<spelare2<<" gav upp"<<endl<<endl;

        cout<<endl<<" Tyv\204rr blir ingen po\204ng sparats i po\204nlistan f\224r att din motst\206ndarens\n kung fortforande lever"<<endl;

    }

    if (vinna_spelet>0)
    {
        //Gratz f�r den som vann, f�r motst�ndarens kung d�g, ocks� blir fr�gats om du vill spara po�ng i po�nglistan
        //D�rf�r kr�vs det inmatning av y (ja) eller n (nej)

        while (spara_score.size()!=1 || (spara_score!="y" && spara_score!="n"))
        {
            system("cls");
            cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;    //Skrivs ut text p� sk�rmet

            if (vinna_spelet==1)
            {
                cout<<" Grattis!"<<endl<<endl<<" Du har vunnit "<<spelare1<<" f\224r att "<<spelare2<<" gav upp"<<endl<<endl;
                cout<<" Din score (antal s\204tt du gjordes) \204r: "<<antal_satt_tur1<<endl<<endl;
            }
            if (vinna_spelet==2)
            {
                cout<<" Grattis!"<<endl<<endl<<" Du har vunnit "<<spelare2<<" f\224r att "<<spelare1<<" gav upp"<<endl<<endl;
                cout<<" Din score (antal s\204tt du gjordes) \204r: "<<antal_satt_tur2<<endl<<endl;
            }

            cout<<endl<<endl<<" Vill du spara din po\204ng? Mata in y/n: ";
            cin>>spara_score;
            cout<<"\a";

            if (spara_score.size()==0 || (spara_score!="y" && spara_score!="n"))
            {
                cout<<endl<<" Fel inmatning!"<<endl;
                cout<<" Bara mata in y eller n!"<<endl;
                cout<<" F\224rs\224k om g\204rna!"<<endl;
                cin.ignore(); cin.ignore();
            }
        }

        //S� om inmatningen blev y ska vinnarens po�ng sparats i filen "scorelistan.txt", det bara tilllas

        if (spara_score=="y")
        {
            int antal_satt_win;
            string spelare_win;
            if (vinna_spelet==1)
            {
                spelare_win=spelare1;
                antal_satt_win=antal_satt_tur1;
            }
            if (vinna_spelet==2)
            {
                spelare_win=spelare2;
                antal_satt_win=antal_satt_tur2;
            }
            cout<<endl<<" Dina po\204ng blev sparats"<<endl<<endl;
            ofstream utfil;
            utfil.open("scorelistan.txt", ios::app);
            utfil<<endl<<spelare_win;
            utfil<<endl<<antal_satt_win;
            utfil.close();
        }
    }
    //Och om inmatningen �r n sparats det inga po�ng i po�nglistan

    if (spara_score=="n")
        cout<<endl<<" Ingen po\204ng blir sparats"<<endl<<endl;

    //Och h�r ska programmet skriva ut sina sista meningar p� sk�rmet innan den avslutats genom huvudfunkionen (om man vinner avslutet spelet, �ven om n�gon gav upp)

    cin.ignore(); cin.ignore();
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<" Tack f\204r att spela RobSchack!"<<endl<<endl<<" Tills n\204sta g\206ng!"<<endl;
    cout<<endl<<endl<<endl<<" Klicka p\206 n\206gon knapp f\224r att st\204nga av programmet"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}





int main() //huvudfunktionen
{
    //H�r b�rjar programmet allts�, och tillas alla variabler, int och string, kan du f�rs�ka hitta de alla i koden? �ven i n�gra funktioner skrivs det ut n�gra temp variabler

    int error, steg=0, steg_extra=0, x=1, y=1, tur=1, schackfalt_pjaser[8][8], antal_satt_tur1=0, antal_satt_tur2=0, vinna_spelet=0;
    string val, spelare1, spelare2, schackfalt[8][8], x_str, y_str, riktning;
    int rockad_tur1=0, rockad_vanster_tur1=0, rockad_hoger_tur1=0, rockad_tur2=0, rockad_vanster_tur2=0, rockad_hoger_tur2=0;

    //H�r ska allts� laddas in data fr�n filen "spelare.txt" s� programmet vet vem ska k�ra mot vem

    ifstream infil("spelare.txt");
    infil>>spelare1;
    infil>>spelare2;
    infil.close();

    //H�r b�rjar programmet riktig och k�rs det funktionen Huvudmeny (som g�rs bara text)

    HUVUDMENY();

    //D�refter kommer allts�funktionen Meny som ska fr�ga anv�ndaren efter vilken mode den ska aktiveras
    //programmet kan k�ra spelet, �ndra de namn, visa po�nglistan, radera po�nglistan, l�sa genom spelreglar och avsluta progammet

    while (val!="0")
    {
        //H�r ska aktiveras en while-loop, s� att vi kan v�lja hela tiden en mode efter en mode �r f�rdig (de funktioner som anr�pas genom val kallas mode)

        MENY(val);

        //Om val blir 1 d� k�rs spelet riktig, det b�rjar allts� med all bygga up schackf�ltet, men den k�rs bara 1 g�ng

        if (val=="1")
            BYGGA_SCHACKFALT(schackfalt);

        //Sen en ny while-loop som s� riktig o�ndligt, om man ska spela spelet k�ra den o�ndligt tills spelet �r f�rdigt (genom Spelet_fardigt funktionen)
        //Och det finns ingen m�jlighet sen att komma tillbaka p� meny, d� m�ste man starta om programmet
        //Loopen �r o�ndlig f�r att programmet kommer aldrig att �ndra v�rden p� val n�r man k�r mode 1 (spelet allts�)

        while (val=="1")
        {
            //F�rst med varje varv resetas error till 0, mycket viktig allts�, om error �r inte 0 d� kan n�stan ingen funktion k�ra vidare

            error=0;

            //D�refter anr�pas alla funktioner i f�lj f�r att kunna spela spelet, n�gra funktioner anr�per ocks� funktioner inom funktionen

            SKRIV_UT_FALT(schackfalt, tur, spelare1, spelare2);
            MATA_KOORDINATER(schackfalt, error, x, y, x_str, y_str, tur, vinna_spelet);

            //H�r finns det en snabbkontroll om a) b�da kungar lever   b) n�gon matade in 0 0 p� koordinater
            //Om ett av de st�mmer anr�pas funktionen Spelet_fardigt och sen anv�nds det return 0 (s� spelet ska avsluta)

            if (   (x_str=="0" && y_str=="0") || vinna_spelet>0)
            {
                SPELET_FARDIGT(tur, spelare1, spelare2, antal_satt_tur1, antal_satt_tur2, vinna_spelet);
                return 0;
            }

            //En sista kontroll h�r om error �r fortfarande 0, annars �r inga pj�s selekterads och k�rs funktionen om (den finns i en while loop som slutar aldrig)

            if (error==0)
            {
                error=1;
                BYGGA_SCHACKFALT_PJASER(schackfalt, schackfalt_pjaser, tur);
                ROR_OBJEKT(schackfalt, schackfalt_pjaser, steg, steg_extra, x, y, riktning, x_str, y_str, tur, error, spelare1, spelare2, antal_satt_tur1, antal_satt_tur2, rockad_tur1, rockad_vanster_tur1, rockad_hoger_tur1, rockad_tur2, rockad_vanster_tur2, rockad_hoger_tur2);
            }
        }

        //Och h�r anr�pas n�gra kortare funktioner (de �vriga mode), efter den funktionen �r f�rdigt kommer programmet tillbaka p� b�rjan av loopen

        if (val=="2")
            LASA_REGLARNA();
        if (val=="3")
            ANDRA_SPELARE(spelare1, spelare2);
        if (val=="4")
            VISA_POANGLISTAN();
        if (val=="5")
            RADERA_POANGLISTAN();
    }

    //Och den allra sisten koden referar till om val blir 0, s� avslutas spelet ocks�, s� man beh�ver inte k�ra f�rdigt hela spelet, detta h�r anr�pas genom funktioen Meny enkelt

    if (val=="0")
    {
        cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;
        cout<<endl<<" Tack f\204r att spela RobSchack!"<<endl<<endl<<" Tills n\204sta g\206ng!"<<endl;
        cout<<endl<<endl<<endl<<" Klicka p\206 n\206gon knapp f\224r att st\204nga av programmet"<<endl<<endl<<endl;
        return 0;
    }
}
