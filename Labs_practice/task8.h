#pragma once
#ifndef TASK8_H
#define TASK8_H
#include <set>
#include "task1.h"
#include "task5.h"

std::string ReadFileContent(const std::filesystem::path& path_to_file);
std::size_t GetFileContentHash(const std::filesystem::path& path_to_file);
void RemoveDuplicatesFromDirectory(const std::filesystem::path& path_to_directory);


#endif // !TASK8_H