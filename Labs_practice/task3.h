#pragma once
#ifndef TASK3_H
#define TASK3_H
#include "task1.h"

void WriteToConsole(nlohmann::json data);
tm GetRequiredDateTime();
nlohmann::json TmToJson(tm date_time);
void WriteToJsonFile(nlohmann::json& json_object, std::filesystem::path file_path);

#endif // !TASK3_H

