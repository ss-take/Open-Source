/**
 * 初期条件
 * １．ポケモンHOMEの逃がすポケモンが入ったボックスを開く
 * ２．操作を通常（モンスターボールマーク）にZR（ZL）で合わせる
 * 
 * A↑＊２A  [「↓A」「（→＋A）＊５」]    [「↓A」「（←＋A）＊５」]    [「↓A」「→」]   [「↓A」「←」]   [「↓A」「→」]   ＋    ↑AA  
 */


#include <auto_command_util.h>

//  define
void DownA(){
    pushHatButton(Hat::DOWN, 500);
    pushButton(Button::A, 500);
}

void RightA5(){
    for (int i = 0; i < 5; i++){
        pushHatButton(Hat::RIGHT, 500);
        pushButton(Button::A, 500);
    }
}

void LeftA5(){
    for (int i = 0; i < 5; i++){
        pushHatButton(Hat::LEFT, 500);
        pushButton(Button::A, 500);
    }
}

void RightSet(){
    DownA();
    RightA5();
}

void LeftSet(){
    DownA();
    LeftA5();
}

void setup(){
    pushButton(Button::B, 500, 5);
}

void loop(){
    pushButton(Button::A, 500);
    pushHatButton(Hat::UP, 500, 2);
    pushButton(Button::A, 1000);
    RightSet();
    LeftSet();
    RightSet();
    LeftSet();
    RightSet();
    pushButton(Button::PLUS, 1000);
    pushHatButton(Hat::UP, 500);
    pushButton(Button::A, 1000, 2);

    exit(0);
}