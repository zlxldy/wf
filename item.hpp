#ifndef ITEM_HPP
#define ITEM_HPP

#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
using time_point = std::chrono::time_point<std::chrono::system_clock>;
#define TYPE_FILE "<F>"
#define TYPE_DIR  "<D>"
#define NERD_FILE "\uf4a5"
#define NERD_DIR "\uf413"
class item{
public:
    std::string name;
    std::string type;
    long long   size;
    time_point last_write_time;
    std::string permissions;
};

#endif