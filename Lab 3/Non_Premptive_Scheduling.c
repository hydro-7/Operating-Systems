#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    if(a < b) return a;
    return b;
}

int max(int a, int b)
{
    if(a > b) return a;
    return b;
}

float maxf(float a, float b)
{
    if(a > b) return a;
    return b;
}

int main()
{
    int n; // num of proc
    scanf("%d", &n);
    
    int arrival[n];
    int burst[n];
    
    for(int i = 0; i < n; i++) scanf("%d", &arrival[i]);
    for(int i = 0; i < n; i++) scanf("%d", &burst[i]);
    
    // inputs are already sorted by arrival time
    
    // --------------------------------------------------------------------------------------------------------------------- //
    
    int fcfstt[n];
    int temp[n];
    int currtime = burst[0];
    
    temp[0] = burst[0];
    fcfstt[0] = burst[0];
    
    for(int i = 1; i < n; i++)
    {
        temp[i] = max(arrival[i], currtime) + burst[i];
        currtime = temp[i];
    }
    
    for(int i = 1; i < n; i++) 
    {
        fcfstt[i] = temp[i] - arrival[i];
    }
    
    int fcfswt[n];
    
    for(int i = 0; i < n ; i++) fcfswt[i] = fcfstt[i] - burst[i];
    
    
    float fwt = 0;
    
    for(int i = 0; i < n; i++) fwt += (float)fcfswt[i];
    
    currtime = 0;
    
    printf("%.2f ", fwt/n); // fcfs output
    
    
    // --------------------------------------------------------------------------------------------------------------------- //    
    
    // shortest job first
    
    int sjftt[n], sjfwt[n], temp1[n], awaiting_processes[n];
    
    int sjfarrival[n];
    for(int i = 0; i < n; i++) sjfarrival[i] = arrival[i];
    
    int await_ite = 0;
    
    sjftt[0] = burst[0];
    temp1[0] = burst[0];
    currtime = temp1[0];
    sjfarrival[0] = 1000;
    
    for(int i = 1; i < n; i++)
    {
        await_ite = 0;
        for(int j = 0; j < n; j++)
        {
            if(sjfarrival[j] < currtime) awaiting_processes[await_ite++] = burst[j];
        }
                
        // get min of awaiting proc
        
        int mini = 1000;
        
        for(int j = 0; j < await_ite; j++) mini = min(mini, awaiting_processes[j]);
        
        int tempidx = 0;
        
        for(int j = 0; j < n; j++) {
            if(burst[j] == mini && sjfarrival[j] != 1000)
            {
                sjfarrival[j] = 1000;
                tempidx = j;
                break;
            }
        }
        
        
        
        if(mini == 1000) // no proc found next
        {
            sjfarrival[i] = 1000;
            temp1[i] = max(arrival[i], currtime) + burst[i];
            currtime = temp1[i];
        }
        else // find the mini burst ka index
        {         
            temp1[i] = currtime + mini;
            currtime = temp1[i];
        }
        
    }
    
    
    for(int i = 1; i < n; i++)
    {
        sjftt[i] = temp1[i] - arrival[i];
    }
    
    for(int i = 0; i < n ; i++) sjfwt[i] = sjftt[i] - burst[i];
    
    
    fwt = 0;
    
    for(int i = 0; i < n; i++) fwt += (float)sjfwt[i];
    
    currtime = 0;
    
    printf("%.2f ", fwt/n); // sjf output
    
    
    // --------------------------------------------------------------------------------------------------------------------- //    
    
    // longest job first
    
    int ljftt[n], ljfwt[n], temp2[n], awaiting_proc[n];
    int ljfarrival[n];
    
    for(int i = 0; i < n; i++) ljfarrival[i] = arrival[i];
    
    await_ite = 0;
    
    ljftt[0] = burst[0];
    temp2[0] = burst[0];
    currtime = temp2[0];
    ljfarrival[0] = 1000;
    
    
    for(int i = 1; i < n; i++)
    {
        await_ite = 0;
        for(int j = 0; j < n; j++)
        {
            if(ljfarrival[j] < currtime && ljfarrival[j] != -1) awaiting_proc[await_ite++] = burst[j];
        }
        
        int maxi = -1;
        for(int j = 0; j < await_ite; j++) maxi = max(maxi, awaiting_proc[j]);
        
        int tempidx = 0;
        
        for(int j = 0; j < n; j++) {
            if(burst[j] == maxi && ljfarrival[j] != -1)
            {
                ljfarrival[j] = -1;
                tempidx = j;
                break;
            }
        }
        
        if(maxi == -1) // no proc found next
        {            
            ljfarrival[i] = -1;
            temp2[i] = max(arrival[i], currtime) + burst[i];
            currtime = temp2[i];
        }
        else // find the mini burst ka index
        {
            temp2[i] = currtime + maxi;
            currtime = temp2[i];
        }
    }
    
    for(int i = 1; i < n; i++)
    {
        ljftt[i] = temp2[i] - arrival[i];
    }
    
    for(int i = 0; i < n ; i++) ljfwt[i] = ljftt[i] - burst[i];
    
    
    fwt = 0;
    
    for(int i = 0; i < n; i++) fwt += (float)ljfwt[i];
    
    currtime = 0;
    
    printf("%.2f ", fwt/n); // ljf output
    
    
    // --------------------------------------------------------------------------------------------------------------------- //    
    
    int hrrntt[n], hrrnwt[n], temp3[n];
    int hrrnarrival[n];
    
    for(int i = 0; i < n; i++) hrrnarrival[i] = arrival[i];
    
    hrrntt[0] = burst[0];
    temp3[0] = burst[0];
    currtime = burst[0];
    hrrnarrival[0] = -1;
    
    for(int i = 1; i < n; i++)
    {
        float maxres = -1;
        int idxx = 0;
        for(int j = 0; j < n; j++)
        {
            if(hrrnarrival[j] <= currtime && hrrnarrival[j] != -1)
            {
                float res = (currtime - hrrnarrival[j]);
                res /= burst[j];
                
                if(res > maxres) {
                    idxx = j;
                    maxres = res;
                }
            }
        }
        
        if(maxres == -1)
        {
            hrrnarrival[i] = -1;
            temp3[i] = max(arrival[i], currtime) + burst[i];
            currtime = temp3[i];
        }
        else
        {
            hrrnarrival[idxx] = -1;
            temp3[i] = currtime + burst[idxx];
            currtime = temp3[i];
        }
    }
    
    for(int i = 1; i < n; i++)
    {
        hrrntt[i] = temp3[i] - arrival[i];
    }
    
    for(int i = 0; i < n ; i++) hrrnwt[i] = hrrntt[i] - burst[i];
    
    fwt = 0;
    
    for(int i = 0; i < n; i++) fwt += (float)hrrnwt[i];
    
    currtime = 0;
    
    printf("%.2f ", fwt/n); // hrrn output
    

    
    return 0;
}