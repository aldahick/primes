#include <cmath>
#include "PrimeGenerator.hpp"

PrimeGenerator::PrimeGenerator() {
  if (!this->load()) {
    this->primes.push_back(2);
  }
}

bool PrimeGenerator::is_prime(Prime value) {
  for (unsigned int i = 0; i < this->primes.size(); i++) {
    if (i > sqrt(value)) {
      return true;
    }
    if (value % this->primes[i] == 0) {
      return false;
    }
  }
  return true;
}

Prime PrimeGenerator::next() {
  Prime i = this->primes.back() + 1;
  while (!this->is_prime(i)) {
    i++;
  }
  this->primes.push_back(i);
  return i;
}
