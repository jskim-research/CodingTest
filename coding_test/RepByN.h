#pragma once
#include "Problem.h"

/*
Level3 N���� ǥ��
https://programmers.co.kr/learn/courses/30/lessons/42895

0���� ������ case �����ϵ��� �ؾ���
calculate �Լ������� number�� ã���Ƿ� N, NN, NNN ó�� calculate �ٱ����� ��������� ��� count�� �ȵǴ� ��� ����
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