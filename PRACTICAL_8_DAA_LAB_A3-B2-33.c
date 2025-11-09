#include <stdio.h> 
#include <stdbool.h> 
 
#define MAX 20  
 
int graph[MAX][MAX]; 
int color[MAX]; 
int V;  
int m;  
 
bool isSafe(int v, int c) { 
   for (int i = 0; i < V; i++) { 
       if (graph[v][i] && color[i] == c) 
           return false; 
   } 

   return true; 
} 
 
bool graphColoringUtil(int v) { 
   if (v == V) 
       return true; 
 
   for (int c = 1; c <= m; c++) { 
       if (isSafe(v, c)) { 
           color[v] = c; 
 
           if (graphColoringUtil(v + 1)) 
               return true; 
 
           color[v] = 0; 
       } 
   } 
   return false; 
} 
 
bool graphColoring() { 
   for (int i = 0; i < V; i++) 
       color[i] = 0; 
 
   if (!graphColoringUtil(0)) { 

       printf("\nSolution does Not Exist.\n"); 
       return false; 
   } 
 
   printf("\nColor Assigned to Each Vertex:\n"); 
   for (int i = 0; i < V; i++) 
       printf("Vertex %d ---> Colour %d\n", i + 1, color[i]); 
   return true; 
} 
 
int main() { 
   printf("Enter the Number of Vertices: "); 
   scanf("%d", &V); 
 
   printf("Enter the Adjacency Matrix (%d x %d):\n", V, V); 
   for (int i = 0; i < V; i++) { 
       for (int j = 0; j < V; j++) { 
           scanf("%d", &graph[i][j]); 
       } 
   } 
 
   printf("Enter the Number of Colors Available: "); 
   scanf("%d", &m); 
 
   graphColoring(); 
   return 0; 
} 
