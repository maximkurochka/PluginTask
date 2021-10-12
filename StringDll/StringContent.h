#pragma once

#ifdef STRINGCONTENT_EXPORTS
#define STRINGCONTENT_API __declspec(dllimport)
#else
#define STRINGCONTENT_API __declspec(dllexport)
#endif

extern "C" STRINGCONTENT_API bool DoSomething(
	const char* sentence,
	const char* subsentence
);
