/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD
-> Accepted (D3)
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int str_base = 48;
unordered_map<string, int> dp;

int find_ans(string state_now, int num_remain)
{
    if(num_remain == 0)
    {
        int res = 0;
        int base = 1;
        for(int i = state_now.length()-1; i>=0; --i)
        {
            res += base * (state_now[i] - str_base);
            base *= 10;
        }
        return res;
    }

    string key = state_now + '.' + to_string(num_remain);
    auto it = dp.find(key);
    if(it != dp.end())
        return it->second;

    int global_max = -1;
    for(int i = 0; i<state_now.length()-1; ++i)
    {
        for(int j = i+1; j<state_now.length(); ++j)
        {
            char c0 = state_now[i];
            char c1 = state_now[j];
            string state_next(state_now);
            state_next[i] = c1;
            state_next[j] = c0;
            int local_max = find_ans(state_next, num_remain-1);
            global_max = max(global_max, local_max);
        }
    }
    dp.emplace(key, global_max);
  
    return global_max;
}

int main(int argc, char** argv)
{
    int tc = 0;
    cin >> tc;
    for(int tc_i = 1; tc_i<=tc; ++tc_i)
    {
        int state_init_int = 0;
        int n = 0;
        cin >> state_init_int >> n;

        if(n == 0)
        {
            cout << "#" << tc_i << " " << state_init_int << endl;
            continue;
        }
        dp.clear();

        int base = 10;
        while(true)
        {
            if(state_init_int % base == state_init_int)
                break;

            base *= 10;
        }
        base /= 10;
        
        string state_init;
        while(true)
        {
            state_init += to_string(state_init_int / base);
            state_init_int %= base;
            if(base == 1)
                break;
          
            base /= 10;
        }

        int res = find_ans(state_init, n);
        cout << "#" << tc_i << " " << res << endl;
    }
  
    return 0;
}
