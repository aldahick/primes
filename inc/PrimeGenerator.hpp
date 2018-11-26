#ifndef PRIME_GENERATOR_HPP
#define PRIME_GENERATOR_HPP

#include <vector>

#define Prime long long

class PrimeGenerator {
public:
  PrimeGenerator();
  std::vector<Prime> primes;
  void save();
  bool is_prime(Prime value);
  Prime next();
private:
  bool load();
};

#endif
