#include <iostream>

using namespace std;

int main()
{
	int a, b, x;
	x = 0;
	cout << "Enter a b" << endl;
	cin >> a >> b;
	_asm
	{
		xor eax, eax
		xor ebx, ebx

		mov eax, a;
		mov ebx, b;

		cmp eax, ebx;
		jg great
		jl m4
		mov x, 6;
		jmp end_if

		great:
			imul eax; <eax> = a ^ 2
			sub eax, ebx; <eax> = a ^ 2 - b
			push eax; eax в стек
			mov eax, a; <eax> = a
			sub eax, 3; <eax> = a - 3
			mov ebx, eax; <ebx> = a - 3
			pop eax; <eax> = a^2 - b
			cdq;
			idiv ebx; 
			mov x, eax;

			jmp end_if

		m4:
			imul eax; <eax> = a ^ 2
			sub eax, 3; <eax> = a ^ 2 - 3
			cdq;
			idiv ebx; <eax> = a ^ 2 - 3 / b
			mov x, eax;

			jmp end_if

		end_if:

	}
	cout << x;
	return 0;
}