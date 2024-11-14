#include <chrono>
#include <iostream>

using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace mp = boost::multiprecision;
//typedef mp::number<mp::cpp_dec_float<1000>> FLOAT;
typedef mp::cpp_dec_float_100 FLOAT;

FLOAT Permutation(long long n, long long m) {
    FLOAT result = 1.0f;
    for(long long i = n; i <= m; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    FLOAT A, B, C, PI;

    const long long Loop = 1;
    A = 13591409.0f;
    B = 545140134.0f;
    C = 640320.0f;
    PI = 1.0f;

    FLOAT C3, I3, DEN, MOL;
    C3 = C * C * C;

    for (long long I = Loop; 0 <= I; --I) {
        I3 = (I + 1) * (I + 1) * (I + 1);

        MOL = (-1) * Permutation((6 * I) + 1, 6 * (I + 1));

        DEN = Permutation((3 * I) + 1, 3 * (I + 1)) * I3 * C3;
        
        PI *= ((A + (B * I)) + (MOL / DEN));
    }
    PI = mp::sqrt(C3) / (PI * 12);

    cout << setprecision(numeric_limits<decltype(PI)>::digits10 + 1) << PI << endl;
          
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();          // 計測開始時間


    end = chrono::system_clock::now();  // 計測終了時間
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end - start)
                         .count();  // 処理に要した時間をミリ秒に変換
    cout << "ms : " << elapsed << endl;

    return 0;
}
