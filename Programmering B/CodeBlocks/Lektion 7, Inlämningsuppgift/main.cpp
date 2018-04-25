#include <iostream>
#include <string>
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
    node* next;
};

void insert(node*& p, person d)
{
    node* temp=new node;
    temp->next=p;
    temp->data=d;
    p=temp;
}

void print_list(node* p)
{
    while(p)
    {
        cout<<"F\224rnamn: "<<p->data.fnamn<<endl;
        cout<<"Efternamn: "<<p->data.enamn<<endl;
        cout<<"Personnummer: "<<p->data.personnr<<endl<<endl;
        p=p->next;
    }
}

int main()
{
    node* list_pek=0;
    person p1={"Kalle","Anka","340609-9377"};
    person p2={"Musse","Pigg","280729-9876"};
    person p3={"Alexander","Lukas","480101-1337"};
    insert(list_pek,p1);
    insert(list_pek,p2);
    insert(list_pek,p3);
    print_list(list_pek);
    return 0;
}
