#pragma once
#ifndef TASK6_H
#define TASK6_H
#include <set>
#include "task5.h"

void CheckArgumentsAmountForTask6(int arguments_amount);
std::string ReadFileContentForTask6(const std::filesystem::path& path_to_file);
std::set<std::string> GetFilesContentFromDirectory(const std::filesystem::path& path_to_directory);
int mainTask6(int argc, char* argv[]);


#endif // !TASK6_H

