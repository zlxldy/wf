#include <iostream>
#include <filesystem>
#include <chrono>
#include <algorithm>
#include <vector>
#include "tf.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

void setup_console() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

namespace fs = std::filesystem;

std::vector<std::string> make_args(int argc, char const *argv[]) {
    std::vector<std::string> args;
    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }
    return args;
}

template<typename... Args>
    std::vector<std::string> make_eq_args(Args... args) {
        return {args...};
    }


bool have_arg(std::vector<std::string> args, std::string arg) {
    return std::find(args.begin(), args.end(), arg) != args.end();
}

bool have_arg(std::vector<std::string> args, std::vector<std::string> arg) {
    for (std::string a : arg) {
        if (have_arg(args, a)) return true;
    }
    return false;
}

void print_i(const item it, size_t ll, bool all = false, bool right = false, bool table = false, bool nerd = false) {
    if (!all && is_hidden(it.path)) {
        return;
    }
    if (table) {
        if (nerd) {
            std::cout << it.type.data() << ' ';
        }
        std::cout << it.name << ' ';
        return;
    }
    
    

    if (!right) {
        std::cout << it.type.data()
                  << ' '
                  << it.name;
        for (size_t i = it.name.length(); i < ll; i++) {
            std::cout << ' ';
        }
        std::cout << '<'
                  << it.size << ' '
                  << it.last_write_time << ' '
                  << it.permissions << ' '
                  << '>'
                  << std::endl;
        return;
    }
    
    std::cout << it.type.data() << ' ';
    for (size_t i = it.name.length(); i < ll; i++) {
        std::cout << ' ';
    }
    std::cout << it.name << ' '
              << '<'
              << it.size << ' '
              << it.last_write_time << ' '
              << it.permissions << ' '
              << '>'
              << std::endl;
}

void print_vi(const std::vector<item>& it, bool all = false, bool right = false, bool table = false, bool nerd = false) {
    size_t ll = 0;
    for (auto i : it) {
        if (i.name.length() > ll) {
            ll = i.name.length();
        }
    }
    for (auto i : it) {
        print_i(i, ll, all, right, table, nerd);
    }
}

int main(int argc, char const *argv[]){
    setup_console();

    auto args = make_args(argc, argv);

    if (!args.size()) {
        std::cout << "Usage: wf [options] [path]\n"
                  << "Options:\n"
                  << "  -n, --nerd                 Use nerd font icons\n"
                  << "  -a, --all                    Show hidden items\n"
                  << "  -s, --stamp Show last write time by time stamp\n"
                  << "  -r, --right                    Use right align\n"
                  << "  -t, --table                    Use table format\n";
        return -1;
    }

    bool hvnd = have_arg(args, make_eq_args("-n", "--nerd"));
    bool hvall = have_arg(args, make_eq_args("-a", "--all"));
    bool hvstmp = have_arg(args, make_eq_args("-s", "--stamp"));
    bool hvright = have_arg(args, make_eq_args("-r", "--right"));
    bool hvtable = have_arg(args, make_eq_args("-t", "--table"));

    std::string path = ".";
    for (std::string arg : args) {
        if (arg[0] != '-') {
            path = arg;
            break;
        }
    }

    fs::path dir_path(path);
    std::vector<item> items = trav(dir_path, hvnd, hvstmp);
    print_vi(items, hvall, hvright, hvtable, hvnd);
    return 0;
}