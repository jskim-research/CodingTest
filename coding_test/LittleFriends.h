#pragma once
#include "Problem.h"

using namespace std;

/*
2017 īī�� ����, ��Ʋ������ ��õ��
https://programmers.co.kr/learn/courses/30/lessons/1836
*/

class LittleFriends : public ProgrammersProblem
{
public:
	LittleFriends(FileFormat file_format);
	std::vector<std::string> Solve(std::vector<std::vector<std::string>>& input) override;
	char FindMatching(vector<string>& board, map<char, vector<pair<int, int>>>& coords);
	bool IsPathAvailable(vector<string>& board, char target, const pair<int, int>& src, const pair<int, int>& dst);
	bool IsBlock(vector<string>& board, char target, const pair<int, int>& src, const pair<int, int>& dst);
};
