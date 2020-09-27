#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n;
vector<vi>adj;
int s,l;
int main(){
	cin >> s >> l;
	adj = vector <vector<int>>(s);
	int a,b;
	while(l--){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt =0;
	bool oneExist = 0;
	vector <pair<int, int>> toDelete;
	while(true){
		for(int i=0; i<int(adj.size()); i++){
				if(adj[i].size() == 1) {
					toDelete.push_back({i,adj[i][0]});
					oneExist = 1;
					}
				}
		cnt += oneExist;
		if(!oneExist) break;
		oneExist = 0;
		for(int i = 0;i< (int)(toDelete.size());i++){
			int f = toDelete[i].first, v = toDelete[i].second;

			adj[f].erase(remove(adj[f].begin(), adj[f].end(), v),adj[f].end());
			adj[v].erase(remove(adj[v].begin(), adj[v].end(), f),adj[v].end());
			}
		toDelete.clear();
	}
	cout << cnt;
}
