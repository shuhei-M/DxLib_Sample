/**
 * @file   : Vector3.h
 * @author : Shuhei Matsushima
 *
 * @belief : 3Dベクトルクラス
 */

#ifndef __VECTOR3_H_
#define __VECTOR3_H_

/**
 * 3Dベクトルクラス
 */
class Vector3 
{
public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	// デフォルトコンストラクタ
	Vector3() {}
	// コピーコンストラクタ
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}
	// コンストラクタ
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

	//代入
	Vector3& operator =(const Vector3& a);
	// 等しい
	bool operator ==(const Vector3& a) const;
	// 一致しない
	bool operator !=(const Vector3& a) const;

	// ゼロベクトル
	void zero();
	// ベクトルの反転
	Vector3 operator -() const;

	// ベクトルの加算（ニ項式）
	Vector3 operator +(const Vector3& a) const;
	// ベクトルの減算（ニ項式）
	Vector3 operator -(const Vector3& a) const;

	//スカラーによる乗算
	Vector3 operator *(float a) const;
	//スカラーによる除算
	Vector3 operator /(float a) const;

	// 加算代入演算子
	Vector3& operator +=(const Vector3& a);
	// 減算代入演算子
	Vector3& operator -=(const Vector3& a);
	// 乗算代入演算子
	Vector3& operator *=(float a);
	// 除算代入演算子
	Vector3& operator /=(float a);

	//ベクトルの正規化
	void normalize();

	// ベクトルの内積
	float operator *(const Vector3& a) const;
};

// ベクトルの大きさを求める
inline float vectorMag(const Vector3& a);

// 二つのベクトルの内積を求める
inline Vector3 crossProduct(const Vector3& a, const Vector3& b);

// 左スカラーを乗算する
inline Vector3 operator *(float k, const Vector3& v);

// 2点の距離を計算する
inline float distance(const Vector3& a, const Vector3& b);

// 2点の距離を計算する（√なし）
inline float distanceSquared(const Vector3& a, const Vector3& b);

namespace 
{
	// グローバルなゼロベクトル定数を提供する
	extern const Vector3 kZeroVector;
}

#endif // #ifndef __VECTOR3_H_
