#include <stdio.h> 
 
int n; 
int G[10][10]; 
int x[10]; 
int found = 0; 
 
void NextVertex(int k) { 
   while(1) { 
       x[k] = (x[k] + 1) % (n + 1); 
       if(x[k] == 0) 
           return; 
          
       if (G[x[k - 1]][x[k]] != 0) { 
           int j; 
           for (j = 1; j < k; j++) 
               if (x[j] == x[k]) 
                   break; 
                  
       if(j == k) { 
           if ((k < n) || (k == n && G[x[n]][x[1]] != 0)) 
               return; 
           } 
       } 
   } 
} 
 
void Hamiltonian(int k) { 
   while(1) { 
       NextVertex(k); 

      
       if(x[k] == 0) 
           return; 
      
       if (k == n) { 
           found = 1; 
           printf("\nHamiltonian Cycle: "); 
           for (int i = 1; i <= n; i++) 
               printf("%d ", x[i]); 
           printf("%d", x[1]); 
       } else { 
           Hamiltonian(k + 1); 
       } 
   } 
} 
 
int main() { 
   printf("Enter the Number of Vertices: "); 
   scanf("%d", &n); 
  
   printf("Enter the Adjacency Matrix: "); 
   for(int i = 1; i <= n; i++) { 
       for(int j = 1; j <= n; j++) { 
           scanf("%d", &G[i][j]); 
       } 
   } 
  
   for(int i = 1; i <= n; i++) 
       x[i] = 0; 
  
   x[1] = 1; 
   Hamiltonian(2); 
  
   if(!found) 
       printf("\nNo Hamiltonian Cycle exists.\n"); 
  
   return 0; 
} 
