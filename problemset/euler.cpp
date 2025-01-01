#include "euler.hpp"

using namespace std;

namespace euler {
    bool is_prime(long num) {
        for (int i=2; i <= int(pow(num, 0.5)); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
