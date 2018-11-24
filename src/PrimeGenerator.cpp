#include <fstream>
#include <iostream>
#include <sstream>
#include "PrimeGenerator.hpp"
#include "util.hpp"

PrimeGenerator::PrimeGenerator() {
  if (!this->load()) {
    this->primes.push_back(2);
  }
}

bool PrimeGenerator::load() {
  std::ifstream stream("primes.txt");
  if (!stream.is_open()) return false;
  std::string line;
  while (std::getline(stream, line)) {
    Prime prime;
    std::istringstream str_stream(line);
    while (str_stream >> prime) {
      this->primes.push_back(prime);
    }
  }
  log("Loaded " + std::to_string(this->primes.size()) + " primes.");
  stream.close();
  return true;
}

void PrimeGenerator::save() {
  std::ofstream stream("primes.txt");
  for (unsigned int i = 0; i < this->primes.size(); i++) {
    stream << this->primes[i] << " ";
  }
  stream.close();
}

bool PrimeGenerator::isPrime(Prime value) {
  for (unsigned int i = 0; i < this->primes.size(); i++) {
    if (value % this->primes[i] == 0) {
      return false;
    }
  }
  return true;
}

Prime PrimeGenerator::next() {
  Prime i = this->primes.back() + 1;
  while (!this->isPrime(i)) {
    i++;
  }
  this->primes.push_back(i);
  return i;
}
