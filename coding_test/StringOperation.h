#pragma once
#include "DataStructureLayer.h"

class StringOperation
{
public:
	static std::vector<std::string> split(const std::string& input, char delimiter);
	static std::string trim(const std::string& input);
	static std::string ltrim(const std::string& input);
	static std::string rtrim(const std::string& input);
	static std::string replace(const std::string& input, char replace_target);
};