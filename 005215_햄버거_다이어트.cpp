/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWT-lPB6dHUDFAVT
-> Accepted (D3)
*/

// backtracking
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int traverse(int cal_max, vector<int>& scores, vector<int>& cals, int idx, int N, int cal, int score, vector<int>& used)
{
    int cal_new = cal + cals[idx];
    if(cal_new > cal_max)
        return score;
    
    int score_new = score + scores[idx];
    
    int score_upt = score_new;
    for(int idx_upt = idx+1; idx_upt<N; ++idx_upt)
    {
        if(used[idx_upt] == 1)
            continue;
        
        used[idx_upt] = 1;
        score_upt = max(score_upt, traverse(cal_max, scores, cals, idx_upt, N, cal_new, score_new, used));
        used[idx_upt] = 0;
    }
    return score_upt;
}

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        int cal_max;
        vector<int> scores;
        vector<int> cals;
        vector<int> used;
        cin >> N >> cal_max;
        for(int i = 0; i<N; ++i)
        {
            int score;
            int cal;
            cin >> score >> cal;
            scores.emplace_back(score);
            cals.emplace_back(cal);
            used.emplace_back(0);
        }
    
        int max_score = 0;
        for(int idx = 0; idx<N; ++idx)
        {
            used[idx] = 1;
            max_score = max(max_score, traverse(cal_max, scores, cals, idx, N, 0, 0, used));
            used[idx] = 0;
        }
        cout << "#" << test_case << " " << max_score << endl;
    }
    return 0;
}

// dp
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        int cal_max;
        vector<int> scores(1, 0);
        vector<int> cals(1, 0);
        cin >> N >> cal_max;
        for(int i = 0; i<N; ++i)
        {
            int score;
            int cal;
            cin >> score >> cal;
            scores.emplace_back(score);
            cals.emplace_back(cal);
        }
        
        vector<vector<int>> dp(N+1, vector<int>(cal_max+1, 0));
        for(int i = 1; i<=N; ++i)
        {
            for(int j = 1; j<=cal_max; ++j)
            {
                if(cals[i] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-cals[i]] + scores[i]);
            } 
        }
    
        cout << "#" << test_case << " " << dp.back().back() << endl;
    }
    return 0;
}
