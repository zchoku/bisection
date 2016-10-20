#include <iostream>
using namespace std;

//これは関数テンプレート
template <class X> void swapargs(X &a, X &b)
{
  X temp;

  temp = a;
  a = b;
  b = temp;
}

int main()
{
  int i=10, j=20;
  float x = 10.1, y=23.3;
  char a = 'x', b='z';

  cout << "Original  i,j : " << i << ' ' << j << endl;
  cout << "Original  x,y : " << x << ' ' << y << endl;
  cout << "Original  a,b : " << a << ' ' << b << endl;

  swapargs(i, j);
  swapargs(x, y);
  swapargs(a, b);
  
  cout << "Swapped  i, j: " << i << ' ' << j << endl;
  cout << "Swapped  x, y: " << x << ' ' << y << endl;
  cout << "Swapped  a, b: " << a << ' ' << b << endl;

  return 0;
}