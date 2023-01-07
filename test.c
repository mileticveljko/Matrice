#include "matrice.h"
#include <stdio.h>

void main(){
    //show(multiply(ones(2,3),eye(3,2)));
    //printf("\n");
    //show(add(ones(2,2),ones(2,2)));
    //printf("\n");

    //show(lower(ones(4,4)));
    //printf("\n");
    //show(upper(ones(4,4)));
    
    //Matrix *B = ones(3,3);
    //B->data[0][0]=12;B->data[0][1]=15;B->data[0][2]=16;
    //B->data[1][0]=3;B->data[1][1]=6;B->data[1][2]=80;
    //B->data[2][0]=12;B->data[2][1]=3;B->data[2][2]=3;

    //printf("\n%f",Det(B));
   
    //Matrix *B = zeros(4,4);
    //B->data[0][0]=12;B->data[0][1]=15;B->data[0][2]=16;B->data[0][3]=2;
    //B->data[1][0]=3;B->data[1][1]=6;B->data[1][2]=0;B->data[1][3]=0;
    //B->data[2][0]=12;B->data[2][1]=3;B->data[2][2]=3;B->data[2][3]=4;
    //B->data[3][0]=12;B->data[3][1]=3;B->data[3][2]=3;B->data[3][3]=15;
    //show(B);
    //printf("\n%f",Det(B));

    //Matrix *B = zeros(4,4);
    //B->data[0][0]=12;B->data[0][1]=15;B->data[0][2]=16;B->data[0][3]=2;
    //B->data[1][0]=3;B->data[1][1]=6;B->data[1][2]=80;B->data[1][3]=30;
    //B->data[2][0]=12;B->data[2][1]=3;B->data[2][2]=3;B->data[2][3]=4;
    //B->data[3][0]=12;B->data[3][1]=3;B->data[3][2]=3;B->data[3][3]=15;
    //show(B);
    //printf("\n%f",det(B));

    //Matrix *B = zeros(5,5);
    //B->data[0][0]=1;B->data[0][1]=2;B->data[0][2]=3;B->data[0][3]=5;B->data[0][4]=6;
    //B->data[1][0]=0;B->data[1][1]=9;B->data[1][2]=17;B->data[1][3]=8;B->data[1][4]=9;
    //B->data[2][0]=2;B->data[2][1]=2;B->data[2][2]=2;B->data[2][3]=2;B->data[2][4]=2;
    //B->data[3][0]=9;B->data[3][1]=0;B->data[3][2]=9;B->data[3][3]=0;B->data[3][4]=9;
    //B->data[4][0]=1;B->data[4][1]=1;B->data[4][2]=4;B->data[4][3]=1;B->data[4][4]=2;
    //printf("\n");
    //show(B);
    //printf("\n%f",det(B));
    //printf("\n");
    //show(transpose(B));
    
    //Matrix *B = zeros(2,2);
    //B->data[0][0]=2;B->data[0][1]=9;
    //B->data[1][0]=10;B->data[1][1]=3;
    //show(B);
    //printf("\n");
    //show(adj(B));

    //Matrix *B = zeros(3,3);
    //B->data[0][0]=8;B->data[0][1]=1;B->data[0][2]=6;
    //B->data[1][0]=3;B->data[1][1]=6;B->data[1][2]=7;
    //B->data[2][0]=4;B->data[2][1]=9;B->data[2][2]=2;
    //show(B);
    //printf("\n");
    ////show(adj(B));
    //show(inv(B));

    //Matrix *B = zeros(3,3);
    //B->data[0][0]=8;B->data[0][1]=1;B->data[0][2]=6;
    //B->data[1][0]=3;B->data[1][1]=6;B->data[1][2]=7;
    //B->data[2][0]=4;B->data[2][1]=-9;B->data[2][2]=2;
    //printf("Minimum je %.2f\n\n",min(B));
    //printf("Maksimum je %.2f\n\n",max(B));

    //Matrix *B = ones(4,3);
    //B->data[0][0]=8;B->data[0][1]=50;B->data[0][2]=6;
    //B->data[1][0]=3;B->data[1][1]=-6;B->data[1][2]=7;
    //B->data[2][0]=4;B->data[2][1]=-9;B->data[2][2]=2;
    //show(sort(B,descending));
    //printf("\n");
    //show(sort(B,ascending));

    //Matrix *B = ones(4,3);
    //B->data[0][0]=8;B->data[0][1]=50;B->data[0][2]=6;
    //B->data[1][0]=3;B->data[1][1]=-6;B->data[1][2]=7;
    //B->data[2][0]=4;B->data[2][1]=-9;B->data[2][2]=2;
    //show(coef(B,2));

    show(randM(3,3,floating));
}
