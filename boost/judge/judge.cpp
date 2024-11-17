#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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

int  main () {
    cout << "Please enter pi.txt path : ";
    string path = "";
    cin >> path;

    string myPIa = getStringFromFile(path);
    string PIa = getStringFromFile("./pismall.txt");

    string myPI = removeEnter(myPIa);
    string PI = removeEnter(PIa);


    for (long long i = 0; i < myPI.size(); ++i) {
        if (myPI.at(i) != PI.at(i)) {
            cout << i << endl;
            cout << "This is true : ";
            for (long long j = 0; j < i; ++j) {
                cout << myPI.at(j);
            }
            cout << endl;
            return 0;
        }
    }
}
