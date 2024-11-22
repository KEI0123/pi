#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <math.h>
#include <gmpxx.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
//namespace mp = boost::multiprecision;

//typedef mp::cpp_dec_float_100 FLOAT;
//typedef mp::number<mp::cpp_dec_float<5000>> FLOAT;
//typedef mp::cpp_int INT;

int main () {
    int digi = 100;
    int prec = digi * log2(10);

    mpf_set_default_prec(prec);

    mpz_class NINE, ADD, ONE, THREE, FOUR, I, Loop;
    mpf_class PI(1, prec);
    mpf_class DEN(1, prec);
    mpf_class MOL(1, prec);

    NINE = 9;
    ADD = 1;
    ONE = 1;
    THREE = 3;
    FOUR = 4;
    MOL = 1.0;
    DEN = 1.0;
    PI = 1;
    I = 0;
    Loop =3;

    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    while(I < Loop) {
        MOL *= (THREE + (I * 2)) * (FOUR + (I * 2));

        DEN *= (ONE + I) * (ONE + I);

        PI += DEN / MOL;

        I++;
    }

    end = chrono::system_clock::now();
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cout << "ms : " << elapsed << endl;
    
    PI = PI * NINE;
    PI = sqrt((mpf_class)PI);
    cout << setprecision(digi) << PI << endl;
    
    char *str = nullptr;
    gmp_asprintf(&str, "%.Ff", PI.get_mpf_t());
    string result(str);
    string PIstr = str;
    string PIout = "";

    int i = 0;
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
    free(str);

    return 0;
}
