/*
 * file:     fld_trade_p15.c
 * unit:     yes
 * function: func_021CE78C, func_021CE7AC, func_021CE81C, func_021CE84C, func_021CE8B0, func_021CE8F4
 * address:  0x021CE78C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   data_021DB498  0x021DB498  data   ov021
 *   func_02190490  0x02190490  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190794  0x02190794  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190758  0x02190758  thumb  ov021
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021CE934  0x021CE934  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   func_021CE984  0x021CE984  thumb  ov021
 *   data_021DB470  0x021DB470  data  a4
 */
#include "../../matched/include/Obj09217.h"
#include "../../matched/include/Obj03619.h"
#include "../../matched/include/Obj02736.h"

struct Fx;
struct Slot;
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u8 b[6]; } Mac;

typedef signed int     s32;

extern u32 func_02190EF0(u32 *p);
extern u32 func_02188C54(u8 *p);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
extern int func_02190740(u32 a, u32 b, u32 c, u32 d);
extern int func_02190728(void *a);
extern void func_02190490(u8 *p);
extern int func_0219077C(u8 *p);
extern void func_02190794(struct Slot **p, int x, int y, int w, int h);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);
extern int func_0203EFC8(const void *a, const void *b, int n);
extern void func_021CE934(u8 *p, u8 *e, u8 i);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_021CE984(u32 *p, u32 n);
int func_021CE78C(u32 a);
void func_021CE7AC(u32 *p);
void func_021CE81C(u32 *p);
int func_021CE84C(u32 *p, int n);
void func_021CE8B0(u8 *p, u8 *e, int i);
void func_021CE8F4(u8 *p, u8 *e, int i);
extern u8 data_021DB498[];
extern u8 data_021DB470[];


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CE78C(u32 a)
{
if (*(u32 *)((u8 *)(a) + ((1 << 8))) == 0) {
    if (func_02190EF0((u32 *)(((struct Obj09217 *)((u8 *)(a)))->f14)) == 1) {
        return 1;
    }
}
return 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021CE7AC(u32 *p)
{
    u32 h;
    int k;

    h = func_02188C54((u8 *)p[0]);
    k = 0x10;
    if (((struct Obj03619 *)p)->f51F) {
        k = 0xe;
    }
    p[3] = (u32)func_02190708((struct Fx *)h, p[2], 2, 6, 0x12, k - 6);
    p[4] = (u32)func_02190708((struct Fx *)h, p[2], 2, 1, 0x1c, 2);
    func_02190740(p[4], 0, 0, *(u16 *)(data_021DB498 + ((struct Obj03619 *)p)->f520 * 12));
}


void func_021CE81C(u32 *p)
{
    u32 h = func_02188C54((u8 *)p[0]);

    if (p[4] != 0) {
        func_02190728((void *)p[4]);
        p[4] = 0;
    }
    if (p[3] != 0) {
        func_02190728((void *)p[3]);
        p[3] = 0;
    }
    func_02190490((u8 *)h);
}


int func_021CE84C(u32 *p, int n)
{
    if (p[3] && func_0219077C((u8 *)p[3]) == 1) {
        func_02190794((struct Slot **)p[3], 0, 0x40, 0x90, 0x50);
        func_0201EFA4((struct WordSet *)p[1], 0, ((struct Obj02736 *)p)->f51D - n, 1, 0, 1);
        func_0201F250((struct WordSet *)p[1], (void *)p[10], (void *)p[9]);
        func_02190758(p[3], 0, 0x40, p[10]);
        return 1;
    }
    return 0;
}


void func_021CE8B0(u8 *p, u8 *e, int i)
{
    u8 *t;

    t = p + 0x55a;
    if (func_0203EFC8(e + 0x23, t + i * 6, 6)) {
        func_021CE934(p, e, i);
        func_02082D44(e + 0x23, t + i * 6, 6);
    }
}


void func_021CE8F4(u8 *p, u8 *e, int i)
{
    if (func_0203EFC8(p + 0x55a + i * 6, data_021DB470, 6)) {
        func_021CE984((u32 *)p, i);
        func_02082D44(data_021DB470, ((Mac *)(p + 0x55a))[i].b, 6);
    }
}
