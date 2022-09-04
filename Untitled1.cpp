// solution for Traffic congestion problem
#include <iostream>
using namespace std;
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
int passengers [3];
int j = 0;

// Prints the items which are put in a knapsack of capacity W
void knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
 
    // stores the result of Knapsack
    int res = K[n][W];
    passengers [j] = res;
    j++;
   
   
}
 
 
// Driver code
int main()
{
    int val[] = {6,20,5,7,130,83,60,17,70};
    int wt[] =  {100,200,80,1000,1500,800,500,200,850};
    string HighWay;
    int numberOfPassengers, OptimalPath;
    int Portmore,Mandela,ThreeMile;
    //int W = 15;
    int n = sizeof(val) / sizeof(val[0]);
    int Portmorecapacity = 4700;
    int Mandelacapacity = 5000;
    int ThreeMilecapacity = 4600;
     
    knapSack(Portmorecapacity, wt, val, n);
    knapSack(Mandelacapacity, wt, val, n);
    knapSack(ThreeMilecapacity, wt, val, n);
   
    cout << endl;
  
    
	if (passengers[0] > passengers[1])
	{
		numberOfPassengers = passengers[0];
		HighWay = "Portmore";
	}
	else
	{
		numberOfPassengers = passengers[1];
		HighWay = "Mandela";
	}

	if (numberOfPassengers < passengers[2])
	{
		numberOfPassengers = passengers[2];
		HighWay = "ThreeMile";
	}

	cout << "The optimal path using the Knapsack method is " << HighWay  << " High Way" << endl;
	cout << "The maximum number of passengers that can be transported to and from Kingston is " << numberOfPassengers << endl;
     
    return 0;
}
 



