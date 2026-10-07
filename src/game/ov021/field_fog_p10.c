/*
 * file:     field_fog_p10.c
 * unit:     yes
 * function: func_021A01BC, func_021A01C4, func_021A01CC, func_021A01D4, func_021A01D8, func_021A01FC, func_021A0224, func_021A0244
 * address:  0x021A01BC
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
 *   func_021A0260  0x021A0260  thumb  ov021
 *   func_021A0250  0x021A0250  thumb
 */
#include "../../matched/include/Obj07212.h"
#include "../../matched/include/Obj12080.h"
#include "../../matched/include/Obj12081.h"
#include "../../matched/include/Obj17986.h"
#include "../../matched/include/Obj12696.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_021A0260(u8 *p, u32 a, u32 b, u16 c, u16 d, u16 e);
extern int func_021A0250(u32 a);
int func_021A01BC(u32 a, u32 b);
int func_021A01C4(u32 a, u32 b);
int func_021A01CC(u32 a, u32 b);
u32 func_021A01D4(u8 *p);
void func_021A01D8(u8 *p);
void func_021A01FC(u8 *p, u32 a, u32 b, u32 c);
void func_021A0224(u8 *p, u32 a, u32 b, u32 c, u32 d, u16 e);
int func_021A0244(u8 *p);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A01BC(u32 a, u32 b)
{
((struct Obj07212 *)((u8 *)(a)))->f4 = b;
((struct Obj07212 *)((u8 *)(a)))->f40 = 1;
return a;
}


int func_021A01C4(u32 a, u32 b)
{
((struct Obj12080 *)((u8 *)(a)))->f8 = b;
((struct Obj12080 *)((u8 *)(a)))->f40 = 1;
return a;
}


int func_021A01CC(u32 a, u32 b)
{
((struct Obj12081 *)((u8 *)(a)))->f3 = b;
((struct Obj12081 *)((u8 *)(a)))->f40 = 1;
return a;
}


/*
 * Loads the byte at +0x2 of the object.
 */
u32 func_021A01D4(u8 *p)
{
    return ((struct Obj17986 *)p)->f2;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A01D8(u8 *p)
{
    int i;
    for (i = 0; i < 32; i++) {
        p[0xC + i] = i * 4;
        p[0xC + i] += (i * 4) / 32;
    }
}


void func_021A01FC(u8 *p, u32 a, u32 b, u32 c)
{
    func_021A0260(p + 0x2c, ((struct Obj12696 *)p)->f4, a, p[2], b, c);
}


void func_021A0224(u8 *p, u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_021A0260(p + 0x2c, a, b, c, d, e);
}


/*
 * Tail-call thunk on the object 0x2c bytes in.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0244(u8 *p)
{
    return func_021A0250((u32)(p + 0x2c));
}
