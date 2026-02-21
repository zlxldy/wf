#ifndef ITEM_HPP
#define ITEM_HPP

#include <filesystem>
#include <string>
#include <chrono>
namespace fs = std::filesystem;
using time_point = std::chrono::time_point<std::chrono::system_clock>;
#define TYPE_FILE "<F>"
#define TYPE_DIR  "<D>"
#define TPHD_FILE "<f>"
#define TPHD_DIR  "<d>"

#define NERD_FILE u8"\uf4a5"
#define NERD_DIR u8"\uf413"
#define NDHD_FILE u8"\U000f0613"
#define NDHD_DIR u8"\U000f179e"

struct item{
    fs::path path;
    std::string name;
    std::string type;
    long long   size;
    time_point  last_write_time;
    std::string permissions;
};

#endif