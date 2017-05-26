#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "mytimer.h"
#include "chkcmd.h"
#include "mythread.h"
#include "ysleep.h"

#ifdef _MSC_VER
#if _MSC_VER >= 1400
#pragma warning( disable : 4996 )
#pragma warning( disable : 4819 )
#endif
#endif

#ifdef OYAKI
#define TIMER_BASE_DIR "."
#else
#define TIMER_BASE_DIR "."
#endif

#define MAX_NUM_OF_TIMER 100
#define MYTIMER_FILE_NAME "mytimer.csv"


//
// util
//


static void get_timer_base_dir(char* buf, int sz)
{
	strncpy(buf, TIMER_BASE_DIR, sz);
}



//
// タイマー情報の読み書き
//


struct mytimer{
	int hour;
	int min;
	int duration;
	int flag;
	int enabled;
};

//タイマーリストコマンド用
static struct mytimer mytimer_list[MAX_NUM_OF_TIMER];
//タイマーリストループ読み込み用
static struct mytimer mytimer_list2[MAX_NUM_OF_TIMER];

static int read_timer_file()
{
	char filename[256];
	FILE* fp;

	get_timer_base_dir(filename,256);
	strcat(filename, "/");
	strcat(filename, MYTIMER_FILE_NAME);
	fp = fopen(filename, "rt");
	if (fp == NULL)return -1;
	//
	// TODO
	//
	// タイマー構造体の情報をcsvファイルから読む
	//
	//
	fclose(fp);
	return 0;
}

static int read_timer_file2()
{
	char filename[256];
	FILE* fp;

	get_timer_base_dir(filename, 256);
	strcat(filename, "/");
	strcat(filename, MYTIMER_FILE_NAME);
	fp = fopen(filename, "rt");
	if (fp == NULL)return -1;
	//
	// TODO
	//
	// タイマー構造体の情報をcsvファイルから読む
	//
	//
	fclose(fp);
	return 0;
}

static int write_timer_file()
{
	char filename[256];
	FILE* fp;

	get_timer_base_dir(filename, 256);
	strcat(filename, "/");
	strcat(filename, MYTIMER_FILE_NAME);
	fp = fopen(filename, "wt");
	if (fp == NULL)return -1;
	//
	// TODO
	//
	// タイマー構造体の情報をcsvファイルに書く
	//
	//
	fclose(fp);
	return 0;
}


//
// タイマーのコールバック関数
//

static void(*pfunc_on)(void*) = NULL;
static void* data_on = NULL;
static int timer_on()
{
	if (pfunc_on)pfunc_on(data_on);
}

void  mytimer_set_onfunc(void  (*pfunc)(void*), void* vp)
{
	pfunc_on = pfunc;
	data_on = vp;
}

static void (*pfunc_off)(void*) = NULL;
static void* data_off = NULL;
static int timer_off()
{
	if (pfunc_off)pfunc_off(data_off);
}

void  mytimer_set_offunc(void  (*pfunc)(void*), void* vp)
{
	pfunc_off = pfunc;
	data_off = vp;
}


//
// タイマー設定コマンド
//
int gettm(int argc, char *argv[])
{
	//
	// TODO
	//
	// タイマー構造体の情報を返す
	//
	//
	mychkcmd_print("gettm()");
	return 0;
}

int settm(int argc, char *argv[])
{
	//
	// TODO
	//
	// タイマー構造体の情報を更新
	//
	//
	mychkcmd_print("settm()");
	return 0;
}

int deltm(int argc, char *argv[])
{
	//
	// TODO
	//
	// タイマー構造体の情報を削除
	//
	//
	mychkcmd_print("deltm()");
	return 0;
}

int gettmnum(int argc, char *argv[])
{
	//
	// TODO
	//
	// タイマー設定個数
	//
	//
	mychkcmd_print("gettmnum()");
	return 0;
}



int onsw(int argc, char *argv[])
{
	mychkcmd_print("onsw()");
	timer_on();
	return 0;
}

int offsw(int argc, char *argv[])
{
	mychkcmd_print("offsw()");
	timer_off();
	return 0;
}



//
// タイマーのループ関数
//

static mythread_t* th = NULL;
static int stop_flag = 0;

void mytimer_loop(void* vp)
{
	printf("mytimer_loop() start\n");
	read_timer_file2();
	while (1){
		if (stop_flag)break;
		printf(".");
		ysleep(1);

		//
		// TODO
		//
		// 時間が来たらオンとオフの関数を呼ぶ
		// 
		//
		//
	}
	printf("\n");
	printf("mytimer_loop() stop\n");
}



int mytimer_init()
{
	printf("mytimer_init()\n");
	th = mythread_create(mytimer_loop,NULL);
	return 0;
}

int mytimer_done()
{
	printf("mytimer_done()\n");
	stop_flag = 1;
	if (th){
		mythread_join(th);
	}
	th = NULL;
	stop_flag = 0;
	return 0;
}

int mytimer_reset()
{
	printf("mytimer_reset()\n");
	stop_flag = 1;
	if (th){
		mythread_join(th);
	}
	stop_flag = 0;
	th = mythread_create(mytimer_loop, NULL);
	return 0;
}





