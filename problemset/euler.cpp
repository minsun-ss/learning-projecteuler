#include "euler.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>


namespace euler {
// math related
bool is_prime(long num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= int(pow(num, 0.5)); i++) {
        if (num % i == 0) {
        return false;
        }
    }
    return true;
}

std::vector<long> proper_divisors(long n) {
    std::vector<long> divisors;
    divisors.push_back(1);

    for (long i=2; i <= pow(n, 0.5); i++) {
        if (n%i==0) {
            if (i != n/i) {
                // insert appears to be a lot faster than 2 pushbacks
                divisors.insert(divisors.end(), {i, n/i});
            } else {
                divisors.push_back(i);
            }
        }
    }
    return divisors;
}

// string related
std::string read(std::string filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << filename << " did not open successfully. Does it exist?\n";
        throw std::runtime_error("Failed to open file");
    }

    std::stringstream buf;
    buf << file.rdbuf();
    std::string sbuf = buf.str();
    return sbuf;
}

std::string& sreplace(std::string& orig, std::string from, std::string to) {
    size_t pos = 0;
    while ((pos = orig.find(from)) != std::string::npos) {
        orig.replace(pos, from.size(), to);
    }
    return orig;
}

std::string strip(const std::string& str) {
    std::string s = str;
    s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
    s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1);
    return s;
}

std::vector<std::string> split(std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t beg = 0;
    size_t end = str.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(str.substr(beg, end - beg));
        beg = end+1;
        end = str.find(delimiter, beg);
    }

    // push in last token
    tokens.push_back(str.substr(beg));
    return tokens;
}

}  // namespace euler
