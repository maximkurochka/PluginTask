#include "utils.h"

namespace utils
{
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

	bool FindAndExecuteFunction(
		const std::vector<std::filesystem::path>& dllPathes,
		const std::string& funcName,
		DoSomething func,
		const char* param
	)
	{
		HINSTANCE hDll;

		for (auto path : dllPathes)
		{
			hDll = LoadLibrary(static_cast<LPCWSTR>(path.c_str()));
			if (hDll == NULL)
			{
				continue;
			}

			func = reinterpret_cast<DoSomething>(GetProcAddress(hDll, funcName.c_str()));
			if (func == NULL)
			{
				FreeLibrary(hDll);
				continue;
			}

			func(param);
			FreeLibrary(hDll);
			return true;
		}
		return false;
	}
}