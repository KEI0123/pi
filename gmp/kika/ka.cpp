#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <gmpxx.h>
#include <cmath>
#include <vector>
#include <thread>
#include <mutex>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;

mutex mtx;

void worker_function(mpf_class A, mpf_class B, mpf_class T, mpf_class P, mpf_class &PI, int iterations) {
    mpf_class An, TWO = 2.0, AA, AAA, AAAA;

    for (int i = 0; i < iterations; ++i){
        AA = A + B;
        An = AA / 2;
        AAA = A * B;
        B = sqrt(AAA);
        AAAA = A - An;

        {
            lock_guard<mutex> lock(mtx);
            T -= P * (AAAA * AAAA);
            P *= 2;
            PI = (AA * AA) / (4 * T); // ここでPIを更新する必要はないかもしれません
        }

        A = An;
    }
}

int main () {
    long long digi = 1000;
    double log = 3.32192809489;
    long long prec = digi * log;

    mpf_set_default_prec(prec);

    mpf_class A = 1.0, B = 1 / sqrt(2.0), T = 0.25, P = 1.0;
    mpf_class PI = 0.0;

    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    int Loop = 20;
    int threads_count = 6;
    int iterations_per_thread = Loop / threads_count;

    vector<thread> threads;
    vector<mpf_class> PIs(threads_count);

    for (int i = 0; i < threads_count; ++i) {
        threads.emplace_back(worker_function, A, B, T, P, ref(PIs[i]), iterations_per_thread);
    }

    for (auto &th : threads) {
        th.join();
    }

    for (auto &val : PIs) {
        PI += val / threads_count;
    }

    end = chrono::system_clock::now();
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << setprecision(digi) << PI << endl;
    cout << "ms : " << elapsed << endl;

    char *str = nullptr;
    gmp_asprintf(&str, "%.Ff", PI.get_mpf_t());
    string result(str);
    string PIstr = str;
    string PIout = "";

    int i = 1;
    PIstr.erase(1, 1);
    for (char c : PIstr) {
        PIout.push_back(c);
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
