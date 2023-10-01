#include<bits/stdc++.h>
using namespace std;

#define int long long 
map<int, vector<int>> mp;
vector<vector<int>> g;
vector<int> vis;
int n,m;
void dfs(int  node , int compno){
    vis[node] = 1;
    mp[compno].push_back(node);
  
      for(auto x: g[node]){
          if(!vis[x]){
              dfs(x,compno);
              
          }}}
signed main(){
    mp.clear();
    cin>>n>>m;g.assign(n+1,vector<int>());vis.assign(n+1,0);int compno = 0;
    for(int j = 0; j<m;j++){
       int a,b;
       cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);
    }
for(int i =1 ; i<=n; i++){
    if(!vis[i]){
        compno++;
        dfs(i,compno);
    }
}
cout<<mp.size() -1<<"\n";

for(int i = 1 ; i< mp.size() ; i++){
    cout<<mp[i][0]<<" "<<mp[i+1][0];
    cout<<"\n";
}

}