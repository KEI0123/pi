#include <iostream>

using namespace std;

// n を受け取って、0~n の総和を計算して返す関数
int sum(int n) {
  // ベースケース
  if (n == 0) {
    return 0;
  }

  // 再帰ステップ
  int s = sum(n - 1);
  return s + n;
}

int main() {
    int n;
    cin >> n;

    cout << sum(n) << endl;
}
