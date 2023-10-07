/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV19AcoKI9sCFAZN
-> Accepted (D3)
*/

#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    int N = 0;
    cin >> N;
    for(int i = 0; i<N; ++i)
    {
        string str;
        cin >> str;
        
        int cnt = 0;
        char prev = '0';
        for(int j = 0; j<str.length(); ++j)
        {
            if(str[j] != prev)
            {
                ++cnt;
                prev = str[j];
            }
        }
        
        cout << "#" << i+1 << " " << cnt << endl;
    }
    
	return 0;
}
