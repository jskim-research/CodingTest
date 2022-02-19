```cpp
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool DFS(string cur_airport, map<string, int>& ticket_num, map<string, vector<string>>& ticket_dests, vector<string>& path, int target_num)
{
    path.push_back(cur_airport);
    if (path.size() == target_num)
    {
        return true;
    }
    
    vector<string> dests = ticket_dests[cur_airport];
    
    for (int i=0; i<dests.size(); i++)
    {
        string dest = dests[i];
        if (ticket_num[cur_airport + dest] != 0)
        {
            ticket_num[cur_airport + dest]--;
            if(!DFS(dest, ticket_num, ticket_dests, path, target_num))
            {
                ticket_num[cur_airport + dest]++;
                path.pop_back();
            }
            else
                return true;
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, int> ticket_num;
    map<string, vector<string>> ticket_dests;
    map<string, vector<string>>::iterator iter;
    
    for (int i=0; i<tickets.size(); i++)
    {
        string a = tickets[i][0];
        string b = tickets[i][1];
        
        if (ticket_num.find(a+b) != ticket_num.end())
            ticket_num[a+b] ++;
        else 
            ticket_num[a+b] = 1;
        
        if (ticket_dests.find(a) != ticket_dests.end())
            ticket_dests[a].push_back(b);
        else
        {
            vector<string> v;
            v.push_back(b);
            ticket_dests[a] = v;
        }
    }
    
    iter = ticket_dests.begin();
    for (;iter!=ticket_dests.end(); iter++)
    {
        sort(iter->second.begin(), iter->second.end());
    }
    
    DFS("ICN", ticket_num, ticket_dests, answer, tickets.size() +1);
    
    return answer;
}
```