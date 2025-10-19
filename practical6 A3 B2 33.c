#include <stdio.h>
#define MAX 100
void optimal_BST(float p[], float q[], int n, float e[][n+1], int root[][n]) {
    float w[n+1][n+1];
   
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    for (int length = 1; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            e[i][j] = MAX;
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];

            for (int r = i; r <= j; r++) {
                float cost = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (cost < e[i][j]) {
                    e[i][j] = cost;
                    root[i - 1][j - 1] = r;
                }
            }
        }
    }
}
int main() {
    int n = 4;
    float p[] = {0.1, 0.2, 0.4, 0.3};
    float q[] = {0.05, 0.1, 0.05, 0.05, 0.1};

    float e[n + 2][n + 1];
    int root[n+1][n+1];

    optimal_BST(p, q, n, e, root);
for(int i=1;i<=n; i++){
        for(int j=1;j<=n; j++){
             printf("e[%d][%d] = %.3f\n", i, j, e[i][j]);
        }
    }
    printf("\nRoot matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            printf("root[%d][%d] = %d\n", i, j, root[i][j]);
        }
    }
    printf("\nOptimal cost for the entire tree: %.3f\n", e[1][n]);
    return 0;
}