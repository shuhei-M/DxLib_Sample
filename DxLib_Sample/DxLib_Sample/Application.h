/**
 * @file   : Application.h
 * @author : Shuhei Matsushima
 *
 * @belief : �A�v���P�[�V����
 */

#ifndef __APPLICATION_H_
#define __APPLICATION_H_

class Vector3;

/**
 * �A�v���P�[�V�����N���X
 */
class Application
{
public:
	// ������
	bool tryInit();
	// ���s
	void run();

private:
	// �X�V�̎葱��
	bool update();
	// �X�V�̓�������
	void calc(Vector3* p1, Vector3* p2, Vector3* p3);

private:
	int mTimer = 0;
};

#endif // #ifndef __APPLICATION_H_