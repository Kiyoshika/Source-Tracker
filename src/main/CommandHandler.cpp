#include "commands.hpp"
#include "util.hpp"
#include "globals.hpp"
#include <cstring>

int main(int argc, char* argv[])
{
    globals::root_dir = util::filepaths::get_root_directory();
    globals::branches_dir = globals::root_dir + "/strac-archive/branches";

    if (strncmp(argv[1], "init", 4) == 0)
        commands::init();

    if (strncmp(argv[1], "new", 3) == 0)
        commands::new_branch(std::string(argv[2]));
    
    if (strncmp(argv[1], "delete", 6) == 0)
        commands::delete_branch(std::string(argv[2]));
    
    if (strncmp(argv[1], "branches", 8) == 0)
        commands::branches();
    
    if (strncmp(argv[1], "switch", 6) == 0)
        commands::switch_branch(std::string(argv[2]));

    return 0;
}