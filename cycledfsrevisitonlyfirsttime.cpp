#include<bits/stdc++.h>
using namespace std;

#define int long long 
vector<int> comp;
vector<vector<int>> g;
vector<int> dis;
vector<int> vis;
vector<int> par;
int n,m;
vector<int> any_cycle;
bool iscycle = false;
void dfs(int  node , int compno){
    vis[node] = 1;
    par[node] = compno;
  
      for(auto x: g[node]){
          if(!vis[x]){
              dfs(x,node);}
          else if(x!=par[node]){
             int curr  = node;
             if(iscycle==0){
            any_cycle.push_back(x);
             while(curr!= x){
                 any_cycle.push_back(curr);
                 
                 curr = par[curr];
                 
             }
                 
             any_cycle.push_back(x);
           // reverse(any_cycle.begin(), any_cycle.end());
           
             iscycle = true;}
            
           }
          
      }
}
signed main(){
   
    cin>>n>>m;g.assign(n+1,vector<int>());vis.assign(n+1,0);
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
  if(!vis[i] && !iscycle){
      //  cout<<i;
        dfs(i,0);
    }
}
if(!iscycle){
     cout<<"IMPOSSIBLE"<<"\n";
 }
 else{
    cout<<any_cycle.size()<<'\n';
for(auto x : any_cycle){
    cout<<x<<" ";
}

    cout<<endl;
}
}