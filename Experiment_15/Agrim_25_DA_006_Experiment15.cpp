// N - Queens

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int n;
vector<int> pos;
bool safe(int r,int c){
    for(int i=0;i<r;i++)
        if(pos[i]==c||abs(pos[i]-c)==abs(i-r)) return false;
    return true;
}
bool solve(int r){
    if(r==n) return true;
    for(int c=0;c<n;c++){
        if(safe(r,c)){
            pos[r]=c;
            if(solve(r+1)) return true;
        }
    }
    return false;
}
int main(){
    cin>>n;
    pos.resize(n);
    if(solve(0)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<(pos[i]==j?"Q ":" .");
            cout<<"\n";
        }
    }else cout<<"No solution exists\n";
    return 0;
}