#include "euler.hpp"

using namespace std;
using namespace euler;

long really_big_sum(vector<string>& nums) {
    std::vector<int> singles;
    long carry = 0;
    for (int i = nums[0].size()-1; i >= 0; i--) {
        long single = 0;
        for (const auto& j: nums) {
            single += stoi(string(1, j[i]));
        }
        single += carry;
        // reset carry
        carry = 0;

        // converto string, push back singles, carry the rest
        string ssingle = to_string(single);
        singles.push_back(stoi(string(1, ssingle[ssingle.size()-1])));

        carry = stoi(ssingle.substr(0, ssingle.size()-1));
    }
    string full_carry = to_string(carry);
    for (size_t i=singles.size()-1; i > singles.size()-9; i--) {
        full_carry += to_string(singles[i]);
    }
    return stol(full_carry);
}

int main(int, char**) {
    auto snums = euler::read("problemset/0013.txt");
    snums = euler::strip(snums);
    auto nums = euler::split(snums, "\n");

    auto [result, duration] = euler::ntime(really_big_sum, nums);
    cout << "First ten digits: " << result << "\n";
    cout << "Time to function: " << duration << "ns\n";
    return 0;
}
