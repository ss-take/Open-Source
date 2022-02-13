/**
* レイドバトル→ポケモンを捕獲→願いの塊を投げ入れるを繰り返すスケッチ
*
* 初期条件は以下の通り
* 1. 願いの塊を投げ入れた巣穴の前にいること
* 2. 手持ちが1体のみのこと
* 3. Aボタン連打でレイドバトルで勝てるようにすること
* 4. ボックスが空のこと
*/
#include <auto_command_util.h>

// レイドバトルが終わるまでの時間
const int BATTLE_FINISH_SEC = 180;
//レイドバトルの回数
int raid_loop_times=35;

// 巣穴の前からひとりレイドを始め、レイドポケモンを倒し、捕まえる
void startRaidBattle(){
    // ひとりではじめる
    pushButton(Button::A, 1500);
    pushHatButton(Hat::DOWN, 500);
    // レイドバトル中はA連打
    for(int i=0; i<BATTLE_FINISH_SEC; i++){
        pushButton(Button::A, 500, 2);
    }
}

// レイドバトル後もしばらく続くAボタン連打の後の画面から、
// 巣穴の前の最初のポジションに戻す
void resetState(){
    tiltJoystick(0,0,0,0,100);
    pushButton(Button::B, 1000, 4);
    delay(1000);
    pushButton(Button::A, 1000, 2);
    pushButton(Button::B, 1000, 3);
}

//setupは必ず必要
void setup(){
    pushButton(Button::B, 500, 5);
}

//loopは必ず必要でexit(0)で終了可能
void loop(){
    for (int j = 0; j < raid_loop_times; j++){
        startRaidBattle();
        resetState();
    }

    exit(0);
}
