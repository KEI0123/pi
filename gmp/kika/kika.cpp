#include <gmpxx.h>
#include <math.h>

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    long long digi = 100000;
    double log = 3.32192809489;
    long long prec = digi * log;

    mpf_set_default_prec(prec);

    mpf_class A, An, TWO, B, T, P, MOL, DEN, PI;

    A = 1.0;
    An = 0.0;
    TWO = 2.0;
    B = 1 / sqrt(TWO);
    T = 0.25;
    P = 1.0;

    PI = 1.0;

    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    //=====================================================================================//

    int Loop = 3;

    mpf_class AA, AAA, AAAA;
    for (int i = 0; i < Loop; ++i) {
        AA = A + B;

        An = AA / 2;

        AAA = A * B;

        B = sqrt(AAA);

        AAAA = A - An;
        T -= P * (AAAA * AAAA);
        P *= 2;
        A = An;
    }
    AA = A + B;
    PI = (AA * AA) / (4 * T);

    //=====================================================================================//

    end = chrono::system_clock::now();
    double elapsed =
        chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << setprecision(digi) << PI << endl;
    cout << "ms : " << elapsed << endl;

    char *str = nullptr;
    gmp_asprintf(&str, "%.Ff", PI.get_mpf_t());
    string result(str);
    string PIstr = str;
    string PIout = "";

    int i = 1;
    // bool a = true;
    PIstr.erase(1, 1);
    for (char c : PIstr) {
        PIout.push_back(c);
        // if (i == 1 && a == true) {
        //     PIout.push_back('\n');
        //     a = false;
        //     i = 0;
        // }
        // else if (i % 11 == 0) {
        //     PIout.push_back(' ');
        // }
        if (i == 100) {
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
