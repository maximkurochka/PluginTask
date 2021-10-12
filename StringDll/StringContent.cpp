#include "pch.h"
#include "StringContent.h"

bool DoSomething(
	const char* sentence,
	const char* subsentence
)
{
	std::string sent(sentence);
	std::string subsent(subsentence);

	return sent.find(subsent) != std::string::npos;
}