/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LsaaqDzYDFAXc
-> Accepted (D3)
*/

#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case)
  {
      int N, M, K;
      cin >> N >> M >> K;
      vector<int> customers;
      int customer_max = -1;
      for(int i = 0; i<N; ++i)
      {
          int customer;
          cin >> customer;
          customers.emplace_back(customer);
        
          customer_max = max(customer_max, customer);
      }
      
      map<int, int> net_per_time;
      for(int i = M; i<=customer_max; i+=M)
          net_per_time.emplace(i, K);
      
      for(int i = 0; i<N; ++i)
      {
          int customer_time = customers[i];
        
          auto it = net_per_time.find(customer_time);
          if(it == net_per_time.end())
              net_per_time.emplace(customer_time, -1);
          else
              --(it->second);
      }
      
      int now = 0;
      int ok = 1;
      for(auto& it : net_per_time)
      {
          now += it.second;
        
          if(now < 0)
          {
              ok = 0;
              break;   
          }
      }
      
      if(ok)
          cout << "#" << test_case << " Possible" << endl;
      else
          cout << "#" << test_case << " Impossible" << endl;
	}
  
	return 0;
}
