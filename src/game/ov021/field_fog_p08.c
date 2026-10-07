/*
 * file:     field_fog_p08.c
 * unit:     yes
 * function: func_021A0138, func_021A0140
 * address:  0x021A0138
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
 *   func_020307B0  0x020307B0  arm
 *   func_021A0250  0x021A0250  thumb  ov021
 *   func_021A0280  0x021A0280  thumb  ov021
 *   func_021A0290  0x021A0290  thumb  ov021
 *   func_021A02A8  0x021A02A8  thumb  ov021
 */
#include "../../matched/include/Obj09536.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

extern u32 func_020307B0(void *p);
extern int func_021A0250(u8 *);
extern int func_021A0280(u32 a);
extern u32 func_021A0290(u8 *);
extern u16 func_021A02A8(u8 *);
void func_021A0138(u32 a);
void func_021A0140(u8 *p);


/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A0138(u32 a)
{
    func_020307B0((void *)a);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A0140(u8 *p)
{
    if (func_021A0250(p + 0x2c)) {
        func_021A0280((u32)(p + 0x2c));
        ((struct Obj09536 *)p)->f4 = func_021A0290(p + 0x2c);
        p[2] = func_021A02A8(p + 0x2c);
        ((struct Obj09536 *)p)->f40 = 1;
    }
}
