#include "task6.h"

void CheckArgumentsAmountForTask6(int arguments_amount)
{
    if (arguments_amount != 3)
    {
        std::string message = "Invalid command line arguments amount : current – ";
        message += std::to_string(arguments_amount);
        message += ", required – 3!";
        throw std::invalid_argument(message);
    }
}

std::string ReadFileContentForTask6(const std::filesystem::path& path_to_file)
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

std::set<std::string> GetFilesContentFromDirectory(const std::filesystem::path& path_to_directory)
{
    std::set<std::string> resultSet;
    for (const auto& it : std::filesystem::directory_iterator(path_to_directory)) {
        if (std::filesystem::is_regular_file(it)) {
            std::string fileContent = ReadFileContentForTask6(it);
            if (!fileContent.empty()) {
                resultSet.insert(fileContent);
            }
        }
    }
    return resultSet;
}

//int main(int argc, char* argv[])
//{
//    try {
//        CheckArgumentsAmountForTask6(argc);
//        std::filesystem::path inputPath = argv[argc - 2];
//        std::filesystem::path outputPath = argv[argc - 1];
//        CheckInputPathForTask5(inputPath);
//        CheckInputPathForTask5(outputPath);
//        std::set<std::string> destinationDirectory = GetFilesContentFromDirectory(outputPath);
//
//        for (const auto& entry : std::filesystem::directory_iterator(inputPath)) {
//
//            const auto path_in_dir_out = outputPath / entry.path().filename();
//            std::string content = ReadFileContentForTask6(entry.path());
//            if (destinationDirectory.find(content) == destinationDirectory.end()) {
//                std::filesystem::copy_file(entry.path(), path_in_dir_out, std::filesystem::copy_options::overwrite_existing);
//                std::cout << "File " << entry.path().filename().string() << " is in " << path_in_dir_out.string() << std::endl;
//                destinationDirectory.insert(content);
//            }
//        }
//    }
//    catch (std::exception& ex) {
//        std::cout << ex.what();
//    }
//    return 0;
//}