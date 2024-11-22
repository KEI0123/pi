#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;

//typedef mp::cpp_dec_float_100 FLOAT;
//typedef mp::number<mp::cpp_dec_float<100000>> FLOAT;
//typedef mp::cpp_int INT;

int main () {
    int dig = 10000000;
    mpf_float::default_precision(dig);
    mpf_float A, An, TWO, B, T, P, MOL, DEN, PI;

    A = 1;
    An = 0;
    TWO = 2;
    B = 1 / sqrt(TWO);
    T = 0.25;
    P = 1;

    PI = 1;

    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    //=====================================================================================//
    
    long long Loop = 10;

    for (long long i = 0; i < Loop; ++i){
        mpf_float AA, AAA, AAAA;
        AA = A + B;
        PI = pow(AA, 2) / (4 * T);

        An = AA / 2;

        AAA = A * B;
        B = sqrt(AAA);

        AAAA = A - An;
        T -= P * pow(AAAA, 2);
        P *= 2;
        A = An;
    }
    
    //=====================================================================================//

    end = chrono::system_clock::now();
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();

    cout << setprecision(dig) << PI << endl;
    cout << "ms : " << elapsed << endl;
    
    //cout << setprecision(200) << PI << endl;
    
    string PIstr = PI.str();
    string PIout = "";

    long long i = 0;
    bool a = true;
    for (char c : PIstr) {
        PIout.push_back(c);
        if (i == 1 && a == true) {
            PIout.push_back('\n');
            a = false;
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
}
