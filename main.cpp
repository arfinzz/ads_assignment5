#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int minTrials(int n, int k)
{
    
    int prev_dp[n+1]={0};
    int cur_dp[n+1]={0};

    for(int egg=1;egg<=k;egg++)
    {
        for(int floor=1;floor<=n;floor++)
        {
            if(egg==1)
            {
                cur_dp[floor]=floor-1;
            }
            else if(floor==1)
            {
                cur_dp[floor]=0;
            }
            else
            {
                int mini=INT_MAX;

                for(int mj=floor-1, pj=1;mj>0;mj-- , pj++)
                {
                    mini = min( max(cur_dp[mj] , prev_dp[pj]) , mini );
                }

                 cur_dp[floor]=mini+1;
            }


        }

        for(int floor=1;floor<=n;floor++)
        {
            prev_dp[floor]=cur_dp[floor];
        }

    }

    return cur_dp[n];
   
}




int main()
{
   ifstream fileIn("input.txt");
   cin.rdbuf(fileIn.rdbuf());
   ofstream fileOut("output.txt");
   cout.rdbuf(fileOut.rdbuf());
    
    string str;
    int n,k;
    cin>>str;
    char *cstr = str.data();
    char *token = strtok(cstr, ",");
    n=stoi(token);
    token = strtok(NULL, ",");
    k=stoi(token);

   

    
 
    cout<< minTrials(n, k);
    return 0;
}

