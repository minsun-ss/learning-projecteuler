#include "euler.hpp"

using namespace std;
using namespace euler;


int sum_digits(std::vector<int>& digits) {
    int sumDigits = 0;
    for (const auto&i: digits) {
        sumDigits += i;
    }
    return sumDigits;
}

int factorial(int n, int digitSize) {
    std::vector<int> digits(digitSize,0); // here we go again with digits...
    // set up n
    string nstr = to_string(n);
    for (int i=nstr.size()-1; i>=0; i--) {
        digits[nstr.size()-1-i] = stoi(string(1, nstr[i]));
    }

    for (int i=n-1; i>0; i--) {
        std::vector<int> digits_copy = digits;
        for (int counter=1; counter<i; counter++){
            int carry = 0;
            for (size_t j=0; j < digits.size(); j++) {
                int nv = (digits[j] + digits_copy[j]) + carry;
                if (nv >= 10) {
                    carry = 1;
                    nv -= 10;
                } else {
                    carry = 0;
                }
                digits[j] = nv;
            }
        }
    }
    return sum_digits(digits);
}


int main(int, char**) {
    auto [result, duration] = euler::ntime(factorial, 100, 200);
    cout << "Sum of 100!: " << result << "\n";
    cout << "Duration(ns): " << duration <<  "\n";
    return 0;
}
