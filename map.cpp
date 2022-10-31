#include <ncurses.h>
#include <unistd.h>
#include <cmath>
#include <string>
#include <cstring>
#include "snake.cpp"
#include "mission.cpp"

using namespace std;

class Map{
    public:
    bool gameover;
    int stageLevel = 0;
    int** map;   
    int board[2][23][23] = 
    {

        {{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}}

        ,

    
        {{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}}
        
    
    };
    Map(int stage){
        gameover = false;
        int len = 23;
        map = new int*[23];
        for(int i=0; i< len; i++){
            map[i] = new int[len];
        }
        for(int i=0; i<len; i++)
            for(int j=0; j<len ; j++){
                map[i][j] = board[stage][i][j];
            }
    }



    void get_set_snake(snake &s) {
        
        int x = s.snk1[0];
        int y = s.snk1[1];
        map[y][x] = 0;
        
        for(int i=0; i<s.size ; i++){   
            if(i == 0 ){
                int x = s.snk[i][0];
                int y = s.snk[i][1];
                map[y][x] = 3;
            }
            else {
                int x = s.snk[i][0];
                int y = s.snk[i][1];
                map[y][x] = 4;
            }
        }
    }

    void make_item(int times) {
        if (times % 90 == 0) {
            for(int i=0 ; i< 23; i++){
                for(int j=0; j<23;j++) {
                    if(map[i][j] == 5 or map[i][j] == 6)
                        map[i][j] = 0;
                }
            }

            bool item_on_map = false;
            while (!item_on_map) {
                int grow_X = rand() % (23 - 2) + 1;
                int grow_Y = rand() % (23 - 2) + 1;
                int poison_X = rand() % (23 - 2) + 1;
                int poison_Y = rand() % (23 - 2) + 1;

                if (grow_X == poison_X && grow_Y == poison_Y)
                    continue;
                if (map[grow_Y][grow_X] == 0 && map[poison_Y][poison_X] == 0) {
                    map[grow_Y][grow_X] = 5;
                    map[poison_Y][poison_X] = 6;
                    item_on_map = true;
                }
            }
        }
    }

    void change_snake(snake &s) {
        int head_y = s.snk[0][1];
        int head_x = s.snk[0][0];

        int tail_front_y = s.snk[s.size - 2][1];
        int tail_front_x = s.snk[s.size - 2][0];
        int& tail_y = s.snk[s.size-1][1];
        int& tail_x = s.snk[s.size-1][0];

        int dir_y = tail_y - tail_front_y;
        int dir_x = tail_x - tail_front_x;

        if(map[head_y][head_x] == 5) {
            s.snk[s.size][1] = tail_y + dir_y;
            s.snk[s.size][0] = tail_x + dir_x;
            s.size++;
            s.cnt_Growth++;
        }
        else if(map[head_y][head_x] == 6) {
            map[tail_y][tail_x] = 0;
            s.size--;
            s.cnt_Poison++;
            if(s.size < 3) throw 32;
        }
    }

    void makeGate(int time, int gateCode) {
        if(time % 140 == 0 && gateCode == 0)
        {
            for(int i=0 ; i< 23; i++){
                for(int j=0; j<23;j++) {
                    if(map[i][j] == 7) {
                        map[i][j]=1;
                    }
                }
            }
            bool is_gate_on = false;

            while (!is_gate_on) {
                int gate_aX = rand() % (23);
                int gate_aY = rand() % (23);
                int gate_bX = rand() % (23);
                int gate_bY = rand() % (23);

                if (gate_aX == gate_bX && gate_aY == gate_bY)
                    continue;
                if (map[gate_aY][gate_aX] == 1 && map[gate_bY][gate_bX] == 1) {
                    is_gate_on = true;
                    map[gate_aY][gate_aX] = 7;
                    map[gate_bY][gate_bX] = 7;
                }
            }
        }
    }

    bool is_snake_in_gate(snake &s, int& gateCode) {
        int head_y = s.snk[0][1];
        int head_x = s.snk[0][0];
        if(map[head_y][head_x] == 7 or gateCode > 0) {
            if(gateCode == 0)
                gateCode = s.size;
            else if(gateCode > 0)
                gateCode--;
            return true;
        }
        return false;
    }

    void warp_direction(int y, int x, int& y_dir, int& x_dir) {
        if(y == 22) {
            y_dir = -1;
            x_dir = 0;
        }
        else if(x == 0) {
            y_dir = 0;
            x_dir = 1;
        }
        else if(y == 0) {
            y_dir = 1;
            x_dir = 0;
        }
        else if(x == 22) {
            y_dir = 0;
            x_dir = -1;
        }
    }

    void warp_by_gate(snake &s, int gateCode) {
        if(gateCode == s.size) {
            s.cnt_Gate++;
            int y = s.snk[0][1];
            int x = s.snk[0][0];
            int other_gate_y, other_gate_x;
            int y_dir, x_dir;

            for(int i=0; i<23; i++)
                for(int j=0; j<23; j++) {
                    if(map[i][j] == 7 && (i != y or j != x)) {
                        other_gate_y = i;
                        other_gate_x = j;
                    }
                }

            warp_direction(other_gate_y, other_gate_x, y_dir, x_dir);
            s.dirt_y = y_dir;
            s.dirt_x = x_dir;
            s.snk[0][1] = other_gate_y + y_dir;
            s.snk[0][0] = other_gate_x + x_dir;
        }
    }
};


void draw(int** map,WINDOW *a){
    for(int i=0 ; i< 23; i++){
        for(int j=0; j<23;j++){
            if(map[i][j] == 0) {
                wattron(a, COLOR_PAIR(0));
                mvwprintw(a, i, j, " ");
                wattroff(a, COLOR_PAIR(0));
            }
            else if(map[i][j] == 1) {
                wattron(a, COLOR_PAIR(1));
                mvwprintw(a, i, j, "1");
                wattroff(a, COLOR_PAIR(1));
            }
            else if(map[i][j] == 2) {
                wattron(a, COLOR_PAIR(2));
                mvwprintw(a, i, j, "2");
                wattroff(a, COLOR_PAIR(2));
            }
            else if(map[i][j] == 3) {
                wattron(a, COLOR_PAIR(3));
                mvwprintw(a, i, j, "H");
                wattroff(a, COLOR_PAIR(3));
            }
            else if(map[i][j] == 4) {
                wattron(a, COLOR_PAIR(4));
                mvwprintw(a, i, j, "T");
                wattroff(a, COLOR_PAIR(4));
            }
            else if(map[i][j] == 5) {
                wattron(a, COLOR_PAIR(5));
                mvwprintw(a, i, j, "G");
                wattroff(a, COLOR_PAIR(5));
            }
            else if(map[i][j] == 6) {
                wattron(a, COLOR_PAIR(6));
                mvwprintw(a, i, j, "P");
                wattroff(a, COLOR_PAIR(6));
            }
            else if(map[i][j] == 7) {
                wattron(a, COLOR_PAIR(7));
                mvwprintw(a, i, j, "@");
                wattroff(a, COLOR_PAIR(7));
            }
        }
    }
}

void updateScore(snake &s ,WINDOW *a){
    // window로 전해줄 *char들 
    char Growth[20];
    char Poison[20];
    char Gate[20];
    char score[20];
    // snake 객체에 있는 값들을 window로 반영해줌.
    string sco = "score : " + to_string(s.size);
    strcpy(score, sco.c_str());
    string Grow = "+ : " + to_string(s.cnt_Growth);
    strcpy(Growth, Grow.c_str());
    string poi = "- : " + to_string(s.cnt_Poison);
    strcpy(Poison, poi.c_str());
    string Gat = "G : " + to_string(s.cnt_Gate);
    strcpy(Gate, Gat.c_str());

    mvwprintw(a ,3,5,score);
    mvwprintw(a ,4,5,Growth);
    mvwprintw(a ,5,5,Poison);
    mvwprintw(a ,6,5,Gate);
}


void updateMission(snake &s , WINDOW *w, mission &m){
    // window로 전해줄 *char들 
    char Growth[20]; 
    char Poison[20];
    char Gate[20];
    char score[20];

    // mission 객체의 목표와 실제 snake의 값 비교. 일치하면 v표시해줌 else문은 불일치 하는 경우로, v표 하지 않고 비워둠.
    static bool size_clear = false;
    static bool grow_clear = false;
    static bool poison_clear = false;
    static bool gate_clear = false;

    if(m.m_list[m.stage][0] <= s.size){
        string sco = "score : " + to_string(m.m_list[m.stage][0]) + "(v)";
        strcpy(score, sco.c_str());
        size_clear = true;
    }
    else{
        string sco = "score : " + to_string(m.m_list[m.stage][0]) + "( )";
        strcpy(score, sco.c_str());
        size_clear = false;
    }
    if(m.m_list[m.stage][1] <= s.cnt_Growth){
        string Grow = "+ : " + to_string(m.m_list[m.stage][1]) + "(v)";
        strcpy(Growth, Grow.c_str());
        grow_clear = true;
    }
    else{
        string Grow = "+ : " + to_string(m.m_list[m.stage][1]) + "( )";
        strcpy(Growth, Grow.c_str());
        grow_clear = false;
    }
    if(m.m_list[m.stage][2] <= s.cnt_Poison){
        string Pois = "- : " + to_string(m.m_list[m.stage][2]) + "(v)";
        strcpy(Poison, Pois.c_str());
        poison_clear = true;
    }
    else{
        string Pois = "- : " + to_string(m.m_list[m.stage][2]) + "( )";
        strcpy(Poison, Pois.c_str());
        poison_clear = false;
    }
    if(m.m_list[m.stage][3] <= s.cnt_Gate){
        string Gat = "G : " + to_string(m.m_list[m.stage][3]) + "(v)";
        strcpy(Gate, Gat.c_str());
        gate_clear = true;
    }
    else{
        string Gat = "G : " + to_string(m.m_list[m.stage][3]) + "( )";
        strcpy(Gate, Gat.c_str());
        gate_clear = false;
    }
    // 실제 윈도우에 반영 이후 wrefresh 해주면 실제로 변경.
    mvwprintw(w ,3,5,score);
    mvwprintw(w ,4,5,Growth);
    mvwprintw(w ,5,5,Poison);
    mvwprintw(w ,6,5,Gate);

    if(size_clear and grow_clear and poison_clear and grow_clear) throw 'c';
}

void is_crashed(int** map) {
    for(int i=0; i<23; i++) {
        for(int j=0; j<23; j++) {
            if(map[i][j] == 3) {
                if(i == 0 or i == 22 or j == 0 or j == 22)
                    throw 23;
            }
        }
    }
}

int main(){
    
    WINDOW *win_game;
    WINDOW *win_scoreboard;
    WINDOW *win_mission;
    keypad(stdscr,TRUE);
    curs_set(0);
    initscr();
    noecho();


    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK); // empty
    init_pair(1, COLOR_YELLOW, COLOR_WHITE); // wall
    init_pair(2, COLOR_YELLOW, COLOR_WHITE); // immune wall
    init_pair(3, COLOR_CYAN, COLOR_CYAN); // Head
    init_pair(4, COLOR_BLUE, COLOR_BLUE); // Body
    init_pair(5,COLOR_BLACK,COLOR_GREEN); // Grow
    init_pair(6,COLOR_CYAN,COLOR_RED); // Poison
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK); // Gate

 
    border('@','@','@','@' ,'@','@','@','@');
    attron(COLOR_PAIR(1));
    mvprintw(1,1,"snake game");
    attroff(COLOR_PAIR(1));
    refresh();
    
    //setting gamewindow
    win_game = newwin(25,25,10,10);

    //setting scoreboard
    win_scoreboard = newwin(10,20,10,44);
    mvwprintw(win_scoreboard , 1,1 , "scoreboard");
    wborder(win_scoreboard, '*','*','*','*','*','*','*','*');

    //setting missionboard
    win_mission = newwin(10,20,25,44);
    mvwprintw(win_mission , 1,1 , "missionboard");
    wborder(win_mission, '*','*','*','*' ,'*','*','*','*');





    snake s;
    Map m(0);
    mission mis;
    draw(m.map,win_game);
    wrefresh(win_mission);
    wrefresh(win_scoreboard);
    wrefresh(win_game);
    nodelay(stdscr,TRUE);
    try{
        int get_time = 0;
        int sleep_time = 250000;
        int gateCode = 0;
        while(!m.gameover){
            m.make_item(get_time);
            m.makeGate(get_time, gateCode);
            s.get_dirt();
            s.move_snk();
            m.is_snake_in_gate(s, gateCode);
            m.warp_by_gate(s, gateCode);
            m.change_snake(s);
            m.get_set_snake(s);

            updateScore(s , win_scoreboard);
            updateMission(s ,  win_mission ,mis );
            is_crashed(m.map);
            draw(m.map,win_game);

            wrefresh(win_mission);
            wrefresh(win_scoreboard);
            wrefresh(win_game);
            get_time += sleep_time / 100000;
            usleep(sleep_time);
        }
    }
    catch(char){
        nodelay(stdscr,false);
        clear();
        mvprintw(5,1,"You Clear!");
        refresh();
        getch();
    }
    catch(...){
        nodelay(stdscr,false);
        clear();
        mvprintw(5,1,"You failed");
        refresh();
    }
    getch();
    endwin();
    return 0;
}

