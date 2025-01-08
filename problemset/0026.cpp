#include "euler.hpp"

using namespace std;
using namespace euler;

int repeating_divisor(int n) {
    if (n % 2 == 0) {
        return 0;
    }

    std::set<int> remainders;
    int carry = 1;
    while (true) {
        if (carry == 0) {
            return 0;
        }

        if (carry < n) {
            carry *= 10;
        } else {
            int val = carry / n;
            carry -= (val * n);
            if (remainders.find(carry) != remainders.end()) {
                break;
            }
            remainders.insert(carry);
        }
    }

    // euler::print(remainders);
    return remainders.size();
}

int repeating_length(int n) {
    int longest_length = 0;
    int d = 0;
    for (int i=0; i < n; i++) {
        int val = repeating_divisor(i);
        if (val > longest_length) {
            longest_length = val;
            d = i;
        }
    }
    return d;
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(repeating_length, 1000);
    cout << result << "\n";
    cout << duration << "\n";
    return 0;
}
