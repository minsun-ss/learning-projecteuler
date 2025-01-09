#include "euler.hpp"

using namespace std;
using namespace euler;

int consec_primes(int a, int b) {
    int maxprime = 0;
    int coefa = 0;
    int coefb = 0;
    if (a > b) {
        cout << "";
    }
    for (int i=(-1*a+1); i<a; i++ ) {
        for (int j=(-1*b); j<=b; j++) {
            // cout << "Testing a: " << i << " b: " << j;
            int n = 0;
            while (true) {
                long val = pow(n,2) + (i*n) + j;
                // cout << val << "\n";
                if (!euler::is_prime(val)) {
                    n -= 1;
                    break;
                } else {
                    n += 1;
                }
            }

            if (n > maxprime) {
                maxprime = n;
                coefa = i;
                coefb = j;
            }
            // cout << "\n";
        }
    }
    cout << "maxprimes: " << maxprime << " " << coefa << " " << coefb << "\n";
    return coefa * coefb;
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(consec_primes, 1000, 1000);
    cout << "Prime coefficient product: " << result << "\n";
    cout << "Duration (ns): " << duration << "\n";
    return 0;

}
