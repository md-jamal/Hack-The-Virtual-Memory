#include <stdio.h>

void func1(void)
{
	int a;
	int b;
	int c;
	register long rsp asm ("rsp");
	register long rbp asm ("rbp");

	a = 98;
	b = 972;
	c = a + b;
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("func1, rpb = %lx\n", rbp);
	printf("func1, rsp = %lx\n", rsp);
	printf("func1, a = %d\n", *(int *)(((char *)rbp) - 0xc) );
	printf("func1, b = %d\n", *(int *)(((char *)rbp) - 0x8) );
	printf("func1, c = %d\n", *(int *)(((char *)rbp) - 0x4) );
	printf("func1, previous rbp value = %lx\n", *(unsigned long int *)rbp );
	printf("func1, return address value = %lx\n", *(unsigned long int *)((char *)rbp + 8) );
}

void func2(void)
{
	int a;
	int b;
	int c;
	register long rsp asm ("rsp");
	register long rbp asm ("rbp");

	printf("func2, a = %d, b = %d, c = %d\n", a, b, c);
	printf("func2, rpb = %lx\n", rbp);
	printf("func2, rsp = %lx\n", rsp);
}

int main(void)
{
	register long rsp asm ("rsp");
	register long rbp asm ("rbp");

	printf("main, rpb = %lx\n", rbp);
	printf("main, rsp = %lx\n", rsp);
	func1();
	func2();
	return (0);
}

