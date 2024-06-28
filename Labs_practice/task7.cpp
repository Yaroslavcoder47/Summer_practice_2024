#include "task7.h"

void FileStorage::InitStorage()
{
    for (const auto& it : std::filesystem::directory_iterator(path_to_directory_)) {
        if (std::filesystem::is_regular_file(it)) {
            std::string fileContent = ReadFileContentForTask6(it.path());
            if (!fileContent.empty()) {
                files_content_storage_.insert(fileContent);
            }
        }
    }
}
void FileStorage::CopyFile(const std::filesystem::path& path_to_file)
{
    std::string content = ReadFileContentForTask6(path_to_file);
    if (files_content_storage_.find(content) == files_content_storage_.end()) {
        const auto path_in_dir_out = path_to_directory_ / path_to_file.filename();
        std::filesystem::copy_file(path_to_file, path_in_dir_out, std::filesystem::copy_options::overwrite_existing);
        files_content_storage_.insert(content);
        std::cout << "File " << path_to_file.filename().string() << " is in " << path_to_directory_.string() << std::endl;
    }
}

int mainTask7(int argc, char* argv[])
{
    try {
        CheckArgumentsAmountForTask6(argc);
        std::filesystem::path inputPath = argv[argc - 3];
        std::filesystem::path outputPath = argv[argc - 2];
        CheckInputPathForTask5(inputPath);
        CheckInputPathForTask5(outputPath);
        FileStorage storage(outputPath);
        storage.InitStorage();

        for (const auto& it : std::filesystem::directory_iterator(inputPath)) {
            if (std::filesystem::is_regular_file(it.path())) {
                storage.CopyFile(it.path());
            }

        }
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }
    return 0;
}