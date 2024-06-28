#include "task4.h"

void CheckInputPathForTask4(const std::filesystem::path& path_to_filesystem_object)
{
    if (!std::filesystem::exists(path_to_filesystem_object)) {
        throw std::invalid_argument("Filesystem object by path" + path_to_filesystem_object.string() + " is not exists!");
    }
    if (!std::filesystem::is_regular_file(path_to_filesystem_object) && !std::filesystem::is_directory(path_to_filesystem_object)) {
        throw std::invalid_argument("Filesystem object by path " + path_to_filesystem_object.string() + " is not a regular file or directory!");
    }
}

std::size_t Size(const std::filesystem::path& path_to_filesystem_object)
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

nlohmann::json GetRegularFileInfo(const std::filesystem::path& path_to_file)
{
    nlohmann::json objInfo;
    if (std::filesystem::is_regular_file(path_to_file)) {
        objInfo["type"] = "regular_file";
        objInfo["full_name"] = path_to_file.filename().string();
        objInfo["name_without_extension"] = path_to_file.stem().string();
        if (path_to_file.has_extension()) {
            objInfo["extension"] = path_to_file.extension().string();
        }
        else {
            objInfo["extension"] = nullptr;
        }
        objInfo["size"] = Size(path_to_file);
    }
    else {
        throw std::invalid_argument("This file is not regular");
    }
    return objInfo;
}

nlohmann::json GetDirectoryInfo(const std::filesystem::path& path_to_directory)
{
    nlohmann::json objInfo;

    if (std::filesystem::is_directory(path_to_directory)) {
        size_t fileCount = 0;
        size_t dirCount = 0;
        size_t sizeOfDir = Size(path_to_directory);

        for (const auto& it : std::filesystem::directory_iterator(path_to_directory)) {
            if (std::filesystem::is_regular_file(it)) {
                fileCount++;
            }
            else if (std::filesystem::is_directory(it)) {
                dirCount++;
            }
        }

        objInfo["type"] = "directory";
        objInfo["name"] = path_to_directory.stem().string();
        objInfo["size"] = sizeOfDir;
        objInfo["files_amount"] = fileCount;
        objInfo["directories_amount"] = dirCount;
    }
    else {
        throw std::invalid_argument("Mistake in path");
    }
    return objInfo;
}

nlohmann::json GetFsObjectInfo(const std::filesystem::path& path_to_filesystem_object)
{
    nlohmann::json result;
    if (std::filesystem::is_directory(path_to_filesystem_object)) {
        result = GetDirectoryInfo(path_to_filesystem_object);
    }
    else if (std::filesystem::is_regular_file(path_to_filesystem_object)) {
        result = GetRegularFileInfo(path_to_filesystem_object);
    }
    else {
        throw std::invalid_argument("Filesystem object is nor a regular file or a directory");
    }
    return result;
}

void WriteToFileForTask4(nlohmann::json& json_object, std::filesystem::path file_path)
{
    std::ofstream output;
    output.open(file_path.replace_filename("fs_object_info.json"));
    output << json_object.dump(4);
    output.close();
}

//int main(int argc, char* argv[])
//{
//    try {
//        CheckArgumentsAmount(argc);
//        CheckInputPathForTask4(std::filesystem::path(argv[argc - 1]));
//        nlohmann::json resultObject = GetFsObjectInfo(argv[1]);
//        std::cout << resultObject.dump(4);
//        WriteToFileForTask4(resultObject, std::filesystem::path(argv[argc - 1]));
//    }
//    catch (std::exception& ex) {
//        std::cout << ex.what();
//    }
//    return 0;
//}