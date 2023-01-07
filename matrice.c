#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FACTOR 13*11

typedef struct {
    unsigned short r;
    unsigned short c;
    double **data;
} Matrix;

Matrix* zeros(unsigned short r, unsigned short c){
    Matrix *m = malloc(sizeof(Matrix));
    
    m->r=r;
    m->c=c;
    m->data = malloc(r*sizeof(double));

    for (unsigned short y = 0; y < r; y++)
    {
        m->data[y] = malloc(c*sizeof(double));
        for (unsigned short x = 0; x < c; x++)
        {
            m->data[y][x]=0.0;
        }
    }
    return m;
}

Matrix* ones(unsigned short r, unsigned short c){
    Matrix *m = malloc(sizeof(Matrix));
    
    m->r=r;
    m->c=c;
    m->data = malloc(r*sizeof(double));

    for (unsigned short y = 0; y < r; y++)
    {
        m->data[y] = malloc(c*sizeof(double));
        for (unsigned short x = 0; x < c; x++)
        {
            m->data[y][x]=1.0;
        }
    }
    return m;
}
    
Matrix* eye(unsigned short r, unsigned short c){
    Matrix *m = malloc(sizeof(Matrix));
    
    m->r=r;
    m->c=c;
    m->data = malloc(r*sizeof(double));

    for (unsigned short y = 0; y < r; y++)
    {
        m->data[y] = malloc(c*sizeof(double));
        for (unsigned short x = 0; x < c; x++)
        {
            if (y==x){
                m->data[y][x]=1.0;
            }
            else {
                m->data[y][x]=0.0;
            }
        }
    }
    return m;
}

void show(Matrix *m){
    unsigned short y,x;
    for (y = 0; y < m->r; y++)
    {
        for (x = 0; x < m->c; x++)
        {
            printf("%10.2f",m->data[y][x]);
        }
        printf("\n");
    }  
}

Matrix* add(Matrix *a, Matrix *b){
    Matrix *m = malloc(sizeof(Matrix));

    if (a->r != b->r || a->c != b->c)
    {
        printf("Error: Matrix dimensions must agree.\n");
        return m;
    }

    m->r=a->r;
    m->c=b->c;
    m->data = malloc(m->r*sizeof(double));

    for (unsigned short y = 0; y < m->r; y++)
    {
        m->data[y] = malloc(m->r*sizeof(double));
        for (unsigned short x = 0; x < m->c; x++)
        {
            m->data[y][x]=a->data[y][x]+b->data[y][x];
        }
    }
    return m;
}

Matrix* multiply(Matrix *a, Matrix *b){

    Matrix *m = malloc(sizeof(Matrix));

    if (a->c != b->r || b->c != a->r)
    {
        printf("Error: Matrix dimensions must agree.\n");
        return 0;
    }

    m->r=a->r;
    m->c=b->c;
    m->data = malloc(m->r*sizeof(double));

    for (unsigned short y = 0; y < m->r; y++)
    {
        m->data[y] = malloc(m->r*sizeof(double));
        for (unsigned short x = 0; x < m->c; x++)
        {   
            m->data[y][x]=0;
            for (short i = 0; i < m->c; i++)
            {
                m->data[y][x]+=a->data[y][i]*b->data[i][x];
            }
        }
    }
    return m;
}

Matrix* lowerT(Matrix *a){
    Matrix *m = malloc(sizeof(Matrix));
    m->r=a->r;
    m->c=a->c;
    m->data = malloc(m->r*sizeof(double));
    for (unsigned short y = 0; y < m->r; y++)
    {
        m->data[y] = malloc(m->r*sizeof(double));
        for (unsigned short x = 0; x < m->c; x++)
        {
            if (x>y)
            {
                m->data[y][x]=0.0;
            } else {
                m->data[y][x]=a->data[y][x];
            }
            
        }
    }
    return m;
}

Matrix* upperT(Matrix *a){
    Matrix *m = malloc(sizeof(Matrix));
    m->r=a->r;
    m->c=a->c;
    m->data = malloc(m->r*sizeof(double));
    for (unsigned short y = 0; y < m->r; y++)
    {
        m->data[y] = malloc(m->r*sizeof(double));
        for (unsigned short x = 0; x < m->c; x++)
        {
            if (x<y)
            {
                m->data[y][x]=0.0;
            } else {
                m->data[y][x]=a->data[y][x];
            }
            
        }
    }
    return m;
}

double det(Matrix *m){
    
    int row_size = m->r;
    int column_size = m->c;

    if (row_size != column_size) {
        printf("DimensionError: Operation Not Permitted \n");
        exit(1);
    }

    else if (row_size == 1)
        return (m->data[0][0]);

    else if (row_size == 2)
        return ((m->data[0][0])*(m->data[1][1]) - (m->data[1][0])*(m->data[0][1]));

    else {
        Matrix* minor = malloc(sizeof(Matrix));
        minor->r=m->r-1;
        minor->c=m->c-1;
        unsigned short row_minor, column_minor;
        unsigned short firstrow_columnindex;
        double sum = 0;
        char factor = 1;

        register int row,column;

        for(firstrow_columnindex = 0; firstrow_columnindex < row_size;
                firstrow_columnindex++) {

            row_minor = 0;
            minor->data = malloc((minor->r)*sizeof(double));
            for(row = 1; row < row_size; row++) {

                column_minor = 0;
                minor->data[row_minor] = malloc((minor->c)*sizeof(double));
                for(column = 0; column < column_size; column++) {
                    if (column == firstrow_columnindex)
                        continue;
                    else
                        minor->data[row_minor][column_minor] = m->data[row][column];
                        //printf("%d",minor->data[row_minor][column_minor]);

                    column_minor++;
                }

                row_minor++;
            }

            sum += m->data[0][firstrow_columnindex] * det(minor) * factor;
            factor *=-1;

        } return sum;
    }
}  

Matrix* transpose(Matrix *a){
    Matrix *m = malloc(sizeof(Matrix));
    m->r=a->c;
    m->c=a->r;
    m->data = malloc(m->c*sizeof(double));
    for (unsigned short y = 0; y < m->r; y++)
    {
        m->data[y] = malloc(m->r*sizeof(double));
        for (unsigned short x = 0; x < m->c; x++)
        {
            m->data[y][x]=a->data[x][y];
        }
    }
    return m;
}

Matrix* getCofactor(Matrix* a, unsigned short p, unsigned short q){
    unsigned short i = 0, j = 0;
    Matrix* m = malloc(sizeof(Matrix));
    m->r=a->r-1;
    m->c=a->c-1;
    m->data = malloc(m->r*sizeof(double));
    for (unsigned short row = 0; row < a->r; row++) {
        m->data[row] = malloc(m->r*sizeof(double));
        for (unsigned short col = 0; col < a->c; col++) {
            if (row != p && col != q) {
                m->data[i][j] = a->data[row][col];
                j++;
                if (j == a->r - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return m;
}

Matrix* adj(Matrix *a){
    Matrix* m = malloc(sizeof(Matrix));
    m->r=a->r;
    m->c=a->c;
    m->data = malloc(m->r*sizeof(double));
    for (unsigned short y = 0; y < m->r; y++)
    {
        m->data[y] = malloc(m->r*sizeof(double));
        for (unsigned short x = 0; x < m->c; x++)
        {
            m->data[y][x]=det(getCofactor(a,y,x))*pow(-1,x+y);
        }
    }
    return transpose(m);
}

Matrix* inv(Matrix *a){
    Matrix* m = adj(a);
    for (unsigned short y = 0; y < m->r; y++)
    {
        for (unsigned short x = 0; x < m->c; x++)
        {
            m->data[y][x]= m->data[y][x]/det(a);
        }
    }
    return m;
}

Matrix* sub(Matrix *a, Matrix *b){
    Matrix *m = malloc(sizeof(Matrix));

    if (a->r != b->r || a->c != b->c)
    {
        printf("Error: Matrix dimensions must agree.\n");
        return m;
    }

    m->r=a->r;
    m->c=b->c;
    m->data = malloc(m->r*sizeof(double));

    for (unsigned short y = 0; y < m->r; y++)
    {
        m->data[y] = malloc(m->r*sizeof(double));
        for (unsigned short x = 0; x < m->c; x++)
        {
            m->data[y][x]=a->data[y][x]-b->data[y][x];
        }
    }
    return m;
}

short ascending(double a, double b){
    if (a<b) return -1;
    return 1;
}
short descending(double a, double b){
    if (a>b) return -1;
    return 1;
}

Matrix* sort(Matrix* a, short (*compare)(double,double)){
    double* niz = (double*)malloc(a->r*a->c*sizeof(double));
    for (unsigned short y = 0; y < a->r; y++)
    {
        for (unsigned short x = 0; x < a->c; x++)
        {
            niz[(y*a->c+x)]=a->data[y][x];
        }
    }
    double temp;
    for (unsigned short i = 0; i < a->r*a->c; i++)
    {   
        for (unsigned short j = 0; j < a->r*a->c-1; j++)
        {
            if(compare(niz[j],niz[j+1])>0){
                temp = niz[j];
                niz[j] = niz[j+1];
                niz[j+1] = temp;
            }
        }
        
    }
    Matrix* m = malloc(sizeof(Matrix));
    m->r=a->r;
    m->c=a->c;
    m->data = malloc(m->r*sizeof(double));

    for (unsigned short y = 0; y < m->r; y++)
    {
        m->data[y] = malloc(m->r*sizeof(double));
        for (unsigned short x = 0; x < m->c; x++)
        {
            m->data[y][x]=niz[(y*a->c+x)];
        }
    }
    free(niz);
    return m;
} 

double min(Matrix* a){
    double Min = a->data[0][0];
    for (unsigned short y = 0; y < a->r; y++)
    {   
        for (unsigned short x = 0; x < a->c; x++)
        {
            if (a->data[y][x]<Min) Min = a->data[y][x];
        }
    }
    return Min;
}

double max(Matrix* a){
    double Max = a->data[0][0];
    for (unsigned short y = 0; y < a->r; y++)
    {   
        for (unsigned short x = 0; x < a->c; x++)
        {
            if (a->data[y][x]>Max) Max = a->data[y][x];
        }
    }
    return Max;
}

Matrix* coef(Matrix* a,double k){
    Matrix* m = malloc(sizeof(Matrix));
    m->r=a->r;
    m->c=a->c;
    m->data =malloc(m->r*sizeof(double));
    for (unsigned short y = 0; y < a->r; y++)
    {   
        m->data[y]=malloc(m->c*sizeof(double));
        for (unsigned short x = 0; x < a->c; x++)
        {
            m->data[y][x]=a->data[y][x]*k;
        }
    }
    return m;
}

short integer() {return 1;}
short floating() {return 0;}

Matrix* randM(unsigned short a, unsigned short b,short (*type)()){
    Matrix* m = malloc(sizeof(Matrix));
    m->r=a;
    m->c=b;

    short f=type();

    m->data = malloc(m->r*sizeof(double));
    for (unsigned short y = 0; y < m->r; y++)
    {
        m->data[y]=malloc(m->c*sizeof(double));
        for (unsigned short x = 0; x < m->c; x++)
        {
            m->data[y][x]=(f) ? ((double)rand()):((double)rand()/FACTOR);
        }
    }
    return m;
}
