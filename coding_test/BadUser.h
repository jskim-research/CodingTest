#pragma once
#include "Problem.h"

// 결국 순열로 모든 경우의 수를 구하고 중복제거를 하는 문제임.
// 순서를 고려하지 않는 조합의 경우 순서에 따라 가능한 조합을 무시하므로
// 순서를 고려하는 순열을 사용해야함.
/*
2019 카카오 개발자 겨울 인턴십 > 불량 사용자
https://programmers.co.kr/learn/courses/30/lessons/64064
*/

class BadUser : ProgrammersProblem
{
public:
	void Solve() override;
	bool Matching(const std::string& s1, const std::string& s2) const;
	int GetNumCases(std::map<std::string, bool>& selected, const std::vector<std::vector<std::string>> & v, int i, std::set<std::string>& s);
};
