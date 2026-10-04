/*
 * function: func_021BC9FC
 * address:  0x021BC9FC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB9F4  0x021BB9F4  thumb  ov099
 *
 * Runs the setup for selector 0x58 and stamps it 0x1CC bytes in.
 */
#include "../include/Obj18194.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021BB9F4(int a);

int func_021BC9FC(char *p, int v)
{
    func_021BB9F4((int)p);
    ((struct Obj18194 *)p)->f1CC = 0x58;
    return v;
}
