#include <iostream>
using namespace std;

void knapsack(int P[],int wt[],int n,int m){
        int k[n][m];
        for (int i =0;i<=n;i++){
            for (int w = 0;w<=m;w++){
                if(i==0||w==0){
                    k[i][w]=0;
                }
                else if(wt[i]<=w){
                    k[i][w]=max(P[i]+k[i-1][w-wt[i]],k[i-1][w]); 
                }
                else{
                    k[i][w] = k[i-1][w];
                }
            }
        }
    cout<<"The maximum profit is "<<k[n][m];
}

int main(){
    cout<<"Enter number of items"<<endl;
    int n;
    cin>>n;
    cout<<"Enter value of items"<<endl;
    int P[n];
    P[0]=0;
    for(int i=1;i<=n;i++){
        cin>>P[i];
    }
    cout<<"Enter weight of items"<<endl;
    int wt[n];
    wt[0]=0;
    for(int i=1;i<=n;i++){
        cin>>wt[i];
    }
    cout<<"Enter capacity of knapsack"<<endl;
    int m;
    cin>>m;
    // int P[5] = {0,25,10,5,10};
    // int wt[5] = {0,5,2,1,3};
    knapsack(P,wt,n,m);
    return 0;
}
