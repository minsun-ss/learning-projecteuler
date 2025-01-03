#include <chrono>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <ranges>

namespace euler {

// math related
bool is_prime(long);

// string related
std::string read(std::string);
std::string& sreplace(std::string&, std::string, std::string);
std::string strip(const std::string&);
std::vector<std::string> split(std::string&, const std::string&);

/**
 * @brief pretty prints unordered maps
 * @tparam K key of pair
 * @tparam V value of pair
 * @param unordered map to print
 */
template <typename K, typename V>
void print(const std::unordered_map<K, V>& kv) {
  std::cout << "{ ";
  for (const auto& i : kv) {
    std::cout << i.first << ": " << i.second << " ";
  }
  std::cout << "}\n";
}

/**
* @brief pretty prints those container that don't contain a pair
* @tparam T container value
* @param T container
*/
template<typename T>
void print(const T& t) {
    std:: cout << "[ ";
    for (const auto& i : t) {
        std:: cout << i << ", ";
    }
    std:: cout << "]\n";
}

// todo - refactor later because think this timing is a bit bad but good enough
// for a proxy for now
template <typename F, typename... Args>
long long int ntime(F func, Args&&... args) {
  auto start = std::chrono::high_resolution_clock::now();
  func(std::forward<Args>(args)...);
  auto end = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
      .count();
}

}  // namespace euler
