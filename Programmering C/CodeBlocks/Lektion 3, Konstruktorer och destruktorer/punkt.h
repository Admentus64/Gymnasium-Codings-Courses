#ifndef PUNKTH
#define PUNKTH
using namespace std;

class Punkt
{
private:
    float x;
    float y;
public:
    Punkt(const Punkt& x);
    Punkt()
    {
        x=0; y=1;
        cout<<"        (x = 0) (y = 1)"<<endl;
    }
    Punkt(float x0)
    {
        x=x0; y=0;
        cout<<"x       (x = "<<x<<") (y = 0)"<<endl;
    }
    Punkt(float x0, float y0)
    {
        x=x0; y=y0;
        cout<<"x & y   (x = "<<x<<") (y = "<<y<<")"<<endl;
    }

    float getX()
        { return x; }
    void setX(float x0)
        { x=x0; }
    float getY()
        { return y; }
    void setY(float y0)
        { y=y0; }

    //Här står alla koden ifrån de vanliga konstruktorer.

    //Punkt();
    //Punkt(float x0, float y0);
    //void setX(float x0);
    //float getX();
    //void setY(float y0);
    //float getY();
};

#endif
