class NumberConverter {
public:

	int hexCharToNumber(char input);

	char numberToHexChar(int input);

	int hexCharToDecimal(std::string input);

	std::string decimalToHex(int input);

	std::string binaryToHex(std::string binaryInput);

	std::string hexToBinary(std::string hexInput);

	std::string decimalToBinary(int decimal_input);
};