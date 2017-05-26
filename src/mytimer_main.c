#include <stdio.h>
#include "chkcmd.h"
#include "mytimer.h"

#ifdef _MSC_VER
#if _MSC_VER >= 1400
#pragma warning( disable : 4996 )
#pragma warning( disable : 4819 )
#endif
#endif

#if defined(_WIN32) && !defined(__GNUC__)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#if 1


static void func_on(void *vp)
{
	printf("func_on()\n");
}

static void func_off(void *vp)
{
	printf("func_off()\n");
}


int main()
{
	char buf[256];
	const char* p;

#if defined(_WIN32) && !defined(__GNUC__)
	//	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_WNDW);
	//	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_WNDW);
	//	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_WNDW);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	mytimer_init();
	p = mychkcmd_get_print_buffer();
	mytimer_set_onfunc(func_on, NULL);
	mytimer_set_offunc(func_off, NULL);
	while (1){
		buf[0] = 0;
		fgets(buf, 256, stdin);
		if (buf[0] == 0)break;
		mychkcmd_execute_command(buf);
		printf("result=>>%s<<\n",p);
		printf("\n");
	}
	mytimer_done();
}


#endif


