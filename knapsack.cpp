#include <iostream>
using namespace std;

void knapsack(int P[],int wt[],int n,int m){
        int M[n][m];
        for (int i =0;i<=n;i++){
            for (int w = 0;w<=m;w++){
                if(i==0||w==0){
                    M[i][w]=0;
                }
                else if(wt[i]<=w){
                    M[i][w] = max(M[i-1][w],P[i]+M[i-1][w-wt[i]]);
                }
                else{
                    M[i][w] = M[i-1][w];
                }
            }
        }
    cout<<"The maximum profit is "<<M[n][m];
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
    knapsack(P,wt,n,m);
    return 0;
}
