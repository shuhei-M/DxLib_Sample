/**
 * @file   : Application.h
 * @author : Shuhei Matsushima
 *
 * @belief : アプリケーション
 */

#ifndef __APPLICATION_H_
#define __APPLICATION_H_

class Vector3;

/**
 * アプリケーションクラス
 */
class Application
{
public:
	// 初期化
	bool tryInit();
	// 実行
	void run();

private:
	// 更新の手続き
	bool update();
	// 更新の内部処理
	void calc(Vector3* p1, Vector3* p2, Vector3* p3);

private:
	int mTimer = 0;
};

#endif // #ifndef __APPLICATION_H_