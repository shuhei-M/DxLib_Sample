/**
 * @file   : Application.cpp
 * @author : Shuhei Matsushima
 *
 * @belief : アプリケーション
 */

#include <iostream>
#include "DxLib.h"
#include "Application.h"
#include "Vector3.h"
#include "MathUtil.h"

/**
 * 初期化
 */
bool
Application::tryInit()
{
    // 定数の定義
    const int WIDTH = 1200, HEIGHT = 720; // ウィンドウの幅と高さのピクセル数

    SetWindowText("実験"); // ウィンドウのタイトル
    SetGraphMode(WIDTH, HEIGHT, 32); // ウィンドウの大きさとカラービット数の指定
    ChangeWindowMode(TRUE); // ウィンドウモードで起動
    if (DxLib_Init() == -1) return false; // ライブラリ初期化 エラーが起きたら終了
    SetBackgroundColor(0, 0, 0); // 背景色の指定
    SetDrawScreen(DX_SCREEN_BACK); // 描画面を裏画面にする

    mTimer = 0; // 経過時間を数える変数

    // 正常終了
    return true;
}

/**
 * 実行
 */
void 
Application::run()
{
    mTimer = 0; // 経過時間を数える変数
    bool isUpdate = true;
    
    while (isUpdate) { isUpdate = update(); }

    DxLib_End(); // ＤＸライブラリ使用の終了処理
}

/**
 * 更新の手続き
 */
bool
Application::update()
{
    ClearDrawScreen(); // 画面をクリアする

    mTimer++; // 時間のカウント
    DrawFormatString(0, 0, GetColor(255, 255, 0), "%d", mTimer);

    Vector3 p1(0.0f, 0.5f, 0.0f);
    Vector3 p2(-0.5f, -0.5f, 0.0f);
    Vector3 p3(-0.50f, 0.5f, 0.0f);

    DrawFormatString(0, 30, GetColor(255, 255, 0), "%f", p1.y * (720.0f / 2.0f));

    // 更新の内部処理
    calc(&p1, &p2, &p3);

    ScreenFlip(); // 裏画面の内容を表画面に反映させる
    WaitTimer(16); // 一定時間待つ
    if (ProcessMessage() == -1) return false; // Windowsから情報を受け取りエラーが起きたら終了
    if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) return false; // ESCキーが押されたら終了

    // 続行
    return true;
}

/**
 * 更新の内部処理
 */
void
Application::calc(Vector3* p1, Vector3* p2, Vector3* p3)
{   
    // 定数の定義
    const float WIDTH = 1200.0f, HEIGHT = 720.0f; // ウィンドウの幅と高さのピクセル数
    
    // 三角形の描画
    DrawTriangle(
        p1->x * (WIDTH / 2.0f) + (WIDTH / 2.0f), p1->y * (HEIGHT / 2.0f),
        p2->x * (WIDTH / 2.0f) + (WIDTH / 2.0f), p2->y * (HEIGHT / 2.0f) + (HEIGHT / 2.0f),
        p3->x * (WIDTH / 2.0f) + (WIDTH / 2.0f), p3->y * (HEIGHT / 2.0f) + (HEIGHT / 2.0f),
        GetColor(255, 192, 0), 
        TRUE);

}