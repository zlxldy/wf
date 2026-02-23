#ifndef TF_HPP
#define TF_HPP

#include <filesystem>
#include <vector>
#include <iostream>
#include "item.hpp"

std::vector<item> trav(fs::path& path, bool nerd, bool use_time_stamp);
bool is_hidden(const fs::path& path);
std::string time_stamp_to_clock(time_t ts);

#endif