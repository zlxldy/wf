#ifndef ITEM_HPP
#define ITEM_HPP

#include <filesystem>
#include <string>
#include <chrono>
namespace fs = std::filesystem;
using time_point = std::chrono::time_point<std::chrono::system_clock>;
#define TYPE_FILE "<F>"
#define TYPE_DIR  "<D>"
#define NERD_FILE u8"\uf4a5"
#define NERD_DIR u8"\uf413"
struct item{
    std::string name;
    std::string type;
    long long   size;
    time_point  last_write_time;
    std::string permissions;
};

#endif