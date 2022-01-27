#pragma once
#include "DataStructureLayer.h"

class StringOperation
{
public:
	static std::vector<std::string> split(const std::string& input, char delimiter);
	static std::string trim(const std::string& input); // string의 양 끝단 문자 제거
	static std::string ltrim(const std::string& input); // string의 왼쪽 끝단 문자 제거
	static std::string rtrim(const std::string& input); // string의 오른쪽 끝단 문자 제거
	static std::string remove_all(const std::string& input, char remove_target); // remove_target에 해당하는 문자 제외하고 반환
};