#include <stdio.h>

// obchyslennia sumy riadu S = sum(a^n / n!) bez ##math.h
int main(void) {
    double a, S = 0.0;
    int N;

    // vvedennia znachen z klaviatury
    printf("Enter value a: ");
    scanf("%lf", &a);

    printf("Enter integer N (N >= 0): ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Error: N must be >= 0\n");
        return 1;
    }

    // obchyslennia riadu
    double term = 1.0; // a^0 / 0! = 1
    for (int n = 0; n <= N; ++n) {
        if (n > 0) term *= a / n; // obchyslennia nastupnoho chlena
        S += term;
    }

    // vyvid rezultatu
    printf("Sum S = %.10f\n", S);
    return 0;
}
