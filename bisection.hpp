//////////////////////////////////////////////////////////////////////////////////////
// 使い方 of class bisection
// 0) 解きたい方程式
//    f(x) = 0
//    に対応する関数 func(double x, double param)
//    を用意する。
//*今回は方程式がパラメータを一つ含むとして定義しています。
//関数を定義するクラスのメンバ変数としてパラメータを設定できればこんなことをしなくてもいいんだが、
//そうするとメンバ関数のポインタを渡せない。static　な関数しか渡せない。
//それを解決する方法もあるっぽいけど、今はしない。
//
//
//
// 1) コンストラクタ: bisection<double (or something type)>
//                  object( 解きたい変数の最小値, 最大値, 方程式の関数名)
// 1') セットパラメータにしましょう　ob.setprm( min, max, func)
// 2) object.cal(方程式のパラメータ)で、パラメタの値に対応した方程式の解を return します。
// 解きたい方程式の形に応じて微調整して下さい。
// templateを使ったclassのメンバ関数で、宣言と実装を分ける方法については
// http://qiita.com/MasayaMizuhara/items/b1e3a53f62df88205eb7
// を参考にした。
//////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cmath>
using namespace std;

template<class X> class bisection
{
private:
  double x_low, x_high;
  static const double eps = 1e-08;  // 打ち切り精度
  static const int  limit = 50;
  X (*pfunc)(double, double) = NULL;
public:
  
  void setprm(double x_low_, double x_high_, X (*func)(double, double));
  double cal(double U_);
};

template<class X>
void bisection<X>::setprm(double x_low_, double x_high_, X (*func)(double, double))
{
  x_low = x_low_;
  x_high = x_high_;
  pfunc = func;
}
template<class X>
double bisection<X>::cal(double U_)
{
  
    double xa, xb,x_temp;
  
    xa = x_low;
    xb = x_high;
  double U = U_;
  
    //二分法で計算
  int count = 0;
    while(abs(xa-xb) > eps)
    {
      x_temp = (xa+xb)/2;
      if( (*pfunc)(xa, U) * (*pfunc)(x_temp, U) < 0)
      {
        xb=x_temp;
      }
      else  if( (*pfunc)(xa, U) * (*pfunc)(x_temp, U) > 0)
      {
        xa = x_temp;
      }
      else break;
      count++;
      if(count > limit)
      {
        cout << "収束しませんでした" << endl;
        break;
      }
    }
    return x_temp;//これが方程式の解
}