#ifndef FILEPATHS_HPP
#define FILEPATHS_HPP

#include <string>
#include <filesystem>
#include <fstream>

namespace util
{
    namespace filepaths
    {
        std::string get_root_directory();

        std::string strip_root_directory(std::filesystem::path filepath);
        std::string strip_root_directory(std::string filepath);

        std::string strip_branches_directory(std::filesystem::path filepath);
        std::string strip_branches_directory(std::string filepath);

        bool filepath_contains(std::filesystem::path filepath, std::string search_text);
        bool filepath_contains(std::string filepath, std::string search_text);
    }; // namespace filepaths

    namespace files
    {
        void copy_files(std::string from_path, std::string to_path, bool ignore_strac_files = true);
        void remove_files(std::string filepath, bool ignore_strac_files = true);
    }; // namespace files

    namespace branches
    {
        void switch_branch(std::string branch_name);
        std::string get_current_branch();
        bool branch_exists(std::string branch_name);
    }; // namespace branches
}; // namespace util
#endif