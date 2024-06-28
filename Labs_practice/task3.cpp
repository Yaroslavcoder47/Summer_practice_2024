#include "task3.h"

void WriteToConsole(nlohmann::json data)
{
    std::cout << data.dump(4);
}

tm GetRequiredDateTime()
{
    time_t currentTime = time(nullptr);
    tm timeStruct;
    localtime_s(&timeStruct, &currentTime);
    timeStruct.tm_mday--;
    return timeStruct;
}

nlohmann::json TmToJson(tm date_time)
{
    nlohmann::json dataTime;
    dataTime["Year"] = date_time.tm_year + 1900;
    dataTime["Month"] = date_time.tm_mon + 1;
    dataTime["Day"] = date_time.tm_mday;
    dataTime["Hours"] = date_time.tm_hour;
    dataTime["Minutes"] = date_time.tm_min;
    return dataTime;
}

void WriteToJsonFile(nlohmann::json& json_object, std::filesystem::path file_path)
{
    std::ofstream out(file_path);
    out << json_object.dump(4);
}

//int main(int argc, char* argv[])
//{
//    try {
//        CheckArgumentsAmount(argc);
//        CheckInputPath(std::filesystem::path(argv[argc - 1]));
//        nlohmann::json timeObject = TmToJson(GetRequiredDateTime());
//        WriteToConsole(timeObject);
//        WriteToJsonFile(timeObject, argv[argc - 1]);
//    }
//    catch (std::exception& ex) {
//        std::cout << ex.what();
//    }
//    return 0;
//}