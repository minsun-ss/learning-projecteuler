#include "euler.hpp"

using namespace std;
using namespace euler;

// compares every 2 items in a vector and return max of each two
std::vector<int> compare_int(std::vector<int> nums) {
    std::vector<int> max_nums;

    for (size_t i=0; i < nums.size()-1; i++) {
        if (nums[i] > nums[i+1]) {
            max_nums.push_back(nums[i]);
        } else {
            max_nums.push_back(nums[i+1]);
        }
    }
    return max_nums;
}

std::vector<int> to_string(string s) {
    s = euler::strip(s);
    std::vector<string> nums = euler::split(s, " ");
    std::vector<int> inums;
    for (size_t i = 0; i < nums.size(); i++) {
        inums.push_back(stoi(nums[i]));
    }
    return inums;
}

int process(std::vector<string>& triangle) {
    // process very last row at least once
    std::vector<int> max = compare_int(
        to_string(triangle[triangle.size()-1])
    );

    for (int i=triangle.size()-2; i >= 0; i--) {
        std::vector<int> s = to_string(triangle[i]);
        // add the prev row to this and max out
        for (size_t j=0; j < s.size(); j++) {
            s[j] += max[j];
        }
        if (s.size() == 1) {
            return s[0];
        }
        // otherwise keep shrinking and move on
        max = compare_int(s);
    }
    return -1;
}

int main(int, char**) {
    auto striangle = euler::strip(euler::read("problemset/0018.txt"));
    auto triangle = euler::split(striangle, "\n");
    auto [result, duration] = euler::ntime(process, triangle);
    cout << "Max sum: " << result << "\n";
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
