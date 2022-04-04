#include "filepaths.hpp"

std::string util::filepaths::get_root_directory()
{
    return std::filesystem::current_path().string();
}

std::string util::filepaths::strip_root_directory(std::filesystem::path filepath, std::string root_dir)
{
    return filepath.string().substr(root_dir.length());
}

std::string util::filepaths::strip_root_directory(std::string filepath, std::string root_dir)
{
    return filepath.substr(root_dir.length());
}

bool util::filepaths::filepath_contains(std::filesystem::path filepath, std::string search_text)
{
    return filepath.string().find(search_text) != std::string::npos;
}

bool util::filepaths::filepath_contains(std::string filepath, std::string search_text)
{
    return filepath.find(search_text) != std::string::npos;
}