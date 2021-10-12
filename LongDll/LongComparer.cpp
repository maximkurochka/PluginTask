#include "pch.h"
#include "LongComparer.h"
#include <shellapi.h>

void OpenGoogle(const char* url)
{
	ShellExecuteA(0, 0, url, 0, 0, SW_SHOW);
}