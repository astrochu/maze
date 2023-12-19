#include "maze.h"
#include <stdio.h>

//原始迷宮
int maze[Map][Map] ={
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
    { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
    { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
    { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
    { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

//主程式
int main() {
    int startX = 1, startY = 0;  // 起點座標
    int endX = 6, endY = 9;   // 目標座標

    printf("原始迷宮:\n");
    printMaze();

    if (mazeStack(startX, startY, endX, endY)) {
        printf("\n找到路徑:\n");
    } else {
        printf("\n沒有找到路徑\n");
    }

    printf("\n路徑(x):\n");
    printMaze();

    return 0;
}
