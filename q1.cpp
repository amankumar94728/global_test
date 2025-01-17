#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int lcs(string s1,string s2){
   int n=s1.length();
   int m=s2.length();

     int dp[n+1][m+1];
     for(int i=0;i<=n;i++ ){
        dp[i][0]=0;
     }
    for(int i=0;i<=m;i++ ){
        dp[0][i]=0;
     }

     for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
     }

return dp[n][m];

}
int main(){

      string s1="abcde";
      string s2="ace";

      cout<<" LCS : "<<lcs(s1,s2)<<endl;
    return 0;
}
