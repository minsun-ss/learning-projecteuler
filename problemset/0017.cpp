#include "euler.hpp"

using namespace std;
using namespace euler;

// only will work for 9999 and below
string stringify(int n) {
    std::unordered_map<string, string> intmap{
        {"0","zero"}, {"1", "one"}, {"2", "two"}, {"3", "three"}, {"4", "four"}, {"5", "five"},
        {"6", "six"}, {"7", "seven"}, {"8", "eight"}, {"9", "nine"}, {"10", "ten"}, {"11", "eleven"},
        {"12", "twelve"}, {"13", "thirteen"}, {"14", "fourteen"}, {"15", "fifteen"},
        {"16", "sixteen"}, {"17", "seventeen"}, {"18", "eighteen"}, {"19", "nineteen"},
        {"20", "twenty"}, {"30", "thirty"}, {"40", "forty"}, {"50", "fifty"}, {"60", "sixty"},
        {"70", "seventy"}, {"80", "eighty"}, {"90", "ninety"}
    };

    string stringified_num = "";
    if (n > 999) {
        return "one thousand";
    }

    if (n >99) {
        auto hundreds = string(1,to_string(n)[0]);
        stringified_num = intmap[hundreds] + " hundred";
        n -= stoi(hundreds)*100;
        if (n > 0) {
            stringified_num += " and ";
        } else {
            return stringified_num;
        }
    }

    auto tens = to_string(n);

    if (intmap.find(tens) != intmap.end()) {
        stringified_num += intmap[tens];
        return stringified_num;
    } else {
        stringified_num += intmap[string(1,tens[0])+"0"];
        n -= stoi(string(1,tens[0]))*10;
        if (n > 0) {
            stringified_num += " " + intmap[to_string(n)];
        }
        return stringified_num;
    }

    return stringified_num;
}

size_t length(int n) {
    string nstring = stringify(n);
    string new_string = euler::sreplace(nstring, " ", "");
    return new_string.size();
}

int calc_length(int n) {
    int stringlen = 0;
    for (int i=1; i <= n; i++) {
        stringlen += length(i);
    }
    return stringlen;
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(calc_length, 1000);
    cout << "Number of letters: " << result << "\n";
    cout << "Nanoseconds: " << duration << "\n";
    return 0;
}
