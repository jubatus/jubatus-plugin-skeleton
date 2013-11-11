#include <jubatus/core/plugin.hpp>

class EXAMPLE_splitter : public jubatus::core::fv_converter::word_splitter {
 public:
  void split(const std::string& string,
             std::vector<std::pair<size_t, size_t> >& ret_boundaries) const;

  bool find_next(const std::string& text,
                 size_t pos,
                 std::pair<size_t, size_t>& boundary) const;
};
