/*
 * function: func_0200AB2C
 * address:  0x0200AB2C
 * packet:   pkt_0200A940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   (none - no data references)
 */
#include "../include/Obj11229.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *p, int c, u32 n);

void func_0200AB2C(void *a0)
{
    MI_CpuFill8(a0, 0, 0x34c);
    ((struct Obj11229 *)a0)->f348 = (((struct Obj11229 *)a0)->f348 & ~0xff) | 0x7f;
}
