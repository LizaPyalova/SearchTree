#include<iostream>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    long long mod = 1000000007, num = 1, den = 1, res = 1;
    for (int i = K + 1; i <= N; ++i) {
        num = (num * i) % mod;
    }
    for (int i = 1; i < N - K+1; ++i) {
        den = (den * i) % mod;
    }
    long long mod2 = mod - 2;
    while (mod2) {
        if ((mod2) % 2 == 1) {
            res = (res * den) % mod;
        }
        den = (den * den) % mod;
        mod2 >>= 1;
    }
    
    cout << (num * res) % mod;
    return 0;
}
