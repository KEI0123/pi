#include <chrono>
#include <iostream>

using namespace std;

/* ------------------------------------------------------ */
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

//namespace mp = boost::multiprecision;
//typedef mp::number<mp::cpp_dec_float<1000>> FLOAT;

#include <gmpxx.h>
/* ------------------------------------------------------ */

int main() {
    int digi = 1000;
    int prec = digi * log2(10);

    mpf_set_default_prec(prec);

    mpf_class ONE, THREE, PI;
          
    std::chrono::system_clock::time_point start, end;
    start = std::chrono::system_clock::now();          // 計測開始時間

    PI = 0;
    ONE = 1;
    THREE = 3;
    long long Loop = 100000;

    for (long long i = 1; i <= Loop; ++i) {
        PI += ((1 / ONE) - (1 / THREE));
        ONE += 4;
        THREE += 4;
    }

    PI *= 4;

    cout << setprecision(digi) << PI << endl;

    end = chrono::system_clock::now();  // 計測終了時間
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end - start)
                         .count();  // 処理に要した時間をミリ秒に変換
    cout << "ms : " << elapsed << endl;

    return 0;
}
