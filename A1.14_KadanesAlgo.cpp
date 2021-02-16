#include<iostream>
#include<vector>
int maxSubArray(vector<int>& nums)
    {  
       int mx=INT_MIN, sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i], mx=max(mx,sum);
            if(sum<0) sum=0;
        }
        return mx;
    } 

int main()
{
   vector<int> V;
   int arr[]={-2,1,-3,4,-1,2,1,-5,4};
   int n= sizeof(arr)/sizeof(arr[0]);
   for(int i=0;i<n;i++)
   {
       V.push(arr[i]);
   }
   int max=maxSubArray(&V);
   cout<<max;
    return 0;
}