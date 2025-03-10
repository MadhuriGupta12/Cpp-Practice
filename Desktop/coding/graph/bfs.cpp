#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Graph {
    int v;
    list<int>* l; 
    public:
    Graph(int v){
        this->v=v;
        l=new list<int>[v];
    }
    void addedge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    // void print(){
    //     for(int u=0;u<v;u++){
    //         list<int>neightbors=l[u];
    //         cout<<u<<" : ";
    //         for(int v: neightbors){
    //             cout<<v<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    void bfs(){
        queue<int> q;
        vector<bool> vis(v,false);
        q.push(0);
        vis[0]=true;
        while (q.size()>0){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            list<int>neightbors=l[u];
            for(int v:neightbors){
                if(! vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
};
int main(){
    Graph graph(5);
    graph.addedge(0,1);
    graph.addedge(1,2);
    graph.addedge(1,3);
    graph.addedge(2,3);
    graph.addedge(2,4);
    graph.bfs();
    return 0;
}