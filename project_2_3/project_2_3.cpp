#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "NumberConverter.h"

// std::vector<double> readInVector(std::string s) {
//   int prev_location = 0;
//   int next_location = 0;
//   std::vector<double> result;
//   while(s.find(',', prev_location) != std::string::npos) {
//     next_location = s.find(',', prev_location);
//     //std::cout << "prev_location: " << prev_location << std::endl;
//     //std::cout << "next_location: " << next_location << std::endl;
//     // substr [,]
//     //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
//     result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
//     next_location++;
//     prev_location = next_location;
//   }
//   result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
//   return result;
// }

int main() {
  std::string s;
  std::cin >> s;
  int dec_output = 0;
  int digit = s.size() - 1;
  for (int i = 0; i < s.size(); i++) {
    dec_output += std::pow(16, digit);
  }
}
