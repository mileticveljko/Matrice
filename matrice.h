#pragma once

typedef struct {
    unsigned short r;
    unsigned short c;
    double **data;
} Matrix;

Matrix* zeros(unsigned short r, unsigned short c);
Matrix* ones(unsigned short r, unsigned short c);
Matrix* eye(unsigned short r, unsigned short c);
void show(Matrix *m);
Matrix* add(Matrix *a, Matrix *b);
Matrix* multiply(Matrix *a, Matrix *b);
Matrix* lowerT(Matrix *a);
Matrix* upperT(Matrix *a);
double det(Matrix*a);
Matrix* transpose(Matrix *a);
Matrix* getCofactor(Matrix *a);
Matrix* adj(Matrix *a);
Matrix* inv(Matrix *a);
Matrix* sub(Matrix *a, Matrix *b);
double min(Matrix* a);
double max(Matrix* a);
short ascending(double a, double b); // Pomocna f-ja: nacin sortiranja
short descending(double a, double b); // Pomocna f-ja: nacin sortiranja
Matrix* sort(Matrix* a, short (*compare)(double,double));
Matrix* coef(Matrix* a,double k);
short integer(); // Pomocna f-ja za randM
short floating(); // Pomocna f-ja za randM
Matrix* randM(unsigned short a, unsigned short b,short (*type)());
