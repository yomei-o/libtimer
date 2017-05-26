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

#define GOTO 3
#define I_USE_HEARTBEET

// タイマーコマンド機能を実装するときはこれを有効にする
//#define I_IMPLIMENT_TIMER_CMD

// タイマーのテストをするときはこれを有効にする
//#define I_USE_TEST_TIME_PTN 0

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
#ifdef 	I_IMPLIMENT_TIMER_CMD
	int param1;
	int param2;
	void* data1;
	void* data2;
#endif
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

#ifdef 	I_IMPLIMENT_TIMER_CMD
	//
	// TODO
	//
	//
	// タイマー構造体の情報をcsvファイルから読む
	//
	do{
	}while(0);
#endif
	
	
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


#ifdef 	I_IMPLIMENT_TIMER_CMD
	//
	// TODO
	//
	// タイマー構造体の情報をcsvファイルから読む
	//
	//
	do{
	}while(0);
#endif

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


#ifdef 	I_IMPLIMENT_TIMER_CMD
	//
	// TODO
	//
	// タイマー構造体の情報をcsvファイルに書く
	//
	//
	do{
	}while(0);
#endif

	fclose(fp);
	return 0;
}


//
// タイマーのコールバック関数
//

static void(*pfunc_on)(int,void*) = NULL;
static void* data_on = NULL;
static int timer_on(int id)
{
	if (pfunc_on)pfunc_on(id,data_on);
	return 0;
}

void  mytimer_set_onfunc(void  (*pfunc)(int,void*), void* vp)
{
	pfunc_on = pfunc;
	data_on = vp;
}

static void (*pfunc_off)(int,void*) = NULL;
static void* data_off = NULL;
static int timer_off(int id)
{
	if (pfunc_off)pfunc_off(id,data_off);
	return 0;
}

void  mytimer_set_offunc(void  (*pfunc)(int,void*), void* vp)
{
	pfunc_off = pfunc;
	data_off = vp;
}


//
// タイマー設定コマンド
//
int gettm(int argc, char *argv[])
{
#ifdef 	I_IMPLIMENT_TIMER_CMD
	//
	// TODO
	//
	// タイマー構造体の情報を返す
	//
	//
	do{
	}while(0);
#else
	mychkcmd_print("gettm()");
#endif
	return 0;
}

int settm(int argc, char *argv[])
{
#ifdef 	I_IMPLIMENT_TIMER_CMD
	//
	// TODO
	//
	// タイマー構造体の情報を更新
	//
	//
	do{
	}while(0);
#else
	mychkcmd_print("settm()");
#endif
	return 0;
}

int deltm(int argc, char *argv[])
{
#ifdef 	I_IMPLIMENT_TIMER_CMD
	//
	// TODO
	//
	// タイマー構造体の情報を削除
	//
	//
	do{
	}while(0);
#else
	mychkcmd_print("deltm()");
#endif
	return 0;
}

int deltmall(int argc, char *argv[])
{
#ifdef 	I_IMPLIMENT_TIMER_CMD
	//
	// TODO
	//
	// タイマー構造体の情報を削除
	//
	//
	do{
	}while(0);
#else
	mychkcmd_print("deltmall()");
#endif
	return 0;
}

int gettmnum(int argc, char *argv[])
{
#ifdef 	I_IMPLIMENT_TIMER_CMD
	//
	// TODO
	//
	// タイマー設定個数
	//
	//
	do{
	}while(0);
#else
	mychkcmd_print("gettmnum()");
#endif
	return 0;
}



int onsw(int argc, char *argv[])
{
	int id = -1;
	mychkcmd_print("onsw()");
	if (argc >= 2)sscanf(argv[1],"%d", &id);
	timer_on(id);
	return 0;
}

int offsw(int argc, char *argv[])
{
	int id = -1;
	mychkcmd_print("offsw()");
	if (argc >= 2)sscanf(argv[1],"%d", &id);
	timer_off(id);
	return 0;
}



//
// オンオフをするかどうか判定
//


static void check_active(int gsec)
{
#ifdef 	I_IMPLIMENT_TIMER_CMD
	//
	// TODO
	//
	// 時間が来たらオンとオフの関数を呼ぶ
	// 
	//
	//
	do{
	}while(0);
#else
	int hogehoge = 0;
	if(hogehoge)timer_on(0);
	if (hogehoge)timer_off(0);
#endif
}

#ifdef  I_USE_TEST_TIME_PTN
static int test_ptn_cnt = 0;

static int test_ptn[][100] = {
	{ 1, 2, 3,  -1 },
	//
	// TODO ここにテストパターンを追加
	//
};
static time_t test_time(void)
{
	int ret=-1;
	ret = test_ptn[I_USE_TEST_TIME_PTN][test_ptn_cnt];
	test_ptn_cnt++;
	if (test_ptn[I_USE_TEST_TIME_PTN][test_ptn_cnt] < 0)test_ptn_cnt = 0;
	return ret;
}

#endif


//
// タイマーのループ関数
//

static mythread_t* th = NULL;
static int stop_flag = 0;

void mytimer_loop(void* vp)
{
	int ct = 0;
	time_t t;
	struct tm* ptm;
	int hour,sec,min,gsec;
	printf("mytimer_loop() start\n");
	read_timer_file2();

	while (1){
		ct++;
		if(stop_flag)break;
		ysleep(1);
		if (ct%GOTO != 0)continue;
#ifdef I_USE_HEARTBEET
		printf(".");
#endif
#ifdef  I_USE_TEST_TIME_PTN
		t = test_time();
#else
		t = time(NULL);
#endif
		ptm=localtime(&t);
		hour = ptm->tm_hour;
		min = ptm->tm_min;
		sec = ptm->tm_sec;
		gsec = hour * 3600 + min * 60 + sec;
		check_active(gsec);
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



//
// interface
//
void mytimer_execute_command(const char* cmd)
{
	mychkcmd_execute_command(cmd);
}

const char* mytimer_get_print_buffer()
{
	return mychkcmd_get_print_buffer();
}




