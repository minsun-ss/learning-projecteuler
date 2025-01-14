#include "euler.hpp"

using namespace std;
using namespace euler;

// The prime factors of 13195 are 5, 7, 13, 29
// What is the largest prime factor of the number 600851475143?

int largest_factor(long num) {
  std::vector<int> factors;

  for (int i = 2; i <= int(pow(num, 0.5)); i++) {
    if ((num % i == 0) && euler::is_prime(i)) {
      factors.push_back(i);
    }
  }
  if (factors.size() == 0) {
    return 1;
  } else {
    return factors[factors.size() - 1];
  }
}

int main() {
    auto [result, duration] = euler::ntime(largest_factor, 600851475143);
    cout << "Largest prime factor: " << result << "\n";
    cout.imbue(locale(""));
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
