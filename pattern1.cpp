#include<iostream>
using namespace std;
int main(){
int n;
int count=1;
cin>>n;
int i=1;
while(i<=n){
    int j=1;
    while(j<=n){
        cout<<count<<" ";
        count=count+1;
        j=j+1;
    }
    cout<<endl;
    i=i+1;
}
}
