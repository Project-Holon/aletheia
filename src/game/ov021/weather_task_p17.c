/*
 * file:     weather_task_p17.c
 * unit:     yes
 * function: func_021A2A84, func_021A2AAC, func_021A2AB8, func_021A2B8C
 * address:  0x021A2A84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj02344.h"
#include "../../matched/include/Obj07494.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef struct {
    u32 f0;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fA;
    s16 fC;
    s16 fE;
    s16 f10;
    s16 f12;
    s32 f14;
    void (*f18)(u32 a, s32 b, u32 c);
} Obj;

typedef struct {
    u32 arg;
    short x4;
    short timer;
    short reload;
    u8 padA[0xE];
    void (*cb)(u32 arg, int x, int a);
} Obj021A2B8C;

int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5);
void func_021A2AAC(char *p, int a, int b, int c, int d);
s32 func_021A2AB8(Obj *o, u32 arg);
int func_021A2B8C(Obj021A2B8C *p, int a);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5)
{
((struct Obj02344 *)((u8 *)(a)))->f0 = b;
((struct Obj02344 *)((u8 *)(a)))->f6 = 0;
((struct Obj02344 *)((u8 *)(a)))->fA = 0;
((struct Obj02344 *)((u8 *)(a)))->f4 = d;
((struct Obj02344 *)((u8 *)(a)))->fC = e0;
((struct Obj02344 *)((u8 *)(a)))->f8 = c;
((struct Obj02344 *)((u8 *)(a)))->fE = e1;
((struct Obj02344 *)((u8 *)(a)))->f10 = e2;
((struct Obj02344 *)((u8 *)(a)))->f12 = e3;
((struct Obj02344 *)((u8 *)(a)))->f14 = e4;
((struct Obj02344 *)((u8 *)(a)))->f18 = e5;
return a;
}


void func_021A2AAC(char *p, int a, int b, int c, int d)
{
    ((struct Obj07494 *)p)->fC = a;
    ((struct Obj07494 *)p)->fE = b;
    ((struct Obj07494 *)p)->f10 = c;
    ((struct Obj07494 *)p)->f14 = d;
}


/*
 * Addresses are Black-image addresses.
 */
s32 func_021A2AB8(Obj *o, u32 arg)
{
    u32 flags;
    s32 neg;

    flags = 0;
    if (o->f10 == 0) {
        flags |= 1;
    } else {
        neg = o->f10 > 0 ? 0 : 1;
        if ((o->f8 >= o->fE && neg == 0) || (o->f8 <= o->fE && neg == 1)) {
            flags |= 1;
            o->f8 = o->fE;
        }
    }
    if (o->f14 == 0) {
        flags |= 2;
    } else {
        neg = o->f14 > 0 ? 0 : 1;
        if ((o->f4 >= o->fC && neg == 0) || (o->f4 <= o->fC && neg == 1)) {
            flags |= 2;
            o->f4 = o->fC;
        }
    }
    o->f6--;
    if (o->f6 <= 0) {
        o->f18(o->f0, o->f4, arg);
        o->f6 = o->f8;
        if (!(flags & 1)) {
            o->f8 += o->f10;
        }
        if (!(flags & 2)) {
            o->fA++;
            if (o->fA >= o->f12) {
                o->fA = 0;
                o->f4 += (s16)o->f14;
            }
        }
    }
    return (flags & 1) ? 1 : 0;
}


int func_021A2B8C(Obj021A2B8C *p, int a)
{
    p->timer--;
    if (p->timer <= 0) {
        p->cb(p->arg, p->x4, a);
        p->timer = p->reload;
        return 1;
    }
    return 0;
}
