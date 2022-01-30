#pragma once
#include "Problem.h"

/*
2020 카카오 인턴십 > 보석 쇼핑
https://programmers.co.kr/learn/courses/30/lessons/67258
*/

class JewelShopping : ProgrammersProblem
{
public:
	void Solve() override;
	int GetCatNum(const std::vector<std::string>& gems);

};
