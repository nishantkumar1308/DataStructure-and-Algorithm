#include<bits/stdc++.h>
using namespace std;
//recursive
int min_coin(int n,int arr[],int size)
{
	if(n==0)
	{
		return 0;
	}
	int ans=INT_MAX;
	for(int i=0;i<size;i++)
	{
		if(n>=arr[i])
		{
			ans= min(ans,min_coin(n-arr[i],arr,size)+1);
		}
	}
	return ans;

}
//top down approach

vector<int>dp1(10005,-1);
int min_coin_dp(int n,int arr[],int s)
{
	if(n==0)
	{
		return 0;
	}
	if(dp1[n]!=-1)
	{
		return dp1[n];
	}
	int ans=INT_MAX;
	for(int i=0;i<s;i++)
	{
		if(n>=arr[i])
		{
			ans=min(ans,min_coin_dp(n-arr[i],arr,s)+1);
		}
	}
	dp1[n]=ans;
	return dp1[n];

}


//bottom up approach

int min_coin_bottom_up(int n, int arr[],int s)
{
	vector<int>dp(n+1,0);
	dp[0]=0;
	dp[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		 int ans=INT_MAX;
		for(int j=0;j<s;j++)
		{
			if(i-arr[j]>=0)
			{
				ans=min(ans,dp[i-arr[j]]+1);
			}


		}
		dp[i]=ans;
		
	}
	for(auto it:dp)
	{
		cout<<it<<" ";
	}
	cout<<endl;
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	int arr[3]={1,7,10};
     int ans=min_coin( n,arr,3);//recursive case;
	cout<<ans<<endl;
	cout<<min_coin_dp( n,arr,3)<<endl;//top down approach
	cout<<min_coin_bottom_up(n,arr,3)<<endl;//bottom up approach

}