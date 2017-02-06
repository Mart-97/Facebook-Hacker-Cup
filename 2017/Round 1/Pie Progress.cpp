#include <bits/stdc++.h>
#define MAXN 310
using namespace std;
int grid[MAXN][MAXN];
int pows[MAXN];
typedef long long ll;
int main(){
    for(int i = 1; i<=300; i++)
        pows[i] = i*i;
    int n,m,tc;
    scanf("%d",&tc);
    for(int t = 1; t<=tc; t++){
        scanf("%d%d",&n,&m);
        int minimo;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                scanf("%d",&grid[i][j]);
            }
        }
        for(int i = 1; i<=n; i++){
            grid[i][0] = 0;
            sort(grid[i] + 1,grid[i] + m + 1);
        }
        ll ans = 0,ant = ans;;
        for(int i = 1; i<=n; i++){
            int row;
            minimo = INT_MAX;
            for(int j =  1; j<=i; j++){
                int items = grid[j][0];
                int actual = ant + grid[j][items + 1] + pows[items + 1] - pows[items];
                if(minimo > actual && items + 1<=m){
                    minimo = actual;
                    row = j;
                }
            }
            ans = minimo;
            ant = ans;
            grid[row][0]++;
        }
        printf("Case #%d: %lld\n",t,ans);
    }
    return 0;
}
