#pragma once
#include "Problem.h"

/*
Level3 N으로 표현
https://programmers.co.kr/learn/courses/30/lessons/42895

0으로 나누는 case 무시하도록 해야함
calculate 함수에서만 number를 찾으므로 N, NN, NNN 처럼 calculate 바깥에서 만들어지는 경우 count가 안되는 경우 조심
*/

class RepN : public ProgrammersProblem
{
public:
	RepN(FileFormat file_format);
	std::vector<std::string> Solve(std::vector<std::vector<std::string>>& input) override;
	void PushAll(std::vector<int>& memo, const std::vector<int>& tmp);
	int MakeNs(int N, int i);
	std::vector<int> calculate(const std::vector<int>& lhs, const std::vector<int>& rhs, int (*func)(const int&, const int&), int number, bool& found);

};