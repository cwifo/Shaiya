#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <array>

#include <include/main.h>
#include <include/util.h>

unsigned u0x4C42C6 = 0x4C42C6;
unsigned u0x4C4336 = 0x4C4336;
__declspec(naked) void naked_0x4C42BF()
{
	__asm
	{
		add eax, 0x88
		cmp edx, eax
		jg _u0x4C4336
		jmp u0x4C42C6
		_u0x4C4336 :
		jmp u0x4C4336
	}
}

void hook::recreationviewer()
{
	util::detour((void*)0x4C42BF, naked_0x4C42BF, 7);
}
