// Agrim Chaturvedi 25/DA/006

// Bellman-Ford Algorithm

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge{int u,v,w;};
int main(){
    int n,m;
    cin>>n>>m;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++) cin>>edges[i].u>>edges[i].v>>edges[i].w;
    int s;
    cin>>s;
    vector<int> dist(n,INT_MAX);
    dist[s]=0;
    for(int i=1;i<n;i++){
        bool updated=false;
        for(auto e:edges){
            if(dist[e.u]!=INT_MAX&&dist[e.u]+e.w<dist[e.v]){
                dist[e.v]=dist[e.u]+e.w;
                updated=true;
            }
        }
        if(!updated) break;
    }
    for(auto e:edges){
        if(dist[e.u]!=INT_MAX&&dist[e.u]+e.w<dist[e.v]){
            cout<<"Negative weight cycle detected\n";
            return 0;
        }
    }
    cout<<"Vertex\tDistance\n";
    for(int i=0;i<n;i++){
        cout<<i<<"\t";
        if(dist[i]==INT_MAX) cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
    cout<<"No negative weight cycle detected\n";
    return 0;
}