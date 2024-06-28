#pragma once
#ifndef TASK9_H
#define TASK9_H
#include "task1.h"

void CheckInputPathForTask9(const std::filesystem::path& path_to_filesystem_object);
std::filesystem::path GetPathToMove(const std::filesystem::path& path_to_file);
void Move(const std::filesystem::path& path_to_file);


#endif // !TASK9_H