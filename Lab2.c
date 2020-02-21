
//Written by: Eunsoo Jang
//Title: Lab2.c
//Date: Feb 4, 2020

//$ulimit -s 10000000
//sys.setrecursionlimit(100000000)

#include <stdio.h>
#include <time.h>


int linearSearch(int[], int, int);
int betterLinearSearch(int[], int, int);
int SentinelLinearSearch(int[], int, int);
int RecursiveLinearSearch(int[], int, int, int);
//void printHelper(int[], int, int, char[])

int main(void){

  int x = -10;


  printf("linearSearch");
  printf("\n");
  for (int i =1000000; i<=100000000; i+=1000000){
    int A[i];
    for(int j =0; j<i; j++){
      A[j] = j;
    }
    long start = clock();
    linearSearch(A, i, x);
    double duration = ((clock() - (float)start) / CLOCKS_PER_SEC);
    printf("%f", duration);
    printf("\n");
  }

  printf("betterLinearSearch");
  printf("\n");
  for (int i =1000000; i<=100000000; i+=1000000){
    int A[i];
    for(int j =0; j<i; j++){
      A[j] = j;
    }
    long start = clock();
    betterLinearSearch(A, i, x);
    double duration = ((clock() - (float)start) / CLOCKS_PER_SEC);
    printf("%f", duration);
    printf("\n");
  }

  printf("SentinelLinearSearch");
  printf("\n");
  for (int i =1000000; i<=100000000; i+=1000000){
    int A[i];
    for(int j =0; j<i; j++){
      A[j] = j;
    }
    long start = clock();
    SentinelLinearSearch(A, i, x);
    double duration = ((clock() - (float)start) / CLOCKS_PER_SEC);
    printf("%f", duration);
    printf("\n");
  }

  printf("RecursiveLinearSearch");
  printf("\n");
  for (int i =1000000; i<=100000000; i+=1000000){
    int A[i];
    for(int j =0; j<i; j++){
      A[j] = j;
    }
    long start = clock();
    RecursiveLinearSearch(A, i, 0, x);
    double duration = ((clock() - (float)start) / CLOCKS_PER_SEC);
    printf("%f", duration);
    printf("\n");
  }

  /*
  printHelper(A, n, x, "linearSearch");
  printHelper(A, n, x, "betterLinearSearch");
  printHelper(A, n, x, "SentinelLinearSearch");
  printHelper(A, n, x, "RecursiveLinearSearch");
  */
  return 0;
}

int linearSearch(int A[], int n, int x){
  int answer = -1;
  for(int i =0; i<n; i++){
    if(A[i]==x){
      answer = i;
    }
  }
  return answer;
}

int betterLinearSearch(int A[], int n, int x){
  for(int i =0; i<n; i++){
    if(A[i]==x){
      return i;
    }
  }
  return -1;
}

int SentinelLinearSearch(int A[], int n, int x){
  int last = A[n-1];
  A[n-1] = x;
  int i =0;
  while(A[i]!= x){
    i=i+1;
  }
  A[n-1] = last;
  if((i<n-1) ||(A[n-1]==x)){
    return i;
  }
  else{
    return -1;
  }
}

int RecursiveLinearSearch(int A[], int n, int i, int x){
  if (i>=n){
    return -1;
  }
  if(A[i]==x){
    return i;
  }
  return RecursiveLinearSearch(A,n,i+1,x);

}
/*
void printHelper(int A[], int n, int x, char nameofSearch[]){
  int result = -1;
  if(nameofSearch == "RecursiveLinearSearch"){
    result = RecursiveLinearSearch(A, n, 0, x);
  }
  else if(nameofSearch == "linearSearch"){
    result = linearSearch(A, n, x);
  }
  else if(nameofSearch == "betterLinearSearch"){
    result = betterLinearSearch(A, n, x);
  }
  else if(nameofSearch == "SentinelLinearSearch"){
    result = SentinelLinearSearch(A, n, x);
  }
  System.out.println("Searching array of size: %d/n", n);
  System.out.println("Algorithm: %s/n", nameofSearch);
  System.out.println("Looking for element: %d/n", x);
  System.out.println("Result: %d/n", result);

}*/
