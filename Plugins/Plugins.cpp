// Plugins.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <filesystem>
#include <stdio.h>
#include <excpt.h>
#include <Windows.h>

using DoSomething = bool(*)(const char*, const char*);

const std::wstring gPathToThePlugins = L"C:\\Users\\maxim.kurochka\\Desktop\\Plugins\\Debug";
const std::wstring gDllExtension = L".dll";
const std::string gFuncName = "DoSomething";

void GetDllPathesFromDirectory(const std::filesystem::path& dir, std::vector<std::filesystem::path>& dllPathes)
{
	for (auto& entry : std::filesystem::recursive_directory_iterator(dir))
	{
		if (entry.path().extension() == gDllExtension)
		{
			dllPathes.emplace_back(entry.path());
		}
	}
}

template<typename FuncPtr, typename Param1, typename Param2>
bool ExecuteFunction(FuncPtr& func, Param1 param1, Param2 param2)
{
	bool result = false;
	__try
	{
		func(param1, param2);
		result = true;
	}
	__finally
	{
		return result;
	}
}

template<typename FuncPtr, typename Param1, typename Param2>
bool FindAndExecuteFunction(
	const std::vector<std::filesystem::path>& dllPathes,
	const std::string& funcName,
	FuncPtr func,
	Param1 param1,
	Param2 param2
)
{
	HINSTANCE hDll;
	bool result;

	for (auto path : dllPathes)
	{
		hDll = LoadLibrary((LPCWSTR)path.c_str());
		if (hDll == NULL)
		{
			continue;
		}

		func = reinterpret_cast<FuncPtr>(GetProcAddress(hDll, funcName.c_str()));
		if (func == NULL)
		{
			FreeLibrary(hDll);
			continue;
		}

		result = ExecuteFunction(func, param1, param2);
		FreeLibrary(hDll);

		if (result)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	DoSomething doSomething = nullptr;
	std::vector<std::filesystem::path> dllPathes;

	GetDllPathesFromDirectory(gPathToThePlugins, dllPathes);

	std::cout << "The function does ";
	if (!FindAndExecuteFunction(dllPathes, gFuncName, doSomething, "asdasd", "55"))
	{
		std::cout << "not ";
	}
	std::cout << "exist" << std::endl;
}
