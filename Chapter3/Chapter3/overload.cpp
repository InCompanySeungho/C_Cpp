#include<cstdio>
#include<cstring>
// �����ε� ����:
// ���� �̸��� �Լ���������, �Ķ���� ��ȯ�� ���� �ٸ��� �����Ͽ� �پ��ϰ� ������ �� �ִ�.
class Vector
{
public:
	float x;
	float y;
public:
	Vector()
	{
		x = 0.0f;
		y = 0.0f;
	}
	Vector(float _x, float _y)
	{
		this->x = _x;
		this->y = _y;
	}
	void printInfo()

	{
		printf("%.2f, %.2f", x, y);
}
};

Vector operator+(Vector& _v1, Vector& _v2) // ���۷����͸� Ȱ���Ͽ� �⺻ ��Ģ������ �ٸ� �������� ����� �� �ִ�.
{
	// & ���۷��� ���·� �����;� �����ս��� ����. �����簡 �Ͼ������
	return Vector(_v1.x + _v2.x, _v1.y + _v2.y);
}


class Vector3
{
public:
	float x;
	float y;
	float z;
	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3(float _x, float _y, float _z)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}
	void printInfo()
	{
		printf("%.2f, %.2f, %.2f", x, y, z);
	}
};

Vector3 operator*(Vector3& v1, float scalar) // scalar : ����/���������� � ������ ��ġ
{
	return Vector3(v1.x * scalar, v1.y * scalar, v1.z * scalar);
}


int main()
{
	Vector v1 = Vector(1,2);
	Vector v2 = Vector(100, 200);

	Vector v3 = v1 + v2;

	//v3.printInfo();
	Vector3	v = Vector3(10, 20, 30);

	Vector3 result = v * 10;
	result.printInfo();
}