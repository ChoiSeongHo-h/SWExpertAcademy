/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7IzvG6EksDFAXB
-> Accepted (D3)
*/

#include<iostream>
#include<vector>

using namespace std;

int traverse(vector<int>& arr, vector<int>& visited, int idx_now, int partial_sum, int K, int N)
{
    int sum = partial_sum + arr[idx_now];
    if(sum > K)
        return 0;
    
    if(sum == K)
        return 1;
    
    int partial_ans = 0;
    for(int i = idx_now+1; i<N; ++i)
    {
        if(visited[i] == 1)
            continue;
        
        visited[i] = 1;
        partial_ans += traverse(arr, visited, i, sum, K, N);
        visited[i] = 0;
    }
    
    return partial_ans;
}

int main(int argc, char** argv)
{
	int T;
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        int N, K;
        vector<int> arr, visited;
        cin >> N >> K;
        for(int i = 0; i<N; ++i)
        {
            int Ai;
            cin >> Ai;
            arr.emplace_back(Ai);
            visited.emplace_back(0);
        }
        
        int ans = 0;
        for(int i = 0; i<N; ++i)
        {
            visited[i] = 1;
            int partial_sum = 0;
            ans += traverse(arr, visited, i, partial_sum, K, N);
            visited[i] = 0;
        }

        cout << "#" << test_case << " " << ans << endl;
	}
  
	return 0;
}
