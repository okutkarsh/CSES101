#include<bits/stdc++.h>
using namespace std;

#define int long long 
vector<int> comp;
vector<vector<int>> g;
vector<int> dis;
vector<int> vis;
vector<int> par;
int n,m;
bool isbipar = true;
void dfs(int  node , int compno){
    comp[node] = compno;
    //dis[node] = 0;
   // par[node] = 0;
  
      for(auto x: g[node]){
          if(!comp[x]){
              dfs(x,3-compno);
              
          }
          else if(comp[x]==comp[node]){
              isbipar = false;
              return;
          }
          
      }
    
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
    if(!comp[i] && isbipar){
        compno = 1;
        dfs(i,compno);
    }
}
if(!isbipar){
    cout<<"IMPOSSIBLE"<<"\n";
}
else{
    for(int i = 1; i<=n ; i++){
        cout<<comp[i]<<" ";
    }
    cout<<endl;
}



}