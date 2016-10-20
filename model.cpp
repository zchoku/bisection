#include <iostream>
#include "bisection.hpp"
using namespace std;

class equation
{
private:
  bisection<double> ob;
  double x_min, x_max;
public:
  equation()
  {
    x_min = 0;
    x_max = 10;
    ob.setprm(x_min, x_max, eq);
  }
  
  static double eq(double x, double U);
  double solu(double U);
};
double equation::eq(double x, double U)
{
  double f = x*x - U - 4;
  return f;
}
double equation::solu(double U)
{
  double KAI = ob.cal(U);
  return KAI;
}
int main()
{
  equation ob;
  for(int i=0; i<10; i++)
  {
    double U = i*0.1;
    double kai = ob.solu(U);
    cout << U << ' ' << kai << endl;
  }
  return 0;
}