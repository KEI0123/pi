#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;

using FLOAT = mp::number<mp::cpp_dec_float<1000>>;
using INT = mp::cpp_int;

FLOAT binary_split(int a, int b) {
    if (b - a <= 1) {
        return a;
    }

    int mid = (a + b) / 2;
    return binary_split(a, mid) + binary_split(mid, b);
}

int main () {
    INT A, B, C;
    A = 13591409;
    B = 545140134;
    C = 640320;

    FLOAT PI, ABC;
    ABC = 426880 * mp::sqrt(10005);


    PI = 0.0f;
    cout << "hello" << endl;
}
