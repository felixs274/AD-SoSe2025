#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Definition der Matrix-Struktur
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Funktion zur Initialisierung der Matrix
void Init(Matrix *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
    
    // Speicher für die Zeilen der Matrix allokieren
    mat->data = (int **)malloc(rows * sizeof(int *));
    
    // Speicher für jede Zeile allokieren und mit 0 initialisieren
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = 0;
        }
    }
}

// Funktion zur Ausgabe der Matrix
void Print(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf(" %d ", mat->data[i][j]);
        }
        printf("\n");
    }
}


// Funktion um die Matrix mit random Zahlen zu füllen
void RandomFill(Matrix *mat){
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            mat->data[i][j] = rand() % 10;
        }
    }
}


// Funktion zur Eingabe der Matrix
void Input(Matrix *mat) {
    printf("Geben Sie die Matrixelemente ein (%d x %d):\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat->data[i][j]);
        }
    }
}


int Add(Matrix *m1, Matrix *m2, Matrix *m3, int *act){

    if(!(m1->rows == m2->rows && m1->cols == m2->cols)){
        printf("Matrizen nicht gleich groß!");
        return 0;
    }

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            m3->data[i][j] = m1->data[i][j] + m2->data[i][j];
            *act += 1;
        }
    }
}


int Mult(Matrix *m1, Matrix *m2, Matrix *m3, int *act){

    if(!(m1->rows == m2->cols)){
        printf("Spaltenzahl von Matrix1 nicht gleich Zeilenzahl von Matrix2!");
        return 0;
    }

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            for (int k = 0; k < m1->cols; k++) {
                m3->data[i][j] += m1->data[i][k] * m2->data[k][j];
                // printf("%d, %d, %d\n", i, j, k);
                *act += 1;
            }
        }
    }
}


// Funktion zur Freigabe des Speichers
void FreeMatrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
}

int main() {
    srand(time(NULL));
    clock_t start, end;
    double time_taken_ms;

    int actions_add = 0;
    int actions_mul = 0;

    int rows = 100;
    int cols = 100;

    Matrix mat1;
    Matrix mat2;
    Matrix mat3;

    Init(&mat1, rows, cols);
    Init(&mat2, rows, cols);
    Init(&mat3, rows, cols);

    RandomFill(&mat1);
    RandomFill(&mat2);

    // printf("Matrix 1\n"); Print(&mat1); printf("\n");
    // printf("Matrix 2\n"); Print(&mat2); printf("\n");

    // printf("Addition Matrix 3\n"); 
    start = clock();
    Add(&mat1, &mat2, &mat3, &actions_add);
    end = clock(); 
    // Print(&mat3);
    printf("Addition took %f ms and %d actions\n\n", (((double) (end - start)) / CLOCKS_PER_SEC * 1000) ,actions_add);

    // printf("Multiplikation Matrix 3\n"); 
    start = clock();
    Mult(&mat1, &mat2, &mat3, &actions_mul);
    end = clock(); 
    // Print(&mat3);
    printf("Multiplication took %f ms and %d actions\n\n", (((double) (end - start)) / CLOCKS_PER_SEC * 1000) ,actions_mul);

    FreeMatrix(&mat1);
    FreeMatrix(&mat2);
    FreeMatrix(&mat3);

    return 0;
}

// Addition
// m = n = 10   -> 0.001 ms
// m = n = 100  -> 0.022 ms
// m = n = 1000 -> 2.155 ms
//
// -> f(x) = 2.15 * 10^(-5) * x^(1.6665)
// -> f(10min) = 27_907_000_000
//
// Multiplication
// m = n = 10   -> 0.18 ms
// m = n = 100  -> 2.56 ms
// m = n = 1000 -> 3110.262 ms
//
// -> f(x) = 0.00137 * x^(2.119)
// -> f(10min) = 11969