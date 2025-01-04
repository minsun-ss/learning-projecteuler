#include "euler.hpp"

using namespace std;
using namespace euler;

int lets_just_add(int n) {
    std::vector<int> digits(400,0);
    digits[0] = 2;
    int carry = 0;

    for (int i=2; i<=n; i++) {
        carry = 0;
        for (size_t j=0; j<digits.size(); j++) {
            int new_digit = (digits[j] * 2) + carry;
            if (new_digit >= 10) {
                carry = 1;
                new_digit -= 10;
                digits[j] = new_digit;
            } else{
                carry = 0;
                digits[j] = new_digit;
            }
        }
    }
    if (carry == 1) {
        digits.push_back(1);
    }

    int final_sum = 0;
    for (const auto& i: digits) {
        final_sum += i;
    }
    return final_sum;
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(lets_just_add, 1000);
    cout << "Final digit sum is " << result << "\n";
    cout << "Time nanoseconds: " << duration << "\n";
    return 0;
}
