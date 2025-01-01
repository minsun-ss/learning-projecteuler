#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>


namespace euler {
    bool is_prime(long);

    template<typename K, typename V>
    void print(const std::unordered_map<K, V>& kv) {
        std::cout << "{ ";
        for (const auto& i: kv) {
            std::cout << i.first << ": " << i.second << " ";
        }
        std::cout << "}\n";
    }
}
