#include <iostream>
#include <vector>
using namespace std;

class Person
{
     private:
         string namn;
     public:
         Person(string n){namn=n;}
         Person(){}
         string getNamn(){return namn;}
         void setNamn(string n){namn=n;}
         virtual void visa()
         {
              cout<<"Namn: "<<namn<<endl;
         }
};

class Student:public Person
{
     private:
          string utb;
     public:
          Student(string n,string u):Person(n),utb(u){}
          Student(){}
          string getUtb(){return utb;}
          void setUtb(string u){utb=u;}
          virtual void visa()
          {
               Person::visa();cout<<"Utbildning: "<<utb<<endl;
          }
};

int main()
{
     vector<Person> pv;
     pv.push_back(*new Person("Kalle"));
     pv.push_back(*new Student("Andreas","Teknikprogrammet"));
     for(vector<Person>::iterator i=pv.begin();i!=pv.end();i++)
     {
          i->visa();
     }
     for(int i=0;i<pv.size();i++)
          pv.at(i).visa();

     cin.ignore();
     return 0;
}
