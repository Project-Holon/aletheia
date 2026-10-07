/*
 * file:     compatible_irc_sys_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B6148, func_021B6150, func_021B61E8, func_021B6254, func_021B62AC, func_021B62FC, func_021B630C, func_021B63BC, func_021B63C4, func_021B63CC, func_021B63D0, func_021B6424, func_021B6480, func_021B6494, func_021B64B8, func_021B64F0, func_021B6508, func_021B6518
 * address:  0x021B6100
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
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021B7524 0x021B7524 data a1
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203CBAC 0x0203CBAC arm
 *   func_021B6670 0x021B6670 thumb ov101
 *   func_021B66E0 0x021B66E0 thumb ov101
 *   d_021B743C 0x021B743C data a4
 *   func_021B6760  0x021B6760  thumb  ov101
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_021B6674  0x021B6674  thumb  ov101
 *   func_0203D0DC 0x0203D0DC arm
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D378 0x0203D378 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02039468 0x02039468 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0203A574 0x0203A574 arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_021B678C 0x021B678C thumb ov101
 */
#include "../../matched/include/Obj06362.h"
#include "../../matched/include/Obj22090.h"
#include "../../matched/include/Obj22091.h"
#include "../../matched/include/Obj22092.h"
#include "../../matched/include/Obj22093.h"
#include "../../matched/include/Obj22094.h"
#include "../../matched/include/Obj22095.h"

struct Req;
struct Entry;
struct Link;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef short s16;

typedef signed char s8;

typedef int s32;

struct Config { int words[26]; int context; int tail; };

struct Obj_021B6150 { int first; int data[15]; int context; unsigned state; int rest[11]; int ready; int done; int spare[3]; u16 heap; };

typedef struct Obj_021B61E8 {
    int f00;
    unsigned char sub[0x40];
    int state;
    unsigned char pad48[0xC];
    int done;
    unsigned char pad58[0x1C];
    int pending;
    int busy;
} Obj_021B61E8;

typedef struct Obj_021B63D0 { unsigned char pad[0x78]; int busy; unsigned char pad7c[6]; u16 counter; } Obj_021B63D0;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,u32);
extern u32 func_020307B0(void *p);
extern int func_0203CD98(void);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_021B6670(void);
extern void func_021B66E0(int,int,int);
extern void func_021B6760(int *p);
extern int func_0203CEAC(int a0);
extern void func_021B6674(int *p);
extern int func_0203D0DC(int);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern u32 func_0203D378(void);
extern u32 func_0203D1A4(struct Link *p);
extern int func_02039468(u32,u32);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
extern void func_0203A574(u32,u32,u32,u32);
extern void func_0203A5E4(u32);
extern int func_021B678C(int *p, int a, int b);
void *func_021B6100(int a,int b,int c,int d);
void func_021B6148(void *a0);
int func_021B6150(struct Obj_021B6150 *p);
int func_021B61E8(Obj_021B61E8 *o);
int func_021B6254(int *p);
int func_021B62AC(int *p);
int func_021B62FC(int *p);
int func_021B630C(int *p,int value);
void func_021B63BC(int *p);
void func_021B63C4(int *p);
void func_021B63CC(int *p,int n);
int func_021B63D0(Obj_021B63D0 *p);
int func_021B6424(int p);
int func_021B6480(int *p);
int func_021B6494(u32 p,u32 a,u32 b,u32 c);
u32 func_021B64B8(u32 p,u32 a,u32 b,u32 c,u8 d,u32 e,u32 f,u32 g);
void func_021B64F0(u32 p,u32 a,u32 b,u32 c,u32 d);
void func_021B6508(u32 p,u32 a);
int func_021B6518(u32 p,u32 a,u32 b);
extern const char d_021B7524[];
extern const struct Config d_021B743C;

void *func_021B6100(int a,int b,int c,int d) {
 char *p;
 p=func_02030734(c,0x8c,0,d_021B7524,0x113);
 func_02082BCC(p,0,0x8c);
 ((struct Obj06362 *)p)->f40=a;
 ((struct Obj06362 *)p)->f88=c;
 ((struct Obj06362 *)p)->f74=0;
 ((struct Obj06362 *)p)->f78=d;
 ((struct Obj06362 *)p)->f0=b;
 return p;
}

void func_021B6148(void *a0) { func_020307B0(a0); }

int func_021B6150(struct Obj_021B6150 *p) {
 struct Config config;
 if(p->done!=0) return 1;
 switch(p->state) {
 case 0:
  if(func_0203CD98()!=0) { p->state=2; }
  else {
   config=d_021B743C;
   config.context=p->context;
   func_0203CBAC((struct Req *)(&config),(u32)func_021B6670,(int)p);
  }
  p->state=1;
  break;
 case 1:
  if(func_0203CD98()!=0) p->state=2;
  break;
 case 2:
  func_021B66E0((int)p+4,(int)p,p->heap);
  p->ready=1;
  p->state=3;
  break;
 case 3:
  p->state=0;
  return 1;
 }
 return 0;
}


int func_021B61E8(Obj_021B61E8 *o)
{
    if (o->busy != 0)
        return 1;
    switch (o->state) {
    case 0:
        if (o->pending != 0) {
            func_021B6760((int *)o->sub);
            o->pending = 0;
        }
        o->done = 0;
        o->state = 1;
        break;
    case 1:
        if (func_0203CEAC((int)func_021B6674) != 0)
            o->state = 2;
        else
            o->state = 3;
        break;
    case 2:
        if (o->done != 0)
            o->state = 3;
        break;
    case 3:
        o->state = 0;
        return 1;
    }
    return 0;
}

int func_021B6254(int *p)
{
    if (p[30] != 0) return 1;
    switch(p[17]) {
    case 0:
        func_0203D0DC(0);
        p[17] = 1;
        p[33] = 1;
        p[20] = 0;
        p[19] = 0;
        break;
    case 1:
        if(p[20] != 0) {
            p[33] = 0;
            p[17] = 2;
        }
        break;
    case 2:
        p[17] = 0;
        return 1;
    }
    return 0;
}

int func_021B62AC(int *p)
{
    if(p[30]) return 1;
    switch(p[17]) {
    case 0:
        func_02039C68((struct Link *)func_020399A8(),14,13);
        p[17]=1;
        break;
    case 1:
        if(func_02039CB4((struct Link *)func_020399A8(),14,13)) p[17]=2;
        break;
    case 2:
        p[17]=0;
        return 1;
    }
    return 0;
}

int func_021B62FC(int *p) { if(p[30]) return 1; return p[20]; }

int func_021B630C(int *p,int value)
{
    int i;
    if(p[30]) return 1;
    switch(p[17]) {
    case 0:
        p[28]=0;
        if(func_021B6494((unsigned int)p,0xD00,4,(unsigned int)(&value))) p[17]=1;
        break;
    case 1:
        if(func_0203D378()) {
            for(i=0;i<2;i++) { if(value != p[26+i]) break; }
            if(i == 2) p[17]=2;
        } else p[17]=3;
        break;
    case 2:
        if(func_021B6494((unsigned int)p,0xD01,4,(unsigned int)(&value))) p[17]=4;
        break;
    case 3:
        if(p[28]) p[17]=4;
        break;
    case 4:
        p[17]=0;
        return 1;
    }
    return 0;
}

void func_021B63BC(int *p) { p[17]=0; }

void func_021B63C4(int *p) { p[15]=0; p[14]=0; }

void func_021B63CC(int *p,int n) { p[14]=n; }

int func_021B63D0(Obj_021B63D0 *p)
{
    u16 old;
    if (p->busy) return 1;
    old = p->counter;
    p->counter += 1;
    if (old > 180) {
        p->counter = 0;
        if (!func_02039468(0xD02,func_0203D1A4((void *)func_020399A8())))
            return func_021B6424((int)p);
    }
    return 0;
}

int func_021B6424(int p)
{
    unsigned int id;
    u8 other;
    if(((struct Obj22090 *)p)->f78) return 1;
    id=func_0203D1A4((void *)func_020399A8());
    other=(id == 0);
    if(func_02039468(0xD02,id) == 0) {
        return func_021B64B8(p,0xD02,4,p+0x38,other,0,0,1);
    } else {
        return 0;
    }
}

int func_021B6480(int *p) { if(p[30]) return 0; return p[14]-p[15]; }

/*
 * note: trailing two zero alignment bytes. Extern b/c widened because
 *       caller forwards full words without callee's u16 truncation pairs.
 */
int func_021B6494(u32 p,u32 a,u32 b,u32 c) {
    if(((struct Obj22091 *)p)->f78!=0) return 1;
    return func_0203D3A8((struct Entry *)func_020399A8(),a,b,c);
}

u32 func_021B64B8(u32 p,u32 a,u32 b,u32 c,u8 d,u32 e,u32 f,u32 g) {
    if(((struct Obj22092 *)p)->f78!=0) return 1;
    return func_0203D3F8((u32)func_020399A8(),d,a,b,c,e,f,g);
}

/*
 * note: trailing two zero alignment bytes.
 */
void func_021B64F0(u32 p,u32 a,u32 b,u32 c,u32 d) {
    if(((struct Obj22093 *)p)->f78==0) func_0203A574(a,b,c,d);
}

void func_021B6508(u32 p,u32 a) {
    if(((struct Obj22094 *)p)->f78==0) func_0203A5E4(a);
}

int func_021B6518(u32 p,u32 a,u32 b) {
    if(((struct Obj22095 *)p)->f78!=0) return 1;
    return func_021B678C((int *)(p+4),a,b);
}
