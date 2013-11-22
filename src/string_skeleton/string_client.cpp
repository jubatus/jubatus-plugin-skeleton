#include <vector>
#include <jubatus/client.hpp>

#define NAME "plugin_test"
#define HOST "localhost"
#define PORT 9199
#define TIMEOUT 10

int main() {
  jubatus::classifier::client::classifier c(HOST, PORT, NAME, TIMEOUT);
  jubatus::client::common::datum d;
  d.add_string("data", "The quick brown fox jumps over the lazy dog.");
  std::vector<jubatus::classifier::labeled_datum> v;
  v.push_back(jubatus::classifier::labeled_datum("label1", d));

  c.train(v);

  return 0;
}
