/*
 * 八皇后，用回溯法
 */
#include <stdio.h>

void print_queens(int* result);
bool is_ok(int row, int column);

int result[8];
void cal8queen(int row) {
    if (row == 8) { // 最后一行
        print_queens(result);
        return;
    }
    for (int column = 0; column < 8; ++column) {
        if (is_ok(row, column)) {
            result[row] = column;
            cal8queen(row + 1);
        }
    }
}

bool is_ok(int row, int column) {
    //判断row行column列放置是否合适
    int leftup = column - 1, rightup = column + 1;
    for (int i = row-1; i >= 0; --i) { // 逐行往上考察每一行
        if (result[i] == column) return false; // 第i行的column列有棋子吗？
        if (leftup >= 0) { // 考察左上对角线：第i行leftup列有棋子吗？
            if (result[i] == leftup) return false;
        }
        if (rightup < 8) { // 考察右上对角线：第i行rightup列有棋子吗？
            if (result[i] == rightup) return false;
        }
        --leftup; ++rightup;
    }
    return true;
}

void print_queens(int* result) {
    for (int row = 0; row < 8; ++row) {
        for (int column = 0; column < 8; ++column) {
            if (result[row] == column) {
                printf("Q ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    cal8queen(0);
}
