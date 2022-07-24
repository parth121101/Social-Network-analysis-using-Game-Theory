#include<bits/stdc++.h>

#define ld long double

using namespace std;




vector<vector<int>> distance_Matrix(vector<int>net){
    int n = net.size();
    vector<vector<int>>dm(n+1,vector<int>(n+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=i+1;j<n+1;j++){
            dm[i][j] = dm[i][net[j-1]]+1;
            dm[j][i] = dm[i][j];
        }
    }
    return dm;

}

vector<ld> calculate_Payoff(vector<vector<int>>dm,ld delta,ld alpha,vector<ld>theta){
    int n = dm.size();
    vector<ld>payoff(n,0);
    for(int i=1;i<n;i++){
        for(int j=1;j<i;j++){
            payoff[i]+=(pow(delta,dm[i][j])*theta[j]);
        }
        for(int k=i+1;k<n;k++){
            payoff[i]+=((pow(delta,dm[i][k]))*(theta[k])*(pow(alpha,k-i-1)));
        }
    }
    return payoff;

}



void Networks(vector<int>&net,int n,ld delta,ld alpha,vector<ld>theta){
    if(n==1){
        vector<vector<int>>dm;
        dm = distance_Matrix(net);
        vector<ld>payoff;
        payoff = calculate_Payoff(dm,delta,alpha,theta);

        for(auto x:net){
            cout<<x<<" ";
        }
        cout<<endl;
        for(int i=1;i<payoff.size();i++){
            cout<<setprecision(9)<<payoff[i]<<" ";
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
        
    }
    for(int i=1;i<n;i++){
        net[n-1] = i;
        Networks(net,n-1,delta,alpha,theta);
    }
    
}


int main(){
    


    int n=7;
    ld alpha = 0.9;
    ld delta = 0.9;
    vector<ld>theta = {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7};
    

    // vector<int>net(n,0);
    // Networks(net,n,delta,alpha,theta);

    vector<int>net = {0,1,2,3,4,4,4};

    vector<vector<int>>dm;
    dm = distance_Matrix(net);
    vector<ld>payoff;
    payoff = calculate_Payoff(dm,delta,alpha,theta);


    // for(auto x:dm){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    for(auto x:net){
        cout<<x <<" ";
    }
    cout<<endl;
    for(int i=1;i<payoff.size();i++){
        cout<<payoff[i]<<" ";
    }
    return 0;

}
