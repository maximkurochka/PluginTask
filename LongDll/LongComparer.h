#pragma once

#ifdef LONGCOMPARER_EXPORTS
#define LONGCOMPARER_API __declspec(dllimport)
#else
#define LONGCOMPARER_API __declspec(dllexport)
#endif

//If param1 != 0, the function returns true, else - false
extern "C" LONGCOMPARER_API bool DoSomething(
	long param1
);
