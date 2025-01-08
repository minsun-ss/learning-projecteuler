#include "euler.hpp"

using namespace std;
using namespace euler;

// 2520 is the smallest number that can be divided by each of the numbers
// from 1 to 10 without any remainder.
//
// What is the smallest positive number that is evenly divisible by all of
// the numbers from 1 to 20?

std::unordered_map<int, int> get_factors(int num) {
  std::unordered_map<int, int> factors;

  int n = num;
  while (n != 1) {
    if (n == 0) {
      break;
    }

    if (euler::is_prime(n)) {
      factors[n] += 1;
      break;
    }

    for (int i = 2; i <= int(pow(n, 0.5)); i++) {
      if ((n % i == 0) && (euler::is_prime(i))) {
        factors[i] += 1;
        n /= i;
        break;
      }
    }
  }
  return factors;
}

int least_common_multiple(std::vector<int> nums) {
  int lcm = 1;
  std::unordered_map<int, int> all_factors;
  for (const auto& i : nums) {
    auto mp = get_factors(i);
    for (const auto& pair : mp) {
      if (pair.second > all_factors[pair.first]) {
        all_factors[pair.first] = pair.second;
      }
    }
  }

  for (const auto& kv : all_factors) {
    lcm *= pow(kv.first, kv.second);
  }
  return lcm;
}

int main() {
  std::vector<int> nums;
  for (int i = 0; i <= 20; i++) {
    nums.push_back(i);
  }

  auto [result, duration] = euler::ntime(least_common_multiple, nums);
  cout << "Least common multiple from 1-20: " << result << "\n";
  cout.imbue(locale(""));
  cout << "Duration (ns): " << duration << "\n";
  return 0;
}
