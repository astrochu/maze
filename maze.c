#include "maze.h"
#include <stdio.h>

//定義point,迷宮中(x,y)座標
typedef struct {
    int x, y;
} Point;

//堆疊頂端
int top = -1;
Point stack[Map * Map];

//加入堆疊
void push(Point p) {
    stack[++top] = p;
}

//刪除堆疊
Point pop() {
    return stack[top--];
}

//檢查堆疊
int isStackEmpty() {
    return top == -1;
}

//印出迷宮
void printMaze() {
    int i, j;
    for (i = 0; i < Map; i++) {
        for (j = 0; j < Map; j++) {
            if (maze[i][j] == 1) {
                printf("1 ");
            } else if (maze[i][j] == -1) {
                printf("x ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

//路徑(深度優先搜索)
int mazeStack(int startX, int startY, int endX, int endY) {
    Point start = {startX, startY};
    push(start);

    while (!isStackEmpty()) {
        Point current = pop();
        int x = current.x, y = current.y;

        if (x == endX && y == endY) {
            return 1;
        }

        if (x >= 0 && x < Map && y >= 0 && y < Map && maze[x][y] == 0) {
            maze[x][y] = -1;

            Point up = {x - 1, y};
            Point left = {x, y - 1};
            Point down = {x + 1, y};
            Point right = {x, y + 1};

            push(right);
            push(down);
            push(left);
            push(up);
        }
    }

    return 0;
}