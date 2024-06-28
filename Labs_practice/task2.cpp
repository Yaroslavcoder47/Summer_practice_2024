#include "task2.h"

void ModifyJsonObject(nlohmann::json& json_object)
{
	std::vector<nlohmann::json> keyToDelete;
	for (auto& item : json_object.items()) {

		if (item.value().is_object()) {

			nlohmann::json& itemObject = item.value();
			std::vector<nlohmann::json> keyToDeleteInObject;
			for (auto& it : itemObject.items()) {
				if (it.value().is_null()) {
					keyToDeleteInObject.push_back(it.key());
				}
			}
			for (const auto& key : keyToDeleteInObject) {
				item.value().erase(key);
			}
		}

		if (item.value().is_null()) {
			keyToDelete.push_back(item.key());
		}
	}

	for (const auto& key : keyToDelete) {
		json_object.erase(key);
	}
}

void WriteToFile(nlohmann::json& json_object, std::filesystem::path file_path)
{
	for (const auto& item : json_object.items()) {

		std::ofstream output;
		output.open(file_path.replace_filename(item.key() + ".json"));

		if (output.is_open()) {
			output << json_object[item.key()].dump(4);
		}
		output.close();
	}
}

//int mainTask2(int argc, char* argv[])
//{
//	try {
//		CheckArgumentsAmount(argc);
//		CheckInputPath(std::filesystem::path(argv[argc - 1]));
//		std::ifstream inputFile(argv[argc - 1]);
//		nlohmann::json inputData = nlohmann::json::parse(inputFile);
//
//		ModifyJsonObject(inputData);
//		WriteToFile(inputData, argv[1]);
//	}
//	catch (std::exception& ex) {
//		std::cerr << ex.what();
//	}
//
//	return 0;
//}