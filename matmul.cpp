#include <iostream>


int main(){

    const int M = 6;
    const int N = 6;
    const int K = 6;
    // ensure the matrix is correctly padded 
    // assumed that the blocks will not got out of bounds
    float A[6][6] = {
        {1.0, 2.0, 3.0, 4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0, 10.0, 11.0, 12.0},
        {13.0, 14.0, 15.0, 16.0, 17.0, 18.0},
        {19.0, 20.0, 21.0, 22.0, 23.0, 24.0},
        {25.0, 26.0, 27.0, 28.0, 29.0, 30.0},
        {31.0, 32.0, 33.0, 34.0, 35.0, 36.0}
    };

    float B[6][6] = {
        {36.0, 35.0, 34.0, 33.0, 32.0, 31.0},
        {30.0, 29.0, 28.0, 27.0, 26.0, 25.0},
        {24.0, 23.0, 22.0, 21.0, 20.0, 19.0},
        {18.0, 17.0, 16.0, 15.0, 14.0, 13.0},
        {12.0, 11.0, 10.0, 9.0, 8.0, 7.0},
        {6.0, 5.0, 4.0, 3.0, 2.0, 1.0}
    };

    float C[6][6] = {0};

    int BLOCK_SIZE_M = 3;
    int BLOCK_SIZE_N = 3;
    int BLOCK_SIZE_K = 3;

    for(int m_blck = 0; m_blck < M; m_blck += BLOCK_SIZE_M){
        for(int n_blck = 0; n_blck < N; n_blck += BLOCK_SIZE_N){
            for(int k_blck = 0; k_blck < N; k_blck += BLOCK_SIZE_K){
                for(int m=0; m < BLOCK_SIZE_M; m++){
                    for(int n=0; n < BLOCK_SIZE_N; n++){
                        for(int k=0; k < BLOCK_SIZE_K; k++){
                            C[m_blck + m][n_blck + n] = A[m_blck + m][k_blck + k] * B[k_blck + k][n_blck + n];
                        }
                    }
                }
        }
        }
    }

    for (int i=0; i< M; i++){
        for (int j=0; j < N; j++){
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;



}

// g++ -o matmul matmul.cpp
// ./matmul