#include <stdio.h>
#define sz 20
#define INF 200000

void Matrix_Chain_Order(int w[], int num1) {
    unsigned long x[sz][sz] = {0}; // Array to store the minimum number of multiplications
    unsigned int q = 0;
    int i, j, k, l;
    int n = num1;

    // Initialize the main diagonal to 0, as a single matrix requires no multiplication
    for (i = 1; i <= n; i++)
        x[i][i] = 0;

    // l is the chain length
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= (n - l + 1); i++) {
            j = i + l - 1;
            x[i][j] = INF;
            for (k = i; k <= j - 1; k++) {
                q = x[i][k] + x[k+1][j] + w[i-1] * w[k] * w[j];
                if (q < x[i][j]) {
                    x[i][j] = q;
                }
            }
        }
    }

    printf("\n\nThe Minimum Number of Multiplications Required is:\n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%5lu", x[i][j]);
        }
        printf("\n\n");
    }
    printf("\nThe Number of Multiplications Required is : %lu\n", x[1][n]);
}

int main() {
    int i, num1 = 0, w[sz] = {0};

    printf("Enter the number of matrices: ");
    scanf("%d", &num1);

    printf("Enter the dimensions of the matrices for %d matrices multiplication:\n", num1);
    for (i = 0; i <= num1; i++) {
        scanf("%d", &w[i]);
    }

    printf("\n\nMATRIX MULTIPLICATION SEQUENCE IS : \n\n");
    Matrix_Chain_Order(w, num1);

    return 0;
}
