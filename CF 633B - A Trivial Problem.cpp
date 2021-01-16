// In the name of ALLAH the most Gracious the most Merciful
//  problem_link:https://codeforces.com/contest/633/problem/B

#include <bits/stdc++.h>
using namespace std;
// O(log(n) * log(n))
int trailing_zeros(int n){
	int i=5;		// n of trailing zeros of 128! is ==> 128/5 + 128/25 + 128/126
	int cnt = 0;
	while(n >= i){		// O(log(n))
		cnt+= n/i;
		i*=5;
	}
	return cnt;
}

int bin_search(int s,int e,int val){
	while(s <= e){		// O(log(n))
		int mid = s+(e-s)/2;
		if(trailing_zeros(mid) == val)return mid;
		else if(trailing_zeros(mid) > val) e = mid-1;
		else s = mid+1;
	}
	return -1;
}

int main() {
	int m;
	cin >> m;
	int start = 5;
	int end = m*5;
	int res = bin_search(start,end,m);
	if(res == -1){cout << 0 << endl;}
	else{
		res -= res%5;
		cout << 5 << endl;
		cout << res++ << " " << res++ << " " <<res++ << " " <<res++ << " " <<res++<< endl;
	}

	return 0;
}
