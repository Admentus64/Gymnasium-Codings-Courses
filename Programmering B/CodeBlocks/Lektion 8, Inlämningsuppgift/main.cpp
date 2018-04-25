#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

struct person
{
    string fnamn;
    string enamn;
    string personnr;
};

struct node
{
    person data;
    node* left;
    node* right;
};

void insert(node*& n, person d)
{
    if(!n)
    {
        n=new node;
        n->data=d;
        n->left=0;
        n->right=0;
    }
    else if(d.enamn<n->data.enamn)
    {
        insert(n->left,d);
    }
    else
    {
        insert(n->right,d);
    }
}

void inorder(node* n)
{
    if(n) //Om trädet inte är tomt
    {
        inorder(n->left);
        cout<<n->data.fnamn<<" "<<n->data.enamn<<" (Personnr: "<<n->data.personnr<<")"<<endl;
        inorder(n->right);
    }
}

//node* search(node* p, person d)
//{
//    if(!p)
//        return 0;
//    else if(d.enamn == p->data.enamn)
//        return p;
//    else if (d.enamn < p->data.enamn)
//        return search(p->left, d);
//    else
//        return search(p->right, d);
//}

node* search(node* p, person d)
{
    if(!p)
        return 0;
    else if(d.personnr == p->data.personnr)
        return p;
    else if (d.personnr < p->data.personnr)
        return search(p->left, d);
    else
        return search(p->right, d);
}

void meny(string& val)
{
    system("cls");
    while (val.size()==0 || val!="1" && val!="2" && val!="3" && val!="0")
    {
        cout<<"======================\n=== Personregister ===\n======================"<<endl<<endl;
        cout<<"1. L\204gg till person"<<endl;
        cout<<"2. S\224k efter person"<<endl;
        cout<<"3. Skriv ut personregister"<<endl;
        cout<<"0. Avsluta programmet"<<endl<<endl;
        cout<<"Ange ditt val: ";
        getline(cin,val);
        cout<<"\a";

        if (val.size()==0 || val!="1" && val!="2" && val!="3" && val!="0")
        {
            cout<<"\nFel inmatning!"<<endl;
            cout<<"Mata bara in siffrorna 0 till och med 3!"<<endl;
            cout<<"F\224rs\224k om g\204rna!"<<endl;
            cin.ignore();
        }
        system("cls");
    }
}

int main()
{
    string val,leta_personnr,mata_fnamn,mata_enamn,mata_personnr;
    node* root=0;

    while (val!="0")
    {
        val=" ";
        meny(val);
        if (val=="1")
        {
            cout<<"======================\n=== Personregister ===\n======================"<<endl<<endl;
            cout<<"Mata in en person:"<<endl<<"============================="<<endl<<endl;

            cout<<"Mata in f\224rnamn: ";
            getline(cin,mata_fnamn);

            cout<<"\n\nMata in efternamn: ";
            getline(cin,mata_enamn);

            cout<<"\n\nMata in personnummer: ";
            getline(cin,mata_personnr);

            person p={mata_fnamn,mata_enamn,mata_personnr};
            insert(root,p);

            cout<<"\nPersonen har laggrats in."<<endl;
            cout<<mata_fnamn<<" "<<mata_enamn<<" (Personnr: "<<mata_personnr<<")"<<endl;
            cin.ignore();

        }
        if (val=="2")
        {
            cout<<"======================\n=== Personregister ===\n======================"<<endl<<endl;
            cout<<"Mata in personnummer: ";
            getline(cin,leta_personnr);
            person leta_person={"","",leta_personnr};

            cout<<endl<<"S\224ker efter person:"<<endl<<"==================="<<endl<<endl;
            node* hitta_personnr=search(root,leta_person);

            if (hitta_personnr==0)
                cout<<"Finns inte";
            else
                cout<<"Hittade:\n"<<hitta_personnr->data.fnamn<<" "<<hitta_personnr->data.enamn<<" (Personnr: "<<hitta_personnr->data.personnr<<")"<<endl;
            cin.ignore();
        }
        if (val=="3")
        {
            cout<<"======================\n=== Personregister ===\n======================"<<endl<<endl;
            cout<<"Skriver ut noderna i ordning:"<<endl<<"============================="<<endl<<endl;
            inorder(root);
            cin.ignore();
        }
    }
    return 0;
}
