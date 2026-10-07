/*
 * file:     pdc_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B613C, func_021B6140, func_021B6144, func_021B6148, func_021B614C, func_021B6150, func_021B6154, func_021B6158, func_021B615C, func_021B61A4
 * address:  0x021B6100
 * region:   ov098
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
 *   d_021B6E60 0x021B6E60 data a1
 *   ov094_id       0x0000005E  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_021B61E8  0x021B61E8  thumb  ov098
 *   func_021B6308 0x021B6308 thumb ov098
 */
#include "../../matched/include/Obj21998.h"
#include "../../matched/include/Obj21999.h"
#include "../../matched/include/Obj22000.h"
#include "../../matched/include/Obj22001.h"
#include "../../matched/include/Obj22002.h"
#include "../../matched/include/Obj22003.h"
#include "../../matched/include/Obj22004.h"
#include "../../matched/include/Obj10195.h"

struct Obj0203159C;
typedef unsigned int u32;

typedef unsigned short u16;

struct P { u32 a, b, c, d, e, f, g, h; };

typedef unsigned char u8;

typedef short s16;

typedef signed char s8;

typedef int s32;

struct W {
    u32 f00;
    u32 f04;
    u16 f08;
};

extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_02034AC4(int id);
extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082AC0(int v, void *p, u32 n);
extern u32 func_021B61E8(int a, int b);
extern int func_021B6308(unsigned p);
struct P *func_021B6100(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 heap);
int func_021B613C(void *p);
int func_021B6140(void *p);
int func_021B6144(void *p);
u32 func_021B6148(u8 *p);
int func_021B614C(int *p);
u32 func_021B6150(u8 *p);
int func_021B6154(void *p);
int func_021B6158(void *p);
int func_021B615C(struct Obj0203159C *a, int b, int c);
int func_021B61A4(int a, int b, int c, unsigned p);
extern const char d_021B6E60[];
extern char ov094_id[];

struct P *func_021B6100(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 heap)
{
    struct P *p;
    p = func_02030734(heap, 0x20, 0, d_021B6E60, 0x50);
    p->a = a; p->b = b; p->c = c; p->d = d;
    p->e = e; p->f = f; p->g = g; p->h = 0;
    return p;
}


int func_021B613C(void *p)
{
    return ((struct Obj21998 *)p)->f0;
}


/*
 * three int getters at +0, +4, +8.
 */
int func_021B6140(void *p)
{
    return ((struct Obj21999 *)p)->f4;
}


int func_021B6144(void *p)
{
    return ((struct Obj22000 *)p)->f8;
}


u32 func_021B6148(u8 *p) { return ((struct Obj22001 *)p)->fC; }

int func_021B614C(int *p)
{
    return p[4];
}


u32 func_021B6150(u8 *p) { return ((struct Obj22002 *)p)->f14; }


int func_021B6154(void *p)
{
    return ((struct Obj22003 *)p)->f18;
}


int func_021B6158(void *p)
{
    return ((struct Obj22004 *)p)->f1C;
}


int func_021B615C(struct Obj0203159C *a, int b, int c)
{
    struct W *p;

    func_02034AC4((int)ov094_id);
    func_0203064C(1, 0x85, 0xc0000);
    p = func_0203159C(a, 0xc, 0x85);
    func_02082AC0(0, p, 0xc);
    p->f08 = 0x85;
    p->f00 = func_021B61E8(c, p->f08);
    p->f04 = c;
    return 1;
}

int func_021B61A4(int a, int b, int c, unsigned p)
{
    *(int *)(((struct Obj10195 *)p)->f4 + 0x1c) = func_021B6308((unsigned int)(((struct Obj10195 *)p)->f0));
    if (*(int *)(((struct Obj10195 *)p)->f4 + 0x1c) != 0) return 1;
    return 0;
}
