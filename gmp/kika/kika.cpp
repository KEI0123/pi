#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <gmpxx.h>
#include <math.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
//namespace mp = boost::multiprecision;

//typedef mp::cpp_dec_float_100 FLOAT;
//typedef mp::number<mp::cpp_dec_float<1000>> FLOAT;
//typedef mp::cpp_int INT;

int main () {
    int dig = 1500000000;
    int prec = dig * log2(10);

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
    
    long long Loop = 30;
    for (long long i = 0; i < Loop; ++i){
        mpf_class AA, AAA, AAAA;
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
    
    //=====================================================================================//

    end = chrono::system_clock::now();
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();

    cout << setprecision(dig) << PI << endl;
    cout << "ms : " << elapsed << endl;
    
    //cout << setprecision(200) << PI << endl;
    
    char *str = nullptr;
    gmp_asprintf(&str, "%.Ff", PI.get_mpf_t());
    string result(str);
    string PIstr = str;
    string PIout = "";

    int i = 1;
    //bool a = true;
    PIstr.erase(1, 1);
    for (char c : PIstr) {
        PIout.push_back(c);
        //if (i == 1 && a == true) {
        //    PIout.push_back('\n');
        //    a = false;
        //    i = 0;
        //} 
        //else if (i % 11 == 0) {
        //    PIout.push_back(' ');
        //}
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
