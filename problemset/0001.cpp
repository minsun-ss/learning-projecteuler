#include "euler.hpp"

using namespace std;
using namespace euler;

// If we list all natural numbers below 10 that are multiples of 3 or 5, we get
// 3, 5, 6, or 9 The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.

int fizzbuzz(int n) {
    int multiple_sum = 0;
    for (int i = 1; i < n; i++) {
      if (i % 3 == 0) {
        multiple_sum += i;
      } else if (i % 5 == 0) {
        multiple_sum += i;
      }
    }
    return multiple_sum;
}

int main() {
    auto [result, duration] = euler::ntime(fizzbuzz, 1000);
    cout << "Sum of multiples: " << result  << "\n";
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
