#include <stdio.h>
#include <stdlib.h>

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
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
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

// Funktion zur Freigabe des Speichers
void FreeMatrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
}

int main() {
    Matrix mat;
    int rows, cols;

    // Abfrage der Dimensionen der Matrix
    printf("Geben Sie die Anzahl der Zeilen ein: ");
    scanf("%d", &rows);
    printf("Geben Sie die Anzahl der Spalten ein: ");
    scanf("%d", &cols);

    // Initialisierung der Matrix
    Init(&mat, rows, cols);

    // Eingabe der Matrix
    Input(&mat);

    // Ausgabe der Matrix
    printf("Die eingegebene Matrix ist:\n");
    Print(&mat);

    // Freigabe des Speichers
    FreeMatrix(&mat);

    return 0;
}