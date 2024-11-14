#include <chrono>
#include <iostream>

using namespace std;

/* ------------------------------------------------------ */
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace mp = boost::multiprecision;
typedef mp::number<mp::cpp_dec_float<1000>> FLOAT;
/* ------------------------------------------------------ */

int main() {
    FLOAT ONE, THREE, PI, Loop;
          
    std::chrono::system_clock::time_point start, end;
    start = std::chrono::system_clock::now();          // 計測開始時間

    PI = 0.0f;
    ONE = 1.0f;
    THREE = 3.0f;
    Loop = 10000;

    for (long long i = 1; i <= Loop; ++i) {
        PI += ((1 / ONE) - (1 / THREE));
        ONE += 4;
        THREE += 4;
    }

    PI *= 4;

    cout << setprecision(numeric_limits<decltype(PI)>::digits10 + 1) << PI << endl;

    end = chrono::system_clock::now();  // 計測終了時間
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end - start)
                         .count();  // 処理に要した時間をミリ秒に変換
    cout << "ms : " << elapsed << endl;

    return 0;
}
