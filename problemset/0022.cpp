#include "euler.hpp"

using namespace std;
using namespace euler;

long clean_names(string& snames) {
    vector<string> names = euler::split(snames, ",");
    sort(names.begin(), names.end());

    long name_scores = 0;
    for (size_t name_idx=0; name_idx < names.size(); name_idx++) {
        int name_value = 0;
        for (const auto&i: names[name_idx]) {
            name_value += int(i-64);
        }
        name_value *= (name_idx+1);
        name_scores += name_value;
    }
    return name_scores;
}


int main(int, char**) {
    string snames = euler::strip(euler::read("problemset/0022.txt"));
    snames = euler::sreplace(snames, "\"", "");
    auto [result, duration] = euler::ntime(clean_names, snames);
    cout << "Name scores: " << result << "\n";
    cout.imbue(locale(""));
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
