#include <gmpxx.h>
#include <math.h>
#include <tbb/tbb.h>

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void compute(mpf_class& A, mpf_class& B, mpf_class& T, mpf_class& P,
             mpf_class& PI) {
    mpf_class AA, AAA, AAAA, An;
    AA = A + B;
    PI = (AA * AA) / (4 * T);

    An = AA / 2;

    AAA = A * B;
    B = sqrt(AAA);

    AAAA = A - An;
    T -= P * (AAAA * AAAA);
    P *= 2;
    A = An;
}

int main() {
    long long digi = 100000000;
    double log = 3.32192809489;
    long long prec = digi * log;

    mpf_set_default_prec(prec);

    mpf_class A, TWO, B, T, P, PI;

    A = 1.0;
    TWO = 2.0;
    B = 1 / sqrt(TWO);
    T = 0.25;
    P = 1.0;

    PI = 1.0;

    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    // ループ数の調整
    int Loop = 27;

    // シリアル実行
    for (int i = 0; i < Loop; ++i) {
        compute(A, B, T, P, PI);
    }

    end = chrono::system_clock::now();
    double elapsed =
        chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << setprecision(digi) << PI << endl;
    cout << "ms : " << elapsed << endl;

    char* str = nullptr;
    gmp_asprintf(&str, "%.Ff", PI.get_mpf_t());
    string result(str);
    string PIstr = str;
    string PIout = "";

    int i = 1;
    PIstr.erase(1, 1);
    for (char c : PIstr) {
        PIout.push_back(c);
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
