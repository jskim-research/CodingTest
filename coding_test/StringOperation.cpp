#include "StringOperation.h"
#include "UtilityLayer.h"

std::vector<std::string> StringOperation::split(const std::string& input, char delimiter)
{
	std::stringstream ss(input);
	std::string buffer;
	std::vector<std::string> result;

	while (std::getline(ss, buffer, delimiter))
		result.push_back(buffer);

	return result;
}

std::string StringOperation::trim(const std::string& input)
{
	if (input.size() < 2) return input;
	
	return rtrim(ltrim(input));
}

std::string StringOperation::ltrim(const std::string& input)
{
	if (input.size() == 0) return input;
	return input.substr(1, input.size()-1);
}

std::string StringOperation::rtrim(const std::string& input)
{
	if (input.size() == 0) return input;
	return input.substr(0, input.size()-1);
}

std::string StringOperation::remove_all(const std::string& input, char remove_target)
{
	std::string result;

	for (std::string::size_type i = 0; i < input.size(); i++)
	{
		if (input[i] == remove_target)
			continue;
		result.push_back(input[i]);
	}

	return result;
}
