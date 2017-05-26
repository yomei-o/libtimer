#ifndef MYTIMER_H_
#define MYTIMER_H_

#ifdef __cplusplus
extern "C"
{
#endif

int gettm(int argc,char* argv[]);
int settm(int argc,char* argv[]);
int deltm(int argc, char* argv[]);
int gettmnum(int argc, char* argv[]);
int onsw(int argc, char* argv[]);
int offsw(int argc, char* argv[]);

int mytimer_init();
int mytimer_done();
int mytimer_reset();

void  mytimer_set_onfunc(void  (*pfunc)(void*), void* vp);
void  mytimer_set_offunc(void  (*pfunc)(void*), void* vp);

#ifdef __cplusplus
}
#endif



#endif
