#include<stdio.h>
int main() {
    int n; scanf("%d", &n);
    int allocation[3][n], max[3][n], available[3], need[3][n];

    for(int i = 0; i < n; i++) scanf("%d %d %d", &allocation[0][i], &allocation[1][i], &allocation[2][i]);
    for(int i = 0; i < n; i++) scanf("%d %d %d", &max[0][i], &max[1][i], &max[2][i]);
    scanf("%d %d %d", &available[0], &available[1], &available[2]);
    
    for(int i = 0; i < n; i++) {
        need[0][i] = max[0][i] - allocation[0][i];
        need[1][i] = max[1][i] - allocation[1][i];
        need[2][i] = max[2][i] - allocation[2][i];
    }

    int flag = 1, cnt = 0;

    while(flag && (cnt < 100))
    {   
        for(int i = 0; i < n; i++) {
            if(available[0] >= need[0][i] && available[1] >= need[1][i] && available[2] >= need[2][i]) {
                available[0] += allocation[0][i];
                available[1] += allocation[1][i];
                available[2] += allocation[2][i];

                need[0][i] = 1000, need[1][i] = 1000, need[2][i] = 1000;
            }
        }

        flag = 0;
        for(int i = 0; i < n; i++) if(need[0][i] != 1000) flag = 1;
        cnt++;
    }

    if(cnt == 100) printf("Unsafe\n");
    else printf("Safe\n");
}
