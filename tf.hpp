#ifndef TF_HPP
#define TF_HPP

#include <filesystem>
#include <vector>
#include <iostream>
#include "item.hpp"

std::vector<item> trav(fs::path& path, bool nerd);

#endif