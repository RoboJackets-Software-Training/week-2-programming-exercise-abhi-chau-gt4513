#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "NumberConverter.h"

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
  	next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  NumberConverter num_convert;

  char in;
  std::cin >> in;
  std::string out;
  std::cin >> out;
  if (in == 'b') {
    if (out.compare("0x") == 0) {      // convert binary to hex
      std::string s;
      std::cout << "input: ";
      std::cin >> s;
      std::cout << "output type: h\n" << "result: " << num_convert.binaryToHex(s) << std::endl;
      std::cout << "decimal_inputs: 0\n" << "binary_inputs: 1\n" << "hex_inputs: 0\n";
      std::cout << "decimal_outputs: 0\n" << "binary_outputs: 0\n" << "hex_outputs: 1\n";
    } else if (out.compare("b") == 0) {// nothing happens

    } else {                // convert binary to decimal
      std::string s;
      std::cout << "input: ";
      std::cin >> s;
      std::cout << "output type: d\n" << "result: " << num_convert.hexCharToDecimal(num_convert.binaryToHex(s)) << std::endl;
      std::cout << "decimal_inputs: 0\n" << "binary_inputs: 1\n" << "hex_inputs: 0\n";
      std::cout << "decimal_outputs: 1\n" << "binary_outputs: 0\n" << "hex_outputs: 0\n";
    }
  } else if (in == 'd') {
    if (out.compare("0x") == 0) {      // convert decimal to hex
      int input;
      std::cout << "input: ";
      std::cin >> input;
      std::cout << "output type: h\n" << "result: " << num_convert.decimalToHex(input) << std::endl;
      std::cout << "decimal_inputs: 1\n" << "binary_inputs: 0\n" << "hex_inputs: 0\n";
      std::cout << "decimal_outputs: 0\n" << "binary_outputs: 0\n" << "hex_outputs: 1\n";
    } else if (out.compare("b") == 0) { // convert decimal to binary 
      int input;
      std::cout << "input: ";
      std::cin >> input;
      std::cout << "output type: b\n" << "result: " << num_convert.decimalToBinary(input) << std::endl;
      std::cout << "decimal_inputs: 1\n" << "binary_inputs: 0\n" << "hex_inputs: 0\n";
      std::cout << "decimal_outputs: 0\n" << "binary_outputs: 1\n" << "hex_outputs: 0\n";
    } else {                // nothing happens
      
    }
  } else if (in == 'h') {
    if (out.compare("0x") == 0) {      // nothing happens
      
    } else if (out.compare("b") == 0) { // convert hex to binary 
      int input;
      std::cout << "input: ";
      std::cin >> input;
      std::cout << "output type: b\n" << "result: " << num_convert.hexCharToDecimal(num_convert.decimalToBinary(input)) << std::endl;
      std::cout << "decimal_inputs: 0\n" << "binary_inputs: 0\n" << "hex_inputs: 1\n";
      std::cout << "decimal_outputs: 0\n" << "binary_outputs: 1\n" << "hex_outputs: 0\n";
    } else {                // convert hex to decimal
      std::string s;
      std::cout << "input: ";
      std::cin >> s;
      std::cout << "output type: d\n" << "result: " << num_convert.hexCharToDecimal(s) << std::endl;
      std::cout << "decimal_inputs: 0\n" << "binary_inputs: 0\n" << "hex_inputs: 1\n";
      std::cout << "decimal_outputs: 1\n" << "binary_outputs: 0\n" << "hex_outputs: 0\n";
    }
  }

 //  // Convert hex to decimal
	// std::string s;
 //  std::cin >> s;
 //  std::cout << num_convert.hexCharToDecimal(s) << std::endl;

 //  // Convert decimal to hex
 //  int input = 679;
 //  std::cout << num_convert.decimalToHex(input) << std::endl;
  
 //  // Convert binary to hex
 //  std::string b_input = "11110000";
 //  std::cout << num_convert.binaryToHex(b_input) << std::endl;

 //  // Convert hex to binary
 //  // std::cin >> s;
 //  // std::cout <<  << std::endl;

 //  // Convert decimal to binary
 //  input = 679;
 //  std::cout << num_convert.decimalToBinary(input) << std::endl;
}