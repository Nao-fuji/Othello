#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"conio.h"

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

enum{
  COLOR_NONE=-1,
  COLOR_BLACK=0,
  COLOR_WHITE=1,
  COLOR_MAX //=2
};
char colorNames[][5+1] = { //5文字+null文字
  "Black", //COLOR_BLACK =0
  "White" //COLOR_WHITE =1
};

int cells[BOARD_HEIGHT][BOARD_WIDTH];
int cursorX, cursorY;
int turn;

bool checkCanPut(int _color, int _x, int _y){
  return false;
}

int main(){
  for(int y = 0; y < BOARD_HEIGHT; y++){
    for(int x = 0; x < BOARD_WIDTH; x++)
      cells[y][x] = COLOR_NONE;
  }
  cells[3][3] = cells[4][4] = COLOR_WHITE;
  cells[4][3] = cells[3][4] = COLOR_BLACK;
  bool cantPut = false;

  while(1){
    system("clear");
    for(int y = 0; y < BOARD_HEIGHT; y++){
      for(int x = 0; x < BOARD_WIDTH; x++)
        if(x == cursorX && y == cursorY)
          printf("◎");
        else{
          switch(cells[y][x]){
            case COLOR_NONE:
              printf("•");
              break;
            case COLOR_BLACK:
              printf("●");
              break;
            case COLOR_WHITE:
              printf("○");
              break;
          }
        }
      printf("\n");
    }
    if(cantPut)
      printf("Can't put!\n");
    else
      printf("%s turn.\n", colorNames[turn]);
    
    cantPut = false;
    switch(getch()){
      case 'w':
        cursorY--;
        break;
      case 's':
        cursorY++;
        break;
      case 'a':
        cursorX--;
        break;
      case 'd':
        cursorX++;
        break;
      default:
        if(!checkCanPut(turn, cursorX, cursorY)){
          cantPut = true;
          break;
        }
        
        cells[cursorY][cursorX] = turn;
        turn ^=1; //xor ビット演算子
        break;
    }
  }
}