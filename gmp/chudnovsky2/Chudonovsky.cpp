#include <iostream>
#include <fstream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;

using FLOAT = mp::number<mp::cpp_dec_float<5000>>;
using INT = mp::cpp_int;

INT A = 13591409;
INT B = 545140134;
INT C = 640320;

INT factorial(INT n) {
    INT result = 1;
    for (INT i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

/*
INT cubed(INT n, int a) {
    INT b = n;
    for (int i = 0; i < a; ++i) {
        n *= b;
    }
    return n;
}
*/

FLOAT chudnovsky_P(int n) {
    FLOAT NUM = FLOAT(pow(-1, n)) * FLOAT(factorial(6 * n)) * FLOAT(A + B * n);
    FLOAT DEN = FLOAT(factorial(3 * n)) * FLOAT(pow(factorial(n), 3)) * FLOAT(pow(C, n * 3));
    
    return NUM / DEN;
}

FLOAT chudnovsky(int n) {
    return chudnovsky_P(n);
}


FLOAT binary_split(int a, int b) {
    if (b - a == 1) {
        return chudnovsky(a);
    }


    int mid = (a + b) / 2;
    return binary_split(a, mid) + binary_split(mid, b);
}


int main () {

    FLOAT x = 10005.0f;
    x = mp::sqrt(x);
    FLOAT fl = 426880 * x;


    int a = 0;
    int b = 500;
    FLOAT ba = binary_split(a, b + 1);

    FLOAT PI = fl / ba;

    cout << setprecision(numeric_limits<decltype(PI)>::digits10 + 1) << PI << endl;

    string PIstr = PI.str();
    string PIout = "";

    long long i = 0;
    bool bo = true;
    for (char c : PIstr) {
        PIout.push_back(c);
        if (i == 1 && a == true) {
            PIout.push_back('\n');
            bo = false;
            i = 0;
        } 
        //else if (i % 11 == 0) {
        //    PIout.push_back(' ');
        //}
        else if (i == 100) {
            PIout.push_back('\n');
            i = 0;
        }
        
        ++i;
    }

    ofstream outputfile("pi.txt");
    outputfile << PIout;
    outputfile.close();

    return 0;
}
