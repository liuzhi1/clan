#include <stdio.h> // 标准输入输出 例如c语言中的 printf("%d",i); scanf("%d",&i);等函数
#include <conio.h> // 控制台输入输出  主要是一些用户通过按键盘产生的对应操作，接收键盘输入输出 
#include <windows.h> //控制dos界面（磁盘操作系统） 
#include <time.h>  //用于获得随机数

// N代表长，M代表宽，其它宏定义代表对应的特定物体的字符表示，以下所有都有字母代替便于修改 。 
#define N  20
#define M  65
#define food '0'
#define head '>'
#define body 'X'
#define Wall '*'
#define Empty ' '

/* 函数声明 */ 
int snake[1000][2] = {};   //二维数组，代表蛇每个点坐标的x, y (0代表 x, 1代表 y)。

char map[N][M] = {};   //地图大小。 

enum direction{ up, down, left, right } dir;   //枚举型定义方向, 同时定义全局变量 dir 代表蛇的方向。

int score;  //分数，吃了多少个食物。

int length;   //蛇的长度。 

int food_x, food_y;  //食物的位置。 

int HEAD_X, HEAD_Y; //蛇头的位置。 

void initial();  //初始化函数。

void creatFood();  //制造食物函数 

void ifkey();  //判断是否有按键行为，判断是否有转向。 

void printMap(); //输出整张地图面貌，包括蛇和食物。 

int move(); //蛇移动后的各个反应，如果死了就返回 0, 如果还活着，就返回 1。

void setoutputposition(); //特殊说明：这里不采用清屏函数， 采用直接覆盖原图的效果，同时隐藏光标。 

void over(); //游戏结束 


int main(){
    initial();
    while (1) {
        setoutputposition();
        ifkey();
        if (!move())
            break;
        printMap();
        Sleep(100);  //调速，数值越大速度越慢
    }
    over();
} 

//制造新食物 
void creatFood(){
    score++;
    //以当前时间作为随机数种子。 
    srand((unsigned)time(NULL)); 
    while (map[food_x][food_y] != Empty) {
        food_x = rand() % (N-1) + 1;
        food_y = rand() % (M-1) + 1;
    }
    map[food_x][food_y] = food;
} 

//初始化函数。 
void initial(){
    //两层for循环初始化地图。 
    int i, j; 
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++){
            if (i == 0 || j == 0 || i == N-1 || j == M-1)
                map[i][j] = Wall;
            else
                map[i][j] = Empty;
        }

    creatFood();

    score = 0;
    length = 2;

    snake[0][0] = 1, snake[0][1] = 1;
    snake[1][0] = 1, snake[1][1] = 2;
    map[1][1] = body, map[1][2] = head;
    HEAD_X = snake[1][0], HEAD_Y = snake[1][1]; 
    //初始化蛇的前两节身体，snake[1]是头，snake[0]是尾。

    dir = right; 
    //方向初始化为向右。 
} 

//判断是否有按键行为，判断是否有转向。 
void ifkey() {
    char k1, k2;
    if(kbhit() != 0){
        k1 = getch();
        if(k1 == -32){
            k2 = getch();
            if(k2 == 72 && dir != down)  dir = up;
            if(k2 == 80 && dir != up)    dir = down;
            if(k2 == 75 && dir != right) dir = left;
            if(k2 == 77 && dir != left)  dir = right;
        }
    }
}

//输出整张地图面貌，包括蛇和食物。 
void printMap() {
    printf("当前分数: %d\n", score); 
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
}

//蛇移动后的各个反应，如果死了就返回 0, 如果还活着，就返回 1。 
int move() {
    //记住，移动了一步，无论如何，原来的头的位置肯定变成了身体。
    map[HEAD_X][HEAD_Y] = body; 

    //由方向决定新的头的位置。 
    if(dir == up) HEAD_X--;
    else if(dir == down)  HEAD_X++;
    else if(dir == left)  HEAD_Y--;
    else if(dir == right) HEAD_Y++; 

    //吃到食物的话. 
    if(map[HEAD_X][HEAD_Y] == food) {
        length++;
        snake[length-1][0] = HEAD_X, snake[length-1][1] = HEAD_Y;
        map[HEAD_X][HEAD_Y] = head;
        creatFood(); 
        return 1; 
    }
    else {
        //没有吃到食物的话，原来尾巴的位置变为空格。 
        map[snake[0][0]][snake[0][1]] = Empty;

        if(map[HEAD_X][HEAD_Y] == Empty) { 
            int i;
            for(i = 0; i < length-1; i++) {
                snake[i][0] = snake[i+1][0];
                snake[i][1] = snake[i+1][1];
            }
            snake[length-1][0] = HEAD_X, snake[length-1][1] = HEAD_Y;
            map[HEAD_X][HEAD_Y] = head;
            return 1;
        } 

        return 0; 
    }
}

//这里使用了一些 window API，大致知道功能即可，可以忽略。 
void setoutputposition() {
    //设置光标位置为（ 0， 0 )。 
    COORD t = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), t);
    //隐藏光标。 
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//游戏结束 
void over(){
    system("cls"); //清屏函数。 
    printf("game over\n");
}
