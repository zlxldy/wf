#include <filesystem>
#include <vector>
#include <string>
#include "item.hpp"
#include "tf.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

namespace fs = std::filesystem;

bool is_hidden(const fs::path& path) {
    #ifdef _WIN32
    DWORD attrs = GetFileAttributesW(path.wstring().c_str());
    return (attrs != INVALID_FILE_ATTRIBUTES) && (attrs & FILE_ATTRIBUTE_HIDDEN);
    #else
    return path.filename().string().front() == '.';
    #endif
}

std::vector<item> trav(fs::path& path, bool nerd = false)
{
    std::vector<item> items;
    for (const auto& entry : fs::directory_iterator(path))
    {
        item it;
        it.name = entry.path().filename().string();

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
        it.last_write_time = sctp;

        it.permissions = (entry.status().permissions() & fs::perms::owner_read) != fs::perms::none ? "r" : "-";
        it.permissions += (entry.status().permissions() & fs::perms::owner_write) != fs::perms::none ? "w" : "-";
        it.permissions += (entry.status().permissions() & fs::perms::owner_exec) != fs::perms::none ? "x" : "-";
        items.push_back(it);
    }
    return items;
}