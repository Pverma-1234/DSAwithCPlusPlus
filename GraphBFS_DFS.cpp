#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int v;
    list<int>* l;
public:
    Graph(int v){
        this->v=v;
        l=new list<int>[v];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void bfs(){
        queue<int> Q;
        vector<bool> vis(v,false);
        Q.push(0);
        vis[0]=true;
        
        while(Q.size()>0){
            int u = Q.front();
            Q.pop();
            cout<<u<<" ";
            for(int v:l[u]){
                if(!vis[v]){
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
        cout<<endl;
    }
    void dfsHelper(int u,vector<bool>&vis){
        cout<<u<<" ";
        vis[u]=true;
        
        for(int v:l[u]){
            if(!vis[v]){
                
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){
        int src = 0;
        vector<bool> vis(v,false);
        dfsHelper(src,vis);
        cout<<endl;
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    cout<<"BFS: ";
    g.bfs();
    cout<<"DFS: ";
    g.dfs();
}


