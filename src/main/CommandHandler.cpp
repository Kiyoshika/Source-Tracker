#include "commands.hpp"
#include "util.hpp"
#include "globals.hpp"
#include <cstring>

int main(int argc, char* argv[])
{
    globals::root_dir = util::filepaths::get_root_directory();

    if (strncmp(argv[1], "init", 4) == 0)
        commands::init();

    if (strncmp(argv[1], "new", 3) == 0)
        commands::new_branch(std::string(argv[2]));

    return 0;
}