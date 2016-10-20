#include <iostream>
using namespace std;

template<class X> class bisection
{
private:
  double x_low, x_high;
  double err;
  X (*pointer_to_func)(double, double) = NULL;
public:

  bisection(double x_low_, double x_high_, X (*func)(double, double));
  double cal(double U_);
};

template<class X>
bisection<X>::bisection(double x_low_, double x_high_, X (*func)(double, double))
{
  err = 0.000001;
  x_low = x_low_;
  x_high = x_high_;
  pointer_to_func = func;
}
template<class X>
double bisection<X>::cal(double U_)
{
  double x = 10;
  double resu =  (*pointer_to_func)(x, U_);
  cout << x_low << x_high << endl;
  return resu;
}

double func(double x, double U);

double func(double x, double U)
{
  double f;
  f = x*x*U;
  return U;
}

int main()
{
  
  bisection<double> ob(1, 10, func);
  for(int i=0; i<10; i++)
  {
    double U = 0.1*i;
    double y = ob.cal(U);
    cout << U <<' ' << y << endl;
  }
  return 0;
}


