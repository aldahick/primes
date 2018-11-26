#include <experimental/filesystem>
#include <fstream>
#include "PrimeGenerator.hpp"
#include "util.hpp"

namespace fs = std::experimental::filesystem;

int convert_v1() {
  std::ifstream infile("primes.txt");
  std::string line;
  PrimeGenerator generator;
  while (std::getline(infile, line)) {
    Prime prime;
    std::istringstream tokens(line);
    while (tokens >> prime) {
      generator.primes.push_back(prime);
    }
  }
  infile.close();
  log("Loaded " + std::to_string(generator.primes.size()) + " primes.");
  generator.save();
}
