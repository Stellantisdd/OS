
int mat_add(int** src1, int** src2, int** dst, int len)
{

}

int mat_sub(int** src1, int** src2, int** dst, int len)
{

}

int mat_mul(int** src1, int** src2, int** dst, int len)
{
    int i, j, k;

    for (i = 0; i < len; i++)
    { // i (Row)
        for (j = 0; j < len; j++)
        { // j (Column)
            //c[i][j] = a[i][j] + b[i][j] //add matrix
            dst[i][j] = 0;
            for (k = 0; k < len; k++)
            {
                dst[i][j] += src1[i][k] * src2[k][j]; //matrixx multiplication
            }
        }
    }
    return 0;
}

// 0: Success
// 1: Inverse matrix isn't existed.
int mat_inv(int** src, int** dst, int)
{

}
