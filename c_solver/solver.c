#include <string.h>
#include <stdlib.h>

#define N 9
#define GRID_SIZE (N * N)
#define MAX_SOLUTIONS 5

static int board[N][N];
static int solution_count;
static int solutions_storage[MAX_SOLUTIONS][N][N];

static int is_valid(int row, int col, int num) {
    for (int c = 0; c < N; c++) {
        if (board[row][c] == num) return 0;
    }
    for (int r = 0; r < N; r++) {
        if (board[r][col] == num) return 0;
    }
    int boxRow = row / 3 * 3;
    int boxCol = col / 3 * 3;
    for (int r = boxRow; r < boxRow + 3; r++) {
        for (int c = boxCol; c < boxCol + 3; c++) {
            if (board[r][c] == num) return 0;
        }
    }
    return 1;
}

static void solve(int pos) {
    if (solution_count >= MAX_SOLUTIONS) return;
    if (pos == GRID_SIZE) {
        memcpy(solutions_storage[solution_count], board, sizeof(board));
        solution_count++;
        return;
    }
    int row = pos / N;
    int col = pos % N;
    if (board[row][col] != 0) {
        solve(pos + 1);
        return;
    }
    for (int num = 1; num <= N; num++) {
        if (is_valid(row, col, num)) {
            board[row][col] = num;
            solve(pos + 1);
            board[row][col] = 0;
        }
    }
}

/**
 * Solve Sudoku puzzle.
 *
 * Output buffer layout (Int32):
 *   [0]          = number of solutions found
 *   [1..81]      = solution 0 (row-major, 81 ints)
 *   [82..162]    = solution 1 (row-major, 81 ints)
 *   ...
 *
 * @param input_grid     81 ints (row-major), 0 = empty
 * @param output_buffer  buffer of size (1 + MAX_SOLUTIONS * 81) = 4086 ints
 * @param max_solutions  cap on solutions to find (should be MAX_SOLUTIONS)
 */
void solve_sudoku(int* input_grid, int* output_buffer, int max_solutions) {
    solution_count = 0;
    memset(solutions_storage, 0, sizeof(solutions_storage));

    for (int i = 0; i < GRID_SIZE; i++) {
        board[i / N][i % N] = input_grid[i];
    }
    solve(0);

    output_buffer[0] = solution_count;
    for (int s = 0; s < solution_count; s++) {
        int offset = 1 + s * GRID_SIZE;
        for (int i = 0; i < GRID_SIZE; i++) {
            output_buffer[offset + i] = solutions_storage[s][i / N][i % N];
        }
    }
}
