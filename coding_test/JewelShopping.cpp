#include "JewelShopping.h"
#include "CommonHeaders.h"
using namespace std;

template <class T>
void Print(const T& data)
{
	cout << data << ' ';
}


int JewelShopping::GetCatNum(const vector<string>& gems)
{
	set<string> s;

	for (int i = 0; i < gems.size(); i++)
		s.insert(gems[i]);

	return s.size();
}

void JewelShopping::Solve()
{
	file->ReadFile("./JewelShopping.txt", { ProblemFile::Types::List, ProblemFile::Types::List });

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
		for_each(arrays[test_case + 1].begin(), arrays[test_case + 1].end(), Print<string>);
		cout << endl;
	}
}


