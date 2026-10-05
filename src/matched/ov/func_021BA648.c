/*
 * function: func_021BA648
 * address:  0x021BA648
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_020307B0  0x020307B0  arm
 *   sub_02082BCC  0x02082BCC  arm
 *
 * Releases the pointer the block starts with, then clears its first 0x14 bytes;
 * the first argument is dead (r1 is homed straight to r4).
 */
#include "../include/Obj18161.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void sub_020307B0(void *p);
extern void sub_02082BCC(void *p, int c, u32 n);

void func_021BA648(int unused, void *p)
{
    sub_020307B0(((struct Obj18161 *)p)->f0);
    sub_02082BCC(p, 0, 0x14);
}
