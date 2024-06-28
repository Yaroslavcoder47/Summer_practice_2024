#include "LabsMain.h"

void LabsMain(int argc, char* argv[])
{
	try {
		int numberOfLab = std::stoi(argv[argc - 1]);
		std::vector<int(*)(int, char* [])> func_vector;
		func_vector.push_back(&mainTask1);
		func_vector.push_back(&mainTask2);
		func_vector.push_back(&mainTask3);
		func_vector.push_back(&mainTask4);
		func_vector.push_back(&mainTask5);
		func_vector.push_back(&mainTask6);
		func_vector.push_back(&mainTask7);
		func_vector.push_back(&mainTask8);
		func_vector.push_back(&mainTask9);
		func_vector.push_back(&mainTask10);
		func_vector[numberOfLab - 1](argc, argv);
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
}
