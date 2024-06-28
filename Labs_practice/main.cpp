#include <iostream>
#include <ctime>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#include "task7.h"
#include "task8.h"
#include "task9.h"
#include "task10.h"



int main(int argc, char* argv[])
{
    try {
        CheckArgumentsAmount(argc);
        std::filesystem::path inputPath = argv[1];
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
                    std::cout << "File " + it.path().filename().string() + " was removed successfully" << std::endl;
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