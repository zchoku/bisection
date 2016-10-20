#include <iostream>
using namespace std;

class bibi
{
private:
  double x;
  
public:
  double catch_a_func(double (*func)(double , double ), double U_)
  {
    x = (*func)(10.5, U_);
    return x;
  }
 
};

class fufu
{
private:
  double x;
//  double U;
  bibi ob;
public:
//  void setfufu(double U_){U = U_;}
  static double func(double y, double U)
  {
    double a = U*y*y;
    return a;
  }
  double cal(double U)
  {
    double S = ob.catch_a_func(func, U);
    return S;
  }
};



int main()
{
  fufu ob;
  for(int i=0;i<10;i++)
  {
    double U = 0.5*i;
    cout << U << ' ' << ob.cal(U) <<endl;
  }
  
  return 0;
}