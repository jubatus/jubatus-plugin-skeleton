#include <jubatus/core/plugin.hpp>

class binary_converter : public jubatus::core::fv_converter::binary_feature {
public:
  void add_feature(const std::string& key, const std::string& value, std::vector< std::pair< std::string, float > >& ret_fv) const;
};
