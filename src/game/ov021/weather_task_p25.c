/*
 * file:     weather_task_p25.c
 * unit:     yes
 * function: func_021A30A4, func_021A30B0, func_021A30BC
 * address:  0x021A30A4
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
 *   func_021A3980  0x021A3980  thumb
 *   func_021A398C  0x021A398C  thumb
 *   func_021A3990  0x021A3990  thumb
 */
#include "../../matched/include/Obj19765.h"
#include "../../matched/include/Obj19766.h"
#include "../../matched/include/Obj18018.h"

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_021A3980(u8 *p, u32 a1);
extern u32 func_021A398C(u8 *p);
extern u32 func_021A3990(u8 *p);
void func_021A30A4(u8 *p, u32 b);
u32 func_021A30B0(u8 *p);
int func_021A30BC(u8 *p);


/*
 * Unlabelled leaf: tail-calls 0x021A3980 with the +4 member and the second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021A30A4(u8 *p, u32 b)
{
    func_021A3980((u8 *)(((struct Obj19765 *)p)->f4), b);
}


/*
 * Forwards the +4 member to 0x021A398C (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A30B0(u8 *p)
{
    return func_021A398C((u8 *)(((struct Obj19766 *)p)->f4));
}


/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
int func_021A30BC(u8 *p)
{
    return func_021A3990((u8 *)(((struct Obj18018 *)p)->f4));
}
