#include <iostream>
#include <string>

using namespace std;
class People{
protected:
    string name;
    int year;
    int day;
    int month;
    double weight;
    int age;
    int height;
    double sedentary;
    double moderate;
    double light;
    double high;
    double BMR;
    double intake;
public:
    People();
    void setName(string &b);
    void setAge(double t, double m, double d);
    double getAge();
    void setDate(double x,double y,double z);
    void setWeight(double n);
    double getWeight();
    void setHeight(double h);
    double getHeight();
    double calintake(int u);
};

class Male:public People{
public:
    Male();
    double getBMR();
};
class Female:public People{
public:
    Female();
    double getBMR();
};
//derived classes.
int main()
{
    Male a;
    string h = "Kevin";
    a.setName(h);
    a.setDate(1994, 6, 1);
    a.setHeight(68);
    a.setWeight(158);
    a.setAge(2014, 2, 10);
    cout <<h<<"'s BMR: "<< a.getBMR() <<" recommended caloric intake: "<<a.calintake(0)<< endl;
    Female b;
    string s = "Tiffany";
    b.setName(s);
    b.setDate(1995, 8, 12);
    b.setHeight(62);
    b.setWeight(98);
    b.setAge(2014, 10, 2);
    cout<<s<<"'s BMR: "<<b.getBMR()<<" recommended caloric intake: "<<b.calintake(2)<< endl;


    return 0;
}
//intializes number values.
People::People()
{
    year = 0;
    day = 0;
    month = 0;
    weight = 0;
    age = 0;
    height = 0;
    sedentary = 1.2;
    moderate = 1.55;
    light = 1.35;
    high = 1.725;
    intake = 0;
}

//initializes name.
void People::setName(string &b)
{
    name = b;
}
//constructor defaults to People
Female::Female()
{

}

Male::Male()
{

}

void People::setDate(double x,double y,double z)
{
    year = x;
    month = y;
    day = z;
}

void People::setAge(double t,double m,double d)//x, y, and z is for date of birth. t,m,and d is for current date.
{
    if(m>month || ((m==month) && (d>=day)))
    {
        age = t - year;
    }
    else
    {
        age = (t-year)-1;
    }
}

double People::getAge()
{
    return age;
}

double Male::getBMR()
{
    BMR = 66 + (30.14 * getWeight()) + (1.97 * getHeight()) - (6.8 * getAge());
    return BMR;
}

double Female::getBMR()
{
    double kweight;
    kweight = getWeight()/2.2;
    BMR = 655 + (21.12 * kweight) +(.71 * getHeight()) -(4.7 * getAge());
    return BMR;
}

void People::setWeight(double n)
{
    weight = n;
}

double People::getWeight()
{
    return weight;
}

void People::setHeight(double h)
{
    height = h;
}

double People::getHeight()
{
    return height;
}

//function to return recommended caloric intake
//cases to tell which constant to use.
double People::calintake(int u)
{
    switch(u)
    {
        case 0:
        intake = BMR * sedentary;
        break;
        case 1:
        intake = BMR * light;
        break;
        case 2:
        intake = BMR * moderate;
        break;
        case 3:
        intake = BMR * high;
        break;
    }
    return intake;
}

