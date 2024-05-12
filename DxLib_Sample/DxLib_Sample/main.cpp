/**
 * @file   : main.cpp
 * @author : Shuhei Matsushima
 * 
 * @belief : メイン部
 */

#include "DxLib.h"
#include "Application.h"

/**
 *
 */

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    
    Application app;

    if (!app.tryInit()) return -1;
    app.run();

    return 0; // ソフトの終了
}