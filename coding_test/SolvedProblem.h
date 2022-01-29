#pragma once
#include "Problem.h"

/*
2020 īī�� ���Ͻ� > ���� ����
https://programmers.co.kr/learn/courses/30/lessons/67258
*/

class JewelShopping : ProgrammersProblem
{
public:
	void Solve() override;
	int GetCatNum(const std::vector<std::string>& gems);

};

/*
Level3 N���� ǥ��
https://programmers.co.kr/learn/courses/30/lessons/42895

0���� ������ case �����ϵ��� �ؾ���
calculate �Լ������� number�� ã���Ƿ� N, NN, NNN ó�� calculate �ٱ����� ��������� ��� count�� �ȵǴ� ��� ����
*/

class RepN : ProgrammersProblem
{
public:
	void Solve() override;
	void PushAll(std::vector<int>& memo, const std::vector<int>& tmp);
	int MakeNs(int N, int i);
	std::vector<int> calculate(const std::vector<int>& lhs, const std::vector<int>& rhs, int (*func)(const int&, const int&), int number, bool& found);

};