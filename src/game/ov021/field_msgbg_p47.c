/*
 * file:     field_msgbg_p47.c
 * unit:     yes
 * function: func_0218FEC0, func_0218FF00, func_0218FF20, func_0218FF30, func_0218FF48, func_0218FF50, func_0218FF78
 * address:  0x0218FEC0
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
 *   func_021901E4  0x021901E4  thumb  ov021
 *   func_021901E8  0x021901E8  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 *   func_02190110  0x02190110  thumb  ov021
 *   func_0219014C  0x0219014C  thumb  ov021
 *   func_02190000  0x02190000  thumb
 *   d_021DDA38  0x021DDA38  data  ov021  a4
 *   func_020307B0  0x020307B0  arm
 *   func_02188C58  0x02188C58  thumb
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218F1B4  0x0218F1B4  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_02189A18  0x02189A18  thumb  ov021
 *   func_021AB75C  0x021AB75C  thumb  ov021
 */
#include "../../matched/include/Obj09470.h"
#include "../../matched/include/Obj17918.h"
#include "../../matched/include/Obj04204.h"
#include "../../matched/include/Obj12599.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

extern u32 func_021901E4(u8 *p);
extern u32 func_021901E8(u8 *p);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u32 v);
extern void func_0218ED58(u8 *p, u32 v);
extern void func_0218EC90(u8 *p, u8 *v);
extern void func_0218ECD4(u8 *p, u8 *v);
extern u32 func_02190110(u32);
extern u32 func_0219014C(u32);
extern void func_02190000(u32 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *dst, int val, u32 size);
extern void *func_02188C58(void *p);
extern u32 func_02188CFC(u8 *p);
extern u32 func_02188C5C(u8 *p);
extern void func_021BB260(u32 a, u32 b);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC54(u8 *p);
extern u8 func_0218F1B4(u8 *p);
extern void func_0218F1AC(u8 *p, u32 v);
extern u32 func_02189A18(u8 *p);
extern void func_021AB75C(u8 *p, u32 v);
void func_0218FEC0(u8 *o);
int func_0218FF00(u32 a);
void func_0218FF20(u8 *a);
void *func_0218FF30(u32 heap);
void func_0218FF48(void *a0);
void func_0218FF50(u32 *o, void *a);
u32 func_0218FF78(u32 *p);
extern const char d_021DDA38[];


/*
 * Addresses are Black-image addresses.
 */
void func_0218FEC0(u8 *o)
{
    u8 *a = (u8 *)func_021901E4(o);
    u8 *b = (u8 *)(func_021901E8(o) + 4);
    func_0218ED34(a, ((struct Obj09470 *)b)->f0);
    func_0218ED48(a, ((struct Obj09470 *)b)->f2);
    func_0218ED58(a, ((struct Obj09470 *)b)->f4);
    func_0218EC90(a, b + 8);
    func_0218ECD4(a, b + 0x14);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218FF00(u32 a)
{
if (((struct Obj17918 *)((u8 *)(func_021901E8((u8 *)a))))->f0 == 0) {
    return func_02190110(a);
}
return func_0219014C(a);
}


void func_0218FF20(u8 *a)
{
    if (((struct Obj04204 *)a)->fC != 0)
        func_02190000((u32 *)a);
}


void *func_0218FF30(u32 heap)
{
    return func_02030734(heap, 0x20, 0, d_021DDA38, 0xee);
}


/*
 * Unlabelled tail-call thunk; callee of the thunk at 0x0218FE98.
 *
 * Addresses are Black-image addresses.
 */
void func_0218FF48(void *a0)
{
    func_020307B0(a0);
}


void func_0218FF50(u32 *o, void *a)
{
    func_02082BCC(o, 0, 0x20);
    o[0] = (u32)a;
    o[1] = (u32)func_02188C58(a);
    o[2] = 0;
    o[3] = 0;
    o[5] = 0;
    o[6] = 0;
    o[7] = 0;
}


u32 func_0218FF78(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];
    u8 *r = (u8 *)func_021901E8((u8 *)p);
    if (func_02188CFC((u8 *)a) == 1)
        func_021BB260(func_02188C5C((u8 *)a), 0);
    if (((struct Obj12599 *)r)->f44 != 0) {
        if (func_0218EC5C((u8 *)p[1]) != 0) {
            p[7] = 1;
            p[6] = func_0218EC5C((u8 *)b);
            func_0218EC54((u8 *)b);
        }
    }
    if (((struct Obj12599 *)r)->f48 != 0) {
        p[5] = func_0218F1B4((u8 *)b);
        func_0218F1AC((u8 *)b, 0);
    }
    func_021AB75C((u8 *)func_02189A18((u8 *)a), 0);
    p[3] = 1;
    return p[3];
}
