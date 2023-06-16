#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int memo[100][100];
int ans=0;


int LCS(string x, string y){
    //base case
    if(x.empty() || y.empty())
        return 0;
    //memo condition
    if(memo[x.size()][y.size()])
        return memo[x.size()][y.size()];

    if(x[0] == y[0]){
        ans = 1+LCS(x.substr(1), y.substr(1));
        memo[x.size()][y.size()] = ans;

    }
        
    else {
        ans = max(LCS(x.substr(1), y), LCS(x, y.substr(1)));
        memo[x.size()][y.size()] = ans;
    }
}

int main(){
    string X, Y;
    X = Y = "";
    while(true){
        cin >> X;
        if (X[0] == '#') break;
        cin >> Y;
        cout << LCS(X, Y) << endl;
    }
    return 0;
}