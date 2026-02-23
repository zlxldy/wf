#include <filesystem>
#include <vector>
#include <string>
#include <ctime>
#include "item.hpp"
#include "tf.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

namespace fs = std::filesystem;

std::string time_stamp_to_clock(time_t ts) {
    tm time_info;
    #ifdef _WIN32
    localtime_s(&time_info, &ts);
    #else
    localtime_r(&ts, &tm_info);
    #endif
    std::ostringstream oss;
    oss << std::put_time(&time_info, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

bool is_hidden(const fs::path& path) {
    #ifdef _WIN32
    DWORD attrs = GetFileAttributesW(path.wstring().c_str());
    return (attrs != INVALID_FILE_ATTRIBUTES) && (attrs & FILE_ATTRIBUTE_HIDDEN);
    #else
    return path.filename().string().front() == '.';
    #endif
}

std::vector<item> trav(fs::path& path, bool nerd = false, bool use_time_stamp = false)
{
    std::vector<item> items;
    for (const auto& entry : fs::directory_iterator(path))
    {
        item it;
        it.name = entry.path().filename().string();
        it.path = entry.path();
        if (entry.is_directory()) {
            if (nerd) {
                it.type = is_hidden(entry) ? NDHD_DIR : NERD_DIR;
            } else {
                it.type = is_hidden(entry) ? TPHD_DIR : TYPE_DIR;
            }
        } else {
            if (nerd) {
                it.type = is_hidden(entry) ? NDHD_FILE : NERD_FILE;
            } else {
                it.type = is_hidden(entry) ? TPHD_FILE : TYPE_FILE;
            }
        }

        it.size = entry.is_regular_file() ? fs::file_size(entry) : 0;

        auto ftime = std::filesystem::last_write_time(entry);
        auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
        ftime - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now());
        auto time_stamp = std::chrono::system_clock::to_time_t(sctp);

        it.last_write_time = use_time_stamp ? std::to_string(time_stamp) : time_stamp_to_clock(time_stamp);

        it.permissions = (entry.status().permissions() & fs::perms::owner_read) != fs::perms::none ? "r" : "-";
        it.permissions += (entry.status().permissions() & fs::perms::owner_write) != fs::perms::none ? "w" : "-";
        it.permissions += (entry.status().permissions() & fs::perms::owner_exec) != fs::perms::none ? "x" : "-";
        items.push_back(it);
    }
    return items;
}