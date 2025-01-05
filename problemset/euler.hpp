#include <chrono>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <optional>
#include <set>
#include <map>
#include <concepts>

namespace euler {

// math related
bool is_prime(long);

// string related
std::string read(std::string);
std::string& sreplace(std::string&, std::string, std::string);
std::string strip(const std::string&);
std::vector<std::string> split(std::string&, const std::string&);


template <typename Container>
concept HasPair = requires(Container c) {
    typename Container::value_type::first_type;
    typename Container::value_type::second_type;
};

template <typename Container>
void print(const Container& c) {
    if constexpr (HasPair<Container>) {
        std::cout << "{ ";
        for (const auto& [key, value] : c) {
            std::cout << key << ": " << value << ", ";
        }
        std::cout << "}\n";
    } else {
        std::cout << "[ ";
        for (const auto& i : c) {
            std::cout << i << ", ";
        }
        std::cout << "]\n";
    }
}

// still don't know templates that well...
template <typename F, typename... Args>
auto ntime(F func, Args&&... args) {
  auto start = std::chrono::high_resolution_clock::now();
  auto result = std::forward<F>(func)(std::forward<Args>(args)...);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = (end-start);
  // auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
      // .count();
  return std::make_pair(result, duration);
}

}  // namespace euler
