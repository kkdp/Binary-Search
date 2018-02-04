//  USERNAME: krishankantray
//  INSTITUTION: Galgotias University

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ull unsigned long long int
bool check(int arr[],int n,int m, int mid)
{
	int ctr=1,temp=0;
	for (int i = 0; i < n; ++i)
	{
		
		if(temp+arr[i]>mid)
		{
			ctr++;
			if(ctr>m)
				return false;
			temp=arr[i];
		}
		else
		temp+=arr[i];
	}
	return true;
}

int solve(int arr[], int n, int m)
{
	int mid;
	int left=0;
	int right=0;
	for(int i=0; i<n; ++i) right+=arr[i];
	int ans=INT_MAX;
	while(left <= right)
	{
		mid=(right+left)/2;
		if(check(arr,n,m,mid))
		{
			ans=min(ans,mid);
			right=mid-1;
		}
		else
			left=mid+1;
	}
	return ans;
}

int main()
{
	 #ifndef ONLINE_JUDGE
		  freopen("input.txt","r",stdin);
		  freopen("output.txt","w",stdout);
	#endif
	int n,m;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	sort(arr,arr+n);
	cin>>m;
	cout<<solve(arr,n,m);
	return 0;
}
