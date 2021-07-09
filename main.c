#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>

void star(char arr[7][7]);
void print(char arr[7][7]);
void line(char arr[7][7], int n, int m, int l, int d);
void FindStar(char arr[7][7]);
void star2(char arr[50][50], int i, int j, char c);
void star3(char arr[50][50], int i, int j, char c);
void print2(char arr2[][50], int li, int co);
void coordinate(int cr1[][2], int cr2[][2],int n, int m, int l, int d, char c1, char c2, char arr[50][50]);
void coordinate2(int cr1[][2], int cr2[][2], int n, int m, int l, int d, char c1, char c2, char arr[50][50]);
void line2(char arr[50][50], int n, int m, int l, int d, int cr1[][2], int cr2[][2], char c1, char c2);
void printarr(int arr[][2], int rr, char c1);
int findstar2(char arr[50][50], char c, int li, int co);
int finish(char arr[50][50], int li, int co);
void result(int a, int b, char c1, char c2);
int maxi(int a, int b);
void getname();
void importfile(int li, int co, char arr2[50][50], int cr1[60][2], int cr2[60][2]);

int counter = 0;
int r = 0;
int r1 = 0;
int r2 = 0;
char ch1, ch2;
char c1[20], c2[20];

void main()
{
    int swi = 1;
    while(swi == 1){
    swi = 0;
    int a = 0;
    printf("1.tutorial\n2.two player game\n3.exit\n");
    scanf("%d", &a);
    while(a != 1 && a != 2 && a != 3){
        printf("wrong order!\nenter another:\n");
        scanf("%d", &a);
    }
    if(a == 1){
        int i, j;
        char arr[7][7];
        for(i = 0; i < 7; i++){
            for(j = 0; j < 7; j++){
                if(i % 2 == 0 && j % 2 == 0)arr[i][j]='.';
                else arr[i][j]=' ';
            }
        }
        print(arr);
        char z, y, w ,x;
    while(counter < 9) {
        printf("please enter 2 coordinate:\n");
        scanf(" %c", &z);
        scanf(" %c", &y);
        scanf(" %c", &w);
        scanf(" %c", &x);
        while(z < 48 || z > 57 || y < 48 || y > 57 || w < 48 || w > 57 || x < 48 || x > 57){
            printf("wrong order!enter another:\n");
            scanf(" %c %c %c %c", &z, &y, &w, &x);
        }
        int n = (int)(z - 48);
        int m = (int)(y - 48);
        int l = (int)(w - 48);
        int d = (int)(x - 48);
    while(n > 7 || m > 7 || d > 7 || d > 7 ){
            printf("wrong coordinate! enter another coordinate:\n");
            scanf("%d%d%d%d", &n, &m, &l, &d);
        }
        line(arr, n, m, l, d);
        star(arr);
        system("@cls||clear");
        print(arr);
        FindStar(arr);
        }
        printf("finish!");
    }

    else if(a == 2){
        int cr1[60][2];
        int cr2[60][2];
        getname();
        char z[3], y[3], w[3], x[3];
        int co, li;
        printf("enter numbers of boxes:\n");
        scanf("%d%d", &li, &co);
        system("@cls||clear");
        li = 2 * li + 1;
        co = 2 * co + 1;
        char arr2[50][50];
        for(int i = 0; i < li; i++){
            for(int j = 0; j < co; j++){
                if(i % 2 == 0 && j % 2 == 0)arr2[i][j]='.';
                else arr2[i][j]=' ';
            }
        }
        print2(arr2, li, co);
        int a, b;
        while(finish(arr2, li, co)) {
            if(r % 2 == 0){
                printf("please enter 2 coordinate(player %c):\n", ch1);
            }
            else if(r % 2 == 1){
                printf("please enter 2 coordinate(player %c):\n", ch2);
            }
        scanf(" %s", z);
        if(z[0] == 'p'){
            importfile(li, co, arr2, cr1, cr2);
            system("@cls||clear");
            printf("1.continue\n2.rematch\n3.restart\n4.quit to main menu\n5.exit\n");
            int s;
            scanf("%d", &s);
            if(s == 1){
                print2(arr2, li, co);
            }
            else if(s == 2){
                r1 = 0;
                r2 = 0;
                if(r % 2 == 1)r++;
                for(int i = 0; i < li; i++){
                    for(int j = 0; j < co; j++){
                        if(i % 2 == 0 && j % 2 == 0)arr2[i][j]='.';
                        else arr2[i][j]=' ';
                    }
                }
                system("@cls||clear");
                print2(arr2, li, co);
            }
            else if(s == 3){
                getname();
                r1 = 0;
                r2 = 0;
                if(r % 2 == 1)r++;
                printf("enter numbers of boxes:\n");
                scanf("%d%d", &li, &co);
                li = 2 * li + 1;
                co = 2 * co + 1;
                for(int i = 0; i < li; i++){
                    for(int j = 0; j < co; j++){
                        if(i % 2 == 0 && j % 2 == 0)arr2[i][j]='.';
                        else arr2[i][j]=' ';
                    }
                }
                print2(arr2, li, co);
            }
            else if(s == 4){
                swi = 1;
                system("@cls||clear");
                break;
            }
            else if(s == 5)exit(1);
        }
        else{
            scanf(" %s", y);
            scanf(" %s", w);
            scanf(" %s", x);
            int p = 0;
            while(myatoi(z) == -1 || myatoi(y) == -1 || myatoi(w) == -1 || myatoi(x) == -1){
                printf("wrong order!enter another:\n");
                scanf(" %s", &z);
                if(z[0] == 'p'){
                    p = 1;
                    break;
                }
                else scanf(" %s %s %s", y, w, x);
            }
            if(!p){
            int n = myatoi(z);
            int m = myatoi(y);
            int l = myatoi(w);
            int d = myatoi(x);
            while(n > li || m > co || l > li || d > co){
                printf("wrong coordinate! enter another coordinate:\n");
                scanf("%d%d%d%d", &n, &m, &l, &d);
            }
            line2( arr2, n, m, l, d,cr1, cr2, ch1,ch2);
            Sleep(1000);
            system("@cls||clear");
            print2(arr2, li, co);
            a = findstar2(arr2, ch1, li, co);
            b = findstar2(arr2, ch2, li, co);
            printarr(cr1, r1, ch1);
            printarr(cr2, r2, ch2);
            }
        }
        }
        result(a, b, ch1, ch2);
        printf("finish!\n");
        importfile(li, co, arr2, cr1, cr2);
    }
    else if(a == 3)exit(1);
    }
}


void star(char arr[7][7])
{
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++){
            if(arr[i][j] == '_'){
                if(arr[i + 1][j + 1] == '|'){
                    if(arr[i + 2][j] == '_'){
                        if(arr[i + 1][j - 1] == '|'){
                            arr[i + 1][j] = '*';
                        }
                    }
                }
            }
        }
}
void line(char arr[7][7], int n, int m, int l, int d)
{

    if(n == l && abs(d-m) == 2 && n % 2 == 0 && m % 2 == 0){

        arr[n][(d + m)/2]='_';
    }
    else if(m == d && abs(l - n) == 2){
        arr[(l + n)/2][m] = '|';
    }
    else{
        printf("wrong coordinate. enter another coordinate:\n");
    }
}
void print(char arr[7][7])
{
    printf(" 0 1 2 3 4 5 6\n");
    for(int i = 0; i < 7; i++)
        {
        printf("%d%c %c %c %c %c %c %c\n",i, arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], arr[i][5], arr[i][6]);
        }
}
void FindStar(char arr[7][7])
{
    counter = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            if(arr[i][j] == '*') counter++;
        }
    }
}
void print2(char arr2[][50], int li, int co)
{
    if(co < 10){
        printf("   ");
        for(int i = 0; i < co; i++)
            if(i % 2 == 0)printf("%d   ", i);
        printf("\n");
    }
    else {
        printf("   ");
        for(int i = 0; i < 10; i++)
            if(i % 2 == 0)printf("%d   ", i);
        for(int i = 10; i < co; i++)
            if(i % 2 == 0)printf("%d  ", i);
        printf("\n");
    }
    for(int i = 0; i < li; i++)
        {
        if(i % 2 == 0)printf("%2d ",i);
        else printf("   ");
        for(int j = 0; j < co; j++){
            printf("%c ", arr2[i][j]);
        }
        printf("\n");
        }
}
void line2(char arr[50][50], int n, int m, int l, int d, int cr1[][2], int cr2[][2], char c1, char c2)
{

    if(n == l && abs(d-m) == 2 && n % 2 == 0 && m % 2 == 0){
        if(arr[n][(d + m)/2] == '_')printf("The coordinates are already entered!");
        else
            {
            arr[n][(d + m)/2]='_';

            coordinate(cr1, cr2, n, m, l, d, c1, c2, arr);
            r++;
        }
    }
    else if(m == d && abs(l - n) == 2 && m % 2 == 0 && l % 2 == 0){
        if(arr[(l + n)/2][m] == '|')printf("The coordinates are already entered!");
        else
            {
            arr[(l + n)/2][m] = '|';
            coordinate2(cr1, cr2, n, m, l, d, c1, c2, arr);
            r++;
        }
    }
    else{
        printf("wrong coordinate.\n");
    }
}
void coordinate(int cr1[][2], int cr2[][2],int n, int m, int l, int d, char c1, char c2, char arr[50][50])
{
    if(r % 2 == 0){
        cr1[r1][0] = n;
        cr1[r1][1] = (d + m)/2;
        r1++;
        star2(arr, n, (d + m)/2, c1);
    }
    else if(r % 2 == 1){
        cr2[r2][0] = n;
        cr2[r2][1] = (d + m)/2;
        r2++;
        star2(arr, n, (d + m)/2, c2);
    }
}
void coordinate2(int cr1[][2], int cr2[][2], int n, int m, int l, int d, char c1, char c2, char arr[50][50])
{
    if(r % 2 == 0){
        cr1[r1][0] = (l + n)/2;
        cr1[r1][1] = m;
        r1++;
        star3(arr, (l + n)/2, m, c1);
    }
    else if(r % 2 == 1){
        cr2[r2][0] = (l + n)/2;
        cr2[r2][1] = m;
        r2++;
        star3(arr, (l + n)/2, m, c2);
    }
}
void printarr(int arr[][2], int rr, char c1)
{
    printf("coordinate entered by player %c:\n", c1);
    for(int i = 0; i < rr ; i++){
            printf("(%d,%d) ",arr[i][0], arr[i][1]);
        }
    printf("\n");
}
void star2(char arr[50][50], int i, int j, char c)
{
    if(arr[i - 1][j -1] == '|' && arr[i - 1][j + 1] == '|' && arr[i - 2][j] == '_'){
        arr[i - 1][j] = c;
    }
    if(arr[i + 1][j - 1] == '|' && arr[i + 1][j + 1] == '|' && arr[i + 2][j] == '_'){
        arr[i + 1][j] = c;
    }
}
void star3(char arr[50][50], int i, int j, char c)
{
    if(arr[i + 1][j - 1] == '_' && arr[i - 1][j - 1] == '_' && arr[i][j - 2] == '|'){
        arr[i][j - 1] = c;
    }
    if(arr[i - 1][j + 1] == '_' && arr[i + 1][j + 1] == '_' && arr[i][j + 2] == '|'){
        arr[i][j + 1] = c;
    }
}
int findstar2(char arr[50][50], char c, int li, int co)
{
    counter = 0;
    for(int i = 0; i < li; i++){
        for(int j = 0; j < co; j++){
            if(arr[i][j] == c){
                counter++;
            }
        }
    }
    printf("score of player %c is %d\n", c, counter);
    return(counter);
}
int finish(char arr[50][50], int li, int co)
{
    for(int i = 0; i < li; i++){
        for(int j = 0; j < co; j++){
            if(arr[i][j] == ' ') return 1;
        }
    }
    return 0;
}
void result(int a, int b, char c1, char c2)
{
    if(a > b){
        printf("player %c won!\n", c1);
    }
    else if(b > a){
        printf("player %c won!\n", c2);
    }
    else printf("Two players scored equal points!\n");
}
int maxi(int a, int b)
{
    if(a > b)return(a);
    else return(b);
}
void getname()
{
     int sw = 1;
        printf("please enter your name player 1:\n");
        gets(c1);
        gets(c1);
        printf("please enter your name player 2:\n");
        gets(c2);
        while(sw == 1){
        for(int i = 0; i < maxi(strlen(c1), strlen(c2)) ; i++){
            if(c1[i] != c2[i]){
                if(c1[i] == ' ' || c2[i] == ' ')continue;
                ch1 = c1[i];
                ch2 = c2[i];
                sw = 0;
                break;
            }
        }
           if(sw == 1){ printf("similar name! please enter another name:\n");
            scanf(" %s", &c2);
           }
        }
        if(ch1 == NULL)ch1 = c1[strlen(c1) - 1];
        if(ch2 == NULL)ch2 = c2[strlen(c1) - 1];
        printf("%c stands for %s and %c stands for %s\n", ch1, c1, ch2, c2);
}
void importfile(int li, int co, char arr2[50][50], int cr1[60][2], int cr2[60][2])
{
    FILE *input;
    input = fopen("result.txt","wt");
    fprintf(input, "player 1 is %s and player 2 is %s\n", c1, c2);
    for(int i = 0; i < li; i++){
        for(int j = 0; j < co; j++){
            fprintf(input,"%c", arr2[i][j]);
        }
        fprintf(input,"\n");
    }
    fprintf(input, "coordinate entered by player %c:\n", ch1);
    for(int i = 0; i < r1 ; i++){
            fprintf(input, "(%d,%d) ",cr1[i][0], cr1[i][1]);
        }
    fprintf(input, "\n");
    fprintf(input, "coordinate entered by player %c:\n", ch2);
    for(int i = 0; i < r2 ; i++){
            fprintf(input, "(%d,%d) ",cr2[i][0], cr2[i][1]);
        }
    fprintf(input, "\n");
    int counter2 = 0;
    for(int i = 0; i < li; i++){
        for(int j = 0; j < co; j++){
            if(arr2[i][j] == ch1){
                counter2++;
            }
        }
    }

    fprintf(input,"score of player %c is %d\n", ch1, counter2);
    int counter3 = 0;
    for(int i = 0; i < li; i++){
        for(int j = 0; j < co; j++){
            if(arr2[i][j] == ch2){
                counter3++;
            }
        }
    }
    fprintf(input,"score of player %c is %d\n", ch2, counter3);
    if(counter2 > counter3)fprintf(input,"player %c won!",ch1);
    else if(counter3 > counter2)fprintf(input,"player %c won!",ch2);
    else fprintf(input,"score of players are equal!");
    fclose(input);
}
int myatoi(char * s)
{
  int rv=-1;
  char sign = 0;

     // skip till we find either a digit or '+' or '-'
     while (*s) {
	if (*s <= '9' && *s >= '0')
		break;
	if (*s == '-' || *s == '+')
		break;
	s++;
     }

     if(*s == '-')sign=1;

     sign = (*s == '-');
     if (*s == '-' || *s == '+') s++;

     while (*s && *s >= '0' && *s <= '9') {
        if(rv == -1){
            rv = 0;
        }
        rv = (rv * 10) + ((int)(*s) - '0');
        s++;
     }

    if(sign)return (-rv);
    if(!sign)return (rv);
}
