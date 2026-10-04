/*
 * function: func_021BCAB8
 * address:  0x021BCAB8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBA20  0x021BBA20  thumb  ov099
 *
 * Runs the setup for selector 0x5A and stamps it 0x1CC bytes in.
 */
#include "../include/Obj18201.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021BBA20(int a);

int func_021BCAB8(char *p, int v)
{
    func_021BBA20((int)p);
    ((struct Obj18201 *)p)->f1CC = 0x5A;
    return v;
}
