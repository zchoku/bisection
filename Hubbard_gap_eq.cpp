#include <iostream>
#include <cmath>
//#include <cstdlib>
#include <fstream>
#include "bisection.hpp"
using namespace std;

class equation
{
private:
  bisection<double> ob;
  double x_min, x_max;
//  int N_x, N_y;
public:
  equation()
  {
    x_min = 0; //手動で変更してね
    x_max = 2; //手動で変更してね
    ob.setprm(x_min, x_max, eq);
//    N_x = 20;
//    N_y = 10;
  }
  
  static double eq(double x, double U_over_t);
  double solu(double U_over_t);
};
double equation::eq(double x, double U_over_t)
{
  double f;
  double dainikou=0;
  
  int NN_x = 60;
  int NN_y = 30;
  
  for(int i=0; i<NN_x; i++)
  {
    for(int j=0; j<NN_y; j++)
    {
      
      double kx = -M_PI + 2*M_PI/NN_x * i;
      double ky = M_PI/NN_y * j;
      
      dainikou += 1 / sqrt(4* (cos(kx)+cos(ky))*(cos(kx)+cos(ky)) + x*x/4 * U_over_t * U_over_t );
    }
  }
  f = U_over_t * dainikou/(NN_x*2*NN_y) -1;
  
  return f;
}
double equation::solu(double U)
{
  double KAI = ob.cal(U);
  return KAI;
}
int main()
{
  ofstream out("SvsUovt.dat");
  if(!out){
    cout << "cannot open file. \n";
    return 1;
  }
  
  equation ob;
  for(int i=0; i<90; i++)
  {
    double U = (double)i/10;
    double kai = ob.solu(U);
//    cout << U << ' ' << kai << endl;
    out << U << " " << kai << '\n';
  }
  out.close();
  return 0;
}