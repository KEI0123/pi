#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

// 高精度な計算用にcpp_dec_float_100を使用
using mp_float = number<cpp_dec_float<1000>>;
using mp_int = cpp_int;

mp_int factorial(mp_int n) {
    mp_int result = 1;
    for (mp_int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

mp_float chudnovsky_term(int k) {
    mp_int C = 426880;
    mp_int L = 13591409;
    mp_int X = 545140134;
    mp_int K = 6 * k;
    mp_float numerator = mp_float(factorial(K)) * mp_float(L + X * k);
    mp_float denominator = mp_float(factorial(3 * k)) * pow(mp_float(factorial(k)), 3) * pow(mp_float(-262537412640768000), k);
    return numerator / denominator;
}

mp_float binary_split(int a, int b) {
    if (b - a == 1) {
        return chudnovsky_term(a);
    }
    int mid = (a + b) / 2;
    return binary_split(a, mid) + binary_split(mid, b);
}

mp_float calculate_pi(int n) {
    mp_float C = mp_float(426880) * sqrt(mp_float(10005));
    mp_float K = binary_split(0, n);
    return C / K;
}

int main() {
    int terms = 10;  // 項数を指定
    mp_float pi = calculate_pi(terms);
    std::cout << std::setprecision(std::numeric_limits<mp_float>::digits10) << "円周率: " << pi << std::endl;
    return 0;
}
