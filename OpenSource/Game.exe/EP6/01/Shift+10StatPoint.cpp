#include "pch.h"

unsigned u0x528D96 = 0x528D96;
__declspec(naked) void naked_0x528D8D()
{

	__asm
	{
		pushad
		push 0x10
		call GetAsyncKeyState
		shr ax, 0xF
		cmp ax, 0x1
		popad
		je stats_1
		pushad

		push 0x11
		call GetAsyncKeyState
		shr ax, 0xF
		cmp ax, 0x1
		popad
		je stats_2
		jmp originalcode

		stats_1 :
		cmp dword ptr[esi + 0x4C], 0x0A
		jl originalcode
		sub ecx, 0x0A
		mov[esi + 0x4C], ecx
		add word ptr[esi + eax * 2 + 0x40], 0x0A
		jmp u0x528D96

		stats_2 :
		add[esi + eax * 2 + 0x40], ecx
		sub ecx, ecx
		mov[esi + 0x4C], ecx
		jmp u0x528D96

		originalcode :
		dec ecx
		mov[esi + 0x4C], ecx
		inc word ptr[esi + eax * 2 + 0x40]
		jmp u0x528D96
	}
}

void hook::shiftstatspoint()
{
	util::detour((void*)0x528D8D, naked_0x528D8D, 5);
}