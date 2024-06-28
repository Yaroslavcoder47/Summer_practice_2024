#include "task10.h"

void FileName::Parse()
{
    std::string fileName = path_to_current_file.filename().string();

    size_t index = fileName.find('_');
    year = std::stoul(fileName.substr(0, index));
    fileName.erase(0, index + 1);

    index = fileName.find('_');
    month = std::stoul(fileName.substr(0, index));
    fileName.erase(0, index + 1);

    index = fileName.find('_');
    day = std::stoul(fileName.substr(0, index));
    fileName.erase(0, index + 1);

    only_name = fileName;

}

bool FileName::IsRemoveRequired() const
{
    if (year % 5 == 0 && day % 5 == 0) {
        return true;
    }
    return false;
}

std::filesystem::path GetPathToMoveForTask10(const std::filesystem::path& path_to_file)
{
    std::filesystem::path resultPath;
    resultPath = path_to_file.parent_path();
    FileName fileObj(path_to_file);
    fileObj.Parse();
    resultPath.append(std::to_string(fileObj.year)).append(std::to_string(fileObj.month)).append(std::to_string(fileObj.day)).append(fileObj.only_name);
    return resultPath;

}

void MoveForTask10(const std::filesystem::path& path_to_file)
{
    std::filesystem::path newPath = GetPathToMoveForTask10(path_to_file);
    std::filesystem::create_directories(newPath.parent_path());
    std::filesystem::rename(path_to_file, newPath);
    std::cout << "File by path " + path_to_file.string() + " has been moved to " + newPath.string() + "!\n";
}

int mainTask10(int argc, char* argv[])
{
    try {
        CheckArgumentsAmount(argc);
        std::filesystem::path inputPath = argv[argc-2];
        CheckInputPathForTask9(inputPath);
        for (const auto& it : std::filesystem::directory_iterator(inputPath)) {
            if (!std::filesystem::exists(it.path())) {
                throw std::runtime_error("File " + it.path().filename().string() + " does not exists");
            }
            if (std::filesystem::is_regular_file(it.path())) {
                FileName file_name(it.path().filename());
                file_name.Parse();
                if (file_name.IsRemoveRequired()) {
                    std::filesystem::remove(it.path());
                    std::cout << "File " + it.path().filename().string() + " was removed successfully" << '\n';
                }
            }
        }

        for (const auto& it : std::filesystem::directory_iterator(inputPath)) {
            if (std::filesystem::is_regular_file(it)) {
                MoveForTask10(it);
            }
        }
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }
    return 0;
}