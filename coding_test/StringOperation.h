#pragma once
#include "DataStructureLayer.h"

class StringOperation
{
public:
	static std::vector<std::string> split(const std::string& input, char delimiter);
	static std::string trim(const std::string& input); // string�� �� ���� ���� ����
	static std::string ltrim(const std::string& input); // string�� ���� ���� ���� ����
	static std::string rtrim(const std::string& input); // string�� ������ ���� ���� ����
	static std::string remove_all(const std::string& input, char remove_target); // remove_target�� �ش��ϴ� ���� �����ϰ� ��ȯ
};