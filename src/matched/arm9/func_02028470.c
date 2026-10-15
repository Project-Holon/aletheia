/*
 * function: PRINTSYS_CTRL_Init
 * address:  0x02028470
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PRINTSYS_CTRL_Init.c \\
 *       --func PRINTSYS_CTRL_Init --addr 0x02028470 --thumb --cc 1.1p1
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj15794.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MI_CpuFill8(void *p, u32 v, u32 size);

void PRINTSYS_CTRL_Init(u8 *p, u32 v)
{
    MI_CpuFill8(p, 0, 8);
    ((struct Obj15794 *)p)->f4 = v;
}
