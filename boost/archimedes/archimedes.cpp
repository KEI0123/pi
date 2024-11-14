#include <chrono>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
namespace mp = boost::multiprecision;

//typedef mp::cpp_dec_float_100 FLOAT;
typedef mp::number<mp::cpp_dec_float<5000>> FLOAT;
typedef mp::cpp_int INT;

int main () {
    FLOAT A, MINPI, MAXPI;
    INT NUM;

    MINPI = 0;
    MAXPI = 0;

    cout << "please enter number. " << endl;

    cin >> NUM;

    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();


    for (INT i = 1; i <= NUM - 1; ++i) {
        A = (FLOAT(NUM) * FLOAT(NUM)) - (FLOAT(i) * FLOAT(i));
        MINPI += mp::sqrt(A);
    }
    MINPI = FLOAT(4) / (FLOAT(NUM) * FLOAT(NUM)) * MINPI;

    end = chrono::system_clock::now();
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();

    cout << "ms : " << elapsed << endl;
    
    cout << setprecision(numeric_limits<decltype(MINPI)>::digits10 + 1) << MINPI << endl;
    //cout << setprecision(200) << PI << endl;
    
}
