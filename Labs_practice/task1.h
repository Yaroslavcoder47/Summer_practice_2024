#pragma once
#include <exception>
#include <iostream>
#include <fstream>
#include "json.hpp"

void CheckArgumentsAmount(int arguments_amount);
void CheckInputPath(const std::filesystem::path& path_to_filesystem_object);
bool IsJsonCorrect(const nlohmann::json& json, const nlohmann::json& template_json);