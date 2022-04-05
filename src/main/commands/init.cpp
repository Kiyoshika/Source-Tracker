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
    std::filesystem::create_directories(globals::root_dir + "/strac-archive/branches/main");
    write_root_file();
    util::branches::switch_branch("main");
    util::files::copy_files(globals::root_dir, globals::root_dir + "/strac-archive/branches/main", true);
    std::cout << "initialized repository and created [main] branch!\n";
}