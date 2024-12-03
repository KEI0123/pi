#include <chrono>
#include <iostream>
#include <random>

/* ------------------------------------------------------ */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
/* ------------------------------------------------------ */

using namespace std;

long long NUM = 10000;

int main() {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);

    std::chrono::system_clock::time_point start, end;
    start = std::chrono::system_clock::now();  // 計測開始時間

    Real x, y;
    long long cou = 0;
    for (int i = 0; i < NUM; i++) {
        x = dist(mt);
        y = dist(mt);
        if (x * x + y * y < 1.0) {
            cou++;
        }
    }
    Real pi = 4.0 * cou / NUM;
    cout << pi << endl;

    end = chrono::system_clock::now();  // 計測終了時間
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end - start)
                         .count();  // 処理に要した時間をミリ秒に変換
    cout << "ms : " << elapsed << endl;

    return 0;
}
