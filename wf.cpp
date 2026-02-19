#include <iostream>
#include <filesystem>
#include <chrono>
#include <algorithm>
#include "tf.hpp"

void print_i(const item it, size_t ll) {
    std::cout << it.type
              << it.name;
    for (size_t i = it.name.length(); i < ll; i++) {
        std::cout << ' ';
    }
    std::cout << '<'
              << it.size << ' '
              << it.last_write_time.time_since_epoch().count() << ' '
              << it.permissions << ' '
              << '>'
              << std::endl;
}

void print_vi(const std::vector<item> it) {
    std::vector<std::string> names;
    size_t ll = 0;
    for (auto i : it) {
        names.push_back(i.name);
    }
    //获取最长item名的长度
    for (std::string_view nm : names) {
        if (nm.length() > ll) ll = nm.length();
    }
    for (auto i : it) {
        print_i(i, ll);
    }
}

int main(int argc, char const *argv[])
{
    bool hvnd = false;
    if (argc == 3 && ((std::string)argv[2] == "--nerd" || (std::string)argv[2] == "-n"))hvnd = true;

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <directory_path>" << std::endl;
        return -1;
    }
    std::string path = argv[1];
    if (!fs::exists(path) || !fs::is_directory(path)) {
        std::cerr << "Invalid directory path: " << path << std::endl;
        return 1;
    }
    fs::path dir_path(path);
    std::vector<item> items = trav(dir_path, hvnd);
    print_vi(items);
    return 0;
}
