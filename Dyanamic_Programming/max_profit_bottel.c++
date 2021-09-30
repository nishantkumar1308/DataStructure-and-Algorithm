#include<bits/stdc++.h>
using namespace  std;
//recursion
int max_profit(int i,int j,int arr[],int y)
{
	if(i>j)
	{
		return 0;
	}
	int a= arr[i]*y +max_profit(i+1,j,arr,y+1);
	int b=arr[j]*y + max_profit(i,j-1,arr,y+1);
	return max(a,b); 

}
//top down approach
int max_profit_td(int i,int j,int arr[],int dp[][100],int y)
{
	if(i>j)
	{
		return 0;
	}
	if(dp[i][j]!=0)
	{
		return dp[i][j];
	}
	int op1=arr[i]*y+max_profit_td(i+1,j,arr,dp,y+1);
	int op2=arr[j]*y+max_profit_td(i,j-1,arr,dp,y+1);
	return dp[i][j]= max(op1,op2);
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<max_profit(0,n-1,arr,1)<<endl;//recursive
	//topdown approach
	int dp[100][100]={0};
	cout<<max_profit_td(0,n-1,arr,dp,1)<<endl;



}