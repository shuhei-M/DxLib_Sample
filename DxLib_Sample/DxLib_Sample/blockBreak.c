#include<stdio.h>
#include<conio.h>
#include<windows.h> // Sleep()���g������
#define ROW 24 // �Q�[����ʂ̍s��
#define COL 60 // �Q�[����ʂ̗�
#define BLOCK_ROW 5 // �u���b�N���c�ɂ������Ԃ�
#define BLOCK_COL 10 // �u���b�N�����ɂ������Ԃ�

int block[BLOCK_ROW][BLOCK_COL]; // �u���b�N�̗L�����Ǘ�����z��
int px = COL / 2 - 3, py = ROW - 1; // �o�[�i�p�h���j�̍��W
int bx = 6, by = 10; // �{�[���̍��W
int vx = 1, vy = -1; // �{�[���̈ړ���
int score = 0; // �X�R�A
int game = 0; // �v���C����0�A�Q�[���I�[�o�[��1�A�Q�[���N���A��2

int main(void) {
    int x, y;
    for (y = 0; y < BLOCK_ROW; y++) { // �u���b�N�̏�����
        for (x = 0; x < BLOCK_COL; x++) block[y][x] = 1;
    }
    printf("\x1b[2J"); // ��ʃN���A
    while (game == 0) { // �Q�[���p�̃��[�v
        // �u���b�N��`��
        printf("\x1b[1;1H"); // �J�[�\���ʒu������p��
        for (y = 0; y < BLOCK_ROW; y++) {
            printf("\x1b[3%dm", y + 1); // �u���b�N�̐F
            for (x = 0; x < BLOCK_COL; x++) {
                if (block[y][x] == 1)
                    printf("######"); // �u���b�N�͔��p6������
                else
                    printf("      ");
            }
            printf("\n");
        }

        // �o�[�̑���
        printf("\x1b[%d;%dH", py + 1, px + 1);
        printf("        "); // 1�t���[���O�̃o�[������
        int key = 0;
        if (_kbhit()) key = _getch(); // �L�[����
        if (key == 75) { // ���L�[
            px -= 4;
            if (px < 0) px = 0;
        }
        if (key == 77) { // �E�L�[
            px += 4;
            if (px >= COL - 8) px = COL - 8;
        }
        printf("\x1b[36m"); // ���F
        printf("\x1b[%d;%dH", py + 1, px + 1);
        printf("========"); // �o�[��`��

        // �{�[���̈ړ�
        printf("\x1b[%d;%dH", by + 1, bx + 1);
        printf(" "); // 1�t���[���O�̃{�[��������
        bx += vx;
        by += vy;
        if (bx < 1) vx = 1; // ��ʍ��[�ɂ�����
        if (bx > COL - 2) vx = -1; // ��ʉE�[�ɂ�����
        if (by < 1) vy = 1; // ��ʏ�[�ɂ�����
        if (by > ROW - 1) game = 1; // ��ʉ��[�ɒB������Q�[���I�[�o�[
        if (px - 1 <= bx && bx <= px + 8 && by == py - 1) vy = -1; // �o�[�őł��Ԃ�����
        printf("\x1b[31m"); // ��
        printf("\x1b[%d;%dH", by + 1, bx + 1);
        printf("o"); // �{�[����`��

        if (0 <= by && by < BLOCK_ROW) { // �{�[�����u���b�N�ɓ�������������
            x = bx / 6; // 6�̓u���b�N�̕��i���p�������j
            y = by;
            if (block[y][x] == 1) { // �u���b�N������
                printf("\x1b[%d;%dH", y + 1, x * 6 + 1);
                printf("++++++"); // �󂵂����o
                block[y][x] = 0; // �u���b�N�𑶍݂��Ȃ���Ԃɂ���
                vy = -vy; // y�������̈ړ��ʂ𔽓]
                score += 1; // �X�R�A�𑝂₷
                if (score == BLOCK_ROW * BLOCK_COL) game = 2; // �S�ĉ󂵂���N���A
            }
        }

        printf("\x1b[%d;%dH", ROW + 2, 1);
        printf("\x1b[37m"); // ��
        printf("SCORE %d00\n", score); // �X�R�A�̕\��
        Sleep(80); // �����̈ꎞ��~
    }

    if (game == 1) { // �Q�[���I�[�o�[
        printf("\x1b[%d;%dH", ROW / 2, COL / 2 - 4);
        printf("\x1b[31m"); // ��
        printf("GAME OVER");
    }
    if (game == 2) { // �Q�[���N���A
        printf("\x1b[%d;%dH", ROW / 2, COL / 2 - 7);
        printf("\x1b[37m"); // ��
        printf("Congratulations!");
    }
    printf("\x1b[%d;%dH", ROW + 3, 1); // ��ʂ�����Ȃ��悤�ɃJ�[�\���ʒu����ʉ����ɂ���
    Sleep(5000); // 5�b�قǒ�~������A�������I����
    return 0;
}