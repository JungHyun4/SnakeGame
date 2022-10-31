#include <ncurses.h>

//g++ -std=c++11 -o run snake.cpp -lncursesw <===for complie
class snake{
  public:
    int snk[100][2]={{12,12},{12,13},{12,14},{12,15}}; //snake array
    int snk1[2]={}; //snake array 
    int dirt_x = 1, dirt_y = 0;   //moving direction
    int size=4;     //snake size
    
    int cnt_Growth = 0;
    int cnt_Poison = 0;
    int cnt_Gate = 0;
  
  snake(int size = 4, int dirt_x = 1, int dirt_y = 0) : size(size), dirt_x(dirt_x), dirt_y(dirt_y){}
  void move_snk(){
      snk1[0] = snk[size-1][0];
      snk1[1] = snk[size-1][1];
      for(int j=1;j<size;j++){
          if(snk[0][0]==snk[j][0] && snk[0][1]==snk[j][1]) throw 32;
      }
    for(int i=size-1;i>=0;i--){
      if(i==0){
        snk[i][0]+=dirt_x;
        snk[i][1]+=dirt_y;
      }
      else{
        snk[i][0]=snk[i-1][0];
        snk[i][1]=snk[i-1][1];
      }
    }
  }
  void get_dirt(){
    nodelay(stdscr, true);
    char direction = getch();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    switch (direction) {
      case ERR:
        break;
      case 'w':
        if(dirt_y==1){throw 2;}
        dirt_y=-1;
        dirt_x=0;
        break;
      case 's':
        if(dirt_y==-1){throw 2;}
        dirt_y=1;
        dirt_x=0;
        break;
      case 'a':
        if(dirt_x==1){throw 2;}
        dirt_y=0;
        dirt_x=-1;
        break;
      case 'd':
        if(dirt_x==-1){throw 2;}
        dirt_y=0;
        dirt_x=1;
        break;
    }
  }
};