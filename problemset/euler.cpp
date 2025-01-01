#include "euler.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>


namespace euler {
bool is_prime(long num) {
  for (int i = 2; i <= int(pow(num, 0.5)); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

std::string read(std::string filename) {
    //    std::cout << std::filesystem::current_path() << "\n";

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
        orig.replace(pos, 1, to);
    }
    return orig;
}

}  // namespace euler
