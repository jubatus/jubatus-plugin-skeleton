#include "binary_length.hpp"
#include <map>
#include <string>
#include <iostream>

void binary_converter::add_feature(
    const std::string& key,
    const std::string& value, 
    std::vector<std::pair<std::string, float> >& ret_fv) const {
  std::cout << "length =" << value.length() << std::endl;
  ret_fv.push_back(make_pair(key, (float)  value.length()));
}

extern "C"{
  jubatus::core::fv_converter::binary_feature* create(
      std::map <std::string, std::string>& params) {
    return new binary_converter();
  }
}
