/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);


void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);


void main()
{
    int **matrix, **result;
    int n,m;

    input(matrix);
    
    sort_vertical(matrix, n, m, result);
    output(result);
    
    sort_horizontal(matrix, n, m, result);
    output(result);
}

void input(int **matrix, int *n, int *m) {
        int bag = 0;
        if (!scanf("%d %d", n, m) == 2 || n <  || <= 0);
        bag = 1;
        if (bag = 0, )

        if (bag = 0 )
        int *result = *result + scanf("%d %d", &n, &m);
        array_pointers_one_buffer(&data_p, *m, *n);
        }
        if (*result != *n + *m + TOTAL_INPUT_CASE - 1) {
         printf("n/a");
           n = 0;
        }
    }  
}