#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int checkSpace(), checkMove();
void init(), print(), randNum(), up(), down(), left(), right(), error();

int num[4][4] = {0};
int /**num[][4] = {
    { 2, 4, 8,16},
    { 4, 8,16, 2},
    { 8,16, 2, 2},
    {16, 2, 4, 8}
    }, **/score = 0;
char ch;

int main(void) {
    while(1) {
        init();
        randNum();
        do {
            switch(ch) {
                case 'w':
                case '8': {
                     up(); break; }
                case 's':
                case '2': {
                     down(); break; }
                case 'a':
                case '4': {
                     left(); break; }
                case 'd':
                case '6': {
                     right(); break; }
                default:
                    continue;
            }
            printf("Input w a s d >>> ");
        } while((checkMove() != 0 || checkSpace() == 1) && (ch = getche()) != EOF);
        printf("Game Over\n");
        system("pause");
    }
    return 0;
}
int checkSpace() {
    int i, j;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            if(num[i][j] == 0) { return 1;}
        }
    }
    return 0;
};
int checkMove() {
     int i, j, ho = 0, fl = 0, result = 0;
     for(i = 0; i < 4; i++) {
           for(j = 0; j < 3; j++) {
                 if(num[i][j] == num[i][j + 1]) { 
                     ho = 1;
                     break;
                 }
           }
           if(ho == 1) { break; }
     }
     for(i = 0; i < 4; i++) {
           for(j = 0; j < 3; j++) {
                 if(num[j][i] == num[j + 1][i]) {
                     fl = 1;
                     break;
                 }
           }
           if(fl == 1) { break; }
     }
     result += ho == 0 ? 0 : 1;
     result += fl == 0 ? 0 : 2;
     return result;
};
void init() {
    score = 0;
    int i, j;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            num[i][j] = 0;
        }
    }
};
void print() {
     int i, j;
     system("cls");
     printf("¢z--------------------------¢{\n");
     printf("¢xScore: %19d¢x\n", score);
     printf("¢u--------------------------¢t\n");
     for(i = 0; i < 4; ++i) {
         for(j = 0; j < 4; ++j) {
             printf("¢x");
             if(num[i][j] != 0) {
                 printf("%5d", num[i][j]);
             } else {
                 printf("%4s ", "");
             }
         }
         printf("¢x\n");
         if(i != 3) printf("¢u-----¢q-----¢q-----¢q-----¢t\n");
     }
     printf("¢|--------------------------¢}\n");
};
void randNum() {
    if(checkSpace() == 0) { return; }
    printf("Randoming...");
    sleep(1000);
    srand((unsigned int) time(NULL));
    int i = rand() % 4, j = rand() % 4, k, index[] = {2, 4};
    while(num[i][j] != 0) {
        i = rand() % 4;
        j = rand() % 4;
    }
    num[i][j] = index[rand() % 2];
    print();
    return;
};
void up(){
     int result = checkMove(), buffScore = score, move = 0;
     if(result == 0 || result == 1 && checkSpace() == 0) { 
         error();
         return;
     }
     int i, j, k, l;
     for(i = 0; i < 4; i++) {
         for(j = 0; j < 3; j++) {
             for(k = j + 1; k < 4; k++) {
                 if(num[k][i] == 0) {
                    continue;
                 } else if(num[k][i] == num[j][i]) {
                    move = 1;
                    num[j][i] *= 2;
                    score += num[j][i];
                    num[k][i] = 0;
                    break;
                 } else {
                     break;
                 }
             }
         }
         for(j = 0; j < 3; j++) {
             if(num[j][i] != 0) { continue; }
             for(k = j + 1; k < 4; k++) {
                 if(num[k][i] != 0) {
                     move = 1;
                     num[j][i] = num[k][i];
                     num[k][i] = 0;
                     break;
                 }
             }
         }
     }
     print();
     //if((buffScore != score || buffScore == 0)) {// && move == 1) {
          randNum();
     //}
};
void down(){
     int result = checkMove(), buffScore = score, move = 0;;
     if(result == 0 || result == 1 && checkSpace() == 0) { 
         error();
         return;
     }
     int i, j, k, l;
     for(i = 3; i > -1; i--) {
         for(j = 3; j > 0; j--) {
             for(k = j - 1; k > -1; k--) {
                 if(num[k][i] == 0) {
                    continue;
                 } else if(num[k][i] == num[j][i]) {
                    move = 1;
                    num[j][i] *= 2;
                    score += num[j][i];
                    num[k][i] = 0;
                    break;
                 } else {
                     break;
                 }
             }
         }
         for(j = 3; j > 0; j--) {
             if(num[j][i] != 0) { continue; }
             for(k = j - 1; k > -1; k--) {
                   if(num[k][i] != 0) {
                       move = 1;
                       num[j][i] = num[k][i];
                       num[k][i] = 0;
                       break;
                   }
             }
         }
     }
     print();
     //if((buffScore != score || buffScore == 0)) {// && move == 1) {
          randNum();
     //}
};
void left(){
     int result = checkMove(), buffScore = score, move = 0;
     if(result == 0 || result == 2 && checkSpace() == 0) { 
         error();
         return;
     }
     int i, j, k, l;
     for(i = 0; i < 4; i++) {
         for(j = 0; j < 3; j++) {
             for(k = j + 1; k < 4; k++) {
                 if(num[i][k] == 0) {
                    continue;
                 } else if(num[i][k] == num[i][j]) {
                    move = 1;
                    num[i][j] *= 2;
                    score += num[i][j];
                    num[i][k] = 0;
                    break;
                 } else {
                     break;
                 }
             }
         }
         for(j = 0; j < 3; j++) {
             if(num[i][j] != 0) { continue; }
             for(k = j + 1; k < 4; k++) {
                 if(num[i][k] != 0) {
                     move = 1;
                     num[i][j] = num[i][k];
                     num[i][k] = 0;
                     break;
                 }
             }
         }
     }
     print();
     //if((buffScore != score || buffScore == 0)) {// && move == 1) {
          randNum();
     //}
};
void right(){
     int result = checkMove(), buffScore = score, move = 0;
     if(result == 0 || result == 2 && checkSpace() == 0) { 
         error();
         return;
     }
     int i, j, k, l;
     for(i = 3; i > -1; i--) {
         for(j = 3; j > 0; j--) {
             for(k = j - 1; k > -1; k--) {
                 if(num[i][k] == 0) {
                    continue;
                 } else if(num[i][k] == num[i][j]) {
                    move = 1;
                    num[i][j] *= 2;
                    score += num[i][j];
                    num[i][k] = 0;
                    break;
                 } else {
                     break;
                 }
             }
         }
         for(j = 3; j > 0; j--) {
             if(num[i][j] != 0) { continue; }
             for(k = j - 1; k > -1; k--) {
                   if(num[i][k] != 0) {
                       move = 1;
                       num[i][j] = num[i][k];
                       num[i][k] = 0;
                       break;
                   }
             }
         }
     }
     print();
     //if((buffScore != score || buffScore == 0)) {// && move == 1) {
          randNum();
     //}
};
void error() {
    printf("You can't move, maybe no space or incorrect directrion.\n");
    return;
};
