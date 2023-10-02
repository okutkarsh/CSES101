#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<pair<int,int>>> g;
vector<int> vis;
vector<int> dis;
int n,m;
using ii = pair<int,int>;
void dijkstra (int source){
    //code will be very similar to bfs except with some differences
    //there may be test cases so you need to clear them
    for(int i = 1; i<=n ; i++){
        vis[i] = 0; 
        dis[i] = 1e18;
        
     }
     dis[source] = 0;
    // vis[source] = 1;
     priority_queue<pair<int,int>>pq;
     
     pq.push(make_pair(0, source));
     while(!pq.empty()){
         ii fs = pq.top();
         pq.pop();
         if(vis[fs.second]){
             continue;}
             vis[fs.second] = 1;
         for(auto v: g[fs.second]){
             int neigh = v.first;
             int wt= v.second;
             if(dis[neigh]>wt + dis[fs.second]){
                 dis[neigh] = wt + dis[fs.second];
                 pq.push(make_pair( -dis[neigh],neigh));
             }
         }
     }
}

signed main(){
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
dis.assign(n+1,0);
    vis.assign(n+1,0);
    for(int i = 0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
      //  g[b].push_back(make_pair(b,c));
    }
    
    
   dijkstra(1);
    for(int i = 1; i<=n; i++){
        cout<<dis[i]<<" ";
    }
}
