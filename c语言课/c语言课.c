#include <stdio.h> // ��׼������� ����c�����е� printf("%d",i); scanf("%d",&i);�Ⱥ���
#include <conio.h> // ����̨�������  ��Ҫ��һЩ�û�ͨ�������̲����Ķ�Ӧ���������ռ���������� 
#include <windows.h> //����dos���棨���̲���ϵͳ�� 
#include <time.h>  //���ڻ�������

// N������M����������궨������Ӧ���ض�������ַ���ʾ���������ж�����ĸ��������޸� �� 
#define N  20
#define M  65
#define food '0'
#define head '>'
#define body 'X'
#define Wall '*'
#define Empty ' '

/* �������� */ 
int snake[1000][2] = {};   //��ά���飬������ÿ���������x, y (0���� x, 1���� y)��

char map[N][M] = {};   //��ͼ��С�� 

enum direction{ up, down, left, right } dir;   //ö���Ͷ��巽��, ͬʱ����ȫ�ֱ��� dir �����ߵķ���

int score;  //���������˶��ٸ�ʳ�

int length;   //�ߵĳ��ȡ� 

int food_x, food_y;  //ʳ���λ�á� 

int HEAD_X, HEAD_Y; //��ͷ��λ�á� 

void initial();  //��ʼ��������

void creatFood();  //����ʳ�ﺯ�� 

void ifkey();  //�ж��Ƿ��а�����Ϊ���ж��Ƿ���ת�� 

void printMap(); //������ŵ�ͼ��ò�������ߺ�ʳ� 

int move(); //���ƶ���ĸ�����Ӧ��������˾ͷ��� 0, ��������ţ��ͷ��� 1��

void setoutputposition(); //����˵�������ﲻ�������������� ����ֱ�Ӹ���ԭͼ��Ч����ͬʱ���ع�ꡣ 

void over(); //��Ϸ���� 


int main(){
    initial();
    while (1) {
        setoutputposition();
        ifkey();
        if (!move())
            break;
        printMap();
        Sleep(100);  //���٣���ֵԽ���ٶ�Խ��
    }
    over();
} 

//������ʳ�� 
void creatFood(){
    score++;
    //�Ե�ǰʱ����Ϊ��������ӡ� 
    srand((unsigned)time(NULL)); 
    while (map[food_x][food_y] != Empty) {
        food_x = rand() % (N-1) + 1;
        food_y = rand() % (M-1) + 1;
    }
    map[food_x][food_y] = food;
} 

//��ʼ�������� 
void initial(){
    //����forѭ����ʼ����ͼ�� 
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
    //��ʼ���ߵ�ǰ�������壬snake[1]��ͷ��snake[0]��β��

    dir = right; 
    //�����ʼ��Ϊ���ҡ� 
} 

//�ж��Ƿ��а�����Ϊ���ж��Ƿ���ת�� 
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

//������ŵ�ͼ��ò�������ߺ�ʳ� 
void printMap() {
    printf("��ǰ����: %d\n", score); 
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
}

//���ƶ���ĸ�����Ӧ��������˾ͷ��� 0, ��������ţ��ͷ��� 1�� 
int move() {
    //��ס���ƶ���һ����������Σ�ԭ����ͷ��λ�ÿ϶���������塣
    map[HEAD_X][HEAD_Y] = body; 

    //�ɷ�������µ�ͷ��λ�á� 
    if(dir == up) HEAD_X--;
    else if(dir == down)  HEAD_X++;
    else if(dir == left)  HEAD_Y--;
    else if(dir == right) HEAD_Y++; 

    //�Ե�ʳ��Ļ�. 
    if(map[HEAD_X][HEAD_Y] == food) {
        length++;
        snake[length-1][0] = HEAD_X, snake[length-1][1] = HEAD_Y;
        map[HEAD_X][HEAD_Y] = head;
        creatFood(); 
        return 1; 
    }
    else {
        //û�гԵ�ʳ��Ļ���ԭ��β�͵�λ�ñ�Ϊ�ո� 
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

//����ʹ����һЩ window API������֪�����ܼ��ɣ����Ժ��ԡ� 
void setoutputposition() {
    //���ù��λ��Ϊ�� 0�� 0 )�� 
    COORD t = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), t);
    //���ع�ꡣ 
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//��Ϸ���� 
void over(){
    system("cls"); //���������� 
    printf("game over\n");
}
