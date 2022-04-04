#include "init.hpp"
#include "filepaths.hpp"
#include <cstring>

int main(int argc, char* argv[])
{
    std::string root_dir = util::filepaths::get_root_directory();

    if (strncmp(argv[1], "init", 4) == 0)
    {
        commands::init(root_dir);
    }
    return 0;
}