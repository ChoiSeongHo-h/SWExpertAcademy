/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV139KOaABgCFAYh
-> Accepted (D3)
*/

#include<iostream>
#include<map>
 
using namespace std;
 
int main(int argc, char** argv)
{
    for(int test_case = 0; test_case < 10; ++test_case)
    {
        int dump_num = 0;
        cin >> dump_num;
         
        map<int, int> tb;
        for(int w = 0; w<100; ++w)
        {
            int e = 0;
            cin >> e;
          
            if(tb.find(e) == tb.end())
                tb.emplace(e, 1);
            else
                ++tb[e];
        }
         
        int gap = 0;
        for(int i = 0; i<dump_num; ++i)
        {
            auto low = tb.begin();
            auto high = prev(tb.end());
            if(high->first - low->first <= 1)
            {
                gap = high->first - low->first;
                break;
            }
             
            if(high->second == 1)
                tb.erase(high);
            else
                --(high->second);
             
            if(tb.find(high->first-1) == tb.end())
                tb.emplace(high->first-1, 1);
            else
                ++tb[high->first-1];
             
            if(low->second == 1)
                tb.erase(low);
            else
                --(low->second);
             
            if(tb.find(low->first+1) == tb.end())
                tb.emplace(low->first+1, 1);
            else
                ++tb[low->first+1];
             
            gap = prev(tb.end())->first - tb.begin()->first;
        }
         
        cout << "#" << test_case+1 << " " << gap << endl;
    }
  
    return 0;
}
