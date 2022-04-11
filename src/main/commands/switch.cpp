#include "switch.hpp"
#include "util.hpp"
#include "globals.hpp"

void commands::switch_branch(std::string branch_name)
{
    util::files::remove_files(globals::root_dir);
    util::files::copy_files(globals::branches_dir + "/" + branch_name, globals::root_dir, false);
    util::branches::switch_branch(branch_name);
    std::cout << "Switched to branch [" + branch_name + "]\n";
}