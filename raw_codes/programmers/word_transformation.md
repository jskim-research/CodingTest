```cpp
#include <string>
#include <vector>
#include <map>
#include <iostream>

#define MAX_CNT 100

using namespace std;

int get_diff(const string& a, const string& b)
{
    int result = 0;
    for (int i=0; i<a.size(); i++)
        if (a[i] != b[i]) result++;
    return result;
}

int transform(const string& begin, const string& target, int step, map<string, bool>& bVisit, const vector<string>& words)
{
    vector<int> results;
    int min_result = MAX_CNT;
    
    if (begin == target) return step;
    
    for (int i=0; i<words.size(); i++)
    {
        string word = words[i];
        if (get_diff(begin, word) != 1) continue;
        if (bVisit[word]) continue;
        bVisit[word] = true;
        int tmp = transform(word, target, step+1, bVisit, words);
        bVisit[word] = false;
        results.push_back(tmp);
    }
    
    for (int i=0; i<results.size(); i++)
        if (results[i] < min_result) min_result = results[i];
    
    return min_result;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map<string, bool> bVisit;
    
    
    for (int i=0; i<words.size(); i++)
        bVisit[words[i]] = false;
    
    answer = transform(begin, target, 0, bVisit, words);
    if (answer == MAX_CNT) answer = 0;
    
    return answer;
}
```