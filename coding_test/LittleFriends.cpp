#include "LittleFriends.h"
#include "CommonHeaders.h"

LittleFriends::LittleFriends(FileFormat file_format): ProgrammersProblem(file_format)
{

}

std::vector<std::string> LittleFriends::Solve(std::vector<std::vector<std::string>>& input)
{
	std::vector<std::string> output;

	int m = stoi(input[0][0]);
	int n = stoi(input[1][0]);
		
	vector<string> board = input[2];
	string answer = "";

	map<char, vector<pair<int, int>>> coords;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c = board[i][j];
			if (c < 'A' || c > 'Z') continue;
			if (coords.find(c) != coords.end())
			{
				coords[c].push_back(make_pair(i, j));
			}
			else
			{
				vector<pair<int, int>> v;
				v.push_back(make_pair(i, j));
				coords[c] = v;
			}
		}
	}

	int size = coords.size();
	for (int i = 0; i < size; i++)
	{
		char c = FindMatching(board, coords);
		if (c == ' ')
		{
			answer = "IMPOSSIBLE";
			break;
		}
		answer += c;
	}

	output.push_back(answer);
	return output;
}

char LittleFriends::FindMatching(vector<string>& board, map<char, vector<pair<int, int>>>& coords)
{
	map<char, vector<pair<int, int>>>::iterator iter;
	pair<int, int> src, dst;
	char result = ' ';
	
	for (iter = coords.begin(); iter != coords.end(); iter++)
	{
		src = iter->second[0];
		dst = iter->second[1];
		if (IsPathAvailable(board, iter->first, src, dst))
		{
			board[src.first][src.second] = '.';
			board[dst.first][dst.second] = '.';
			result = iter->first;
			break;
		}
	}

	coords.erase(result);

	return result;
}

bool LittleFriends::IsPathAvailable(vector<string>& board, char target, const pair<int, int>& src, const pair<int, int>& dst)
{
	if ((src.first == dst.first && src.second != dst.second) || (src.first != dst.first && src.second == dst.second))
	{
		return !IsBlock(board, target, src, dst);
	}
	else if (src.first != dst.first && src.second != dst.second)
	{
		pair<int, int> mid1 = make_pair(src.first, dst.second);
		pair<int, int> mid2 = make_pair(dst.first, src.second);
		return (!IsBlock(board, target, src, mid1) && !IsBlock(board, target, mid1, dst)) || (!IsBlock(board, target, src, mid2) && !IsBlock(board, target, mid2, dst));
	}
	else
	{
		// should not be here
		cout << "[IsPathAvailable] error" << endl;
	}
	return false;
}

bool LittleFriends::IsBlock(vector<string>& board, char target, const pair<int, int>& src, const pair<int, int>& dst)
{
	// src - dst 일직선이 아닌 경우 에러 출력 (미구현)
	int incre_first = 0;
	int incre_second = 0;

	if (dst.first - src.first != 0)
	{
		incre_first = (dst.first - src.first) / abs(dst.first - src.first);

		for (int first = src.first; incre_first * first <= incre_first * dst.first; first += incre_first)
		{
			if (board[first][src.second] != '.' && board[first][src.second] != target)
				return true;
		}
	}

	if (dst.second - src.second != 0)
	{
		incre_second = (dst.second - src.second) / abs(dst.second - src.second);

		for (int second = src.second; incre_second * second <= incre_second * dst.second; second += incre_second)
		{
			if (board[src.first][second] != '.' && board[src.first][second] != target)
				return true;
		}
	}
	
	return false;
}
