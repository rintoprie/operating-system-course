/*
Example of First Come First Service (FCFS or FIFO) Scheduling in C++
https://www.geeksforgeeks.org/program-for-fcfs-cpu-scheduling-set-1/

Output:
Processes   Burst time   	Waiting time   Turn around time
   1		   3	    		   0		  		   3
   2		   5	    		   3		  		   8
   3		   8	   		   8		  		   16
Average waiting time = 3.66667
Average turn around time = 9

Explanation:
Processes: Process ID
Burst Time: Time needed to finish the process
Waiting Time: Time spent before process execution starts (Waiting Time = Turn Around Time – Burst Time)
Turn Around Time: Time Difference between completion time and arrival time (Turn Around Time = Completion Time – Arrival Time)

Timeline from simulation (arrival time for P1 = P2 = P3 = 0):
Process Execution:  P1          P2                  P3                              (Completed)
Time unit:          0---1---2---3---4---5---6---7---8---9---10--11--12--13--14--15--16
*/

#include<iostream> 
using namespace std; 
  
// Function to find the waiting time for all  
// processes 
void findWaitingTime(int processes[], int n,  
                          int bt[], int wt[]) 
{ 
    // waiting time for first process is 0 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  bt[i-1] + wt[i-1] ; 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime( int processes[], int n,  
                  int bt[], int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int  i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
  
//Function to calculate average time 
void findavgTime( int processes[], int n, int bt[]) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    //Function to find waiting time of all processes 
    findWaitingTime(processes, n, bt, wt); 
  
    //Function to find turn around time for all processes 
    findTurnAroundTime(processes, n, bt, wt, tat); 
  
    //Display processes along with all details 
    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn  
    // around time 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl; 
    } 
  
    cout << "Average waiting time = " 
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = " 
         << (float)total_tat / (float)n; 
} 
  
// Driver code 
int main() 
{ 
    //process id's 
    int processes[] = { 1, 2, 3}; 
    int n = sizeof processes / sizeof processes[0]; 
  
    //Burst time of all processes 
    int  burst_time[] = {3, 5, 8}; 
  
    findavgTime(processes, n,  burst_time); 
    return 0; 
} 
