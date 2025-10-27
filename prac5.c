#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 500

int lcslen( char X[], char Y[])
{
    int m = strlen(X);
    int n = strlen(Y);

    if(m == 0 || n == 0){
        return 0;
    }

    int dp[MAX][MAX];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1] );
        }
    }
    return dp[m][n]; 
}

int main() {
    char X[MAX], Y[MAX];

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int length = lcslen(X, Y);
    printf("Length of LCS: %d\n", length);

    return 0;
}

