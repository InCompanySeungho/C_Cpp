#include"Header.h"
#define SWAP(X,Y,T) T = X; X =Y; Y=T; // ��Ģ�� �°� �ҽ��ڵ带 ��ü(��ü�� ����)

// ��ũ�θ� �� �ٷ� ����ϱ� ���ؼ��� \ ���� �ٹٲ� ( \ �ڿ��� ������ �������)
#define LineChange(A,B)\
 A+B;\
A-B;

#define P(X,Y) X##Y 

#define PI 3.141592
#define EXCUTE_NUM 1 // ��ó�� ��ũ�θ� Ȱ���Ͽ�
#if EXCUTE_NUM == 0
int main()
{
	printf("HelloWorld 0");
	return 0;
}
#else 
int main()
{
	int v1 = 100;
	int v2 = 200;
	int temp;

	// #define��ũ��(��ó��) �Լ��� ȣ���ϸ�
	// ������ ��ǻ�� ���꿡 ���� �Ͼ�� ���� �ƴ�, �ƿ� �ҽ��ڵ尡 �ٲ������� �ȴ�.
	SWAP(v1, v2, temp);
	temp = v1; v1 = v2; v2 = temp;
	printf("v1 = %d\n", v1);
	printf("v2 = %d\n", v2);

	P(print, f("HelloWorld\n"));

	float pie = PI;
	
	return 0;
}
#endif