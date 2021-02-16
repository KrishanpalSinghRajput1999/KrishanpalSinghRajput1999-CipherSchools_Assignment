#include <bits/stdc++.h> 
#include<iostream>
using namespace std;   
bool everMeet(int x1, int x2, int v1, int v2) 
{ 
    // If speed of a person at a position before 
    // other person is smaller, then return false. 
    if (x1 < x2 && v1 <= v2) 
       return false; 
    if (x1 > x2 && v1 >=v2) 
       return false;   
    
    // Making sure that x1 is greater 
    if (x1 < x2)  
    {  
        swap(x1, x2);  
        swap(v1, v2);  
    }      
    
     // Until one person crosses other  
     while (x1 >= x2) {  
        if (x1 == x2)  
            return true; 
          
        // first person taking one 
        // jump in each iteration 
        x1 = x1 + v1;  
          
        // second person taking 
        // one jump in each iteration 
        x2 = x2 + v2;  
    } 
  
    return false;    
}  
int main() 
{ 
    int x1 = 5, v1 = 8, x2 = 4, v2 = 7; 
    if (everMeet(x1, x2, v1, v2)) 
        printf("Yes");     
    else 
        printf("No"); 
    return 0; 
} 
