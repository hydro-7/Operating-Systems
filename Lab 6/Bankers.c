#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    int alloc[n][m];
    int max[n][m];
    int available[m];
    int need[n][m];
    bool check[m];
    
    for(int i=0;i<m;i++) check[i]=false;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    
    for(int i=0;i<m;i++){
        scanf("%d",&available[i]);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    
    
    while(1){
        int find=0;
        for(int i=0;i<n;i++){
            int flag=1;
            if(!check[i]){
                for(int j=0;j<m;j++){
                    if(available[m]<need[i][j]){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag){
                check[i]=true;
                find=1;
                for(int k=0;k<m;k++){
                    available[k]+=alloc[i][k];
                }
                break;
            }
        }
        
        if(!find){
            printf("Safe\n");
            break;
        }
        
        bool all=true;
        for(int i=0;i<m;i++){
            if(!check[i]){
                all=false;
                break;
            }
        }
        if(all){
            printf("UnSafe\n");
            break;
        }
    
    }   
    return 0;
}
