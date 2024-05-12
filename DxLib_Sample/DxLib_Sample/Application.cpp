/**
 * @file   : Application.cpp
 * @author : Shuhei Matsushima
 *
 * @belief : �A�v���P�[�V����
 */

#include <iostream>
#include "DxLib.h"
#include "Application.h"
#include "Vector3.h"
#include "MathUtil.h"

/**
 * ������
 */
bool
Application::tryInit()
{
    // �萔�̒�`
    const int WIDTH = 1200, HEIGHT = 720; // �E�B���h�E�̕��ƍ����̃s�N�Z����

    SetWindowText("����"); // �E�B���h�E�̃^�C�g��
    SetGraphMode(WIDTH, HEIGHT, 32); // �E�B���h�E�̑傫���ƃJ���[�r�b�g���̎w��
    ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ŋN��
    if (DxLib_Init() == -1) return false; // ���C�u���������� �G���[���N������I��
    SetBackgroundColor(0, 0, 0); // �w�i�F�̎w��
    SetDrawScreen(DX_SCREEN_BACK); // �`��ʂ𗠉�ʂɂ���

    mTimer = 0; // �o�ߎ��Ԃ𐔂���ϐ�

    // ����I��
    return true;
}

/**
 * ���s
 */
void 
Application::run()
{
    mTimer = 0; // �o�ߎ��Ԃ𐔂���ϐ�
    bool isUpdate = true;
    
    while (isUpdate) { isUpdate = update(); }

    DxLib_End(); // �c�w���C�u�����g�p�̏I������
}

/**
 * �X�V�̎葱��
 */
bool
Application::update()
{
    ClearDrawScreen(); // ��ʂ��N���A����

    mTimer++; // ���Ԃ̃J�E���g
    DrawFormatString(0, 0, GetColor(255, 255, 0), "%d", mTimer);

    Vector3 p1(0.0f, 0.5f, 0.0f);
    Vector3 p2(-0.5f, -0.5f, 0.0f);
    Vector3 p3(-0.50f, 0.5f, 0.0f);

    DrawFormatString(0, 30, GetColor(255, 255, 0), "%f", p1.y * (720.0f / 2.0f));

    // �X�V�̓�������
    calc(&p1, &p2, &p3);

    ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f������
    WaitTimer(16); // ��莞�ԑ҂�
    if (ProcessMessage() == -1) return false; // Windows��������󂯎��G���[���N������I��
    if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) return false; // ESC�L�[�������ꂽ��I��

    // ���s
    return true;
}

/**
 * �X�V�̓�������
 */
void
Application::calc(Vector3* p1, Vector3* p2, Vector3* p3)
{   
    // �萔�̒�`
    const float WIDTH = 1200.0f, HEIGHT = 720.0f; // �E�B���h�E�̕��ƍ����̃s�N�Z����
    
    // �O�p�`�̕`��
    DrawTriangle(
        p1->x * (WIDTH / 2.0f) + (WIDTH / 2.0f), p1->y * (HEIGHT / 2.0f),
        p2->x * (WIDTH / 2.0f) + (WIDTH / 2.0f), p2->y * (HEIGHT / 2.0f) + (HEIGHT / 2.0f),
        p3->x * (WIDTH / 2.0f) + (WIDTH / 2.0f), p3->y * (HEIGHT / 2.0f) + (HEIGHT / 2.0f),
        GetColor(255, 192, 0), 
        TRUE);

}