#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/* Params that go to thread */
typedef struct {
    int row, col, (* board)[9];
} params; // parameters

/* Prototypes */
void * traverse_rows(void * _params);
void * traverse_cols(void * _params);
void * evaluate(void * _params);

void * traverse_rows(void * _params) {
    params * data = (params *) _params;
    int start_row = data->row;
    int start_col = data->col;

    for (int i = start_row; i < 9; i++) {
        int row[10] = {0};
        for (int j = start_col; j < 9; j++) {
            int value = data->board[i][j];
            if (row[value] != 0) {
                return (void *) 0;
            } else {
                row[value] = 1;
            }
        }
    }
    return (void *) 1;
}

void * traverse_cols(void * _params) {
    params * data = (params *) _params;
    int start_row = data->row;
    int start_col = data->col;

    for (int i = start_col; i < 9; i++) {
        int col[10] = {0};
        for (int j = start_row; j < 9; j++) {
            int value = data->board[j][i];
            if (col[value] != 0) {
                return (void *) 0;
            } else {
                col[value] = 1;
            }
        }
    }
    return (void *) 1;
}

void * evaluate(void * _params) {
    params * data = (params *) _params;
    int start_row = data->row;
    int start_col = data->col;

    int logged[10] = {0};

    for (int i = start_row; i < start_row + 3; i++) {        
        for (int j = start_col; j < start_col + 3; j++) {
            int value = data->board[i][j];
            if (logged[value] != 0) {
                return (void *) 0;
            } else {
                logged[value] = 1;
            }
        }
    }
    return (void *) 1;
}

int main(void) {
    printf("Process at which main is executing is: %d\n", getpid());
    system("ps >/dev/null 2>&1");

    /* read file */
    FILE *sudokuInput;
    sudokuInput = fopen("sudoku", "r");
    int numbersArray[81];
    int initialBoard[9][9];

    for (int k = 0; k < 81; k++) {
        fscanf(sudokuInput, "%1d", &numbersArray[k]);
    }
    
    int index = 0;
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j++) {
            initialBoard[i][j] = numbersArray[index];
            index++;
        }
    }

    fork();        

    /* rows & cols checking */
    params * p0 = (params *) malloc(sizeof(params));
    p0->row = 0;
    p0->col = 0;
    p0->board = initialBoard;

    /* threads for inner boards (3x3) */
    params * p1 = (params *) malloc(sizeof(params));
    p1->row = 0;
    p1->col = 0;
    p1->board = initialBoard;
    
    params * p2 = (params *) malloc(sizeof(params));
    p2->row = 0;
    p2->col = 3;
    p2->board = initialBoard;
    
    params * p3 = (params *) malloc(sizeof(params));
    p3->row = 0;
    p3->col = 6;
    p3->board = initialBoard;
    
    params * p4 = (params *) malloc(sizeof(params));
    p4->row = 3;
    p4->col = 0;
    p4->board = initialBoard;
    
    params * p5 = (params *) malloc(sizeof(params));
    p5->row = 3;
    p5->col = 3;
    p5->board = initialBoard;
    
    params * p6 = (params *) malloc(sizeof(params));
    p6->row = 3;
    p6->col = 6;
    p6->board = initialBoard;
        
    params * p7 = (params *) malloc(sizeof(params));
    p7->row = 6;
    p7->col = 0;
    p7->board = initialBoard;
    
    params * p8 = (params *) malloc(sizeof(params));
    p8->row = 6;
    p8->col = 3;
    p8->board = initialBoard;
    
    params * p9 = (params *) malloc(sizeof(params));
    p9->row = 6;
    p9->col = 6;
    p9->board = initialBoard;

    /* creating threads */    
    pthread_t t_rows, t_cols, t1, t2, t3, t4, t5, t6, t7, t8, t9;

    void * rows_all;
    void * cols_all;
    void * board1;
    void * board2;
    void * board3;
    void * board4;
    void * board5;
    void * board6;
    void * board7;
    void * board8;
    void * board9;
    
    pthread_create(&t_rows, NULL, traverse_rows, (void *) p0);    
    pthread_create(&t_cols, NULL, traverse_cols, (void *) p0);
    pthread_create(&t1,     NULL, evaluate,      (void *) p1);
    pthread_create(&t2,     NULL, evaluate,      (void *) p2);
    pthread_create(&t3,     NULL, evaluate,      (void *) p3);
    pthread_create(&t4,     NULL, evaluate,      (void *) p4);
    pthread_create(&t5,     NULL, evaluate,      (void *) p5);
    pthread_create(&t6,     NULL, evaluate,      (void *) p6);
    pthread_create(&t7,     NULL, evaluate,      (void *) p7);
    pthread_create(&t8,     NULL, evaluate,      (void *) p8);
    pthread_create(&t9,     NULL, evaluate,      (void *) p9);
    
    pthread_join(t_rows, &rows_all);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());
    pthread_join(t_cols, &cols_all);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());
    pthread_join(t1, &board1);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());
    pthread_join(t2, &board2);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());
    pthread_join(t3, &board3);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());
    pthread_join(t4, &board4);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());
    pthread_join(t5, &board5);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());
    pthread_join(t6, &board6);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());
    pthread_join(t7, &board7);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());
    pthread_join(t8, &board8);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());
    pthread_join(t9, &board9);
    printf("Process id of thread in evaluating one board in specific is: %d\n", getpid());

    /* check if solved */
    if ( (int) rows_all == 1 && (int) cols_all == 1 && (int) board1 == 1 && (int) board2 == 1
            && (int) board3 == 1 && (int) board4 == 1 && (int) board5 == 1 && (int) board6 == 1 && (int) board7 == 1
            && (int) board8 == 1 && (int) board9 == 1 ) {
                printf("Sudoku solved.\n");
    } else {
        printf("Sudoku not solved.\n");
    }

    return 0;
}
