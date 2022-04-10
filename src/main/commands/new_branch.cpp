#include "new_branch.hpp"
#include "util.hpp"
#include "globals.hpp"

void commands::new_branch(std::string new_branch_name)
{
    if (new_branch_name.size() == 0)
    {
        std::cout << "Please provide a branch name -- strac new [branch name]\n"; 
        exit(-1);
    }
    
    // check if branch name already exits
    if (util::branches::branch_exists(new_branch_name))
    {
        std::cout << "Branch [" << new_branch_name << "] already exists!\n";
        exit(-1);
    }

    // create directory for new branch and copy everything from current branch over
    std::filesystem::create_directories(globals::branches_dir + "/" + new_branch_name);
    std::string current_branch_name = util::branches::get_current_branch();
    util::files::copy_files(globals::root_dir, 
                            globals::branches_dir + "/" + new_branch_name,
                            true); // ignore strac files when copying data into new branch
    util::branches::switch_branch(new_branch_name);

    std::cout << "Created and switched to new branch [" << new_branch_name << "]!\n";
    
}