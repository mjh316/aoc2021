#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(x, y) ((x) > (y) ? (x) : (y))

const int n = 1500;
const int m = 1500;
char folds[15][35];
int grid[1500*1500];
int tmp[1500*1500];
int row, col, k;

void fold_y(int y) {
    for (row = 0; row < 1500; ++row) for (col = 0; col < 1500; ++col) tmp[row*1500 + col] = 0;
    for (row = 0; row < n; ++row) {
        for (col = 0; col < m; ++col) {
            if (row <= y) {
                tmp[row*1500 + col] = 0;
                continue;
            }
            if (y-(row-y-1)-1<0) {
                continue;
            }
            tmp[(y-(row-y-1)-1)*1500 + col] = max(grid[(y-(row-y-1)-1)*1500 + col], grid[row*1500 + col]);
            //printf("%d %d %d\n", row, x-(col-x-1)-1, tmp[row][x-(col-x-1)-1]);
            // printf("%d\n", max(grid[row][x-(col-x-1)-1], grid[row][col]));
        }
    }
    for (row = 0; row < 1500; ++row) for (col = 0; col < 1500; ++col) grid[row*1500 + col] = tmp[row*1500 + col];
}


void fold_x(int x) {
    for (row = 0; row < 1500; ++row) for (col = 0; col < 1500; ++col) tmp[row*1500 + col] = 0;
    for (row = 0; row < n; ++row) {
        for (col = 0; col < m; ++col) {
            if (col <= x) {
                tmp[row*1500 + col] = 0;
                continue;
            }
            if ((x-(col-x-1)-1) < 0) {
                continue;
            }
            tmp[row*1500 + x-(col-x-1)-1] = max(grid[row*1500 + x-(col-x-1)-1], grid[row*1500 + col]);
            //printf("%d %d %d\n", row, x-(col-x-1)-1, tmp[row][x-(col-x-1)-1]);
            // printf("%d\n", max(grid[row][x-(col-x-1)-1], grid[row][col]));
        }
    }
    for (row = 0; row < 1500; ++row) for (col = 0; col < 1500; ++col) grid[row*1500 + col] = tmp[row*1500 + col];
}

int main() {
    freopen("13.in", "r", stdin);
    char buff[35];
    char *token;
    while (strncmp(fgets(buff, 11, stdin), "\n", 1) != 0)  {
        token = strtok(buff, ",");
        int x = atoi(token);
        token = strtok(NULL, ",");
        int y = atoi(token);
        grid[y*1500 + x] = 1;
    }
    row = 0;
    while (fgets(buff, 35, stdin) != NULL) {
        col = 0;
        while (buff[col] != 'x' && buff[col] != 'y') ++col;
        memmove(buff, buff+col, strlen(buff)-col);
        buff[4] = 0;
        token = strtok(buff, "=");
        int x = strncmp(token, "x", 1) == 0;
        token = buff;
        while (*token != '=') ++token;
        ++token;
        // printf("%s\n", token);
        if (x) fold_x(atoi(token));
        else fold_y(atoi(token));
        int sum = 0;
        // printf("x: %d, col: %s\n", x, (token));
        for (row = 0; row < 1500; ++row) {
            for (col = 0; col < 1500; ++col) {
                //printf("%c", grid[row][col] > 0 ? '#' : '.');
                if (grid[row*1500 + col] > 0) {
                    // printf("%d %d\n", row, j);
                }
                sum += grid[row*1500 + col];
            }
            // printf("\n");
        }
        printf("sum: %d\n", sum);
        ++row;
    }
    row = 0;
    for (row = 0; row < 20; ++row) {
        for (col = 0; col < 50; ++col) {
            printf("%c", grid[row*1500 + col] > 0 ? '#' : '.');
        }
        printf("\n");
    }
}
