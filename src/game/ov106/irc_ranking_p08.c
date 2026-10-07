/*
 * file:     irc_ranking_p08.c
 * unit:     yes
 * function: func_021B8FC4, func_021B8FD0, func_021B900C, func_021B9134, func_021B913C
 * address:  0x021B8FC4
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _ll_mul 0x0209C054 arm
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_0207C768 0x0207C768 arm
 */
#include "../../matched/include/Obj07991.h"
#include "../../matched/include/Obj22269.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef struct { int a,b,v,dirty; } State_021B8FD0;

typedef struct { int a,b,v,d; signed char direction; } State_021B913C;

extern void func_02082BCC(void *, int, int);
extern u32 func_0207C768(u32,u32);
extern float _ffltu(u32),_fadd(float,float),_fsub(float,float);
extern int _ffix(float);
void func_021B8FC4(void *p);
void func_021B8FD0(State_021B8FD0 *p);
void func_021B900C(u8 *p,int amount,int duration);
void func_021B9134(u8 *p);
int func_021B913C(State_021B913C *p);

void func_021B8FC4(void *p) { func_02082BCC(p, 0, 0x14); }

/*
 * trailing: two-byte alignment padding, no follower.
 */
void func_021B8FD0(State_021B8FD0 *p) { if(p->dirty) { p->dirty=0; p->v=p->a+p->b/2; p->v=(int)(((long long)p->v*163840+2048)>>12); } }

static inline int magnitude(int v) { return v<0 ? (int)(0u-(u32)v) : v; }

static inline int rounded(int v) {
 if(v!=0) return _ffix(_fadd(0.5f,_ffltu((u32)v<<12)));
 return _ffix(_fsub(_ffltu((u32)v<<12),0.5f));
}

/*
 * note: Compiled code ends 021B9132; handed tail 021B9132..021B9134 is two zero alignment bytes. Unsigned magnitude subtraction and duration shift preserve 32-bit wrap; runtime helpers retain all repeated calls.
 */
void func_021B900C(u8 *p,int amount,int duration) {
 int value;
 if(magnitude(amount)<=4096) return;
 p[16]=amount/magnitude(amount);
 amount=magnitude(amount);
 if(amount>245760) amount=245760;
 else if(amount<4096) amount=4096;
 if(rounded(duration)>=53248) return;
 if(rounded(duration)>53248) value=53248;
 else if(rounded(duration)<0) value=0;
 else value=rounded(duration);
 ((struct Obj07991 *)p)->f0=func_0207C768(amount-4096,241664);
 ((struct Obj07991 *)p)->f4=4096-func_0207C768(value,53248);
 ((struct Obj07991 *)p)->fC=1;
}


void func_021B9134(u8 *p) { ((struct Obj22269 *)p)->f8 = 0; }

int func_021B913C(State_021B913C *p) {
 int v=p->v*p->direction;
 if(v>32768) v=32768; else if(v< -32768) v= -32768;
 p->v -= (int)(((long long)p->v*205+2048)>>12);
 if(p->v> -4096 && p->v<4096) p->v=0;
 return (short)(v>>12);
}
