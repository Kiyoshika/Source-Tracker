#include "util.hpp"
#include "globals.hpp"
#include <iostream>

std::string util::filepaths::get_root_directory()
{
    return std::filesystem::current_path().string();
}

std::string util::filepaths::strip_root_directory(std::filesystem::path filepath)
{
    return filepath.string().substr(globals::root_dir.length());
}

std::string util::filepaths::strip_root_directory(std::string filepath)
{
    return filepath.substr(globals::root_dir.length());
}

bool util::filepaths::filepath_contains(std::filesystem::path filepath, std::string search_text)
{
    return filepath.string().find(search_text) != std::string::npos;
}

bool util::filepaths::filepath_contains(std::string filepath, std::string search_text)
{
    return filepath.find(search_text) != std::string::npos;
}

void util::files::copy_files(std::string from_path, std::string to_path, bool ignore_strac_files)
{
    // recursively scan root directory and store everything (besides strac files) into "main" branch
    std::string stripped_dir;
    for (auto const& current_file : std::filesystem::recursive_directory_iterator(from_path))
    {
        // don't read anything within generated strac files (when specified)
        if (ignore_strac_files && util::filepaths::filepath_contains(current_file.path(), "strac-archive"))
            continue;
        
        try
        {
            std::filesystem::copy(current_file.path(), to_path);
        } catch (std::filesystem::filesystem_error const& ex) {} // ignore files that were already copied

    }
}

void util::branches::switch_branch(std::string branch_name)
{
    std::ofstream branch_file(globals::root_dir + "/strac-archive/current-branch.txt");
    branch_file << branch_name;
    branch_file.close();
}

std::string util::branches::get_current_branch()
{
    std::ifstream file(globals::root_dir + "/strac-archive/current-branch.txt");
    std::string current_branch_name;
    file >> current_branch_name;
    file.close();
    return current_branch_name;
}

bool util::branches::branch_exists(std::string branch_name)
{
    std::string search_branch_name;
    for (auto const& branch_path : std::filesystem::directory_iterator(globals::branches_dir))
    {
        // strip root directory (substring is for removing leading slash)
        search_branch_name = branch_path.path().string().substr(globals::branches_dir.length() + 1);

        if (search_branch_name == branch_name)
            return true;
    }
    return false;
}