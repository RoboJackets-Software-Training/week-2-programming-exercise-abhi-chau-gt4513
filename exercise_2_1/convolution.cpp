#include <iostream>
#include <vector>


std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros) {
  std::vector<double> y;
  
  std::cout << "x: {" ;
  for (int i = 0; i < x.size(); i++) {
    if (i == x.size() - 1) {
      std::cout << x[i];
    } else {
      std::cout << x[i] << ", ";
    }
  }
  std::cout << "}" << std::endl;

  std::cout << "w: {" ;
  for (int i = 0; i < w.size(); i++) {
    if (i == w.size() - 1) {
      std::cout << w[i];
    } else {
      std::cout << w[i] << ", ";
    }
  }
  std::cout << "}" << std::endl;

  int packing_size = (w.size() - 1) / 2;
  for (int i = 0; i < x.size(); i++) {
    double sum = 0;
    for (int j = 0; j < w.size(); j++) {
    	if (!pack_with_zeros && i - packing_size + j < 0) {
        sum += x[0] * w[j];
      } else if (!pack_with_zeros && i - packing_size + j >= x.size()) {
        sum += x[x.size() - 1] * w[j];
      } else {
        sum += x[i - packing_size + j] * w[j];
      }
    }
    y.push_back(sum);
  }
  
	return y;
}

void printVector(std::vector<double> vec) {
  std::cout << "{";
  for (int i = 0; i < vec.size(); i++) {
    if (i == vec.size() - 1) {
      std::cout << vec[i];
    } else {
      std::cout << vec[i] << ", ";
    }
  }
  std::cout << "}" << std::endl;
}