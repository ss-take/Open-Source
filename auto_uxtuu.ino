/**
 * 単一の素材でウッウロボ合成
 * ワット掘りにも転用可能

 * 初期条件
 * （０．ヒートスタンプの所持数をを７４９個以下にする）
 * １．クラボのみをMAXまで買う
 * ２．ウッウロボで選択をクラボのみに合わせる（一度合成することを推奨）
 * ３．leonardを接続
 * 
ひたすらAを押す
ウッウロボに必要なのが248セット(1セット14回)
4  500
delay 1000
6 500
delay 1000
1 500
delay 3000
2 500
*/
#include <auto_command_util.h>

void pushA(){
    pushButton(Button::A, 500, 3);
    delay(1000);
    pushButton(Button::A, 500, 1);
    delay(1000);
    pushButton(Button::A, 500, 4);
    delay(1500);
    pushButton(Button::A, 1500, 3);
    delay(3000);
    pushButton(Button::A, 500, 1);
    delay(6000);
    pushButton(Button::A, 500, 2);
    delay(1000);
}

//setupは必ず必要
void setup(){
    pushButton(Button::B, 500, 5);
}

//loopは必ず必要でexit(0)で終了可能
void loop(){
    for (int j = 0; j < 248; j++){
        pushA();
    }

    exit(0);
}
