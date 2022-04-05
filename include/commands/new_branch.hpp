#ifndef NEW_BRANCH_HPP
#define NEW_BRANCH_HPP

#include <iostream>
#include <string>
#include <filesystem>
#include <system_error>
#include <fstream>

namespace commands
{
    /**
     * @brief "strac new [branch name]" command.
     * 
     * This will create a clone of the current repository and automatically switch to using this branch.
     * @param new_branch_name Name of the new branch to create.
     */
    void new_branch(std::string new_branch_name);
}; // namespace commands
#endif