#ifndef ITEM_HPP
#define ITEM_HPP

#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
using time_point = std::chrono::time_point<std::chrono::system_clock>;
#define TYPE_FILE "<FILE>"
#define TYPE_DIR  "< DIR>"
class item{
public:
    std::string name;
    std::string type;
    long long   size;
    time_point last_write_time;
    std::string permissions;
    void print() const {
        std::cout << type
                  << name
                  << '<'
                  << size
                  << ' '
                  << std::chrono::system_clock::to_time_t(last_write_time)
                  << ' '
                  << permissions
                  << '>'
                  << std::endl;
    }
};

#endif