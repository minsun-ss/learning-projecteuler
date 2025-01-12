#include "euler.hpp"

using namespace std;

int findPowerFive(int n) {
    std::vector<int> pows;
    for (int i=3; i < 1000000; i++) {
        std::string svalue = std::to_string(i);
        long sum = 0;
        for (size_t j=0; j < svalue.size(); j++) {
            std::string ssvalue(1, svalue[j]);
            sum += pow(std::stoi(ssvalue),n);
        }
        if (sum == i) {
            cout << sum << "\n";
            pows.push_back(sum);
        }
    }

    int sumpows = 0;
    for (const auto& i: pows) {
        sumpows += i;
    }
    return sumpows;
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(findPowerFive, 5);
    cout << "Sum of 5 powers: " << result << "\n";
    cout << "Duration(ns): " << duration << "\n";
    return 0;
}
