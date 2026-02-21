#ifndef TF_HPP
#define TF_HPP

#include <filesystem>
#include <vector>
#include <iostream>
#include "item.hpp"

std::vector<item> trav(fs::path& path, bool nerd);
bool is_hidden(const fs::path& path);

#endif