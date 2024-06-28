#pragma once
#ifndef TASK4_H
#define TASK4_H
#include "task1.h"

void CheckInputPathForTask4(const std::filesystem::path& path_to_filesystem_object);
std::size_t Size(const std::filesystem::path& path_to_filesystem_object);
nlohmann::json GetRegularFileInfo(const std::filesystem::path& path_to_file);
nlohmann::json GetDirectoryInfo(const std::filesystem::path& path_to_directory);
nlohmann::json GetFsObjectInfo(const std::filesystem::path& path_to_filesystem_object);
void WriteToFileForTask4(nlohmann::json& json_object, std::filesystem::path file_path);
int mainTask4(int argc, char* argv[]);

#endif // !TASK4_H

