#pragma once
#include "Problem.h"

// �ᱹ ������ ��� ����� ���� ���ϰ� �ߺ����Ÿ� �ϴ� ������.
// ������ ������� �ʴ� ������ ��� ������ ���� ������ ������ �����ϹǷ�
// ������ ����ϴ� ������ ����ؾ���.
/*
2019 īī�� ������ �ܿ� ���Ͻ� > �ҷ� �����
https://programmers.co.kr/learn/courses/30/lessons/64064
*/

class BadUser : ProgrammersProblem
{
public:
	void Solve() override;
	bool Matching(const std::string& s1, const std::string& s2) const;
	int GetNumCases(std::map<std::string, bool>& selected, const std::vector<std::vector<std::string>> & v, int i, std::set<std::string>& s);
};
