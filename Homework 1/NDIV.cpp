#include <bits/stdc++.h>

using namespace std;

void getPrimes(vector<int> &primes) {
    int limit = (int)sqrt(1000000000) + 1;
    bool isPrime[limit];
    memset(isPrime, true, sizeof(isPrime));
    primes.push_back(2);
    for (int i = 3; i <= limit; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
}

void getPrimeFact(int num, vector<int> &primes, map<int, int> &primeFact) {
    if (num == 1) return;
    for (int i = 0; i < primes.size() && primes[i] <= num; i++)
        if (num % primes[i] == 0) {
            if (primeFact.find(i) != primeFact.end()) primeFact[i]++;
            else primeFact[i] = 1;
            getPrimeFact(num / primes[i], primes, primeFact);
            return;
        }
    primeFact[num] = 1;
}

int getNDiv(int num, vector<int> &primes) {
    int result = 1;
    map<int, int> primeFact;
    getPrimeFact(num, primes, primeFact);
    for (auto i = primeFact.begin(); i != primeFact.end(); i++) 
        result *= (*i).second + 1;
    return result;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    if (n == 1) {
        if (a == 1) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    vector<int> primes;
    getPrimes(primes);
    int result = 0;
    for (int i = a; i <= b; i++) 
        if (n == getNDiv(i, primes)) result++;
    cout << result << endl;
}