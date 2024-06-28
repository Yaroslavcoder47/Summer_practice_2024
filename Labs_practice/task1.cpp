#include "task1.h"

void CheckArgumentsAmount(int arguments_amount)
{
    if (arguments_amount != 2)
    {
        std::string message = "Invalid command line arguments amount : current – ";
        message += std::to_string(arguments_amount);
        message += ", required – 2!";
        throw std::invalid_argument(message);
    }
}

void CheckInputPath(const std::filesystem::path& path_to_filesystem_object)
{
    if (!std::filesystem::exists(path_to_filesystem_object)) {
        throw std::invalid_argument("Filesystem object by path" + path_to_filesystem_object.string() + " is not exists!");
    }
    if (!std::filesystem::is_regular_file(path_to_filesystem_object)) {
        throw std::invalid_argument("Filesystem object by path " + path_to_filesystem_object.string() + " is not a regular file!");
    }
    if (path_to_filesystem_object.extension() != ".json") {
        throw std::invalid_argument("Filesystem object by path " + path_to_filesystem_object.string() + " has invalid extension!");
    }
}
bool IsJsonCorrect(const nlohmann::json& json, const nlohmann::json& template_json)
{
    if (json.type() != template_json.type()) {
        return false;
    }

    if (json.is_object()) {
        for (const auto& item : template_json.items()) {
            auto key = item.key();
            if (!json.contains(key)) {
                return false;
            }
            if (!IsJsonCorrect(json[key], template_json[key])) {
                return false;
            }
        }
        for (const auto& item : json.items()) {
            auto key = item.key();
            if (!template_json.contains(key)) {
                return false;
            }
        }
    }
    else if (json.is_array()) {
        if (!template_json.empty() && !json.empty()) {
            if (json.size() != template_json.size()) {
                return false;
            }
            return IsJsonCorrect(json[0], template_json[0]);
        }
    }
    return true;
}


//int mainTask1(int argc, char* argv[])
//{
//    try {
//        nlohmann::json template_json = R"({
//        "string_0" : "some string",
//        "number" : 10,
//        "object" : {
//            "boolean" : true,
//            "array" : []
//        },
//        "string_1" : null,
//        "array" : null
//        })"_json;
//
//        CheckArgumentsAmount(argc);
//        CheckInputPath(std::filesystem::path(argv[argc - 1]));
//        std::ifstream inputFile(argv[argc - 1]);
//
//        nlohmann::json inputData = nlohmann::json::parse(inputFile);
//        //std::cout << inputData.dump(4) << "\n";
//        std::cout << IsJsonCorrect(inputData, template_json);
//        if (IsJsonCorrect(inputData, template_json)) {
//            std::cout << ("Structure of JSON - file by path is correct.");
//        }
//        else {
//            std::cout << ("Structure of JSON - file by path is incorrect.");
//        }
//    }
//    catch (std::exception& ex) {
//        std::cerr << ex.what();
//    }
//    return 0;
//}