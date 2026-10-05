/*
 * function: func_021C15FC
 * address:  0x021C15FC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *
 * Runs the setup for selector 0x0B and stamps it 0x1CC bytes in.
 */
#include "../include/Obj18279.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021BA8EC(char *p);

int func_021C15FC(char *p, int v)
{
    func_021BA8EC(p);
    ((struct Obj18279 *)p)->f1CC = 0x0B;
    return v;
}
