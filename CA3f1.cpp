#include <iostream>
using namespace std;
//swapping two numbers
void swapbt(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSortbt(int bt[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (bt[j] < bt[j+1]) 
              swapbt(&bt[j], &bt[j+1]); 
} 
  
/* Function to print an array */
void printArraybt(int bt[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        {
		cout<<bt[i]<<endl; 
	}
    }
  
  void swapat(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSortat(int at[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (at[j] < at[j+1]) 
              swapat(&at[j], &at[j+1]); 
} 
  
//Function to print an array 
void printArrayat(int at[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        {
		cout<<at[i]<<endl; 
	}
    } 
void WaitingTime(int bt[], int n, int wt[]) 
{ 
    wt[0] = 0;  
    for (int i = 1; i < n ; i++ ) 
        wt[i] = wt[i] + bt[i-1] ; 
} 
  
void TurnAroundTime(int bt[], int n, int wt[], int tat[]) 
{ 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 

//Avg Time
void findavgTime(int bt[], int at[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
    //Waiting time
    WaitingTime(bt,n,wt); 
    //Turn around time
    TurnAroundTime(bt,n,wt,tat); 
  
    // Display processes along with all details 
    cout <<"\nArrival Time"<<" Burst time "
         << " Waiting time " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn around time 
    for (int i = 0; i < n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << at[i] << "\t\t"
             << bt[i] << "\t " << wt[i] 
             << "\t\t " << tat[i] <<endl; 
    } 
  
    cout << "Average waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
} 




int main()
{
	int n;
	cout<<"Enter the Total number of processes you want to run:-";
	cin>>n;
	
	int at[20],bt[20],p[20],p1[20],wt[20],tat[20];
	cout<<"Enter arrival time\n";
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<":-";
        cin>>at[i];
        //p[i]=i+1;
	}
	for(int i=0;i<n;i++)
	{
		bt[i]=2*at[i];
	}
     //sorting burst time in descending order using bubble sort
    bubbleSortbt(bt, n); 
    bubbleSortat(at, n); 
    printf("Order of execution according to burst time:-\n"); 
    printArraybt(bt, n); 
    printArrayat(at, n);
    findavgTime(bt ,at ,n); 
}
