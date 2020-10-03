#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "NumberConverter.h"

/**
 * returns a number 0-15 based off of a hex char
 * This uses ascii to figure out number it corresponds to
 * @param input
 * @return int
 */
int NumberConverter::hexCharToNumber(char input) {
  // this means it is [A,B,C,D,E,F]
  if(input > 57) {
    return input - (65 - 10);
  } else {
    // this is a digit in ascii
    return input - 48;
  }
}


/**
 * returns the character that is the given hex number
 * only valid on 0-15
 * @param input
 * @return char
 */
char NumberConverter::numberToHexChar(int input) {
	if(input < 10) {
	  // it is a digit
	  return input + 48;
	} else {
	  return (input - 10) + 65;
	}
}

/**
 * returns the decimal that is the given string
 * @param input
 * @return dec_output
 */
int NumberConverter::hexCharToDecimal(std::string input) {
	int dec_output = 0;
  int digit = input.size() - 1;
  for (int i = 0; i < input.size(); i++) {
    if (digit >= 0) {
      dec_output += hexCharToNumber(input[i]) * std::pow(16, digit);
      digit--;
    }
    
  }
  return dec_output;
}

/**
 * returns the string of hex characters with the given integer
 * @param input
 * @return s
 */
std::string NumberConverter::decimalToHex(int input) {
	std::string s = "";
	char c;
	// int remainder;

	while (input > 0) {
		s.push_back(numberToHexChar(input % 16));
		input /= 16;
	}

	std::reverse(s.begin(), s.end());

	return s;
}

/**
 * returns the string of hex characters with the given binary input
 * @param binaryInput
 * @return s
 */
std::string NumberConverter::binaryToHex(std::string binaryInput) {
	std::string s;
	int decimal = 0;
	int digit = binaryInput.size() - 1;
	while (digit >= 0) {
		decimal += hexCharToNumber(binaryInput[binaryInput.size() - (digit + 1)]) * std::pow(2, digit);
		digit--;
	}
	// std::cout << decimal << std::endl;

	s = decimalToHex(decimal);

	return s;
}

/**
 * returns string of binary with the given hex characters
 * @param hexInput
 * @return
 */
std::string NumberConverter::hexToBinary(std::string hexInput) {
	int decimal = hexCharToDecimal(hexInput);
	std::string s = decimalToBinary(decimal);
	return s;
}

/**
 * returns string of binary with given decimal input
 * @param decimalInput
 * @return s
 */
std::string NumberConverter::decimalToBinary(int decimalInput) {
	std::string s;
	int exp = -1;
	int quotient;

	do {
		exp++;
		quotient = decimalInput / std::pow(2, exp + 1);
	}
	while (quotient > 0);
	exp = 4 * (int) ceil((double) exp / 4);

	// std::cout << exp << std::endl;

	while (exp >= 0) {
		if (decimalInput - std::pow(2, exp) >= 0) {
			decimalInput -= std::pow(2, exp);
			s.push_back('1');
		} else {
			s.push_back('0');
		}
		exp--;
	}

	return s;
}

// *
//  * returns a decimal with given binary
//  * @param binaryInput
//  * @return decimal
 
// std::string NumberConverter::binaryToDecimal(int )

