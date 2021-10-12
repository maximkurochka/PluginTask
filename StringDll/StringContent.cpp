#include "pch.h"
#include "StringContent.h"

void OpenMessageBox(const char* text)
{
	MessageBoxA(0, text, (LPCSTR)"StringContent.dll", MB_OK | MB_ICONINFORMATION);
}