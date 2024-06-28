#pragma once
#ifndef TASK5_H
#define TASK5_H
#include "task1.h"

void CheckInputPathForTask5(const std::filesystem::path& path_to_filesystem_object);
int mainTask5(int argc, char* argv[]);

namespace filesystem_object {
    struct Info {
        std::string name;
        std::string type;
        std::size_t size;
    };

    std::size_t Size(const std::filesystem::path& path_to_filesystem_object);
    std::ostream& operator<<(std::ostream& os, const filesystem_object::Info& info);
    filesystem_object::Info GetInfo(const std::filesystem::path& path_to_filesystem_object);
}

namespace directory_content {
    struct Info {
        std::filesystem::path path_to_directory;
        std::size_t size;
        uint32_t files_amount;
        uint32_t directories_amount;
    };

    std::ostream& operator<<(std::ostream& os, const directory_content::Info& info);
    directory_content::Info GetInfo(const std::filesystem::path& path_to_directory);
}
#endif // !TASK5_H