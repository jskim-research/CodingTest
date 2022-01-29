#include "SolvedProblem.h"
#include "DataStructureLayer.h"
#include <algorithm>
#include <functional>
#include <exception>

using namespace std;

template <class T>
void Print(const T& data)
{
	cout << data << ' ';
}

int Plus(const int& lhs, const int& rhs)
{
	return lhs + rhs;
}

int Minus(const int& lhs, const int& rhs)
{
	return lhs - rhs;
}

int Divide(const int& lhs, const int& rhs)
{
	if (rhs == 0) throw "0으로 나눌 수 없습니다.";
	return lhs / rhs;
}

int Multiply(const int& lhs, const int& rhs)
{
	return lhs * rhs;
}

void JewelShopping::Solve()
{
	file->ReadFile("./보석쇼핑.txt", { "list", "list"});

	vector<vector<string>> arrays = file->GetArrays();

	for (int test_case = 0; test_case < arrays.size(); test_case += 2)
	{
		cout << "case: " << test_case / 2 << endl;
		vector<int> answer;
		vector<string> gems = arrays[test_case];
		int start = 0, end = 0, min_start = 1, min_end = gems.size(), min_len = gems.size(), cat_num = GetCatNum(gems);
		set<string> s;
		map<string, int> m;

		while (start <= end && end <= gems.size())
		{
			if (s.size() == cat_num) // 조건 만족시 start++
			{
				if (end - start < min_len)
				{
					min_len = end - start;
					min_start = start + 1;
					min_end = end;
				}

				m[gems[start]]--;
				if (m[gems[start]] == 0)
					s.erase(gems[start]);
				start++;
			}
			else // 조건 불만족시 조건 만족시까지 end++
			{
				if (end >= gems.size()) break;
				if (m.find(gems[end]) == m.end())
					m[gems[end]] = 1;
				else
					m[gems[end]]++;

				s.insert(gems[end]);
				end++;
			}

		}

		answer.push_back(min_start);
		answer.push_back(min_end);

		for_each(answer.begin(), answer.end(), Print<int>);
		cout << endl;

		// size_t가 맞음
		for_each(arrays[test_case+1].begin(), arrays[test_case+1].end(), Print<string>);
		cout << endl;
	}
}

int JewelShopping::GetCatNum(const vector<string>& gems)
{
	set<string> s;

	for (int i = 0; i < gems.size(); i++)
		s.insert(gems[i]);

	return s.size();
}

void RepN::Solve()
{
	file->ReadFile("./N으로표현.txt", { "value", "value", "value"});
	vector<vector<string>> inputs = file->GetArrays();

	for (int test_case = 0; test_case < inputs.size(); test_case += 3)
	{
		int answer = -1;
		int N = stoi(inputs[test_case][0]), number = stoi(inputs[test_case + 1][0]);
		vector<vector<int>> memo;
		vector<int> tmp;
		bool bFound = false;
		
		for (int i = 1; i <= 7; i++)
		{
			vector<int> v;
			int n = MakeNs(N, i);
			if (n == number)
			{
				answer = i;
			}
			v.push_back(n);
			memo.push_back(v);
		}

		for (int i = 2; i <= 7; i++)
		{
			if (answer != -1) break;
			for (int j = 1; j < i; j++)
			{
				tmp = calculate(memo[j - 1], memo[i - j - 1], Plus, number, bFound);
				PushAll(memo[i - 1], tmp);
				tmp = calculate(memo[j - 1], memo[i - j - 1], Minus, number, bFound);
				PushAll(memo[i - 1], tmp);
				tmp = calculate(memo[j - 1], memo[i - j - 1], Divide, number, bFound);
				PushAll(memo[i - 1], tmp);
				tmp = calculate(memo[j - 1], memo[i - j - 1], Multiply, number, bFound);
				PushAll(memo[i - 1], tmp);
			}
			if (bFound)
			{
				answer = i;
				break;
			}
		}

		cout << answer << ' ' << stoi(inputs[test_case + 2][0]) << endl;
	}
}

void RepN::PushAll(std::vector<int>& memo, const std::vector<int>& tmp)
{
	for (std::vector<int>::size_type i = 0; i < tmp.size(); i++)
		memo.push_back(tmp[i]);
}

int RepN::MakeNs(int N, int i)
{
	if (i <= 0) return 0;
	return N * pow(10, i - 1) + MakeNs(N, i - 1);
}


std::vector<int> RepN::calculate(const std::vector<int>& lhs, const std::vector<int>& rhs, int (*func)(const int&, const int&), int number, bool& found)
{
	std::vector<int> result;
	int tmp = 0;

	for (std::vector<int>::size_type i = 0; i < lhs.size(); i++)
	{
		for (std::vector<int>::size_type j = 0; j < rhs.size(); j++)
		{
			try {
				tmp = func(lhs[i], rhs[j]);
			}
			catch (...)
			{
				continue;
			}
			if (tmp == number)
				found = true;
			result.push_back(tmp);
		}
	}

	return result;
}
