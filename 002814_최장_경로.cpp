/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GOPPaAeMDFAXB
-> Accepted (D3)
*/

#include<iostream>
#include<vector>

using namespace std;

int traverse(int now, int d, vector<vector<int>>& g, vector<int>& visited, int depth)
{
    if(now == d)
        return depth;
    
    if(visited[now] == 1)
        return 0;
    
    visited[now] = 1;
    
    int ret = 0;
    for(int i = 0; i<g[now].size(); ++i)
    {
        int next = g[now][i];
        ret = max(ret, traverse(next, d, g, visited, depth+1));
    }
    
    visited[now] = 0;
    
    return ret;
}

int main(int argc, char** argv)
{
	int T;
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>> g(N+1);
        for(int i = 0; i<M; ++i)
        {
            int s, d;
            cin >> s >> d;
            g[s].emplace_back(d);
            g[d].emplace_back(s);
        }
        
        vector<int> ss;
        vector<int> ds;
        for(int s = 1; s<N; ++s)
        {
            for(int d = s+1; d<=N; ++d)
            {
                ss.emplace_back(s);
                ds.emplace_back(d);
            }
        }
        
        int ans = 1;
        for(int idx0 = 0; idx0<ss.size(); ++idx0)
        {
            int s = ss[idx0];
            int d = ds[idx0];
            vector<int> visited(N+1);
            ans = max(ans, traverse(s, d, g, visited, 1));
        }
        
        cout << "#" << test_case << " " << ans << endl;
	}
    
	return 0;
}
