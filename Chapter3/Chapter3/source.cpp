#include<iostream>
#include<cstdlib>

/*
int main()
{
	int v2[5] = { 1,2,3,4,5 };
	int* pv2 = v2;
	printf("%d", *(pv2 + 1)); // pv2 + 1 = +(Ÿ���� ����Ʈ ��ŭ ���ϱ�) �� ���ؼ� v2[0] + 1  = v2[1] �� �ȴ�.
	// ��� : 2
	// ������ �ּ� ��ü�� ���� ������ �ϰ� �Ǹ� �ּҰ��� ����Ÿ�Ը�ŭ �̵��ϰ� �ȴ�.
	return 0;
}*/

// ����ü + �Լ� = Ŭ����

struct Marine
{
	int hp;
	int mp;
};
int main()
{
	// [ C���� malloc�� �̿��ؼ� �޸𸮿� �Ҵ��ϴ� ��� ]
	Marine* m = (Marine*)malloc(sizeof(Marine));
	free(m);


	// [ C++���� new Ű���带 �̿��ؼ� �޸𸮿� �Ҵ� ]
	Marine* m = new Marine;
	delete m;




	int* myArrray = (int*)malloc(sizeof(int)* 10); // 10 ���� �迭�� ����� �ʹ�
	free(myArrray);

	int* myArray_cpp = new int[100];
	delete[] myArray_cpp;
	return 0;
}