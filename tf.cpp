#include <filesystem>
#include <vector>
#include <iostream>
#include "item.hpp"
#include "tf.hpp"

namespace fs = std::filesystem;

std::vector<item> trav(fs::path& path, bool nerd = false)
{
    std::vector<item> items;
    for (const auto& entry : fs::directory_iterator(path))
    {
        item it;
        it.name = entry.path().filename().string();
        
        if (nerd) {
            if (entry.is_directory()) {
                it.type = NERD_DIR;
            } else {
                it.type = NERD_FILE;
            }
        } else {
            if (entry.is_directory()) {
                it.type = TYPE_DIR;
            } else {
                it.type = TYPE_FILE;
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