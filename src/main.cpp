#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define Prime long long

std::vector<Prime> primes;

bool load() {
	std::ifstream stream("primes.txt");
	if (!stream.is_open()) return false;
	std::string line;
	while (std::getline(stream, line)) {
		Prime prime;
		std::istringstream str_stream(line);
		while (str_stream >> prime) {
			primes.push_back(prime);
		}
	}
	std::cout << "Loaded " << primes.size() << " primes." << std::endl;
	stream.close();
	return true;
}

void save() {
	std::ofstream stream("primes.txt");
	for (unsigned int i = 0; i < primes.size(); i++) {
		stream << primes[i] << " ";
	}
	stream.close();
}

bool is_prime(Prime val) {
	for (unsigned int i = 0; i < primes.size(); i++) {
		if (val % primes[i] == 0) {
			return false;
		}
	}
	return true;
}

Prime next() {
	Prime i = primes.back() + 1;
	while (!is_prime(i)) {
		i++;
	}
	return i;
}

int main(int argc, char** argv) {
	long long limit = 100;
	if (argc > 1) {
		try {
			limit = std::stoi(argv[1]);
		} catch (std::invalid_argument ex) {
			limit = 0;
		}
	}
	if (!load()) primes.push_back(2);
	while (primes.size() < limit) {
		primes.push_back(next());
		std::time_t now  = time(nullptr);
		char* now_str = std::asctime(std::localtime(&now));
		now_str[std::strlen(now_str) - 1] = 0;
		if (primes.size() % 1000 == 0) {
			std::cout << "[" << now_str << "] Found " << primes.size() << " primes." << std::endl;
		}
		if (primes.size() % 10000 == 0) {
			save();
			std::cout << "[" << now_str << "] Saved primes to disk." << std::endl;
		}
	}
	std::cout << primes.back() << std::endl;
	return 0;
}
