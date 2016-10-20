#include <iostream>
using namespace std;

void vline(int i);

int main()
{
  void (*p)(int i);
  p = vline;
  (*p)(4);

  return 0;
}

void vline(int i)
{
  for( ; i; i--) cout << "-";
  cout << '\n';
}
