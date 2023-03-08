/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh
-> Accepted (D3)
*/

#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    for(int tc = 1; tc<=10; ++tc)
    {
        int w = 0;
        cin >> w;
        vector<int> hs(w);
        for(int i = 0; i<w; ++i)
        {
            int h = 0;
            cin >> h;
            hs[i] = h;
        }
      
        vector<int> l2r_1(w, 0);
        for(int i = 1; i<w; ++i)
            l2r_1[i] = hs[i]-hs[i-1];
      
        vector<int> l2r_2(w, 0);
        for(int i = 2; i<w; ++i)
            l2r_2[i] = hs[i]-hs[i-2];
      
        vector<int> r2l_1(w, 0);
        for(int i = 0; i<w-1; ++i)
            r2l_1[i] = hs[i]-hs[i+1];
      
        vector<int> r2l_2(w, 0);
        for(int i = 0; i<w-2; ++i)
            r2l_2[i] = hs[i]-hs[i+2];
      
        int cnt = 0;
        for(int i = 0; i<w; ++i)
        {
            int partial = min(l2r_1[i], l2r_2[i]);
            partial = min(partial, r2l_1[i]);
            partial = min(partial, r2l_2[i]);
            partial = max(partial, 0);
            cnt += partial;
        }
      
        cout << "#" << tc << " " << cnt << endl;
    }
  
    return 0;
}
