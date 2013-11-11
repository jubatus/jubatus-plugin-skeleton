/*
 * Skeleton of Jubatus fv_converter Plug-in
 *  ... based on the `extract_ascii` written by Yuya Unno
 *      http://blog.jubat.us/2012/07/blog-post_18.html
 */

#include "EXAMPLE_splitter.hpp"
#include <map>
#include <string>

void EXAMPLE_splitter::split(const std::string& string,
                             std::vector<std::pair<size_t, size_t> >& ret_boundaries) const {
  size_t pos = 0;
  for (std::pair<size_t, size_t> b; find_next(string, pos, b); ) {
    ret_boundaries.push_back(b);
    pos = b.first + b.second;
  }
}

bool EXAMPLE_splitter::find_next(const std::string& text,
                              size_t pos,
                              std::pair<size_t, size_t>& boundary) const {
  size_t begin = pos;
  while (begin < text.size() && !isalpha(text[begin]))
    ++begin;
  if (begin == text.size())
    return false;
  size_t end = begin;
  while (end < text.size() && isalpha(text[end]))
    ++end;
  boundary.first = begin;
  boundary.second = end - begin;
  return true;
}

extern "C" {
  jubatus::core::fv_converter::word_splitter* create(const std::map<std::string, std::string>& params) {
    return new EXAMPLE_splitter();
  }
}
