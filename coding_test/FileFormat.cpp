#include "FileFormat.h"

FileFormat::FileFormat(std::string _file_name, std::vector<Types> _types)
{
	file_name = _file_name;
	types = _types;
}

std::string FileFormat::GetFileName()
{
	return file_name;
}

std::vector<FileFormat::Types> FileFormat::GetTypes()
{
	return types;
}
