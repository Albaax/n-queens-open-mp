#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX 100

int n, t, solutions[MAX], count = 0;

int place(int k, int i) {
    int j;
    for (j = 1; j <= k - 1; j++) {
        if (solutions[j] == i || (abs(solutions[j] - i) == abs(j - k))) {
            return 0;
        }
    }
    return 1;
}

void nqueens(int k) {
    int i, j;
	#pragma omp parallel for num_threads(t) private(i, j)
	for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            solutions[k] = i;
            if (k == n) {
				#pragma omp critical
				{
                    count++;
                    //printf("Solution %d: ", count);
                    //FOPEN_MAXr (j = 1; j <= n; j++)
                    //{
                       // printf("%d ", solutions[j]);
                    //}
                    //printf("\n");
                }
            }
            else {
                nqueens(k + 1);
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Uso: %s N T\n", argv[0]);
        return 1;
    }
    n = atoi(argv[1]);
    t = atoi(argv[2]);

    double start_time = omp_get_wtime();

	#pragma omp parallel num_threads(t)
    {
		#pragma omp single
        {
            nqueens(1);
        }
    }

    double end_time = omp_get_wtime();
    printf("\nTotal de solucoes: %d\n", count);
    printf("Tempo decorrido: %f segundos, com %d rainhas e %d threads\n", (end_time - start_time), n, t);

    return 0;
}

