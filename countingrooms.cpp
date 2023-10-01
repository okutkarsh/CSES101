#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int dx[] = {1,0,-1,0}; 
int dy[] = {0,-1,0,1};
vector<vector<char>> g;
vector<vector<int>> vis;
using state = pair<int,int> ;
 
bool is_Valid(int x, int y){
    if(x>=0&&y>=0 &&x<n&&y<m &&g[x][y]!='#'){
        return true;
    }
    return false;
}
vector<state> nnbs(int x, int y){
    vector<state> ans; 
    for(int k = 0; k<4 ; k++){
        int xx = x + dx[k];
        int yy = y + dy[k];
        if(is_Valid(xx,yy)){
            ans.push_back({xx,yy});
        }
    }
    return ans;
}
 
void bfs(state node){
   queue<state> q;
   q.push(node);
   vis[node.first][node.second] = 1;
   
  while(!q.empty()){
      state temp = q.front();
      q.pop();
      for(auto x: nnbs(temp.first, temp.second)){
          if(!vis[x.first][x.second]){
              q.push(x);
              vis[x.first][x.second] = 1;
          }
      }
  }
}
signed main(){
    cin>>n>>m;
g.resize(n);
//cout<<g.size();
vis.assign(n,vector<int>(m,0));
//cout<<vis.size();
int count = 0;
 
 
for(int i =0; i<n;i++){
    for(int j = 0; j<m;j++){
        char temp;
        cin>>temp;
 g[i].push_back(temp);
 //cout<<"fdvg"<<" ";
    }
}
for(int i =0; i<n;i++){
    for(int j = 0; j<m;j++){
         
        if(!vis[i][j] && g[i][j]!='#'){
            count++;
          
            bfs({i,j});
        }
    }
}
 
cout<<count;
}
