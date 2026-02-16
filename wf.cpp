#include <iostream>
#include <filesystem>
#include <chrono>

using time_point = std::chrono::time_point<std::chrono::system_clock>;

#define TYPE_FILE "<FILE>"std::s
#define TYPE_DIR  "< DIR>"std::s

typedef struct item
{
    std::string name;
    std::string type;
    long long   size;
    time_point last_write_time;
    std::string permissions;
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
