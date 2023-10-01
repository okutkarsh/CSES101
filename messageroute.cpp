#include<bits/stdc++.h>
using namespace std;

#define int long long 
vector<int> comp;
vector<vector<int>> g;
vector<int> dis;
vector<int> vis;
vector<int> par;
int n,m;
void bfs(int  node , int compno){
    comp[node] = compno;
    vis[node] = 1;
    dis[node] = 0;
    par[node] = 0;
  queue<int> q;
  q.push(node);
  while(!q.empty()){
      int temp = q.front();
      q.pop();
  
      for(auto x: g[temp]){
          if(!vis[x]){
              vis[x] = 1;
              comp[x] = compno;
              q.push(x);
              dis[x] = dis[temp] + 1;
              par[x] = temp;
              
          }}}
          
          
}
signed main(){
   
    cin>>n>>m;g.assign(n+1,vector<int>());vis.assign(n+1,0);int compno = 0;
    dis.assign(n+1,0);
    comp.assign(n+1,0);
    par.assign(n+1,0);
    for(int j = 0; j<m;j++){
       int a,b;
       cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);
    }
for(int i =1 ; i<=n; i++){
    if(!vis[i]){
        compno++;
        bfs(i,compno);
    }
}

if(comp[1]!=comp[n]){
    cout<<"IMPOSSIBLE"<<"\n";
}
else{
    cout<<dis[n] + 1<<"\n";
    int curr = n;
    vector<int> path;
    while(curr!=1){
 path.push_back(curr);
        curr = par[curr];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for(auto x : path){
        cout<<x<<" ";
    }
    cout<<'\n';
    
    
}


}