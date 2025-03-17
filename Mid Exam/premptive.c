#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int max(int a, int b){
    if(a > b) return a;
    return b;
}

int min(int a, int b){
    if(a > b) return b;
    return a;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int at[n], bt[n], priority[n];
    
    for(int i = 0; i < n; i++) scanf("%d", &at[i]);
    for(int i = 0; i < n; i++) scanf("%d", &bt[i]);
    for(int i = 0; i < n; i++) scanf("%d", &priority[i]);
    
    // -------------------------- SRTF ---------------------------- // 
    
    int at1[n], bt1[n], tt1[n], wt1[n];
    for(int i = 0; i < n; i++) {
        at1[i] = at[i]; 
        bt1[i] = bt[i];
    }
    
    int time1 = 0, proc = 0;
    
    while(1)
    {
        time1++;
        
        // reducing from curr proc
        bt1[proc]--;
        
        if(bt1[proc] == 0) {
            tt1[proc] = time1 - at[proc];
            
            for(int i = 0; i < n; i++) {
                if(bt1[i] != 0 && time1 >= at1[i]) {
                    proc = i;
                    break;
                }
            }
        }
        
        // finding next proc
        for(int i = 0; i < n; i++)
        {
            if((time1 >= at1[i]) && (bt1[proc] > bt1[i]) && (bt1[i] != 0)){
                proc = i;
            }
        }
        
        // printf("%d ", bt1[0]);
        
        if(time1 == 5000) break;
    }
    
    // printf("\n");
    for(int i = 0; i < n; i++) wt1[i] = (tt1[i] - bt[i]); 
    
    float sum = 0;
    for(int i = 0; i < n; i++) sum += wt1[i];
    
    float ans = sum/n;
    
    printf("%.1f ", ans);
    
    
    // -------------------------- LRTF ---------------------------- // 
    
    int tt2[n], wt2[n];
    for(int i = 0; i < n; i++) {
        at1[i] = at[i]; 
        bt1[i] = bt[i];
    }
    
    time1 = 0, proc = 0;
    
    while(1)
    {
        time1++;
        
        // reducing from curr proc
        bt1[proc]--;
        
        if(bt1[proc] == 0) {
            tt2[proc] = time1 - at[proc];
            
            for(int i = 0; i < n; i++) {
                if(bt1[i] != 0 && time1 >= at1[i]) {
                    proc = i;
                    break;
                }
            }
        }
        
        // finding next proc
        for(int i = 0; i < n; i++)
        {
            if((time1 >= at1[i]) && (bt1[proc] < bt1[i]) && (bt1[i] != 0)){
                proc = i;
            }
        }
        
        // printf("%d ", bt1[0]);
        
        if(time1 == 5000) break;
    }
    
    for(int i = 0; i < n; i++) wt2[i] = (tt2[i] - bt[i]); 
    
    sum = 0;
    for(int i = 0; i < n; i++) sum += wt2[i];
    
    ans = sum/n;
    
    printf("%.f ", ans);
    
    
    // -------------------------- PRIORITY ---------------------------- //
    
    int tt3[n], wt3[n];
    
    for(int i = 0; i < n ; i++){
        at1[i] = at[i];
        bt1[i] = bt[i];
    }
    
    time1 = 0, proc = 0;
    
    while(1)
    {
        time1++;
        
        bt1[proc]--;
        
        if(bt1[proc] == 0)
        {
            tt3[proc] = time1 - at[proc];
            for(int i = 0; i < n; i++) {
                if(bt1[i] != 0 && time1 >= at1[i]) {
                    proc = i;
                    break;
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if((time1 >= at1[i]) && (priority[i] < priority[proc]) && (bt1[i] != 0)){
                proc = i;
            }
        }
        
        if(time1 == 5000) break;
    }
    
    for(int i = 0; i < n; i++) wt3[i] = (tt3[i] - bt[i]); 
    
    sum = 0;
    for(int i = 0; i < n; i++) sum += wt3[i];
    
    ans = sum/n;
    
    printf("%.1f ", ans);
    
    // -------------------------- Round Robin ---------------------------- // 
    
    
    int tt4[n], wt4[n];
    
    for(int i = 0; i < n ; i++){
        at1[i] = at[i];
        bt1[i] = bt[i];
    }
    
    time1 = 0, proc = 0;
    int q = 0;
    
    int qu[1000];
    
    for(int i = 0; i < 1000 ; i++) qu[i] = (i % 5);
    int ptr = 0;
    
    while(1)
    {
        if(time1 == 5000) break;
        
        if(q != 3)
        {
            q++;
            time1++;
            bt1[proc]--;
            
            if(bt1[proc] == 0)
            {
                q = 3;
                tt3[proc] = time1 - at[proc];
            }
        }
        else
        {
           q = 0;
           
           bool flag = true;
           for(int i = 0; i < n ; i++){
               if(bt1[i] != 0)
               {
                   flag = false;
                   break;
               }
           }
           
           if(flag == true) time1 = 5000;
           else {
               while(1)
               {
                   proc = qu[++ptr];
                   if(bt1[proc] != 0) break;
               }
           }
        }
    }
    
    for(int i = 0; i < n; i++) wt3[i] = (tt3[i] - bt[i]); 
    
    sum = 0;
    for(int i = 0; i < n; i++) sum += wt3[i];
    
    ans = sum/n;
    
    printf("%.1f ", ans);
    
}