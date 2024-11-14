#include <iostream>
#include <string>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
namespace mp = boost::multiprecision;

//typedef mp::cpp_dec_float_100 FLOAT;
typedef mp::number<mp::cpp_dec_float<5000>> FLOAT;
//typedef mp::cpp_int INT;

int main () {
    FLOAT NINE, ADD, ONE, THREE, FOUR, MOL, DEN, PI;
    long long I, Loop;

    NINE = 9.0f;
    ADD = 1.0f;
    ONE = 1.0f;
    THREE = 3.0f;
    FOUR = 4.0f;
    MOL = 1.0f;
    DEN = 1.0f;
    PI = 1.0f;
    I = 0;
    Loop = 5000;

    while(I < Loop) {
        MOL *= (THREE + (I * 2)) * (FOUR + (I * 2));

        DEN *= (ONE + I) * (ONE + I);

        PI += DEN / MOL;

        I++;
    }
    
    PI = mp::sqrt(PI * 9);
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
