#ifndef FILEPATHS_HPP
#define FILEPATHS_HPP

#include <string>
#include <filesystem>

namespace util
{
    namespace filepaths
    {
        std::string get_root_directory();

        std::string strip_root_directory(std::filesystem::path filepath, std::string root_dir);
        std::string strip_root_directory(std::string filepath, std::string root_dir);

        bool filepath_contains(std::filesystem::path filepath, std::string search_text);
        bool filepath_contains(std::string filepath, std::string search_text);
    }; // namespace filepaths
}; // namespace util
#endif