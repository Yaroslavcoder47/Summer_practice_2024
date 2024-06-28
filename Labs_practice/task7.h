#pragma once
#ifndef TASK7_H
#define TASK7_H
#include <set>
#include "task6.h"

class FileStorage {
public:
    FileStorage(const std::filesystem::path& path_to_directory) : path_to_directory_(path_to_directory) {};
    void InitStorage();
    void CopyFile(const std::filesystem::path& path_to_file);
    
private:
    std::filesystem::path path_to_directory_;
    std::set<std::string> files_content_storage_;
};

#endif // !TASK7_H

