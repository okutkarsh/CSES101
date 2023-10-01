#include<bits/stdc++.h>
using namespace std;
using state = pair<int,int> ;
    vector<char> pp;
#define int long long 
int n,m;int dx[] = {1,0,-1,0}; int dy[] = {0,-1,0,1};
char path[] = {'D', 'L', 'U' , 'R'};
map<state, state> mp;
state start; 
state en;

char dir(state s1 , state s2){
    char ans;
    for(int i = 0 ; i<4; i++){
        if(s1.first + dx[i]== s2.first  && s1.second+ dy[i]==s2.second){
          //  cout<<"i"<<i;
            ans = path[i];
        }
    }
    return ans;
}
vector<vector<char>> g;
vector<vector<int>> vis;

bool is_Valid(int x, int y){
    if(x>=0&&y>=0 &&x<n&&y<m &&g[x][y]!='#'){
        return true; }
    return false;}
vector<state> nnbs(int x, int y){
    vector<state> ans; 
    for(int k = 0; k<4 ; k++){
        int xx = x + dx[k];
        int yy = y + dy[k];
        if(is_Valid(xx,yy)){
            ans.push_back({xx,yy});
        } }return ans;}
void bfs(state node){
   queue<state> q;q.push(node);
   vis[node.first][node.second] = 1;
  while(!q.empty()){
      state temp = q.front();q.pop();
      for(auto x: nnbs(temp.first, temp.second)){
          if(!vis[x.first][x.second]){
              q.push(x);
              mp[x]= temp;
              vis[x.first][x.second] = 1;}}}}
signed main(){
    cin>>n>>m;g.resize(n);vis.assign(n,vector<int>(m,0));int count = 0;
 for(int i =0; i<n;i++){
    for(int j = 0; j<m;j++){
        char temp;cin>>temp;g[i].push_back(temp);
        if(temp=='A'){
            start = {i,j};
        }
        else if(temp=='B'){
            en = {i,j};
        }
    }}

          
            bfs(start);
            if(vis[en.first][en.second]){
                cout<<"YES\n";
    state curr = en;
    pp.clear();
    //cout<<dir(mp[en],en);
   // cout<<mp[en].first<<" "<<mp[en].second;
   // cout<<en.first<<" "<<en.second;
    while(curr!=start){
        char tt = dir(mp[curr], curr);
        pp.push_back(tt);
        curr = mp[curr];
    }
reverse(pp.begin(), pp.end());
    cout<<pp.size()<<'\n';
    for(auto x : pp){
        cout<<x;
    }
    cout<<'\n';
}
else{
    cout<<"NO"<<"\n";
}

}