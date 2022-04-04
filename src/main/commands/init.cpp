#include "init.hpp"
#include "filepaths.hpp"

static void write_root_file(std::string root_dir)
{
    std::ofstream root_file(root_dir + "/strac-archive/root-dir.txt");
    root_file << root_dir;
    root_file.close();
}

static void write_branch_file(std::string root_dir)
{
    std::ofstream branch_file(root_dir + "/strac-archive/current-branch.txt");
    branch_file << "main";
    branch_file.close();
}

void commands::init(std::string root_dir)
{
    // initialize strac files
    std::filesystem::create_directories(root_dir + "/strac-archive/branches/main");

    write_root_file(root_dir);

    write_branch_file(root_dir);
    
    // recursively scan root directory and store everything (besides strac files) into "main" branch
    std::string stripped_dir;
    for (auto const& current_file : std::filesystem::recursive_directory_iterator(root_dir))
    {
        // don't read anything within generated strac files
        if (util::filepaths::filepath_contains(current_file.path(), "strac-archive"))
            continue;
        
        stripped_dir = util::filepaths::strip_root_directory(current_file.path(), root_dir);
        try
        {
            std::filesystem::copy(current_file.path(), root_dir + "/strac-archive/branches/main" + stripped_dir);
        } catch (std::filesystem::filesystem_error const& ex) {} // ignore files that were already copied

    }
        

    std::cout << "initialized repository and created 'main' branch!\n";
}