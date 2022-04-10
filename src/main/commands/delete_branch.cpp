#include "delete_branch.hpp"
#include "util.hpp"
#include "globals.hpp"

void commands::delete_branch(std::string branch_name)
{
    if (!util::branches::branch_exists(branch_name))
    {
        std::cout << "Branch [" + branch_name + "] does not exist.\n";
        exit(-1);
    }

    if (util::branches::get_current_branch() == branch_name)
    {
        std::cout << "You cannot delete a branch you are currently on.\n";
        std::cout << "Please switch to a different branch to delete this one.\n";
        exit(-1);
    }

    std::filesystem::remove_all(globals::branches_dir + "/" + branch_name);
    std::cout << "Branch [" + branch_name + "] successfully deleted.\n";
}