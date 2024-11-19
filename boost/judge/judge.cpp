#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <gmpxx.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;

string getStringFromFile(const string& filePath) { 
    ifstream ifs(filePath, ios::binary);
     
    // ファイルサイズを得る
    ifs.seekg(0, ios::end);
    size_t sz = ifs.tellg();
    ifs.seekg(0, ios::beg);
     
    //ファイルサイズ分ファイルから読み込む
    vector<char> buf(sz);
    ifs.read(buf.data(), sz);

    //読み込んだcharデータからstringを作成
    return string(buf.data(), sz);
}

string removeEnter(string& str) {
    string restr = "";
    for (long long i = 0; i < str.size(); ++i) {
        if (str.at(i) == '\n') {
            continue;
        }
        restr.push_back(str.at(i));
    }

    return restr;
}

int  main (int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file path>" << endl;
        return 1;
    }

    string path = argv[1];

    string myPIa = getStringFromFile(path);
    string PIa = getStringFromFile("./pi100000.txt");

    string myPI = removeEnter(myPIa);
    string PI = removeEnter(PIa);
    
    myPI.insert(1, 1, '.');
    int digits = PI.size();
    int prec = digits * log2(10);
    mpf_set_default_prec(prec);


    mpf_class mypi(myPI);
    mpf_class pi(PI);

    cout << mypi - pi << endl;
    return 0;
}
