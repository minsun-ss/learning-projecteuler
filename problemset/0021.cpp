#include "euler.hpp"

using namespace std;
using namespace euler;

int sum_proper_divisor(int n) {
    int sum_proper_divisor = 1;

    for (int i=2; i <= pow(n, 0.5); i++) {
        if (n%i==0) {
            if (i != n/i) {
                // insert appears to be a lot faster than 2 pushbacks
                // divisors.insert(divisors.end(), {i, n/i});
                sum_proper_divisor += i + n/i;
            }
        }
    }
    return sum_proper_divisor;
}

int amicable_pairs(int n) {
    std::set<int> amicable_numbers;

    for (int i=1; i<n; i++) {
        int pd = sum_proper_divisor(i);
        if ((sum_proper_divisor(pd) == i) && (pd != i)) {
            // we have found amicable items
            amicable_numbers.insert({i, pd});
        }
    }

    int amicable_sum = 0;
    for (const auto& i: amicable_numbers) {
        amicable_sum += i;
    }
    return amicable_sum;
}



int main(int, char**) {
    auto [result, duration] = euler::ntime(amicable_pairs, 10000);

    cout << "Amicable sum under 10000: " << result << "\n";
    cout.imbue(locale(""));
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
