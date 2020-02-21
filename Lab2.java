
//Written by: Eunsoo Jang
//Title: Lab2.java
//Date: Feb 4, 2020


import java.io.*;
import java.util.*;

//stack namespace
//java -Xss10000m Lab2


public class Lab2
{
  public static void main(String[] args){
    Random rand = new Random();
    int x = -10;
    int n =0;

    System.out.println("linearSearch");
    for (int i =1000000; i<=100000000; i+=1000000){
      int[] A = new int[i];
      n = A.length;
      for(int j =0; j<i; j++){
        A[j] = j;
      }
      long start = System.nanoTime();
      linearSearch(A, n, x);
      double duration = (System.nanoTime() - start) / 1000000000.0;
      System.out.println(duration);
    }

    System.out.println("betterLinearSearch");
    for (int i =1000000; i<=100000000; i+=1000000){
      int[] A = new int[i];
      n = A.length;
      for(int j =0; j<i; j++){
        A[j] = j;
      }
      long start = System.nanoTime();
      betterLinearSearch(A, n, x);
      double duration = (System.nanoTime() - start) / 1000000000.0;
      System.out.println(duration);
    }

    System.out.println("SentinelLinearSearch");
    for (int i =1000000; i<=100000000; i+=1000000){
      int[] A = new int[i];
      n = A.length;
      for(int j =0; j<i; j++){
        A[j] = j;
      }
      long start = System.nanoTime();
      SentinelLinearSearch(A, n, x);
      double duration = (System.nanoTime() - start) / 1000000000.0;
      System.out.println(duration);
    }

    System.out.println("RecursiveLinearSearch");
    for (int i =1000000; i<=100000000; i+=1000000){
      int[] A = new int[i];
      n = A.length;
      for(int j =0; j<i; j++){
        A[j] = j;
      }
      long start = System.nanoTime();
      RecursiveLinearSearch(A, n, 0, x);
      double duration = (System.nanoTime() - start) / 1000000000.0;
      System.out.println(duration);
    }

/*
    printHelper(A, n, x, "linearSearch");
    printHelper(A, n, x, "betterLinearSearch");
    printHelper(A, n, x, "SentinelLinearSearch");
    printHelper(A, n, x, "RecursiveLinearSearch");
*/

  }

  public static int linearSearch(int[] A, int n, int x){
    int answer = -1;
    for(int i =0; i<n; i++){
      if(A[i]==x){
        answer = i;
      }
    }
    return answer;
  }

  public static int betterLinearSearch(int[] A, int n, int x){
    for(int i =0; i<n; i++){
      if(A[i]==x){
        return i;
      }
    }
    return -1;
  }

  public static int SentinelLinearSearch(int[] A, int n, int x){
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

  public static int RecursiveLinearSearch(int[] A, int n, int i, int x){
      if (i>=n){
        return -1;
      }
      if(A[i]==x){
        return i;
      }
      return RecursiveLinearSearch(A,n,i+1,x);

  }

  public static void printHelper(int[]A, int n, int x, String nameofSearch){
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
    System.out.println("Searching array of size: " + n);
    System.out.println("Algorithm: " + nameofSearch);
    System.out.println("Looking for element: " + x);
    System.out.println("Result: " + result);
  }

}
