/*
 * file:     compatible_irc_sys_p05.c
 * unit:     yes
 * function: func_021B67F8, func_021B685C, func_021B6874, func_021B68A0, func_021B68C0, func_021B68E0, func_021B6920, func_021B6938, func_021B69C4, func_021B69F8, func_021B6A3C, func_021B6A44, func_021B6A4C, func_021B6A60, func_021B6A7C
 * address:  0x021B67F8
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B658C 0x021B658C thumb ov101
 *   func_021B64B8 0x021B64B8 thumb ov101
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02012950 0x02012950 thumb
 *   func_02008468 0x02008468 thumb
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02030734 0x02030734 arm
 *   func_021B6BE4 0x021B6BE4 thumb ov101
 *   func_020120F4 0x020120F4 thumb
 *   func_021B6100 0x021B6100 thumb ov101
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   d_021B753C 0x021B753C data a1
 *   func_02005E9C 0x02005E9C thumb
 *   func_021B6148 0x021B6148 thumb ov101
 *   func_021B6C08 0x021B6C08 thumb ov101
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02005E50 0x02005E50 thumb
 *   func_021B6BFC 0x021B6BFC thumb ov101
 *   func_021B6C20 0x021B6C20 thumb ov101
 *   func_021B6AD8 0x021B6AD8 thumb ov101
 *   func_021B6BA8 0x021B6BA8 thumb ov101
 */
#include "../../matched/include/Obj22106.h"
#include "../../matched/include/Obj22107.h"
#include "../../matched/include/Obj22108.h"
#include "../../matched/include/Obj13716.h"
#include "../../matched/include/Obj04421.h"
#include "../../matched/include/Obj13717.h"
#include "../../matched/include/Obj13718.h"
#include "../../matched/include/Obj22109.h"
#include "../../matched/include/Obj22111.h"

struct Data;
struct Entry;
struct Rec44;
struct Sub24;
struct Obj0203159C;
struct Ctx;
struct S020315D4;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct R { int words[11]; } R;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_021B658C(void *p, struct Data *out);
extern u32 func_021B64B8(u32 p, u32 a, u32 b, u32 c, u8 d, u32 e, u32 f, u32 g);
extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
extern void func_02082D44(void *,const void *,u32);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern int func_02008468(void);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_021B6BE4(u8 *,int);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_021B6100(int,int,int,int);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern int func_02005E9C(void);
extern void func_021B6148(void *);
extern void func_021B6C08(u8 *);
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern int func_02005E50(void);
extern u32 func_021B6BFC(u8 *);
extern int func_021B6C20(int *p, int index, int heap, int arg);
extern void func_021B6AD8(u8 *p, u16 *state);
extern void func_021B6BA8(u8 *p, u16 *state);
int func_021B67F8(int *p,int resource);
void func_021B685C(int *p,R *out);
void func_021B6874(u32 a,int b,void *c,u8 *d,void *e);
void func_021B68A0(u32 a,int b,int c,u8 *d,void *e);
void func_021B68C0(u32 a,int b,int c,u8 *d,void *e);
void func_021B68E0(u32 a, int b, int c, int *d, u32 e);
u32 func_021B6920(u32 a,u8 *p);
int func_021B6938(struct Obj0203159C *a,int b,int c);
int func_021B69C4(int a,int b,int c,u8 *d);
int func_021B69F8(void *task, u32 *state, void *unused, u8 *p);
void func_021B6A3C(u8 *p, u32 v);
void func_021B6A44(u8 *p);
void func_021B6A4C(u8 *p,u16 *state);
void func_021B6A60(u8 *p,u16 *state);
void func_021B6A7C(u8 *p,u16 *state);
extern const char d_021B753C[];

int func_021B67F8(int *p,int resource)
{
    switch(p[1]) {
    case 0:
        if(resource) func_021B658C((void *)resource,(struct Data *)p[10]); else return 1;
        if(func_021B64B8(p[0],0x1003,44,p[10],255,0,0,1)) p[1]=1;
        break;
    case 1:
        if(p[9]) { p[9]=0; p[1]=0; return 1; }
        break;
    }
    return 0;
}

void func_021B685C(int *p,R *out) { *out=*(R *)p[12]; }

void func_021B6874(u32 a,int b,void *c,u8 *d,void *e) {
 if(e==func_020399A8()) { if(a!=func_02039338()) { func_02082D44(c,d+8,8); ((struct Obj22106 *)d)->f18=1; } }
}

void func_021B68A0(u32 a,int b,int c,u8 *d,void *e) {
 if(e==func_020399A8()) { if(a!=func_02039338()) ((struct Obj22107 *)d)->f1C=1; }
}

void func_021B68C0(u32 a,int b,int c,u8 *d,void *e) {
 if(e==func_020399A8()) { if(a!=func_02039338()) ((struct Obj22108 *)d)->f20=1; }
}

void func_021B68E0(u32 a, int b, int c, int *d, u32 e)
{
    void *p;
    if (*(int *)d[0] != 0) {
        p = func_02012950((void *)*(int *)d[0], a);
        func_02082D44((void *)(c + 12), p, func_02008468());
    }
    if (e == (u32)func_020399A8()) {
        if (a != func_02039338())
            d[9] = 1;
    }
}

u32 func_021B6920(u32 a,u8 *p) {
 if(a==func_02039338()) return ((struct Obj13716 *)p)->f2C;
 return ((struct Obj13716 *)p)->f30;
}

int func_021B6938(struct Obj0203159C *a,int b,int c)
{
    u8 *p;
    int handle;
    func_0203064C(1,58,0x8000);
    p=func_0203159C(a,64,58);
    func_02082BCC(p,0,64);
    handle=0;
    ((struct Obj04421 *)p)->f10=c;
    ((struct Obj04421 *)p)->f3C=func_02030734(58,44,0,d_021B753C,0x119);
    func_02082BCC(((struct Obj04421 *)p)->f3C,0,44);
    func_021B6BE4(p+4,58);
    if(*(int *)((struct Obj04421 *)p)->f10) handle=(int)func_020120F4((const struct Ctx *)(*(int *)((struct Obj04421 *)p)->f10));
    ((struct Obj04421 *)p)->f0=func_021B6100(-1,handle,58,0);
    ((struct Obj04421 *)p)->f34=1;
    func_021B6A3C(p,(u32)func_021B6A4C);
    func_02005DE4((void *)1);
    func_02005E64();
    return 1;
}

int func_021B69C4(int a,int b,int c,u8 *d) {
 func_02005E9C(); func_02005DE4(0); func_021B6148(((struct Obj13717 *)d)->f0); func_021B6C08(d+4); func_020307B0(((struct Obj13717 *)d)->f3C); func_020315D4((void *)a); func_020306F0(58); return 1;
}

int func_021B69F8(void *task, u32 *state, void *unused, u8 *p) {
    switch (*state) {
    case 0:
        if (!func_02005E50()) *state += 1;
        break;
    case 1:
        if (func_021B6BFC(p + 4) == 0)
            (*(void (**)(u8 *, u8 *))(p + 20))(p, p + 24);
        if (*(u32 *)(p + 28)) return 1;
        break;
    }
    return 0;
}


void func_021B6A3C(u8 *p, u32 v) { ((struct Obj13718 *)p)->f14 = v; ((struct Obj13718 *)p)->f18 = 0; }


void func_021B6A44(u8 *p) { ((struct Obj22109 *)p)->f1C = 1; }

void func_021B6A4C(u8 *p,u16 *state) { if(*state==0) func_021B6A3C(p,(u32)func_021B6A7C); }

void func_021B6A60(u8 *p,u16 *state) { switch(*state) { case 0: *state=1; break; case 1: func_021B6A44(p); break; } }

void func_021B6A7C(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        if(func_021B6C20((int *)(p+4),0,58,(int)p)) *state=1;
        break;
    case 1:
        switch(((struct Obj22111 *)p)->f20) {
        case 0: func_021B6A3C(p,(u32)func_021B6AD8); break;
        case 1: func_021B6A3C(p,(u32)func_021B6BA8); break;
        case 2: func_021B6A3C(p,(u32)func_021B6A60); break;
        }
        break;
    }
}
