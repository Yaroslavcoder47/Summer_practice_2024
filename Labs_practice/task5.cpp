#include "task5.h"

void CheckInputPathForTask5(const std::filesystem::path& path_to_filesystem_object)
{
    if (!std::filesystem::exists(path_to_filesystem_object)) {
        throw std::invalid_argument("Filesystem object by path" + path_to_filesystem_object.string() + " is not exists!");
    }
    if (!std::filesystem::is_directory(path_to_filesystem_object)) {
        throw std::invalid_argument("Filesystem object by path " + path_to_filesystem_object.string() + " is not a directory!");
    }
}

std::size_t filesystem_object::Size(const std::filesystem::path& path_to_filesystem_object)
{
    if (std::filesystem::is_directory(path_to_filesystem_object)) {
        size_t sizeOfObject = 0;
        for (const auto& it : std::filesystem::recursive_directory_iterator(path_to_filesystem_object)) {
            if (!std::filesystem::is_directory(it)) {
                sizeOfObject += std::filesystem::file_size(it);
            }
        }
        return sizeOfObject;
    }
    else {
        return std::filesystem::file_size(path_to_filesystem_object);
    }
}

std::ostream& filesystem_object::operator<<(std::ostream& os, const filesystem_object::Info& info) {
    os << std::left << std::setfill(' ') << std::setw(50) << info.name << std::setw(20) << info.type << std::setw(20) << info.size;
    return os;
}

filesystem_object::Info filesystem_object::GetInfo(const std::filesystem::path& path_to_filesystem_object)
{
    filesystem_object::Info resultObj;
    resultObj.name = path_to_filesystem_object.stem().string();
    if (std::filesystem::is_directory(path_to_filesystem_object)) {
        resultObj.type = "directory";
    }
    else {
        resultObj.type = path_to_filesystem_object.extension().string();
    }
    resultObj.size = filesystem_object::Size(path_to_filesystem_object);
    return resultObj;
}


std::ostream& directory_content::operator<<(std::ostream& os, const directory_content::Info& info) {
    os << std::left << std::setfill(' ') << std::setw(50) << info.path_to_directory << std::setw(20) << info.size << std::setw(20)
        << info.files_amount << info.directories_amount;
    return os;
}

directory_content::Info directory_content::GetInfo(const std::filesystem::path& path_to_directory)
{
    directory_content::Info resultObj;
    resultObj.path_to_directory = path_to_directory;
    resultObj.size = filesystem_object::Size(path_to_directory);

    uint32_t filesAmount = 0;
    uint32_t directoriesAmount = 0;
    for (const auto& it : std::filesystem::directory_iterator(path_to_directory)) {
        if (std::filesystem::is_regular_file(it)) {
            filesAmount++;
        }
        else if (std::filesystem::is_directory(it)) {
            directoriesAmount++;
        }
    }

    resultObj.files_amount = filesAmount;
    resultObj.directories_amount = directoriesAmount;
    return resultObj;
}

int mainTask5(int argc, char* argv[])
{
    try {
        CheckArgumentsAmount(argc);
        CheckInputPathForTask5(std::filesystem::path(argv[argc - 2]));
        std::cout << directory_content::GetInfo(argv[argc - 2]) << '\n' << '\n' << '\n';
        for (const auto& itObj : std::filesystem::directory_iterator(argv[argc - 2])) {
            std::cout << filesystem_object::GetInfo(itObj) << '\n';
        }
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }
    return 0;
}