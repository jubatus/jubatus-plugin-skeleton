#include <jubatus/client.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#define NAME "plugin_test"
#define HOST "localhost"
#define PORT 9199
#define TIMEOUT 10
using std::string;
using std::vector;
using jubatus::client::common::datum;

int main() {
  datum d;
  std::ifstream ifs;
  try {
    ifs.exceptions(std::ios::failbit);
    ifs.open("jubatus.bmp", std::ios_base::binary);
  }
  catch (std::ios_base::failure& e) {
    std::cout << "Error: can not open data file" << std::endl; 
    exit(1);
  }
  std::streamsize size = ifs.seekg(0, std::ios::end).tellg();
  ifs.seekg(0, std::ios::beg);
  char buf_ptr[size];
  ifs.read(buf_ptr, size);
  ifs.close();
  string str(buf_ptr, size);
  jubatus::classifier::client::classifier c(HOST, PORT, "name", TIMEOUT);
  vector <jubatus::classifier::labeled_datum> train_data;
  d.add_binary("data1", str);
  train_data.push_back(jubatus::classifier::labeled_datum("true", d));
  c.train(train_data);
  c.save("binary_client");
  return 0;
}
