#include "branches.hpp"
#include "globals.hpp"
#include "util.hpp"

void commands::branches()
{
    std::string current_active_branch = util::branches::get_current_branch();
    std::string search_branch;
    std::cout << "CURRENT BRANCH:\n[" + current_active_branch << "]\n\n";
    std::cout << "OTHER BRANCHES:\n";
    for (auto const& current_branch : std::filesystem::directory_iterator(globals::branches_dir))
    {
        search_branch = util::filepaths::strip_branches_directory(current_branch);
        search_branch = search_branch.substr(1); // remove the leading '/' character

        // ignore current active branch
        if (current_active_branch == search_branch)
            continue;

        std::cout << search_branch << "\n";
    }
}