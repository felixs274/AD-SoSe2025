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


int Add(Matrix *m1, Matrix *m2, Matrix *m3){

    if(!(m1->rows == m2->rows && m1->cols == m2->cols)){
        printf("Matrizen nicht gleich groß!");
        return 0;
    }

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            m3->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
}


int Mult(Matrix *m1, Matrix *m2, Matrix *m3){

    if(!(m1->rows == m2->cols)){
        printf("Spaltenzahl von Matrix1 nicht gleich Zeilenzahl von Matrix2!");
        return 0;
    }

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            for (int k = 0; k < m1->cols; k++) {
                m3->data[i][j] += m1->data[i][k] * m2->data[k][j];
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

    int rows = 5;
    int cols = 4;

    Matrix mat1;
    Matrix mat2;
    Matrix mat3;

    Init(&mat1, rows, cols);
    Init(&mat2, rows, cols);
    Init(&mat3, rows, cols);

    RandomFill(&mat1);
    RandomFill(&mat2);

    Print(&mat1); printf("\n");
    Print(&mat2); printf("\n");

    Add(&mat1, &mat2, &mat3);

    Print(&mat3); printf("\n");

    Mult(&mat1, &mat2, &mat3);

    Print(&mat3);

    FreeMatrix(&mat1);
    FreeMatrix(&mat2);
    FreeMatrix(&mat3);

    return 0;
}