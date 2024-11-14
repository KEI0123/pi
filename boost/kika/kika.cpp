#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
namespace mp = boost::multiprecision;

//typedef mp::cpp_dec_float_100 FLOAT;
typedef mp::number<mp::cpp_dec_float<100000>> FLOAT;
//typedef mp::cpp_int INT;

int main () {
    FLOAT A, An, TWO, B, T, P, MOL, DEN, PI;

    A = 1.0f;
    An = 0.0f;
    TWO = 2.0f;
    B = 1 / mp::sqrt(TWO);
    T = 0.25f;
    P = 1.0f;

    PI = 1.0f;

    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    //=====================================================================================//
    
    long long Loop = 10000;
    for (long long i = 0; i < Loop; ++i){
        FLOAT AA, AAA, AAAA;
        AA = A + B;
        PI = mp::pow(AA, 2) / (4 * T);

        An = AA / 2;

        AAA = A * B;
        B = mp::sqrt(AAA);

        AAAA = A - An;
        T -= P * mp::pow(AAAA, 2);
        P *= 2;
        A = An;
    }
    
    //=====================================================================================//

    end = chrono::system_clock::now();
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();

    cout << "ms : " << elapsed << endl;
    cout << setprecision(numeric_limits<decltype(PI)>::digits10 + 1) << PI << endl;
    
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
