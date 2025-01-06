#include "euler.hpp"

using namespace std;
using namespace euler;

int num_type(int n){
    auto pdivisors = euler::proper_divisors(n);

    long psum = 0;
    for (const auto& i: pdivisors) {
        psum += i;
    }

    // euler::print(pdivisors);
    if (psum == n) {
        return 0;
    } else if (psum < n) {
        return -1;
    } else {
        return 1;
    }
}

std::vector<int> all_anums(int n) {
    std::vector<int> pnums;

    for (int i=1; i <= n; i++) {
        if (num_type(i)>0) {
            pnums.push_back(i);
        }
    }
    return pnums;
}

long check_nums(int n) {
    std::set<int> available_nums;
    for (int i=1; i < 28123; i++) {
        available_nums.insert(i);
    }

    // now create the anums
    auto anums = all_anums(n);

    for (const auto&i: anums) {
        for (const auto&j: anums) {
            if ((i+j) <= n) {
                available_nums.erase(i+j);
            }
        }
    }

    long total_sum = 0;
    for (const auto&i: available_nums) {
        total_sum += i;
    }
    return total_sum;
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(check_nums, 28123);
    cout << "Sum of positive non-abundant divisor sum: " << result << "\n";
    cout.imbue(locale(""));
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
