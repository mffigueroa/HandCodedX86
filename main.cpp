#include <iostream>

using namespace std;

int cCoded_sqEuclidDist(int a, int b, int x, int y)
{
	int xDiff = a - x;
	int yDiff = b - y;
	return xDiff*xDiff + yDiff*yDiff;
}

int __cdecl asmCoded_sqEuclidDist(int a, int b, int x, int y)
{
	__asm
	{
		mov eax, [ebp + 8]
		sub eax, [ebp + 16]
		mul eax
		mov ebx, eax
		
		mov eax, [ebp + 12]
		sub eax, [ebp + 20]
		mul eax
		add eax, ebx
	}
}

int __cdecl handCoded_sqEuclidDist(int a, int b, int x, int y)
{
	__asm
	{
		;  mov eax, [ebp + 8]
		; 8B /r
		__emit 0x8B

		; Mod = 01
		; Reg (w) = 000
		; R / M (r) = 101
		__emit 0x45

		__emit 0x08


		;  sub eax, [ebp + 16]
		; 2B /r
		__emit 0x2B

		; Mod = 01
		; Reg(r,w) = 000
		; R / M(r) = 101
		__emit 0x45

		__emit 0x10


		;  mul eax
		; F7 /4
		__emit 0xF7

		; Mod = 11
		; Reg(/4) = 100
		; R / M(r) = 000
		__emit 0xE0

		;  mov ebx, eax
		; 8B /r
		__emit 0x8B

		; Mod = 11
		; Reg(w) = 011
		; R / M(r) = 000
		__emit 0xD8


		;  mov eax, [ebp + 12]
		; 8B / r
		__emit 0x8B

		; Mod = 01
		; Reg(w) = 000
		; R / M(r) = 101
		__emit 0x45

		__emit 0x0C


		;  sub eax, [ebp + 20]
		; 2B / r
		__emit 0x2B

		; Mod = 01
		; Reg(r, w) = 000
		; R / M(r) = 101
		__emit 0x45

		__emit 0x14


		;  mul eax
		; F7 / 4
		__emit 0xF7

		; Mod = 11
		; Reg(/ 4) = 100
		; R / M(r) = 000
		__emit 0xE0

		;  add eax, ebx
		; 03 /r
		__emit 0x03

		; Mod = 11
		; Reg(r,w) = 000
		; R / M(r) = 011
		__emit 0xC3
	}
}

int main()
{
	int a, b;
	int x, y;

	cout << "a: ";
	cin >> a;

	cout << "b: ";
	cin >> b;

	cout << endl;

	cout << "x: ";
	cin >> x;

	cout << "y: ";
	cin >> y;

	cout << endl << endl;
	cout << "C coded squared euclidean distance: " << cCoded_sqEuclidDist(a, b, x, y) << endl;
	cout << "Asm coded squared euclidean distance: " << asmCoded_sqEuclidDist(a, b, x, y) << endl;
	cout << "Hand coded squared euclidean distance: " << handCoded_sqEuclidDist(a, b, x, y) << endl;

	system("pause");

	return 0;
}