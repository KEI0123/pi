#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
namespace mp = boost::multiprecision;

constexpr long Loop = 100000;

typedef mp::cpp_dec_float_100 FLOAT;
//typedef mp::number<mp::cpp_dec_float<5000>> FLOAT;
//typedef mp::cpp_int INT;

random_device rand_gen;
mt19937 engine(rand_gen());

bool touch(double miny, double maxy) {
    for (int i = 0; i < 25; ++i) {
        if (i * 2 >= miny && i * 2 <= maxy)
            return true;
    }
    return false;
}

int main () {
    uniform_real_distribution<long double> dist(0, 22);
    uniform_real_distribution<long double> dists(0, 1);

    long long cou = 0;
    for (long long i = 0; i < Loop; ++i) {
        double mid_posy = dist(engine);
        double mid_posx = dist(engine);

        double hposy = dists(engine);
        double hposx = dists(engine);
        double lposy = dists(engine);
        double lposx = dists(engine);
    
        double y = hposy - lposy;
        double x = hposx - lposx;

        double sin = y / sqrt(x * x + y * y);
        double cos = x / sqrt(x * x + y * y);

        sin += mid_posy;
        cos += mid_posx;

        double maxy = max(mid_posy, sin);
        double miny = min(mid_posy, sin);

        if (touch(miny, maxy))
            cou++;
    }
    
    if (cou != 0) {
        FLOAT PI = FLOAT(Loop) / FLOAT(cou);
        cout << setprecision(numeric_limits<decltype(PI)>::digits10 + 1) << PI << endl;
    }
    else
        cout << "Agein" << endl;
}
