#include<bits/stdc++.h>
using namespace std;
int numDecodings(string s) {
    int n=s.length();
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[n]=1;
    if(s[n-1]!='0'){       //if the last chararcter is not zero then we have one way to decode it
        dp[n-1]=1;
    }
    for(int i=n-2;i>=0;i--){
        if(s[i]!='0'){    
            dp[i]+=dp[i+1];
        }
        if(s[i]=='1'){
            dp[i]+=dp[i+2];
        }
        if(s[i]=='2'){
            if(s[i+1]<='6'){
                dp[i]+=dp[i+2];
            }
        }
    }
    return dp[0];
}
int main(){
    string s="452625";
    cout<<numDecodings(s);
}