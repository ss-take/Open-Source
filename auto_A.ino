/**
ひたすらAを押す
*/
#include <auto_command_util.h>

//0.5秒ごとにAボタン連打
void pushA(){
    pushButton(Button::A, 500, 1)
}

//繰り返し回数の設定
int looptimes=4800;

//setupは必ず必要
void setup(){
    pushButton(Button::B, 500, 5);
}

//loopは必ず必要でexit(0)で終了可能
void loop(){
    for (int j = 0; j < looptimes; j++){
        pushA();
    }

    exit(0);
}
