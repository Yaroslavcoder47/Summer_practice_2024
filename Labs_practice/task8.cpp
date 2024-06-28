#include "task8.h"

std::string ReadFileContent(const std::filesystem::path& path_to_file)
{
    if (!std::filesystem::exists(path_to_file)) {
        throw std::invalid_argument("Filesystem object by path " + path_to_file.string() + " is not exists!");
    }
    std::ifstream in(path_to_file, std::ios::binary);
    if (!in.is_open()) {
        throw std::runtime_error("File by path " + path_to_file.string() + " hasn’t been opened!");
    }
    in.seekg(0, std::ios::end);
    std::streamsize file_size = in.tellg();
    in.seekg(0, std::ios::beg);

    std::string content(file_size, '\0');
    in.read(content.data(), file_size);
    return content;
}

std::size_t GetFileContentHash(const std::filesystem::path& path_to_file)
{
    std::string content = ReadFileContent(path_to_file);
    return std::hash<std::string>{}(content);
}

void RemoveDuplicatesFromDirectory(const std::filesystem::path& path_to_directory)
{
    if (!std::filesystem::exists(path_to_directory)) {
        throw std::invalid_argument("Filesystem object by path " + path_to_directory.string() + " is not exists!");
    }
    std::set<std::size_t> values;
    for (const auto& it : std::filesystem::directory_iterator(path_to_directory)) {
        if (std::filesystem::is_directory(it.path())) {
            continue;
        }
        size_t value = GetFileContentHash(it.path());
        if (values.find(value) == values.end()) {
            values.insert(value);
        }
        else {
            std::filesystem::remove(it.path());
            std::cout << "File by path " << it.path().string() << " has been removed." << std::endl;
        }
    }
}

int mainTask8(int argc, char* argv[])
{
    try {
        CheckArgumentsAmount(argc);
        std::filesystem::path inputPath = argv[argc-2];
        CheckInputPathForTask5(inputPath);
        RemoveDuplicatesFromDirectory(inputPath);

    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }
    return 0;
}