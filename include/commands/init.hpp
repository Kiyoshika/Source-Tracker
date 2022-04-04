#ifndef INIT_HPP
#define INIT_HPP

#include <iostream>
#include <fstream>
#include <system_error>
#include <filesystem>
#include <string>

namespace commands
{
    /**
     * @brief "strac init" command.
     * 
     * Used to initialize (create) a strac repository in the current directory.
     * This will create a folder called "strac-archive" along with the "main" branch and migrate all
     * current files and folders into that main branch.
     * 
     * @param root_dir file path to the current root directory
     */
    void init(std::string root_dir);
}; // namespace commands
#endif