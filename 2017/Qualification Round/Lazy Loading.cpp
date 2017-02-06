#include <bits/stdc++.h>
using namespace std;
int w[102];
int main(){
   int tc,n,items,test = 0;
   scanf("%d",&tc);
   while(tc--){
    scanf("%d",&items);
    for(int i = 1; i<=items; i++){
        scanf("%d",w + i);
    }
    sort(w + 1, w + items + 1);
    int total_izq = items - 1,need,ans = 0;
    for(int i =  items; i>=1; i--){
        if(w[i]>=50){
            ans++;
            total_izq--;
        } else {
            50 % w[i] == 0 ? need = 50 / w[i]: need = 50 / w[i] + 1;
            if(need - 1 <= total_izq) {
                total_izq -= (need - 1);
                ans++;
            } else break;
            total_izq--;
        }
    }
    printf("Case #%d: %d\n",++test,ans);
   }
return 0;
}
