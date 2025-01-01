#include "euler.hpp"

using namespace std;
using namespace euler;

// By listing the first six prime numbers, 2, 3, 5, 7, 11, 13 we can see the 6th
// prime is 13.
//
// What is the 10,001 prime number?

long find_prime(long n) {
  int prime_counter = 1;
  long num_to_check = 2;
  while (prime_counter <= n) {
    if (euler::is_prime(num_to_check)) {
      // cout << prime_counter << " is prime: " << num_to_check << "\n";
      if (prime_counter == n) {
        return num_to_check;
      }
      prime_counter++;
    }
    num_to_check++;
  }
  return -1;
}

int main() {
  long val = find_prime(10001);
  long timer = euler::ntime(find_prime, 10001);
  cout << "Last available prime is: " << val << "\n";
  cout << "Time: " << timer << "ns\n";
  return 0;
}
