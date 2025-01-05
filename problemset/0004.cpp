#include "euler.hpp"
using namespace std;

// Largest Palindrome Product
// A palindromic number reads the same both ways. The largest product made from
// the product of two 2-digit numbers is 9009 = 91 * 99.
//
// Find the largestt palindrome made from the product of two 3 digit numbers.

int is_palindrome(int num) {
  string val = to_string(num);
  for (size_t i = 0; i < val.size(); i++) {
    if (val[i] != val[val.size() - 1 - i]) {
      return false;
    }
  }
  return true;
}

int highest_palindrome(int digits) {
  int highest_palindrome = 0;
  auto ceiling = pow(10, digits) - 1;
  auto floor = pow(10, digits - 1) - 1;
  for (int i = ceiling; i > floor; i--) {
    for (int j = ceiling; j > floor; j--) {
      auto possibly_palindrome = i * j;
      if (is_palindrome(possibly_palindrome)) {
        if (possibly_palindrome > highest_palindrome) {
          highest_palindrome = possibly_palindrome;
        }
      }
    }
  }
  return highest_palindrome;
}

int main() {
    auto [result, duration] = euler::ntime(highest_palindrome, 3);
    cout << "Highest palindrome is " << result << "\n";
    cout.imbue(locale(""));
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
