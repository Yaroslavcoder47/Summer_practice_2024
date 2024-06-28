#pragma once
#ifndef TASK10_H
#define TASK10_H
#include "task1.h"
#include "task9.h"

class FileName {
public:
    FileName(std::filesystem::path path_to_file) : path_to_current_file(path_to_file) {};
    void Parse();
    bool IsRemoveRequired() const;

    std::filesystem::path path_to_current_file;
    uint16_t year;
    uint16_t month;
    uint16_t day;   
    std::string only_name;
};

std::filesystem::path GetPathToMoveForTask10(const std::filesystem::path& path_to_file);
void MoveForTask10(const std::filesystem::path& path_to_file);
int mainTask10(int argc, char* argv[]);

#endif // !TASK10_H

