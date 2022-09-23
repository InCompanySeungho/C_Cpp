#include<cstdio>


void swap(int a, int b);
void p_swap(int* a, int* b);
void ref_swap(int& a, int& b);
int main()
{
	int v1 = 100;
	int v2 = 200;

	int temp; // �ӽú���

	//swap(v1, v2); 
	// �̷��� �ϸ� ������ �� �� ������ �ȵȴ�.
	// �Ű�����(�Ķ����)�� �Լ��� �����鼭 ���ο� ���� ����� �޴´�. �������� v1�� swap�� �Ű����� a �� �ٸ� �����̴�.

	printf("a : %d\n, b : %d\n", v1, v2);
	//p_swap(&v1, &v2);
	ref_swap(v1, v2);
	printf("a : %d\n, b : %d", v1, v2);

}
void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void ref_swap(int& a, int& b) // int �� ���۷��� Ÿ��  (���� �� ��ü�� �����´�)
{	
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void p_swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}