#include <iostream>
#include <math.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <gmpxx.h>

using namespace std;
namespace mp = boost::multiprecision;

typedef mp::cpp_dec_float_100 FLOAT;

int main () {
    FLOAT N, DEG, RED, A, MX;
    cout << "enter nunber : " << endl;
    cin >> N;

    //if (!(N  2 == 0)) {
    //   return 0;
    //}

    DEG = 90.0 - (180.0 / N);
    RED = DEG * M_PI / 180.0;

    A = cos(RED);
    
    MX = A * N;
    //cout << setprecision(numeric_limits<decltype(MX)>::digits10 + 1) << endl;
    cout << MX << endl;
}
