#include <boost/multiprecision/gmp.hpp>
#include <boost/math/special_functions/gamma.hpp>
#include <iostream>

using namespace std;
int main()
{
   using namespace boost::multiprecision;

   mpf_float a = 3.3333333333333333333333333333333333333333333333333;
   mpf_float b = 2.2222222222222222222222222222222222222222222222222;

   cout << a + b << endl;
   return 0;
}
