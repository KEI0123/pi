#include <iostream>
using namespace std;

// 多倍長テンプレ
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

int main() {
  // 整数
  Bint a = 546534242;
  Bint b("238431313536543513515132513213516353");
  Bint c("365435435435135435143548546841324135");
  cout << a * b % c << endl;
  // 浮動小数点数
  Real d = -1.0;
  cout << fixed << setprecision(50) << acos(d) << endl;
}
