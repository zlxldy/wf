#include <iostream>
#include <filesystem>
#include <chrono>
#include "tf.hpp"

int main(int argc, char const *argv[])
{
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
    std::vector<item> items = trav(dir_path);
    for (const auto& it : items) {
        it.print();
    }
    return 0;
}
