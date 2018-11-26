#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include "PrimeGenerator.hpp"
#include "util.hpp"

#define DATA_INDEX_LIMIT 100000

namespace fs = std::experimental::filesystem;

bool PrimeGenerator::load() {
  if (!fs::is_directory("data")) {
    return false;
  }
  std::vector<long> data_indices;
  for (auto& p : fs::directory_iterator("data")) {
    data_indices.push_back(stoi(p.path().filename().string()));
  }
  std::sort(data_indices.begin(), data_indices.end());
  for (long index : data_indices) {
    std::ifstream stream("data/" + std::to_string(index));
    std::string line;
    while (std::getline(stream, line)) {
      Prime prime;
      std::istringstream str_stream(line);
      while (str_stream >> prime) {
        this->primes.push_back(prime);
      }
    }
    stream.close();
  }
  log("Loaded " + std::to_string(this->primes.size()) + " primes.");
  return true;
}

void PrimeGenerator::save() {
  if (!fs::is_directory("data")) {
    fs::create_directory("data");
  }
  Prime last_index = 0;
  for (auto& p : fs::directory_iterator("data")) {
    last_index = std::stoi(p.path().filename().string());
  }
  for (unsigned int k = last_index; k < this->primes.size(); k += DATA_INDEX_LIMIT) {
    std::ofstream stream("data/" + std::to_string(k));
    for (unsigned int i = k; i < k + DATA_INDEX_LIMIT && i < this->primes.size(); i++) {
      stream << this->primes[i] << " ";
    }
    stream.close();
  }
}
