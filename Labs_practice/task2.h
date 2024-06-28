#pragma once
#ifndef TASK2_H
#define TASK2_H
#include "task1.h"

void ModifyJsonObject(nlohmann::json& json_object);
void WriteToFile(nlohmann::json& json_object, std::filesystem::path file_path);

#endif // !TASK2_H