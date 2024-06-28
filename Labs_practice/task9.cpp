#include "task9.h"

void CheckInputPathForTask9(const std::filesystem::path& path_to_filesystem_object)
{
    if (!std::filesystem::exists(path_to_filesystem_object)) {
        throw std::invalid_argument("Filesystem object by path" + path_to_filesystem_object.string() + " is not exists!");
    }
    if (!std::filesystem::is_directory(path_to_filesystem_object)) {
        throw std::invalid_argument("Filesystem object by path " + path_to_filesystem_object.string() + " is not a directory!");
    }
}

std::filesystem::path GetPathToMove(const std::filesystem::path& path_to_file)
{
    if (!std::filesystem::exists(path_to_file)) {
        throw std::invalid_argument("Invalid filename. File path: " + path_to_file.string() + '!');
    }
    std::filesystem::path resultPath;
    resultPath = path_to_file.parent_path();
    std::string fileName = path_to_file.filename().string();

    size_t index = fileName.find('_');
    std::string year = fileName.substr(0, index);
    fileName.erase(0, index + 1);

    index = fileName.find('_');
    std::string month = fileName.substr(0, index);
    fileName.erase(0, index + 1);

    index = fileName.find('_');
    std::string day = fileName.substr(0, index);
    fileName.erase(0, index + 1);
    resultPath.append(year).append(month).append(day).append(fileName);
    return resultPath;
}

void Move(const std::filesystem::path& path_to_file)
{
    std::filesystem::path newPath = GetPathToMove(path_to_file);
    std::filesystem::create_directories(newPath.parent_path());
    std::filesystem::rename(path_to_file, newPath);
    std::cout << "File by path " + path_to_file.string() + " has been moved to" + newPath.string() + "!";
}


//int main(int argc, char* argv[])
//{
//    try {
//        CheckArgumentsAmount(argc);
//        std::filesystem::path inputPath = argv[1];
//        CheckInputPathForTask9(inputPath);
//        for (const auto& it : std::filesystem::directory_iterator(inputPath)) {
//            if (std::filesystem::is_regular_file(it)) {
//                Move(it);
//            }
//        }
//
//    }
//    catch (std::exception& ex) {
//        std::cout << ex.what();
//    }
//    return 0;
//}