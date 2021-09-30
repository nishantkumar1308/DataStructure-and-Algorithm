#include<bits/stdc++.h>
using namespace std;
//recursive
int mini_to_get(int n)
{
	if(n==1)
	{
		return 0;

	}
	int x,y,z;
	x=INT_MAX;
	y=INT_MAX;
	z=INT_MAX;
	if(n%3==0)
	{
		x=mini_to_get(n/3);
	}
	if(n%2==0)
	{
		 y=mini_to_get(n/2);

	}
	z=mini_to_get(n-1);
	return 1+min(x,min(y,z));
}

// bottom up approach 
int min_val(int n)
{
	vector<int>dp(n+1,0);
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	for(int i=4;i<=n;i++)
	{
		int x,y,z;
		x=INT_MAX;
		y=INT_MAX;
		z=INT_MAX;
		if(i%3==0)
		{
			x=dp[i/3];
		}
		if(i%2==0)
		{
			y=dp[i/2];
		}
		z=dp[i-1];

		dp[i]=min(x,min(y,z))+1;
	}

	/*for(auto it: dp)
	{
		cout<<it<<" "; 
	}*/
	return dp[n];
}

//top down approach
vector<int>dp1(10005,-1);
int min1(int n)
{
	if(n==1)
	{
		dp1[1]=0;
		return 0;
	}
	if(dp1[n]!=-1)
	{
		return dp1[n];
	}
	int x,y,z;
	x=INT_MAX;
	y=INT_MAX;
	z=INT_MAX;
	if(n%3==0)
	{
		x=min1(n/3);
	}
	if(n%2==0)
	{
		y=min1(n/2);
	}
	z=min1(n-1);

	return dp1[n]=min(x,min(y,z))+1;

}

int main()
{
	int n;
	cin>>n;
	cout<<mini_to_get(n)<<endl;//recursion
	cout<<min_val(n)<<endl;//Topdown approach
	cout<<min1(n)<<endl;//bottom up approach

}