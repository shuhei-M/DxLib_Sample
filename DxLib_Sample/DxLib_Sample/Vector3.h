/**
 * @file   : Vector3.h
 * @author : Shuhei Matsushima
 *
 * @belief : 3D�x�N�g���N���X
 */

#ifndef __VECTOR3_H_
#define __VECTOR3_H_

/**
 * 3D�x�N�g���N���X
 */
class Vector3 
{
public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	// �f�t�H���g�R���X�g���N�^
	Vector3() {}
	// �R�s�[�R���X�g���N�^
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}
	// �R���X�g���N�^
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

	//���
	Vector3& operator =(const Vector3& a);
	// ������
	bool operator ==(const Vector3& a) const;
	// ��v���Ȃ�
	bool operator !=(const Vector3& a) const;

	// �[���x�N�g��
	void zero();
	// �x�N�g���̔��]
	Vector3 operator -() const;

	// �x�N�g���̉��Z�i�j�����j
	Vector3 operator +(const Vector3& a) const;
	// �x�N�g���̌��Z�i�j�����j
	Vector3 operator -(const Vector3& a) const;

	//�X�J���[�ɂ���Z
	Vector3 operator *(float a) const;
	//�X�J���[�ɂ�鏜�Z
	Vector3 operator /(float a) const;

	// ���Z������Z�q
	Vector3& operator +=(const Vector3& a);
	// ���Z������Z�q
	Vector3& operator -=(const Vector3& a);
	// ��Z������Z�q
	Vector3& operator *=(float a);
	// ���Z������Z�q
	Vector3& operator /=(float a);

	//�x�N�g���̐��K��
	void normalize();

	// �x�N�g���̓���
	float operator *(const Vector3& a) const;
};

// �x�N�g���̑傫�������߂�
inline float vectorMag(const Vector3& a);

// ��̃x�N�g���̓��ς����߂�
inline Vector3 crossProduct(const Vector3& a, const Vector3& b);

// ���X�J���[����Z����
inline Vector3 operator *(float k, const Vector3& v);

// 2�_�̋������v�Z����
inline float distance(const Vector3& a, const Vector3& b);

// 2�_�̋������v�Z����i��Ȃ��j
inline float distanceSquared(const Vector3& a, const Vector3& b);

namespace 
{
	// �O���[�o���ȃ[���x�N�g���萔��񋟂���
	extern const Vector3 kZeroVector;
}

#endif // #ifndef __VECTOR3_H_
