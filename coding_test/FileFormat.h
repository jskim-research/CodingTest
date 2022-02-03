#pragma once
#include "CommonHeaders.h"

class FileFormat
{
public:
	enum Types { List, Value };
	FileFormat(std::string _file_name, std::vector<Types> _types);
	std::string GetFileName();
	std::vector<Types> GetTypes();
private:
	std::string file_name;
	std::vector<Types> types;
};