#pragma once

#ifdef LONGCOMPARER_EXPORTS
#define LONGCOMPARER_API __declspec(dllimport)
#else
#define LONGCOMPARER_API __declspec(dllexport)
#endif

extern "C" LONGCOMPARER_API void OpenGoogle(const char* url);
