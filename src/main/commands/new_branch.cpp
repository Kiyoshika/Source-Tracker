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
    std::string branches_dir = globals::root_dir + "/strac-archive/branches";
    std::string search_branch_name;
    for (auto const& branch_name : std::filesystem::directory_iterator(branches_dir))
    {
        // strip root directory (substring is for removing leading slash)
        search_branch_name = branch_name.path().string().substr(branches_dir.length() + 1);

        if (search_branch_name == new_branch_name)
        {
            std::cout << "Branch [" << new_branch_name << "] already exists!\n";
            exit(-1);
        }
    }

    // create directory for new branch and copy everything from current branch over
    std::filesystem::create_directories(globals::root_dir + "/strac-archive/branches/" + new_branch_name);
    std::string current_branch_name = util::branches::get_current_branch();
    util::files::copy_files(globals::root_dir + "/strac-archive/branches/" + current_branch_name, 
                            globals::root_dir + "/strac-archive/branches/" + new_branch_name);
    util::branches::switch_branch(new_branch_name);

    std::cout << "Created and switched to new branch [" << new_branch_name << "]!\n";
    
}