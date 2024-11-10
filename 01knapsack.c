#include<stdio.h>

int max(int a, int b){
 return (a>b)? a:b;
 }
 
int knapsack(int W, int wt[], int val[], int n){
 int i, w;
 int dp[n+1][w+1];
 for ( i=0; i<=n; i++) {
  for ( w=0; w<= W; w++) {
   if ( i==0 || w==0)
    dp[i][w] = 0;
  else if (wt[i-1] <= w)
    dp[i][w] = max(val[i-1] +dp[i-1][w-wt[i-1]], dp[i-1][w]);
  else 
    dp[i][w] = dp[i-1][w];
   }
  }
  return dp[n][W];
 }
 
 int main() {
  int W; 
  int n;
  
  printf("enter the maximum weight of the knapsack: ");
  scanf("%d", &W);
  
  printf("enter the number of items: ");
  scanf("%d" , &n);
  
  int wt[n], val[n];
  
  printf("enter the weights of the items:\n");
  for( int i=0; i<n; i++){
   printf("weight of the item %d: ", i+1);
   scanf("%d" , &wt[i]);
  }
  
  printf("enter the values of the items:\n");
  for ( int i=0; i<n; i++) {
   printf("value of the item %d: ", i+1);
   scanf("%d", &val[i]);
  }
  
  printf("maximum value that can be obtained: %d\n" , knapsack(W, wt, val, n));
  return 0;
  } 
