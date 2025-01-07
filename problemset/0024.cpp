#include "euler.hpp"

using namespace std;
using namespace euler;

long permutations(int place) {
    // 10 factorial is like 3mm numbers, that can fit
    vector<string> nums = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<string> placeholder = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<string> final_nums;

    for (int i=0; i < 9; i++) {
        for (const auto&i: nums) {
            for (const auto&j: placeholder) {
                if (j.find(i) == string::npos) {

                    final_nums.push_back(i+j);
                }
            }
        }
        placeholder = final_nums;
        final_nums = {};
    }

    vector<long> final_ints;
    sort(placeholder.begin(), placeholder.end());
    long idx = 0;
    final_ints.push_back(stol(placeholder[0]));
    for (size_t i=1; i < placeholder.size(); i++) {
        long n = stol(placeholder[i]);
        if (n != final_ints[idx]) {
            final_ints.push_back(n);
            idx += 1;
        }
    }

    return final_ints[place-1];
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(permutations, 1000000);
    cout << "1,000,000th place: " << result << "\n";
    cout.imbue(locale(""));
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
