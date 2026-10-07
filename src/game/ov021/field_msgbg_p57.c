/*
 * file:     field_msgbg_p57.c
 * unit:     yes
 * function: func_02190758, func_02190764, func_0219077C, func_02190788, func_02190794, func_021907A8, func_021907C0
 * address:  0x02190758
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
 *   func_02190590  0x02190590  thumb  ov021
 *   func_021905C8  0x021905C8  thumb  ov021
 *   func_0219061C  0x0219061C  thumb  ov021
 *   func_02190620  0x02190620  thumb
 *   func_0219063C  0x0219063C  thumb  ov021
 *   func_02190708  0x02190708  thumb  ov021
 */
#include "../../matched/include/Obj17927.h"
#include "../../matched/include/Obj17928.h"
#include "../../matched/include/Obj17929.h"
#include "../../matched/include/Obj17930.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_02190758;

typedef signed char    s8;

typedef short          s16_02190764;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

typedef short          s16_02190794;

typedef short          s16_021907A8;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

extern u32 func_02190590(u32, u32, u32, u32);
extern void func_021905C8(Slot *s, int x, int y, u32 z, u16 w, u32 v);
extern u32 func_0219061C(u32 *p);
extern int func_02190620(u32 a);
extern void func_0219063C(Slot *s, int x, int y, int w, int h);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
int func_02190758(u32 a, u32 b, u32 c, u32 d);
void func_02190764(Slot **p, int x, int y, u32 z, u16 w, u32 v);
int func_0219077C(u8 *p);
void func_02190788(u8 *p);
void func_02190794(Slot **p, int x, int y, int w, int h);
void func_021907A8(Fx *p, u32 a);
u32 func_021907C0(u8 *p);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02190758(u32 a, u32 b, u32 c, u32 d)
{
return func_02190590(((struct Obj17927 *)((u8 *)(a)))->f4, b, c, d);
}


/*
 * Addresses are Black-image addresses.
 */
void func_02190764(Slot **p, int x, int y, u32 z, u16 w, u32 v)
{
    func_021905C8(p[1], x, y, z, w, v);
}


/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
int func_0219077C(u8 *p)
{
    return func_0219061C((u32 *)(((struct Obj17928 *)p)->f4));
}


void func_02190788(u8 *p)
{
    func_02190620(((struct Obj17929 *)p)->f4);
}


void func_02190794(Slot **p, int x, int y, int w, int h)
{
    func_0219063C(p[1], x, y, w, h);
}


void func_021907A8(Fx *p, u32 a)
{
    func_02190708(p, a, 1, 0x13, 0x1E, 4);
}


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021907C0(u8 *p)
{
    return ((struct Obj17930 *)p)->f0;
}
