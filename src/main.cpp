#include <stdexcept>
#include "PrimeGenerator.hpp"
#include "util.hpp"

int main(int argc, char** argv) {
  long long limit = 100;
  if (argc > 1) {
    try {
      limit = std::stoi(argv[1]);
    } catch (std::invalid_argument ex) {
      limit = 0;
    }
  }
  PrimeGenerator generator = PrimeGenerator();
  while (generator.primes.size() < limit) {
    generator.next();
    if (generator.primes.size() % 1000 == 0) {
      log("Found " + std::to_string(generator.primes.size()) + " primes.");
    }
    if (generator.primes.size() % 10000 == 0) {
      generator.save();
      log("Saved primes to disk.");
    }
  }
  log(std::to_string(generator.primes.back()));
  return 0;
}
