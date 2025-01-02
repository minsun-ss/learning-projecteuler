#include "euler.hpp"

using namespace std;
using namespace euler;

long prime_sum(int num) {
    long prime_sum = 0;
    for (int i=2; i < num; i++) {
        if (euler::is_prime(i)) {
            prime_sum += i;
        }
    }
    return prime_sum;
}

int main(int, char**) {
    long psum = prime_sum(2000000);
    cout << "Prime sum: " << psum << "\n";
    return 0;
}
