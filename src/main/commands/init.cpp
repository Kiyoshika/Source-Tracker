#include "init.hpp"
#include "util.hpp"
#include "globals.hpp"

static void write_root_file()
{
    std::ofstream root_file(globals::root_dir + "/strac-archive/root-dir.txt");
    root_file << globals::root_dir;
    root_file.close();
}

void commands::init()
{
    std::filesystem::create_directories(globals::branches_dir + "/main");
    write_root_file();
    util::branches::switch_branch("main");
    util::files::copy_files(globals::root_dir, globals::branches_dir + "/main", true);
    std::cout << "initialized repository and created [main] branch!\n";
}