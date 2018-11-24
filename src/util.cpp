#include <ctime>
#include <cstring>
#include <iostream>
#include "util.hpp"

char* get_timestamp() {
  std::time_t now = time(nullptr);
  char* now_str = std::asctime(std::localtime(&now));
  now_str[std::strlen(now_str) - 1] = 0;
  return now_str;
}

void log(const char* message) {
  log(std::string(message));
}

void log(std::string message) {
  std::cout << "[" << get_timestamp() << "] " << message << std::endl;
}
