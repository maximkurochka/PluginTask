// Plugins.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <filesystem>
#include "utils.h"

int main()
{
	DoSomething doSomething = nullptr;
	std::vector<std::filesystem::path> dllPathes;

	utils::GetDllPathesFromDirectory(gPathToThePlugins, dllPathes);

	std::cout << "The function does ";
	if (!utils::FindAndExecuteFunction(dllPathes, gFuncName, doSomething, "https://www.google.com/")) //Text || https://www.google.com/
	{
		std::cout << "not ";
	}
	std::cout << "exist" << std::endl;
}
