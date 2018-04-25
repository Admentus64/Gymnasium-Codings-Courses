#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std; //Läggs till allt som behövs att kunna köra programmet



void HUVUDMENY() //Huvudmeny funktionen
{
    //I denna funktionen vissas text på skärmen och avspelar sig ett ljud. Man ska klicka på Enter att köra vidare

    cout<<endl<<" ======================="<<endl<<" === V\204lkommen till ===="<<endl<<" ====== RobSchack ======"<<endl<<" ======================="<<endl<<endl<<endl;
    cout<<"\a";
    cout<<" Klicka p\206 Enter f\224r att starta spelet!";
    cin.ignore();
}



void MENY(string& val) //Meny funktionen
{
    //I denna funktionen ska man matta in värdet "val", det kommer att läggas en kontroll på detta om man matade in rätt
    //Varje gång när denna funktionen skärs resettar "val", spelas det ett ljud och blir skärmen tom
    //Genom denna funktion kan man anröpa de andra funktioner
    //När denna funktion är färdig blir skärmen tom igen

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
        getline(cin,val); //Användare kan mata in en värde
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
    //I denna funktionen indelas schackfaltet med alla pjäserna som behövs på startposition, resten är då tomt

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            schackfalt[i][j]=" "; //Läggs till ett tomt ruta

    schackfalt[7][4]="K"; //Kung           //Spelare 1 använder stora bokstaver, vi börjar ligga till den först
    schackfalt[7][3]="Q"; //Drottning
    schackfalt[7][0]="R"; schackfalt[7][7]="R"; //Torn
    schackfalt[7][1]="N"; schackfalt[7][6]="N"; //Häst
    schackfalt[7][2]="B"; schackfalt[7][5]="B"; //Löpare
    for (int j=0;j<8;j++)
        schackfalt[6][j]="P"; //Bonden

    schackfalt[0][4]="k"; //Kung           //Spelare 2 använder mindra bokstaver, vi börjar ligga till den sist
    schackfalt[0][3]="q"; //Drottning
    schackfalt[0][0]="r"; schackfalt[0][7]="r"; //Torn
    schackfalt[0][1]="n"; schackfalt[0][6]="n"; //Häst
    schackfalt[0][2]="b"; schackfalt[0][5]="b"; //Löpare
    for (int j=0;j<8;j++)
        schackfalt[1][j]="p"; //Bonden
}





void SKRIV_UT_FALT(string schackfalt[8][8], int tur, string spelare1, string spelare2) //Skriv_ut_falt funktionen
{
    //I denna funktionen skrivs schackfältet ut som en cout (den av föra funktionen)
    //Också skrivs ut vems tur det är, coutet skrivs ut genom en lista som går 8*8 (64 fält)
    //Denna funktionen består nästan bara av coututskrivning, också beräknas det på för varje rad den tillas vilken rad det blir (varje rad får en siffrabeteckning)
    //Också får varje linje en bokstavbeteckning, men det är lättare för att det bara behövs att tillla en cout efter sista raden
    //Det sista den gör är att skriva ut (genom en beräkning) vems tur det är

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
    //I denna funktionen kontrolleras det om någons kung fortfarande finns med på schackfältet
    //Om det är inte så kommer det att returna ett värde varmed vi vet som vann
    //Om denna kontroll skärs när spelare 1 är på tur kommer spelare 2 att vinna, och tvärtom

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
    //I denna funktionen ska den som är på tur mata in koordinaterna som bestämmer vilken pjäs ska röras
    //Det finns en kontroll i fallet koordinater stämmer inte (inte din pjäs, utanfår bordet, tomt ruta), då måste det göras om

    cout<<"0 0 = uppge\n\n Mata in koordinaterna: ";

    KUNG_CHECK(schackfalt, tur, vinna_spelet);
    if (vinna_spelet>0)
        return;

    //Här mattas in koordinater

    cin>>x_str>>y_str;

    //Här finns den kontrollen

    if (x_str=="a")   x=0;   else if (x_str=="b")   x=1;   else if (x_str=="c")   x=2;   else if (x_str=="d")   x=3;
    else if (x_str=="e")   x=4;   else if (x_str=="f")   x=5;   else if (x_str=="g")   x=6;   else if (x_str=="h")   x=7;
    else error=1;

    if (y_str=="1")   y=7;   else if (y_str=="2")   y=6;   else if (y_str=="3")   y=5;   else if (y_str=="4")   y=4;
    else if (y_str=="5")   y=3;   else if (y_str=="6")   y=2;   else if (y_str=="7")   y=1;   else if (y_str=="8")   y=0;
    else error=1;

    //Om inmatning är på båda värder 0 ska programmet till avslutingsfunktionen

    if (x_str=="0" && y_str=="0")
        return;

    //Kontroll om man äger pjäsen

    if (error==0)
    {
        if (   (tur==1) && (schackfalt[y][x]=="k" || schackfalt[y][x]=="q" || schackfalt[y][x]=="n" || schackfalt[y][x]=="r" || schackfalt[y][x]=="b" || schackfalt[y][x]=="p")   )
            error=2;
        if (   (tur==2) && (schackfalt[y][x]=="K" || schackfalt[y][x]=="Q" || schackfalt[y][x]=="N" || schackfalt[y][x]=="R" || schackfalt[y][x]=="B" || schackfalt[y][x]=="P")   )
            error=2;

        if (schackfalt[y][x]==" ")
            error=3;
    }

    //Varje kontroll betecknas med ett värde i "error", om error på slutet är 0 då finns det ingen fel, om det blir ingen 0 då måste funktionen göras om
    //Denna regeln med "error" gäller överallt

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
    //Detta är osynligt hemlig schackfält som kopieras alla värde från det vanliga schackfält, den endaste skillnaden är att:
    //Alla pjäser av spelare 1 betecknas med 2 och av spelare 2 med 1
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
    //I denna funktionen kontrolleras om man får fortfarande använda Rockaden (att byta kungen med en torn)
    //Den skickas olika värder tillbaka till andra funktioner så programmet vet den spelare får göra det
    //Standard är de värde 0 (betydder får göra), men om kungen och torn har rörat sig från startpostion blir den värde 1

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
    //I denna funktionen kontrolleras om alla pjäser utfom för hästen (N/n, den för hoppa över allt) kan minst röra sig på 1 hål
    //Det kontrolleras genom den hemlig schackbordet (den kopia som räcknar i 1 och 2) för att det krävs mindre if-satser
    //Varje riktning som inte går adderas move_check med ett värde, alla hål tillsammans är 8, om move_check blir då 8 kan pjäsen inte röra sig
    //Varje gång denna funktionen skärs resettas move_check

    int move_check=0;

    //En konstig grej nu, schackfalt_pjaser är baserande på 3 olika tal, varav spelare 1 är 2, spelare 2 är 1 och resten är 0
    //För att kunna köra denna kontroll bytter vi tur bara, men den sparas inte, så efter funktionen blir tur den gamla värde

    if (tur==1)
        tur=2;
    else
        tur=1;

    //Och här körs de olika pjäser på kontroll

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

    //För att kungen och drottningen har samma rörelsesätt kontrolleras de båda i 1 kontroll

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

    //Och om move_check är 8 får spelare error medelande, funktionen Rora_objekt körs vidaren, men ska köras om

    if (move_check==8)
    {
        error=2;
        //Error blir 2 så att i funktioen Rora_objekt den inte behövs köra de följande funktioner men direkt kan köra om
        cout<<"0 0 = uppge";
        cout<<endl<<endl<<" Det finns ingen m\224jlighet att flytta denna pj\204sen! V\204lj en annan!";
        cin.ignore(); cin.ignore();
        return;
    }
    //Annars blir error 0 och kan funktionen Rora_objekt köra vidare
    else
        error=0;
}



void MATA_STEG(string schackfalt[8][8], int schackfalt_pjaser[8][8], int tur, int& steg, int& steg_extra, string& riktning, int x, int y, string x_str, string y_str, int& error, int rockad_tur1, int rockad_vanster_tur1, int rockad_hoger_tur1, int rockad_tur2, int rockad_vanster_tur2, int rockad_hoger_tur2)
//Mata_steg funktionen
{
    //I denna funktionen ska mattas in hur du ska röra den pjäsen om selekterades
    //Den skär i olika steg, först alltså ett värde reset
    //Och skärminfomation
    //Kom ihåg att errror resetas till 0 för att i den föra funktionen kom på 0 (om den var 1 körde denna funktionen inte)

    string steg_str="a", steg_extra_str="a";
    steg=10, steg_extra=10;
    error=1;

    cout<<"0 = G\224ra om   -   ";
    cout<<"Du selekterade: "<<schackfalt[y][x]<<", "<<x_str<<y_str<<endl;

    //Bonden altså (P/p) som blev selekterads, bonde kontrolleras genom att bara antalet steg ska mattas in, som berör av din position
    //Det skrivs också ut instruktionerna berörande vad bonden får göra

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

        //Nu skärs alla kontroll, om steg är 0, eller om antalet steg man mattade in stämmer, eller om position gäller, eller om vi kan attackara någon

        if (steg_str=="0")
            steg=0;
        if (steg==0)
            return;

        if (steg_str=="1")
            steg=1;
        if (steg_str=="2")
            if (   (y==6 && tur==1) || (y==1 && tur==2)   )
                steg=2;

        //Attackering betecknas med "steg" 3 och 4 istället av r och l, bättre att behålla kvar det som en int värde

        if (steg_str=="l" && x!=0 && (   ((schackfalt_pjaser[y-1][x-1]==1 || schackfalt_pjaser[y-1][x-1]==11) && (tur==1))   ||   ((schackfalt_pjaser[y+1][x-1]==2 || schackfalt_pjaser[y+1][x-1]==22) && (tur==2))   )   )
            steg=4;
        if (steg_str=="r" && x!=7 && (   ((schackfalt_pjaser[y-1][x+1]==1 || schackfalt_pjaser[y-1][x+1]==11) && (tur==1))   ||   ((schackfalt_pjaser[y+1][x+1]==2 || schackfalt_pjaser[y+1][x+1]==22) && (tur==2))   )   )
            steg=3;

        if (steg>=1 && steg<=4)
            error=0;

        //Om spelare 1 är på tur översätter vi antalet steg (så länge det är 1 eller 2) till ett minus tal, så att vi reser up på fältet istället av nere

        if (error==0 && tur==1 && (steg==1 || steg==2)   )
            steg=steg*-1;

        //Och igen som med error, så länge error blir 0 är det ingen problem, i de flesta kontrolls används den värden "error", annars får man köra om funktionen

        if (error>0)
            cout<<endl<<" Fel antal steg!";
    }


    //Nu är R/r (torn) selekterads, men den gång används det 2 värder: "steg" och "riktning", och riktning gör som namnet säger
    //Också behövs det mer kontroll för om riktningen gäller och om steg gäller (får nu blir till max. 7 istället)

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

    //N/n (hästen) ska använda ett speciell rörelse sätt, här matas in 2 antal steg, en för horisontell och en för verktikal, igen mer check

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

    //Om du känner till hur torn fungeras är B/b inget annat i kod, bara att det kontrolleras diagonalt istället av andra riktningar

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

    //Drottningen (Q/q) är en kombination av båda torn och löpare tillsammans, så den har igen samman kod, men bara på alla 8 håll

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

    //Kungen (K/k) fungerar då på samma håll som drottningen, men bara att den får flytta 1 steg, så man bara mata in värde "riktning", då flyttas kungen automatiskt 1 steg denna hålet
    //Också kontrolleras bara riktningen då och inte antalet steg

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

        //En extra grej som använder värder från Rockad_check (hämtades innan, men används här)
        //Som allt gäller får kungen göra rockad, men bara med de torn som hade inte redan rört sig, och om kungen hade inte rört sig
        //Om man får göra det finns det möjlighet till att kunna mata in x1 eller/och x2
        //Vidare skärs den vanliga kontroll om riktningen gäller

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

    //Om är förtfarande på "error" = 0, då får man köra vidaren i Ror_objekt funktionen
    //Annars ska man göra om denna funktionen när Ror_objekt funktion kommer (och skrivs det nu ut felmedelande)

    if (error>0)
    {
        cout<<"\a";
        cout<<"   -   F\224rs\224k om!";
        cin.ignore(); cin.ignore();
    }
}



void OMVANDLA_BONDE(string schackfalt[8][8], int tur, string& omvandling, string spelare1, string spelare2, int x, int y, string x_str, string y_str) //Omvandla_bonde funktionen
{
    //Denna funktionen skärs när en bonde nås sista fältet (uppe för P och nere för p)
    //Då får man mata in i vilken pjäs den ska omvandlas, alla får väljas utom bonden (självklart) och kungen (också självklart)
    //Igen... kontroll... kontroll... Om inga fel inmattas körs den vidare till den gamla funktionen, annars körs detta om
    //En grej är att när denna funktion anröpas blir skärmen tomt, skrivs det ut snabbt nya text (svårt att ser förändring på skärmen, bara att pjäsen nådes sista fältet)

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
    //Denna funktionen är den som tillas den dubbla tal på schackfalt_pjaser (den kopia av schackfältet)
    //Det händer bara om en bonde (P/p) flytta 2 steg, det är inför En Passent reglan så att i nästa tur kan blir sågen
    //Läser reglar av spelet för mer info om En Passant

    if (tur==1)
        schackfalt_pjaser[y-1][x]=22;
    if (tur==2)
        schackfalt_pjaser[y+1][x]=11;
}


void ROR_OBJEKT(string schackfalt[8][8], int schackfalt_pjaser[8][8], int steg, int steg_extra, int x, int y, string riktning, string x_str, string y_str, int& tur, int error, string spelare1, string spelare2, int& antal_satt_tur1, int& antal_satt_tur2, int rockad_tur1, int rockad_vanster_tur1, int rockad_hoger_tur1, int rockad_tur2, int rockad_vanster_tur2, int rockad_hoger_tur2)
//Ror_objekt funktionen
{
    //Som namnet sägger, denna funktionen är för att flytta pjäser till nya koordinater... Om... Error är 0, så... Det ska finnas inga error som:
    //Du rör utanför bordet, du rör på ett ställe som redan finns en pjäs av dig, du rör dig till ett ställe som är förspärrad (gäller även för rockaden)
    //Liksom i Mata_koordinater funktionen skärs allt deta i steg berörande vilken pjäs du har

    //Först ska skärmen blir tomt och anröpas funktionen Skriv_ut_falt (så ser vi fältet på skärmen) och Rorelse_kontroll funktionen
    //Sen anröpas funktioner Rockad_check och Mata_steg var systemet ska veta hur pjäsen ska röra sig
    //Men om programmet fick ett felaktig värde ska det göras om hele grejen här

    while (error!=0)
    {
        system("cls");
        SKRIV_UT_FALT(schackfalt, tur, spelare1, spelare2);

        if (schackfalt[y][x]!="N" || schackfalt[y][x]!="n")
            RORELSE_KONTROLL(schackfalt, schackfalt_pjaser, tur, error, x, y);

        //Om Rorelse_kontroll funktionen misslyckades körs följande inte vidare för error är 2

        if (error!=2)
        {
            ROCKAD_CHECK(schackfalt, tur, rockad_tur1, rockad_vanster_tur1, rockad_hoger_tur1, rockad_tur2, rockad_vanster_tur2, rockad_hoger_tur2);
            MATA_STEG(schackfalt, schackfalt_pjaser, tur, steg, steg_extra, riktning, x, y, x_str, y_str, error, rockad_tur1, rockad_vanster_tur1, rockad_hoger_tur1, rockad_tur2, rockad_vanster_tur2, rockad_hoger_tur2);
        }

        //Och om error är inte 0 körs while-loopen om tills den får error är 0

        if (steg==0)
        {
            cout<<"\a";
            system("cls");
            return;
        }

    }

    //Bonden är selekterad (P/p)
    //Först ska kontrolleras vilken värde vi fick från funktionen Mata_steg
    //Det första som kontrolleras är om att vi inte går utifrån bordet, sen om platsen pjäsen ska vara är tomt och att väggen är fritt. Annars blir error > 0
    //Och som vanlig avbrytts aktionen om error är inte 0, varje error värde skriver ut sitt eget medelande

    if (schackfalt[y][x]=="P" || schackfalt[y][x]=="p")
    {
        if (   (steg==1 || steg==2) &&  ((y+steg<0 && tur==1) || (y+steg>7 && tur==2))   )
            error=1;

        //Här skärs alltså den "är rutan och väggen fritt" kontrollen, grejen är bara: om steg är 1 (båda postivit och negativt) körs bara kontrollen om platsten är fritt.
        //Om steg är 2 (+ och -) kontrolleras också om väggen är fritt genom att checka 1 steg vidare är fritt att gå och om 2 steg vidare är tomt

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

        //Det hittades inga fel så länge (om error är inte 0 då slutat funktionen här och skipar programmet till slutet
        //Nu ska pjäsen alltså flyttas till den nya ställe (den finns också kvar på den gamla ställe, så den är på 2 platser, den gamla raderas senare
        //Viktig är att det också kontrolleras alltid vems tur det är så programmet vet vilken sort bonden den ska tillla

        if (error==0)
        {
            if (   tur==1 && (steg!=3 && steg!=4)   )
                schackfalt[y+steg][x]="P";
            if (   tur==2 && (steg!=3 && steg!=4)   )
                schackfalt[y+steg][x]="p";

            //Här ska funktionen En_passent aktiveras om bonden rör sig 2 steg på schackfältet

            if (steg==2 || steg==-2)
                EN_PASSANT(schackfalt_pjaser, tur, x , y);

            //Nu om steg är 3 (attackera r/höger) eller steg är 4 (attackera l/vänster) ska först kontrolleras om vi får sla genom EN PASSANT regeln
            //Om ja då sätts fiendens rutan på tomt
            //Därefter ska pjäsen
            //Kontrollen om pjäsen får sla är gjords i funktionen Mata_steg, den bara utförs här

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

            //Nu om pjäsen är nästa på sista fältet (1 steg innan) den kan nå och ska flytar sig då aktiveras funktionen Omvandla_bonden så att spelare får omvandla sitt bonde i en annan pjäs
            //Men ingen annan bonde eller kung
            //Också som vanligt skärs kontrollen vems tur det är, också resettas stringen man ska matta in inför omvandlingen

            if (   (y==1 && tur==1)   ||   (y==6 && tur==2)   )
            {
                string omvandling="a";
                schackfalt[y][x]=" ";
                OMVANDLA_BONDE(schackfalt, tur, omvandling, spelare1, spelare2, x, y, x_str, y_str);

                //Om pjäsen slog höger eller vänster, måste också medräknas, därför de 3 kontroll på steg, men programmet vet allt det aldrig händer med 2 steg
                //Så vi får den nya pjäsen på rätt rutan


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

    //Här är torn selekterads (R/r)
    //Alla pjäser har samma struktur i kontroll och rörselse, men för att några pjäser har andra rörelsereglar ska kontrollen fungerar litte annårlunda
    //Först då error checken

    if (schackfalt[y][x]=="R" || schackfalt[y][x]=="r")
    {
        if (   (riktning=="u" && y-steg<0) || (riktning=="d" && y+steg>7) || (riktning=="r" && x+steg>7) || (riktning=="l" && x-steg<0)   )
            error=1;

        if (error==0)
        {
            //För att torn kan alltid får 7 som stegvärde (naturligtviss kontrolleras först om den inte går utifrån bordet) ska det först kontrolleras om varje steg
            //är inte på är plats var redan 1 finns, om ja får man som värde att väggen är spärande
            //Om sista rutan är fyld får vi att error ska visa att rutan är inte tomt då får vi att vi avbrytter funktionen, men det finns 1 check kvar

            for (int i=1; i<=steg; i++)
            {
                if (   (riktning=="u" && schackfalt[y-i][x]!=" ") || (riktning=="d" && schackfalt[y+i][x]!=" ") || (riktning=="r" && schackfalt[y][x+i]!=" ") || (riktning=="l" && schackfalt[y][x-i]!=" ")   )
                {
                    if (i!=steg)
                        error=3;
                    if (i==steg && error!=3)
                        error=2;

                    //I denna checken ska kontrolleras om sista fältet är fyld (bara sista) om det blev ett pjäs från motståndaren, om ja, då blir error plötslig 0

                    if (   error!=3 &&   (   (riktning=="u" && schackfalt_pjaser[y-steg][x]==tur) || (riktning=="d" && schackfalt_pjaser[y+steg][x]==tur) || (riktning=="r" && schackfalt_pjaser[y][x+steg]==tur) || (riktning=="l" && schackfalt_pjaser[y][x-steg]==tur)   )   )
                        error=0;
                }
            }
        }

        //Då error är 0 flyttas torn, kom ihåg att torn får flytta på 4 riktningar, så alla de 4 riktningar med spelaren är på tur kontrolleras hela tiden

        if (error==0)
        {
            if (riktning=="u" && tur==1)    schackfalt[y-steg][x]="R";       if (riktning=="u" && tur==2)      schackfalt[y-steg][x]="r";
            if (riktning=="d" && tur==1)    schackfalt[y+steg][x]="R";       if (riktning=="d" && tur==2)      schackfalt[y+steg][x]="r";
            if (riktning=="r" && tur==1)    schackfalt[y][x+steg]="R";       if (riktning=="r" && tur==2)      schackfalt[y][x+steg]="r";
            if (riktning=="l" && tur==1)    schackfalt[y][x-steg]="R";       if (riktning=="l" && tur==2)      schackfalt[y][x-steg]="r";
        }
    }

    //Här kommer hästen (N/n)
    //Hästen är den enklaste kontrollen, där kontrolleras bara om den inte går utifrån bordet

    if (schackfalt[y][x]=="N" || schackfalt[y][x]=="n")
    {
        if ((y+steg>7) || (y+steg<0) || (x+steg_extra>7) || (x+steg_extra<0))
            error=1;

        //Här finns ett kontroll som kontrollerar om hästen kommer på ett tomt rutan eller fiendens rutan, annars

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

    //Löpare (B/b) funger exakt samma som Torn, men bara är det kontrollers av de 4 diagonala riktningar istället av de andra 4 riktningar

    if (schackfalt[y][x]=="B" || schackfalt[y][x]=="b")
    {
        if (   (riktning=="ur" && (y-steg<0 || x+steg>7)   ) || (riktning=="ul" && (y-steg<0 || x+steg<0)   ) || (riktning=="dr" && (y+steg>7 || x+steg>7)   ) || (riktning=="dl" && (y+steg>7 || x-steg<0)   )   )       //Om nya koordinatera kommer att bli utifrån bordet blir ERROR = 1
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

    //Även hos Drottningen (Q/q) skillnar det inte, det är bara en kombination av de riktningar av Torn och Löpare

    if (schackfalt[y][x]=="Q" || schackfalt[y][x]=="q")
    {
        if (   (riktning=="u" && y-steg<0) || (riktning=="d" && y+steg>7) || (riktning=="r" && x+steg>7) || (riktning=="l" && x-steg<0) || (riktning=="ur" && (y-steg<0 || x+steg>7)   ) || (riktning=="ul" && (y-steg<0 || x+steg<0)   ) || (riktning=="dr" && (y+steg>7 || x+steg>7)   ) || (riktning=="dl" && (y+steg>7 || x-steg<0)   )   )       //Om nya koordinatera kommer att bli utifrån bordet blir ERROR = 1
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
    //Men det finns bara 2 skillnader, den kan bara röra sig 1 steg, så det bara kontrolleras om rutan är fritt och inte väggen
    //Det andra är att det kontrolleras om rockaden kan utföras (att väggen är fritt mellan rockaden) och att den kan utföra rockaden med 1 torn
    //Också om rockaden går inte skrivs det ut error = 4, ett nytt värde

    if (schackfalt[y][x]=="K" || schackfalt[y][x]=="k")
    {
        if (   (riktning=="u" && y-1<0) || (riktning=="d" && y+1>7) || (riktning=="r" && x+1>7) || (riktning=="l" && x-1<0) || (riktning=="ur" && (y-1<0 || x+1>7)   ) || (riktning=="ul" && (y-1<0 || x+1<0)   ) || (riktning=="dr" && (y+1>7 || x+1>7)   ) || (riktning=="dl" && (y+1>7 || x-1<0)   )   )
            error=1;

        if (error==0)
        {
            if (   (riktning=="u" && schackfalt[y-1][x]!=" ") || (riktning=="d" && schackfalt[y+1][x]!=" ") || (riktning=="r" && schackfalt[y][x+1]!=" ") || (riktning=="l" && schackfalt[y][x-1]!=" ") || (riktning=="ur" && schackfalt[y-1][x+1]!=" ") || (riktning=="ul" && schackfalt[y-1][x-1]!=" ") || (riktning=="dr" && schackfalt[y+1][x+1]!=" ") || (riktning=="dl" && schackfalt[y+1][x-1]!=" ")   )
                    error=2;

            //I fallet du glömde, först kontrolleras om rutan är fritt, sen kontrolleras om rutan är från motståndaren, om det sista stämmer blir error alltid 0

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

    //Nu skrivs ut de olika error (om error är inte 0 självklart), läs bredvid får de olika betydelse

    if (error>0)
    {
        cout<<"\a"<<endl;
        cout<<" Du kan inte flytta pj\204sen! ";                                    //Allmänt varning att flyttning går inte med ljudsignal
        if (error==1)                                                               //ERROR 1 = Bonden försökte går utifrån bordet
            cout<<"Den kan inte g\204r utifr\206n bordet!";
        if (error==2)                                                               //ERROR 2 = Platsen var pjäsen ska flyttar till är inte tomt
            cout<<"Det finns en annan pj\204s d\204r!";
        if (error==3)                                                               //ERROR 3 = Väggen som pjäsen tar är inte tomt
            cout<<"V\204ggen \204r sp\204rrade!";
        if (error==4)
            cout<<"Rockaden \204r inte tillg\204nglig!";                            //ERROR 4 = Rockaden är inte tillgänglig
        cout<<"   -   F\224rs\224k om!";                                            //Och ett allmänt varning för att göra om
        cin.ignore(); cin.ignore();
        //Och hela funktionen startar om om error är inte 0
        ROR_OBJEKT(schackfalt, schackfalt_pjaser, steg, steg_extra, x, y, riktning, x_str, y_str, tur, error, spelare1, spelare2, antal_satt_tur1, antal_satt_tur2, rockad_tur1, rockad_vanster_tur1, rockad_hoger_tur1, rockad_tur2, rockad_vanster_tur2, rockad_hoger_tur2);      //Gör om funktionen om ERROR > 0

    }

    //Så om programmet kunde klara hele funktionen utan error slutligen blev 0 kan den avsluta funktionen med sista saters och börja med de nästa
    //Först bytta spelare sin tur till den andra spelare, så den får köra
    //Sen höjas antalet sätt den spelare gjorde med 1 som man kan ser tillbaka i poänglistan
    //Och till sist hör man ett ljud och blir skärmet tomt

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
    //Denna funktionen skriver bara ut text som hjälper man att förstå schackreglar och RobSchack systemet
    //Det behövs bara att klicka på enter att kunna köra vidare

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
    //I denna funktionen ska man mata in de namn av de 2 spelare, som sparas i filen "spelare.txt", som blir används i spelet och poänglistan
    //Sen bara enter och man är tillbaka i huvudfunktionen

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



void RADERA_POANGLISTAN() //Radera_poänglistan funktionen
{
    //I denna funktionen fråga systemet om använderen vill radera poänglistan, så att filen "scorelistan.txt" blir tomt, det krävs en inmatning av y (ja) eller n (nej)
    //Sen bara enter och huvudfunktionen är tillbaka

    string radera_score;

    while (radera_score.size()!=1 || (radera_score!="y" && radera_score!="n"))
    {
        system("cls");
        cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;    //Skrivs ut text på skärmet

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
    //I denna funktionen laddas in data från filen "scorelistan.txt" och skrivs de ut på skärmen, så att man ser poänglistan
    //Och igen.. Enter = tillbaka på huvudfunktionen

    cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;   //Skrivs ut text på skärmet

    string score_str;
    int score_cout=1, score_tal=1;

    ifstream infil;
    infil.open("scorelistan.txt");
    while(infil>>score_str) //Fortsätter så länge det finns data kvar
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
    //Denna funktionen skärs när kungen av någon finns inte längre på schackfältet, eller om man matade in 0 0 på koordinater (som betydder avbrytta)
    //Först kontrolleras om verkligen någon kung dög (+ att data resetas och avspelas ett ljud)

    string spara_score;
    cout<<"\a";                                                                     //Skärmet blir tomt med ljudsignal

    if (vinna_spelet==0)
    {
        //Tyvärr, ingen kung dög, så ingen poäng blir sparats i poänglistan, men någon vann alltså, gratz till den

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
        //Gratz för den som vann, för motståndarens kung dög, också blir frågats om du vill spara poäng i poänglistan
        //Därför krävs det inmatning av y (ja) eller n (nej)

        while (spara_score.size()!=1 || (spara_score!="y" && spara_score!="n"))
        {
            system("cls");
            cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;    //Skrivs ut text på skärmet

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

        //Så om inmatningen blev y ska vinnarens poäng sparats i filen "scorelistan.txt", det bara tilllas

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
    //Och om inmatningen är n sparats det inga poäng i poänglistan

    if (spara_score=="n")
        cout<<endl<<" Ingen po\204ng blir sparats"<<endl<<endl;

    //Och här ska programmet skriva ut sina sista meningar på skärmet innan den avslutats genom huvudfunkionen (om man vinner avslutet spelet, även om någon gav upp)

    cin.ignore(); cin.ignore();
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<" Tack f\204r att spela RobSchack!"<<endl<<endl<<" Tills n\204sta g\206ng!"<<endl;
    cout<<endl<<endl<<endl<<" Klicka p\206 n\206gon knapp f\224r att st\204nga av programmet"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}





int main() //huvudfunktionen
{
    //Här börjar programmet alltså, och tillas alla variabler, int och string, kan du försöka hitta de alla i koden? Även i några funktioner skrivs det ut några temp variabler

    int error, steg=0, steg_extra=0, x=1, y=1, tur=1, schackfalt_pjaser[8][8], antal_satt_tur1=0, antal_satt_tur2=0, vinna_spelet=0;
    string val, spelare1, spelare2, schackfalt[8][8], x_str, y_str, riktning;
    int rockad_tur1=0, rockad_vanster_tur1=0, rockad_hoger_tur1=0, rockad_tur2=0, rockad_vanster_tur2=0, rockad_hoger_tur2=0;

    //Här ska alltså laddas in data från filen "spelare.txt" så programmet vet vem ska köra mot vem

    ifstream infil("spelare.txt");
    infil>>spelare1;
    infil>>spelare2;
    infil.close();

    //Här börjar programmet riktig och körs det funktionen Huvudmeny (som görs bara text)

    HUVUDMENY();

    //Därefter kommer allts¨funktionen Meny som ska fråga användaren efter vilken mode den ska aktiveras
    //programmet kan köra spelet, ändra de namn, visa poänglistan, radera poänglistan, läsa genom spelreglar och avsluta progammet

    while (val!="0")
    {
        //Här ska aktiveras en while-loop, så att vi kan välja hela tiden en mode efter en mode är färdig (de funktioner som anröpas genom val kallas mode)

        MENY(val);

        //Om val blir 1 då körs spelet riktig, det börjar alltså med all bygga up schackfältet, men den körs bara 1 gång

        if (val=="1")
            BYGGA_SCHACKFALT(schackfalt);

        //Sen en ny while-loop som så riktig oändligt, om man ska spela spelet köra den oändligt tills spelet är färdigt (genom Spelet_fardigt funktionen)
        //Och det finns ingen möjlighet sen att komma tillbaka på meny, då måste man starta om programmet
        //Loopen är oändlig för att programmet kommer aldrig att ändra värden på val när man kör mode 1 (spelet alltså)

        while (val=="1")
        {
            //Först med varje varv resetas error till 0, mycket viktig alltså, om error är inte 0 då kan nästan ingen funktion köra vidare

            error=0;

            //Därefter anröpas alla funktioner i följ för att kunna spela spelet, några funktioner anröper också funktioner inom funktionen

            SKRIV_UT_FALT(schackfalt, tur, spelare1, spelare2);
            MATA_KOORDINATER(schackfalt, error, x, y, x_str, y_str, tur, vinna_spelet);

            //Här finns det en snabbkontroll om a) båda kungar lever   b) någon matade in 0 0 på koordinater
            //Om ett av de stämmer anröpas funktionen Spelet_fardigt och sen används det return 0 (så spelet ska avsluta)

            if (   (x_str=="0" && y_str=="0") || vinna_spelet>0)
            {
                SPELET_FARDIGT(tur, spelare1, spelare2, antal_satt_tur1, antal_satt_tur2, vinna_spelet);
                return 0;
            }

            //En sista kontroll här om error är fortfarande 0, annars är inga pjäs selekterads och körs funktionen om (den finns i en while loop som slutar aldrig)

            if (error==0)
            {
                error=1;
                BYGGA_SCHACKFALT_PJASER(schackfalt, schackfalt_pjaser, tur);
                ROR_OBJEKT(schackfalt, schackfalt_pjaser, steg, steg_extra, x, y, riktning, x_str, y_str, tur, error, spelare1, spelare2, antal_satt_tur1, antal_satt_tur2, rockad_tur1, rockad_vanster_tur1, rockad_hoger_tur1, rockad_tur2, rockad_vanster_tur2, rockad_hoger_tur2);
            }
        }

        //Och här anröpas några kortare funktioner (de övriga mode), efter den funktionen är färdigt kommer programmet tillbaka på början av loopen

        if (val=="2")
            LASA_REGLARNA();
        if (val=="3")
            ANDRA_SPELARE(spelare1, spelare2);
        if (val=="4")
            VISA_POANGLISTAN();
        if (val=="5")
            RADERA_POANGLISTAN();
    }

    //Och den allra sisten koden referar till om val blir 0, så avslutas spelet också, så man behöver inte köra färdigt hela spelet, detta här anröpas genom funktioen Meny enkelt

    if (val=="0")
    {
        cout<<endl<<" ================="<<endl<<" === RobSchack ==="<<endl<<" ================="<<endl<<endl;
        cout<<endl<<" Tack f\204r att spela RobSchack!"<<endl<<endl<<" Tills n\204sta g\206ng!"<<endl;
        cout<<endl<<endl<<endl<<" Klicka p\206 n\206gon knapp f\224r att st\204nga av programmet"<<endl<<endl<<endl;
        return 0;
    }
}
