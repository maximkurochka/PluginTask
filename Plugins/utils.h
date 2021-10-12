#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <stdio.h>
#include <excpt.h>
#include <Windows.h>

using DoSomething = void(*)(const char*);

const std::wstring gPathToThePlugins = L"C:\\Users\\maxim.kurochka\\Desktop\\Plugins\\Debug";
const std::wstring gDllExtension = L".dll";
const std::string gFuncName = "OpenGoogle"; // DoSomething || OpenGoogle || OpenMessageBox

namespace utils
{
	void GetDllPathesFromDirectory(const std::filesystem::path& dir, std::vector<std::filesystem::path>& dllPathes);

	bool FindAndExecuteFunction(
		const std::vector<std::filesystem::path>& dllPathes,
		const std::string& funcName,
		DoSomething func,
		const char* param1
	);
}